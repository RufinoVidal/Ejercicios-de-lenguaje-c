#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void validarActividades(char actividades[][100], int numActividades, char* fecha) {
    FILE* archivo = fopen("actividades.txt", "w");

    for (int i = 0; i < numActividades; i++) {
        fprintf(archivo, "Cadena: %s\n", actividades[i]);

        char fechaActividad[11];
        strncpy(fechaActividad, actividades[i], 10);
        fechaActividad[10] = '\0';

        if (strcmp(fechaActividad, fecha) == 0) {
            fprintf(archivo, "Resultado: Actividad válida\n\n");
        } else {
            fprintf(archivo, "Resultado: Actividad no válida\n\n");
        }
    }

    fclose(archivo);

    printf("Archivo 'actividades.txt' generado correctamente.\n");
}

int main() {
    int n;
    printf("Ingrese el número de actividades: ");
    scanf("%d", &n);

    char actividades[n][100];
    char fecha[11];

    getchar(); 

    printf("Ingrese la fecha (DD/MM/YYYY): ");
    fgets(fecha, 11, stdin);
    fecha[strcspn(fecha, "\n")] = '\0'; 

    getchar(); 

    for (int i = 0; i < n; i++) {
        printf("Ingrese la actividad %d: ", i + 1);
        fgets(actividades[i], 100, stdin);
        actividades[i][strcspn(actividades[i], "\n")] = '\0'; 
    }

    validarActividades(actividades, n, fecha);

    return 0;
}

