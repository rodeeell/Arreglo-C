#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int *Arreglo;

Arreglo borraArreglo(Arreglo A, int n) {
    if(A) {
        free(A);
    }

    return NULL;
}

Arreglo creaArreglo(int n) {
    Arreglo A = calloc(n, sizeof(int));

    if(A == NULL) {
        printf("ERROR: Memoria insuficiente. Este programa se cerrar%c.", 160);
        exit(EXIT_FAILURE);
    }

    return A;
}

void imprimeArreglo(Arreglo A, int n) {
    int i;

    if(!A) {
        printf("Arreglo no definido.\n\n");
        return;
    }

    for (i=0; i<n; i++) {
        printf("%4i", A[i]);
    }

    printf("\n\n");
}


Arreglo leeArreglo(char nombreArchivo[20], int *pn) {
    FILE *archivo;
    Arreglo A;
    int n, i, valor;

    archivo = fopen(nombreArchivo, "r");

    if(archivo == NULL) {
        printf("Archivo no encontrado. Este programa se cerrar%c.", 160);
        exit(EXIT_FAILURE);
    }

    fscanf(archivo, "%i", &n);
    *pn = n;
    A = creaArreglo(n);

    if(!A) {
        printf("ERROR: No se pudo asignar memoria. Este programa se cerrar%c.", 160);
        exit(EXIT_FAILURE);
    }

    for(i = 0; i < n; i++) {
        fscanf(archivo, "%i", &valor);
        A[i] = valor;
    }

    fclose(archivo);
    return A;
}