// Realizar un programa que tenga las siguientes funciones:
/* Suma de matrices
Substraccion de matrices
Multiplicacion de matrices
Matriz Transpuesta
Presentacion de matrices */

//MATRIZ => Estructura formada como un arreglo 

#include <stdio.h>

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