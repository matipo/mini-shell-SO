# Mini-shell en C para Linux

Proyecto académico de Sistemas Operativos cuyo objetivo es implementar una mini-shell en C para Linux. El repositorio se encuentra actualmente en etapa de preparación: todavía no contiene la implementación.

## Objetivo

La aplicación deberá ejecutar programas externos, administrar procesos en primer y segundo plano, evitar procesos zombis y mostrar información de memoria al finalizar los procesos hijos.

## Requisitos principales

- Usar `fork()` y una función de la familia `exec`.
- Mostrar un prompt `minish>` y leer comandos.
- Ejecutar programas con argumentos, por ejemplo `ls -l /tmp`.
- Gestionar procesos en primer y segundo plano.
- Evitar procesos zombis.
- Incluir los comandos internos `cd`, `exit` y `help`.
- Mostrar información de memoria por proceso y un resumen al salir.
- Compilar sin advertencias y mantener el código modular, indentado y documentado.

## Documentación

- [Enunciado en Markdown](docs/enunciado.md)
- [Enunciado original en PDF](docs/enunciado-original.pdf)

## Estado

Repositorio preparado para iniciar el desarrollo. No se ha añadido código fuente ni una solución del proyecto.

## Entorno previsto

- Linux
- Compilador compatible con C y POSIX, como GCC
- Git

