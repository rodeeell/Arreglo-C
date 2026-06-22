/*
Rodrigo Ignacio Galleguillos Perez 22.188.939-8
*/

#include <stdio.h>
#include <stdlib.h>
#include "arreglo.h"

int busquedabinaria(Arreglo A, int x, int inicio, int fin) {
   
    if (inicio > fin) {
        return -1;
    }
    int mitad = (inicio + fin)/2;
    if (A[mitad] == x) {
        return mitad;
    }
    if (x < A[mitad]) {
        return busquedabinaria(A, x, inicio, mitad - 1);
    }else{
        return busquedabinaria(A, x, mitad + 1, fin);
    }
}

int main() {
    char nombre[20];
    int n;
    int x;
    int resultado;
    Arreglo A;
    
    printf("Ingresa el nombre del archivo: ");
    scanf("%19s", nombre);
    A = leeArreglo(nombre, &n);
    imprimeArreglo(A, n);

    printf("Ingresa el elemento a buscar: ");
    scanf("%d", &x);
    resultado = busquedabinaria(A, x, 0, n - 1);

    if (resultado != -1) {
    printf("Elemento %i encontrado en la posición %i.\n", x, resultado); 
    } else {
    printf("Elemento %i no encontrado.\n", x);
    }

    A = borraArreglo(A, n);
    system("pause");
    return 0;
}


    

