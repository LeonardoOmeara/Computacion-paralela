//Suma de dos numeros ingresados por el usuario
#include <stdio.h>

float fsuma(float, float);
float fresta(float, float);
float fmultiplicacion(float, float);
float fdivision(float, float);
int fmodulo(float, float);


int main(){

    float numero1=0, numero2=0;
    // float suma=0, resta=0, multiplicacion=0, division=0, modulo=0;
    int opcion=0;

    printf("¿Que operacion desea? \n 1.Suma \n 2.Resta \n 3.Multiplicacion \n 4.División \n 5.Modulo \n");
    scanf("%d", &opcion);

    printf("Ingrese el primer numero:\n");
    scanf("%d",&numero1);

    printf("Ingrese el segundo numero:\n");
    scanf("%d",&numero2);

    if (opcion == 1){
        float suma=fsuma(numero1, numero2);
        printf("El resultado de la suma es: %f",suma);
    }
    else if (opcion == 2){
        float resta=fresta(numero1, numero2);
        printf("El resultado de la resta es: %f",resta);
    }
    else if(opcion == 3){
        float multiplicacion=fmultiplicacion(numero1, numero2);
        printf("El resultado de la multiplicacion es: %f",multiplicacion);
    }
    else if(opcion == 4){
        float division=fsuma(numero1, numero2);
        printf("El resultado de la division es: %f",division);
    }
    else if(opcion == 5){
        int modulo=fmodulo(numero1, numero2);
        printf("El resultado del modulo es: %f",modulo);
    }

}

float fsuma( float num1, float num2){
    return num1+num2;
}
float fresta( float num1, float num2){
    return num1-num2;
}
float fmultiplicacion( float num1, float num2){
    return num1*num2;
}
float fdivision( float num1, float num2){
    return num1/num2;
}
int fmodulo( float num1, float num2){
    return (int)num1 % (int)num2;
}