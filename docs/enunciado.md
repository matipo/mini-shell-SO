# Evaluación de Producto RA1: Sistemas Operativos

**Docente:** Lucas Almonacid  
**Correo:** lucas.almonacid@ulagos.cl

## 1. Normas

1. El resultado de aprendizaje a calificar es: **Reconoce la infraestructura computacional de un sistema operativo, identificando sus principios de diseño y métricas de desempeño, con el fin de implementar soluciones que incorporen planificación de procesos e hilos.**
2. La evaluación será de carácter grupal (3 a 4 integrantes).
3. La entrega del proyecto se hará efectiva el día 21 de octubre de 2025 hasta las 11:30 horas, en clases.
4. Es obligatorio el uso de `fork` y funciones de la familia `exec` en la resolución del proyecto.
5. Se tendrá que mostrar una demostración en vivo junto con la revisión del código. Máximo: 10 minutos.

## 2. Enunciado

Implementar una mini-shell en C para Linux que ejecute programas externos, gestione procesos en primer y segundo plano, evite zombis y que, al terminar cada proceso hijo, muestre un reporte de memoria (por ejemplo, memoria disponible del sistema y/o uso de memoria del hijo).

### Prompt y lectura de comandos

- Mostrar un prompt tipo `minish>` e ingresar líneas o comandos.
- Soportar la ejecución de un programa con argumentos; por ejemplo, `ls -l /tmp`.

### Ejecución de procesos y sincronización

La aplicación debe gestionar la ejecución y sincronización de procesos de acuerdo con el enunciado general: primer y segundo plano, prevención de zombis y reporte de memoria al finalizar cada hijo.

### Comandos internos mínimos

- `cd [dir]`: cambia de directorio.
- `exit`: termina la shell, libera sus recursos y muestra un resumen final de memoria.
- `help`: muestra la información de uso.

Al salir de la shell mediante `exit`, se debe mostrar un resumen de los procesos ejecutados y la memoria utilizada.

## 3. Rúbrica de evaluación

| Aspecto | Malo | Regular | Bueno | Excelente |
| --- | --- | --- | --- | --- |
| Compilación | **0 puntos:** no se genera un código ejecutable. | **4 puntos:** se genera un código ejecutable, pero con alertas. | No aplica. | **10 puntos:** se genera un código ejecutable sin alertas. |
| Ejecución | **0 puntos:** no se ejecuta el programa. | **3 puntos:** se ejecuta la aplicación, pero aparece un fallo de segmentación. | No aplica. | **10 puntos:** se ejecuta el código sin complicaciones. |
| Codificación | **0 puntos:** no existe código fuente. | **10 puntos:** se evidencia un código fuente que resuelve parcialmente el problema. | **20 puntos:** se evidencia un código fuente que resuelve el problema. | **35 puntos:** se evidencia un código fuente distribuido en funciones, indentado y documentado correctamente. |
| Demostración en vivo | **0 puntos:** no se presenta una demostración. | **10 puntos:** se presenta una demostración pobre y con muchos errores. | No aplica. | **25 puntos:** se presenta una demostración completa, dentro del tiempo establecido y sin errores. |

> Este archivo es una transcripción legible del documento original. Ante cualquier diferencia, prevalece el [PDF entregado por el docente](enunciado-original.pdf).
