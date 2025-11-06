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
            printf("Código: %s\n", token);
            
            // Obtiene y convierte los siguientes valores
            token = strtok(NULL, ","); // Columna 2
            if (token != NULL) {
                int valor_columna2 = atoi(token);
                printf("IQ: %d\n", valor_columna2);
                
            }
            
            token = strtok(NULL, ","); // Columna 3
            if (token != NULL) {
                float valor_columna3 = atof(token);
                printf("Reultado previo trimestre: %f\n", valor_columna3);
            }
            
            token = strtok(NULL, ","); // Columna 4
            if (token != NULL) {
                float valor_columna4 = atof(token);
                printf("CGPA: %f\n", valor_columna4);
            }
            
            token = strtok(NULL, ","); // Columna 5
            if (token != NULL) {
                int valor_columna5 = atoi(token);
                printf("Rendimiento académico: %d\n", valor_columna5);
            }
            
            token = strtok(NULL, ","); // Columna 6
            if (token != NULL) {
                
                printf("Becado: %s\n", token);
            }
            
            token = strtok(NULL, ","); // Columna 7
            if (token != NULL) {
                int valor_columna7 = atoi(token);
                printf("Puntuación extracurricular: %d\n", valor_columna7);
            }
            
            token = strtok(NULL, ","); // Columna 8
            if (token != NULL) {
                int valor_columna8 = atoi(token);
                printf("Habilidades de comunicación: %d\n", valor_columna8);
            }
            
            token = strtok(NULL, ","); // Columna 9
            if (token != NULL) {
                int valor_columna9 = atoi(token);
                printf("Proyectos completados: %d\n", valor_columna9);
            }
            
            token = strtok(NULL, ","); // Columna 10
            if (token != NULL) {
                
                printf("Trabajo conseguido: %s\n", token);
            }
            
        }
    }

    fclose(archivo);
    return 0;
}

