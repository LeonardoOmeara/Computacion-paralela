#include <stdio.h>
#include <stdlib.h>
#include "funcionesmatrices.h"
#include <omp.h>
#include "ctime.h"

#define SIZE_DATA (1024*1024*64*3)

static double MEM_CHUNK[SIZE_DATA];

// Nueva versión del algoritmo multiplicación de matrices 2 filas * 2 filas
int N, numThreads;
double *matrizA, *matrizB, *matrizC;

int main(int argc, char **argv) {

    int N = (int) atof(argv[1]); //tamaño de la matriz
    int numThreads = (int) atof(argv[2]); // Cantidad de hilos

//	#pragma omp parallel 
	{
		int i, j, k;
		double *matrizA, *matrizB, *matrizC;
		matrizA = MEM_CHUNK;
		matrizB = matrizA + (N*N);
		matrizC = matrizB + (N*N);

		//Se deja que le hilo principal(maestro) haga las rutinas de inicialización
//		#pragma omp master //2,4,8	

		matrizInit(N, matrizA, matrizB, matrizC);
		/*printf("Impresion matriz A \n");
		imprimirMatriz(N,matrizA);
		printf("Impresion matriz B \n");
		imprimirMatriz(N,matrizB);*/

		omp_set_num_threads (numThreads);

		sampleStart();
		// Prueba de multiplicación de matrices con OpenMp

		#pragma omp parallel for
		for (i=0; i<N; i+=2){
			for (j=0; j<N; j+=2){
				double *pA, *pB, c0, c1, c2, c3;
				c0 = c1 = c2 = c3 = 0;
				pA = matrizA+(i*N);
				pB = matrizB+(j*N);
				for (k=N; k>0; k-=2, pA+=2, pB+=2){
					double a0, a1, a2, a3;
					double b0, b1, b2, b3;
					a0 = *pA; a1 = *(pA+1); a2 = *(pA+2); a3 = *(pA+3);				
					b0 = *pB; b1 = *(pB+1); b2 = *(pB+2); b3 = *(pB+3);
					c0 += a0 * b0 + a1 * b1;
					c1 += a0 * b2 + a2 * b3;
					c2 += a2 * b0 + a3 * b1;
					c3 += a2 * b2 + a3 * b3;
				}
				pB = matrizC + i*N+j;
				*pB = c0; *(pB+1)=c1; *(pB+N)=c2; *(pB+N+1)=c3;
			}
		}
		/*printf("impresion matriz C \n");
		imprimirMatriz(N,matrizC);*/
		sampleStop();
	}
	printTime();
}
