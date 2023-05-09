#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int contarVocalesMayusculas(char* palabra) {
    int contador = 0;

    for (int i = 0; palabra[i] != '\0'; i++) {
        char c = palabra[i];

        if (c >= 'A' && c <= 'Z') {
            if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
                contador++;
            }
        }
    }

    return contador;
}

void encontrarPalabraMaxVocales(char** cadenas, int numCadenas) {
    int maxVocales = 0;
    char* palabraMaxVocales = NULL;

    for (int i = 0; i < numCadenas; i++) {
        char* cadena = cadenas[i];
        char* palabra = strtok(cadena, " ");
        
        while (palabra != NULL) {
            int numVocales = contarVocalesMayusculas(palabra);
            
            if (numVocales > maxVocales) {
                maxVocales = numVocales;
                palabraMaxVocales = palabra;
            }
            
            palabra = strtok(NULL, " ");
        }
    }
    
    FILE* archivo = fopen("resultado.txt", "w");
    
    fprintf(archivo, "De las cadenas ingresadas:\n");
    
    for (int i = 0; i < numCadenas; i++) {
        fprintf(archivo, "%s\n", cadenas[i]);
    }
    
    if (palabraMaxVocales != NULL) {
        fprintf(archivo, "\nLa palabra con mayor número de vocales mayúsculas es: %s\n", palabraMaxVocales);
        fprintf(archivo, "Número de vocales mayúsculas: %d\n", maxVocales);
    } else {
        fprintf(archivo, "\nNo se encontraron palabras con vocales mayúsculas.\n");
    }
    
    fclose(archivo);
    
    printf("Archivo 'resultado.txt' generado correctamente.\n");
}

int main() {
    int n;
    printf("Ingrese el número de cadenas: ");
    scanf("%d", &n);

    getchar(); // Limpiar el buffer del salto de línea

    char** cadenas = (char**)malloc(n * sizeof(char*));

    for (int i = 0; i < n; i++) {
        cadenas[i] = (char*)malloc(100 * sizeof(char));

        printf("Ingrese la cadena %d: ", i + 1);
        fgets(cadenas[i], 100, stdin);
        cadenas[i][strcspn(cadenas[i], "\n")] = '\0'; // Eliminar el salto de línea
    }

    encontrarPalabraMaxVocales(cadenas, n);

    for (int i = 0; i < n; i++) {
        free(cadenas[i]);
    }
    free(cadenas);

    return 0;
}

