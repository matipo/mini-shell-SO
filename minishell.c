#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// Generalizar los comandos exec, para asi no tener varias funciones que utilizan la misma estructura
// Procesos en primer y segundo plano.

void mostrar_help()
{
    printf("\nComandos disponibles:\n");
    printf("ls    -> muestra archivos del directorio\n");
    printf("help  -> muestra esta ayuda\n");
    printf("exit  -> termina la shell\n\n");
}


void ejecutar_ls()
{
    pid_t pid = fork();

    if (pid == 0)
    {
        // Proceso hijo

        execlp("ls", "ls", NULL);

        // Solo se ejecuta si execlp falla
        perror("Error al ejecutar ls");

        exit(1);
    }

}


int main()
{
    char comando[100];

    printf("Mini Shell iniciada\n");

    while (1)
    {
        printf("minish> ");

        scanf("%s", comando);


        if (strcmp(comando, "ls") == 0)
        {
            ejecutar_ls();
        }

        else if (strcmp(comando, "help") == 0)
        {
            mostrar_help();
        }

        else if (strcmp(comando, "exit") == 0)
        {
            printf("Cerrando Mini Shell...\n");
            break;
        }

        else
        {
            printf("Comando no reconocido\n");
        }
    }

    return 0;
}