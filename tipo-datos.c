/*
Fecha: 3 agosto 2021
Autor: Leonardo Esteban Omeara Garzon
Tema: Introduccion a C
App: Presentacion de tipos de datos
*/

//---> Header: Llamada al interfaz -> menu de la coleccion de funciones
// disponibles en el header

#include <stdio.h> 
#include <limits.h>
#include  <stdlib.h>// Header: standar de entrada y salida

int main(){
    // float a = 10.3;
    printf("INT _MAX %i \n", INT_MAX);
    printf("INT _MIN %d \n", INT_MIN);
    // printf("Unsigned-INT _MIN %d \n", INT_MAX);
    printf("SHORT _MAX %d \n", SHRT_MAX);
    printf("LONG MAX %d \n", LONG_MAX);
    printf("CHAR _BIT %d \n", CHAR_BIT);

    // printf(" el valor entero es: %i \n",a);
    // printf("%f",a);

    return 0;
}