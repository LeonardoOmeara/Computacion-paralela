#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "funcionesmatrices.h"
#include "ctime.h"

#define SIZE_DATA (1024*1024*64*3)

static double MEM_CHUNK[SIZE_DATA];

// Estrategia declaración de todas las variables de forma global

int N, numThreads;
double *matrizA, *matrizB, *matrizC;

int main(int argc, char **argv) {

    int N = (int) atof(argv[1]); //tamaño de la amtriz
    int numThreads = (int) atof(argv[2]); // Cantidad de hilos

//#pragma omp parallel
{

    double *matrizA, *matrizB, *matrizC;
	matrizA = MEM_CHUNK;
	matrizB = matrizA + (N*N);
	matrizC = matrizB + (N*N);

	//Se deja que el hilo principal(maestro) haga las rutinas de inicialización
//#pragma omp master	

	matrizInit(N, matrizA, matrizB, matrizC);

	omp_set_num_threads (numThreads);

	sampleStart();
	//Prueba de multiplicacion de matrices de OpenMp

#pragma omp parallel for 
	for (int i=0; i<N; i++){
		for (int j=0; j<N; j++){
			double *pA, *pB;
			double suma = 0.0;
			pA = matrizA+(i*N);
			pB = matrizB+j;
			
			for (int k=0; k<N; k++, pA++, pB+=N){
				suma += (*pA * *pB);
			}
			matrizC[i*N+j]= suma;
		}
	}

	sampleStop();
}
	printTime();
	return 0;
}
