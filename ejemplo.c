#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *archivo;
    char linea[256];
    char *token;
    int maxIQ=158;
    int minIQ=45;
    float maxTrim=10;
    float minTrim=5;
    float maxCGPA=10.46;
    float minCGPA=4.54;
    int maxRend=10;
    int minRend = 1;
    int maxCurr=10;
    int minCurr = 0;
    int maxCom = 10;
    int minCom=1;
    int maxProy=5;
    int minProy=0;
  
    
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
                float valor_columnaN2=(((float)valor_columna2 - (float)minIQ)/((float)maxIQ - (float)minIQ));
                printf("IQ normalizado: %.2f\n", valor_columnaN2);
                
            }
            
            token = strtok(NULL, ","); // Columna 3
            if (token != NULL) {
                float valor_columna3 = atof(token);
                printf("Reultado previo trimestre: %.2f\n", valor_columna3);
                float valor_columnaN3=((valor_columna3 - minTrim)/(maxTrim - minTrim));
                printf("Reultado previo normalizado: %.2f\n", valor_columnaN3);
            }
            
            token = strtok(NULL, ","); // Columna 4
            if (token != NULL) {
                float valor_columna4 = atof(token);
                printf("CGPA: %.2f\n", valor_columna4);
                float valor_columnaN4=((valor_columna4 - minCGPA)/(maxCGPA - minCGPA));
                printf("CGPA normalizado: %.2f\n", valor_columnaN4);
            }
            
            token = strtok(NULL, ","); // Columna 5
            if (token != NULL) {
                int valor_columna5 = atoi(token);
                printf("Rendimiento académico: %d\n", valor_columna5);
                float valor_columnaN5=(((float)valor_columna5 - (float)minRend)/((float)maxRend - (float)minRend));
                printf("Rendimiento académico normalizado: %.2f\n", valor_columnaN5);
            }
            
            token = strtok(NULL, ","); // Columna 6
            if (token != NULL) {
                
                printf("Becado: %s\n", token);
            }
            
            token = strtok(NULL, ","); // Columna 7
            if (token != NULL) {
                int valor_columna7 = atoi(token);
                printf("Puntuación extracurricular: %d\n", valor_columna7);
                float valor_columnaN7=(((float)valor_columna7 - (float)minCurr)/((float)maxCurr - (float)minCurr));
                printf("Puntuación extracurricular normalizado: %.2f\n", valor_columnaN7);
            }
            
            token = strtok(NULL, ","); // Columna 8
            if (token != NULL) {
                int valor_columna8 = atoi(token);
                printf("Habilidades de comunicación: %d\n", valor_columna8);
                float valor_columnaN8=(((float)valor_columna8 - (float)minCom)/((float)maxCom - (float)minCom));
                printf("Habilidades de comunicación normalizado: %.2f\n", valor_columnaN8);   
            }
            
            token = strtok(NULL, ","); // Columna 9
            if (token != NULL) {
                int valor_columna9 = atoi(token);
                printf("Proyectos completados: %d\n", valor_columna9);
                float valor_columnaN9=(((float)valor_columna9 - (float)minProy)/((float)maxProy - (float)minProy));
                printf("Proyectos completados normalizado: %.2f\n", valor_columnaN9);   
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

