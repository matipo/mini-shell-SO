#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/resource.h>

// contadores globales para mostrar el resumen al salir
int total_procesos = 0;
long memoria_usada_kb = 0;


// el help
void mostrar_help()
{
    printf("\nComandos disponibles:\n");
    printf("cd [dir] -> cambia de directorio\n");
    printf("help     -> muestra esta ayuda\n");
    printf("exit     -> termina la shell y muestra resumen\n");
    printf("Ademas puedes ejecutar cualquier comando externo (ej: ls -l /tmp)\n");
    printf("Agrega '&' al final para ejecutar en segundo plano (ej: sleep 2 &)\n\n");
}


// muestra el uso de memoria de los procesos hijos
void mostrar_memoria()
{
    struct rusage uso;

    // obtenemos el reporte de recursos usados por los procesos hijos
    getrusage(RUSAGE_CHILDREN, &uso);
    memoria_usada_kb = uso.ru_maxrss;

    printf("[Reporte Memoria] Memoria utilizada por hijos: %ld KB\n", memoria_usada_kb);
}


// cambia de directorio
void cambiar_directorio(char *directorio)
{
    if (directorio == NULL)
    {
        printf("Uso: cd [directorio]\n");
        return;
    }

    // chdir es la funcion de unistd.h para cambiar de carpeta
    if (chdir(directorio) != 0)
    {
        perror("Error al cambiar de directorio");
    }
}


// ejecuta cualquier programa externo usando fork(), execvp() y waitpid()
void ejecutar_comando(char *argumentos[], int segundo_plano)
{
    // creamos un proceso hijo
    pid_t pid = fork();

    if (pid == 0)
    {
       
        // execvp reemplaza el codigo del hijo por el programa y busca en el PATH
        execvp(argumentos[0], argumentos);

        // solo se ejecuta si execvp falla
        perror("Error al ejecutar el comando");
        exit(1);
    }
    else if (pid > 0)
    {
    
        total_procesos++;

        if (segundo_plano == 0)
        {
            // PRIMER PLANO: el padre espera a que este hijo termine
            waitpid(pid, NULL, 0);
            mostrar_memoria();
        }
        else
        {
            // SEGUNDO PLANO: el padre no espera y sigue mostrando el prompt
            printf("[Segundo plano] Proceso hijo creado con PID: %d\n", pid);
        }
    }
    else
    {
        perror("Error en fork");
    }
}


int main()
{
    char linea[100];
    char *argumentos[20];

    printf("Mini Shell iniciada\n");

    while (1)
    {
        // antes de pedir comando, recogemos hijos en segundo plano que ya terminaron
        // asi evitamos que queden como procesos ZOMBIE
        while (waitpid(-1, NULL, WNOHANG) > 0)
        {
            printf("\n[Segundo plano] Un proceso hijo ha terminado.\n");
            mostrar_memoria();
        }

        // mostramos el prompt
        printf("minish> ");

        // leemos toda la linea escrita por el usuario
        if (fgets(linea, sizeof(linea), stdin) == NULL)
        {
            break;
        }

        // separamos la linea por espacios para obtener el comando y sus argumentos
        int i = 0;
        char *palabra = strtok(linea, " \n");
        while (palabra != NULL)
        {
            argumentos[i] = palabra;
            i++;
            palabra = strtok(NULL, " \n");
        }
        argumentos[i] = NULL; 

        // si el usuario presiono Enter sin escribir nada, repetimos el ciclo
        if (argumentos[0] == NULL)
        {
            continue;
        }

        // revisamos si el ultimo argumento es & para segundo plano
        int segundo_plano = 0;
        if (i > 0 && strcmp(argumentos[i - 1], "&") == 0)
        {
            segundo_plano = 1;
            argumentos[i - 1] = NULL; // quitamos el & de los argumentos del comando
        }

        if (strcmp(argumentos[0], "help") == 0)
        {
            mostrar_help();
        }
        else if (strcmp(argumentos[0], "cd") == 0)
        {
            cambiar_directorio(argumentos[1]);
        }
        else if (strcmp(argumentos[0], "exit") == 0)
        {
            // antes de salir esperamos si queda algun proceso hijo pendiente
            while (waitpid(-1, NULL, 0) > 0);

            printf("\n--- Resumen Final ---\n");
            printf("Procesos ejecutados : %d\n", total_procesos);
            printf("Memoria utilizada   : %ld KB\n", memoria_usada_kb);
            printf("Cerrando Mini Shell...\n");
            break;
        }
        else
        {
            ejecutar_comando(argumentos, segundo_plano);
        }
    }

    return 0;
}
