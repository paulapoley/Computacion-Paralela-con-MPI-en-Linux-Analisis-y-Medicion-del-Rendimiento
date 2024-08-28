/* INTEGRACION NUMERICA POR EL METODO DE LOS TRAPECIOS
 *
 * ENTRADA: NINGUNA.
 * SALIDA:  ESTIMACION DE LA INTEGRAL DESDE a HASTA b DE f(x)
 * USANDO EL METODO DE LOS TRAPECIOS CON n TRAPECIOS
 */
#include <stdio.h>
#include <math.h>
#include <mpi.h>

int main(int argc, char** argv) {
    int         mi_rango;  // RANGO DE MI PROCESO
    int         p;         // NUMERO DE PROCESOS
    float       a = -1.0;  // EXTREMO IZQUIERDO
    float       b = 1.0;   // EXTREMO DERECHO
    int         n = 10000; // NUMERO DE TRAPECIOS
    float       h;         // LONGITUD DE LA BASE DEL TRAPECIO
    float       local_a;   // EXTREMO IZQUIERDO PARA MI PROCESO
    float       local_b;   // EXTREMO DERECHO PARA MI PROCESO
    int         local_n;   // NUMERO DE TRAPECIOS PARA EL CALCULO
    float       integral;  // INTEGRAL SOBRE MI INTERVALO
    float       total;     // INTEGRAL TOTAL
    int         fuente;    // PROCESO QUE ENVIA RESULTADO DE INTEGRAL
    int         dest = 0;  // DESTINATARIO: TODOS LOS MENSAJES VAN A 0
    int         etiqueta = 0;
    MPI_Status  status;

    float Trapecio(float local_a, float local_b, int local_n,
              float h);    // CALCULA LA INTEGRAL LOCAL (AREA DEL TRAPECIO)

    MPI_Init(&argc, &argv);		// INICIALIZA MPI ARRANCAR MPI

    MPI_Comm_size(MPI_COMM_WORLD, &p); 	// mi_rango <-- RANGO DE MI PROCESO
    MPI_Comm_rank(MPI_COMM_WORLD, &mi_rango);
  
    h=(b-a)/n;    // CALCULA h: ANCHO DE CADA TRAPECIO
    local_n = n/p;  // CALCULA local_n: EL NUMERO DE TRAPECIOS POR PROCESO

     /* LONGITUD DEL INTERVALO DE INTEGRACION DE CADA PROCESO = local_n*h
      * ASI QUE MI INTERVALO COMIENZA EN: */
    local_a = a + mi_rango*local_n*h; 
    local_b = local_a + local_n*h;

    integral = Trapecio(local_a, local_b, local_n, h);

    /* EL PROCESO 0 RECIBE Y SUMA LAS INTEGRALES CALCULADAS POR CADA PROCESO */
    if (mi_rango == 0) {
    /* Sumo los cálculos de cada proceso, que me envían los demás */
        total = integral;
        for (fuente = 1; fuente < p; fuente++) {
            MPI_Recv(&integral, 1, MPI_FLOAT, fuente, etiqueta, MPI_COMM_WORLD, &status);
            total = total + integral;
        }
    } else { /* Envío mi resultado al proceso 0 */
        MPI_Send(&integral, 1, MPI_FLOAT, dest, etiqueta, MPI_COMM_WORLD);
    }

    /* MUESTRA EL RESULTADO POR PANTALLA */
    if (mi_rango == 0) {
    	printf("ESTIMACION USANDO n=%d TRAPECIOS,\n", n);
    	printf("DE LA INTEGRAL DESDE %f HASTA %f = %f\n", a, b, total); 

	printf("PI = %f\n", 2 * total);
    }

  	MPI_Finalize();	// CIERRA EL UNIVERSO MPI
} /* MAIN  */

/* FUNCION QUE CALCULA LA INTEGRAL LOCAL (AREA DEL TRAPECIO) */
float Trapecio(
          float  local_a   /* entrada */,
          float  local_b   /* entrada */,
          int    local_n   /* entrada */,
          float  h         /* entrada */) {

    float integral;   /* ALMACENA EL RESULTADO EN integral  */
    float x;
    int i;

    float f(float x); /* FUNCION QUE ESTAMOS INTEGRANDO */

    // CALCULA EL VALOR DE integral DESDE local_a HASTA local_b
    integral = (f(local_a) + f(local_b))/2.0;
    x = local_a;
    for (i = 1; i <= local_n-1; i++) {
        x = x + h;
        integral = integral + f(x);
    }
    integral = integral*h;
    return integral;
} /*  TRAPECIO  */

/* FUNCION QUE ESTAMOS INTEGRANDO */
float f(float x) {
    float return_val;
    /* CALCULA f(x) Y DEVUELVE SU VALOR */
    return_val = sqrt(fabs( 1 - x*x ));
    return return_val;
} /* f */



