
# Título: Computacion-Paralela-con-MPI-en-Linux-Analisis-y-Medicion-del-Rendimiento

Este repositorio contiene un proyecto de la asignatura Arquitectura de Sistemas y Software de Base, que explora la computación paralela con MPI en Linux. Incluye la modificación de programas para medir tiempos, ejecutar procesos en paralelo y analizar el rendimiento en diversas configuraciones.

## 1. Descripción
El objetivo de esta práctica es explorar y aplicar técnicas de computación paralela con MPI en sistemas de memoria distribuida. Se modificaron y optimizaron programas para medir tiempos de ejecución, realizar estimaciones numéricas y analizar el rendimiento en diferentes configuraciones de procesos. La práctica incluye ejercicios que abarcan desde la modificación básica de programas hasta la ejecución paralela en múltiples PCs.

## 2. Contenidos del Repositorio
El repositorio está organizado en varias carpetas y archivos que contienen el código fuente, scripts, documentación y resultados del análisis.

### 2.1. Código Fuente (src)
La carpeta /src contiene los programas en C y los scripts asociados:

- [hola_mundo_avanzado.c](src/hola_mundo_avanzado.c): Programa modificado para incluir el nombre del procesador.
  
-  [prod_escalar_mpi.c](src/prod_escalar_mpi.c): Programa que realiza el producto escalar y mide el tiempo de ejecución.
  
-  [integracion_trapecios_pi_esqueleto.c](src/integracion_trapecios_pi_esqueleto.c): Programa paralelo para estimar el valor de π utilizando el método de los trapecios.
-  [integracion_trapecios_pi_esqueleto_modif.c](src/integracion_trapecios_pi_esqueleto_modif.c): Versión modificada del programa para estimación de π con mejoras en la medición de tiempos y optimización.

- [slots.conf](src/slots.conf): Configuración para el número de procesos en el sistema.

### 2.2. Documentos (docs)
La carpeta /docs incluye documentos y gráficos generados durante la práctica:

- [Computacion-paralela-MPI-PPC.pdf](docs/Computacion-paralela-MPI-PPC.pdf) practica_mpi.pdf: Documento que detalla la práctica, los ejercicios realizados y los resultados obtenidos.


## 3. Características Principales
-**Lenguaje y Entorno:** C y Linux.

-**Tecnologías Utilizadas:**
  - MPI (Message Passing Interface)
  - GNUplot para la visualización de datos
    
-**Ejercicios:**
  - Modificación y mejora de programas de ejemplo.
  - Medición del tiempo de ejecución usando MPI_Wtime.
  - Estimación de π y análisis de rendimiento.
  - Ejecución en un clúster de PCs.

## 4. Resultados y Observaciones
- Medición del Tiempo: Los tiempos de ejecución se recopilaron variando el número de procesos, y se observó que la aceleración no siempre sigue una tendencia lineal.
  
- Estudio de Rendimiento: Se realizaron gráficos de tiempo y aceleración para analizar el comportamiento del programa en diferentes configuraciones.
