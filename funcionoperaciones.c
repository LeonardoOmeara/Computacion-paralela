// Realizar un programa que tenga las siguientes funciones:
/* Suma de matrices
Substraccion de matrices
Multiplicacion de matrices
Matriz Transpuesta
Presentacion de matrices */

//MATRIZ => Estructura formada como un arreglo 

#include <stdio.h>
#include "funcionoperaciones.h"

void sumaMatrices(int matrizA[3][3], int matrizB[3][3], int matrizC[3][3]){
    int N = 3;
    for (int i = 0; i <N; i++){
        for (int j = 0; j < N; j++){
            matrizC[i][j] = matrizA[i][j] + matrizB[i][j];
        } 
    }
}

void restaMatrices(int matrizA[3][3], int matrizB[3][3], int matrizC[3][3]){
    int N = 3;
    for (int i = 0; i <N; i++){
        for (int j = 0; j < N; j++){
            matrizC[i][j] = matrizA[i][j] - matrizB[i][j];
        } 
    }
}

void multiplicacionMatrices(int matrizA[3][3], int matrizB[3][3], int matrizC[3][3]){
    int N = 3;
    for (int i = 0; i <N; i++){
        for (int j = 0; j < N; j++){
            matrizC[i][j] = 0;
            for (int k = 0; k < N; k++)
            {
                matrizC[i][j] += matrizA[i][k] * matrizB[k][j];
            }
            
        } 
    }
}

void matrizTranspuesta(int matrizA[3][3], int matrizC[3][3]){
    int N = 3;
    for (int i = 0; i <N; i++){
        for (int j = 0; j < N; j++){
            matrizC[i][j] = matrizA[j][j];
        } 
    }
}

void imprimirMatriz(int matrizResultante[3][3]){
    int N = 3;
    for (int i = 0; i <N; i++){
        for (int j = 0; j < N; j++){
            printf("%d/", matrizResultante[i][j]);
        }
        printf("\n");
    }
}  

