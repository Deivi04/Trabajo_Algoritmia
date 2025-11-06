#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *archivo;
    char linea[256];
    char *token;
    // Asegúrate de que el nombre del archivo sea correcto
    archivo = fopen("CollegePlacement.csv", "r");

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    // Lee la cabecera si es necesario y descártala
    fgets(linea, sizeof(linea), archivo);

    // Lee el archivo línea por línea
    while (fgets(linea, sizeof(linea), archivo)) {
        // Usa strtok para separar los valores por coma (',')
        token = strtok(linea, ",");
        if (token != NULL) {
            // Imprime el primer valor (columna 1)
            printf("Columna 1: %s\n", token);
            
            // Obtiene y convierte los siguientes valores
            token = strtok(NULL, ","); // Columna 2
            if (token != NULL) {
                int valor_columna2 = atoi(token);
                printf("Columna 2: %d\n", valor_columna2);
            }
            // ... repite para las otras columnas
        }
    }

    fclose(archivo);
    return 0;
}

