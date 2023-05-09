#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convertirNumero(const char* numero, char** nuevoNumero) {
    int len = strlen(numero);
    
    *nuevoNumero = (char*)malloc((len + 8) * sizeof(char));
    
    strncpy(*nuevoNumero, "(", 2);
    strncat(*nuevoNumero, numero, 2);
    strncat(*nuevoNumero, ")-", 3);
    strncat(*nuevoNumero, &numero[2], 1);
    strncat(*nuevoNumero, "-", 2);
    strncat(*nuevoNumero, &numero[3], len-3);
}

int main() {
    int n;
    printf("Ingrese el número de números telefónicos: ");
    scanf("%d", &n);

    getchar(); 

    char** numeros = (char**)malloc(n * sizeof(char*));

    for (int i = 0; i < n; i++) {
        numeros[i] = (char*)malloc(20 * sizeof(char));

        printf("Ingrese el número telefónico %d: ", i + 1);
        fgets(numeros[i], 20, stdin);
        numeros[i][strcspn(numeros[i], "\n")] = '\0'; 
    }
    
    FILE* archivo = fopen("resultado.txt", "w");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo para escritura.\n");
        return 1;
    }
    
    fprintf(archivo, "Números telefónicos convertidos:\n");
    
    for (int i = 0; i < n; i++) {
        char* nuevoNumero;
        convertirNumero(numeros[i], &nuevoNumero);
        
        fprintf(archivo, "Número telefónico: %s\n", numeros[i]);
        fprintf(archivo, "Nueva cadena: %s\n\n", nuevoNumero);
        
        free(nuevoNumero);
    }
    
    fclose(archivo);
    
    printf("Archivo 'resultado.txt' generado correctamente.\n");

    for (int i = 0; i < n; i++) {
        free(numeros[i]);
    }
    free(numeros);

    return 0;
}


