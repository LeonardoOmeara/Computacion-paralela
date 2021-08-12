#include <stdio.h>
#include "funcionsuma.h"  //Cuando hagamos nuestras interfaces la invocamos entre comillas


int main(){
    int a, b;

    printf("Ingrese e valor de a: \n");
    scanf("%d", &a);

    printf("Ingrese e valor de b: \n");
    scanf("%d", &b);

    printf("La suma de A + B es: %d",suma(a, b));
    //& para llegar a la refencia de la variable
}