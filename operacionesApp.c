#include <stdio.h>
#include "funcionoperaciones.h"  //Cuando hagamos nuestras interfaces la invocamos entre comillas


int main(){
    int N = 3;
    int matrizA[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    int matrizB[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    int matrizC[3][3]={{0,0,0},{0,0,0},{0,0,0}};

    printf("Matriz A: \n");
    imprimirMatriz(matrizA);

    printf("Matriz B: \n");
    imprimirMatriz(matrizB);

    printf("Suma de Matriz A y Matriz B: \n");
    sumaMatrices(matrizA, matrizB, matrizC);
    imprimirMatriz(matrizC);

    printf("Resta de Matriz A y Matriz B: \n");
    restaMatrices(matrizA, matrizB, matrizC);
    imprimirMatriz(matrizC);

    printf("Multiplicacion de Matriz A y Matriz B: \n");
    multiplicacionMatrices(matrizA, matrizB, matrizC);
    imprimirMatriz(matrizC);

    printf("Matriz transpuesta de A: \n");
    matrizTranspuesta(matrizA, matrizC);
    imprimirMatriz(matrizC);

    return 0;
    
}