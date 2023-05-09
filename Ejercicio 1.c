#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void imprimirCadenaInversa(char* cadena) {
    FILE* archivo = fopen("salida.txt", "w");
    int numEspacios = 0;
    int numVocales = 0;
    int numConsonantes = 0;

    int longitud = strlen(cadena);

    for (int i = longitud - 1; i >= 0; i--) {
        fprintf(archivo, "%c", cadena[i]);

        if (cadena[i] == ' ') {
            numEspacios++;
        }

        char c = tolower(cadena[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            numVocales++;
        } else if ((c >= 'b' && c <= 'z')) {
            numConsonantes++;
        }
    }

    fclose(archivo);

    printf("Archivo 'salida.txt' generado correctamente.\n");
    printf("Número de palabras: %d\n", numEspacios + 1);
    printf("Número de vocales: %d\n", numVocales);
    printf("Número de consonantes: %d\n", numConsonantes);
    printf("Número de espacios: %d\n", numEspacios);
}

int main() {
    char cadena[100];

    printf("Ingrese una cadena de caracteres: ");
    fgets(cadena, 100, stdin);

    if (cadena[strlen(cadena) - 1] == '\n') {
        cadena[strlen(cadena) - 1] = '\0';
    }

    imprimirCadenaInversa(cadena);

    return 0;
}

