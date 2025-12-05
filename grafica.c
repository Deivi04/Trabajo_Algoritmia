#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>





int main() {
    FILE *archivo;
    char linea[256];
    char *token;
    int maxIQ=158;
    int minIQ=41;
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
    
    float tabla[10000][9];
    
    typedef struct objeto{
		float dist;
		float result;
	}objeto;
    
    int i=0;
    int j=0;
  
    
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
			j=0;
            // Imprime el primer valor (columna 1)
            printf("Código: %s\n", token);
            
            // Obtiene y convierte los siguientes valores
            token = strtok(NULL, ","); // Columna 2
            if (token != NULL) {
                int valor_columna2 = atoi(token);
                printf("IQ: %d\n", valor_columna2);
                float valor_columnaN2=(((float)valor_columna2 - (float)minIQ)/((float)maxIQ - (float)minIQ));
                printf("IQ normalizado: %.2f\n", valor_columnaN2);
                tabla[i][j]=valor_columnaN2;
                j++;
                
            }
            
            token = strtok(NULL, ","); // Columna 3
            if (token != NULL) {
                float valor_columna3 = atof(token);
                printf("Reultado previo trimestre: %.2f\n", valor_columna3);
                float valor_columnaN3=((valor_columna3 - minTrim)/(maxTrim - minTrim));
                printf("Reultado previo normalizado: %.2f\n", valor_columnaN3);
                tabla[i][j]=valor_columnaN3;
                j++;
            }
            
            token = strtok(NULL, ","); // Columna 4
            if (token != NULL) {
                float valor_columna4 = atof(token);
                printf("CGPA: %.2f\n", valor_columna4);
                float valor_columnaN4=((valor_columna4 - minCGPA)/(maxCGPA - minCGPA));
                printf("CGPA normalizado: %.2f\n", valor_columnaN4);
                tabla[i][j]=valor_columnaN4;
                j++;
            }
            
            token = strtok(NULL, ","); // Columna 5
            if (token != NULL) {
                int valor_columna5 = atoi(token);
                printf("Rendimiento académico: %d\n", valor_columna5);
                float valor_columnaN5=(((float)valor_columna5 - (float)minRend)/((float)maxRend - (float)minRend));
                printf("Rendimiento académico normalizado: %.2f\n", valor_columnaN5);
                tabla[i][j]=valor_columnaN5;
                j++;
            }
            
            token = strtok(NULL, ","); // Columna 6
            if (token != NULL) {
                
                printf("Becado: %s\n", token);
                if(strcmp(token,"Yes")==0){
					tabla[i][j]=1.0;
					j++;
				}else{
					tabla[i][j]=0.0;
					j++;
				}
            }
            
            token = strtok(NULL, ","); // Columna 7
            if (token != NULL) {
                int valor_columna7 = atoi(token);
                printf("Puntuación extracurricular: %d\n", valor_columna7);
                float valor_columnaN7=(((float)valor_columna7 - (float)minCurr)/((float)maxCurr - (float)minCurr));
                printf("Puntuación extracurricular normalizado: %.2f\n", valor_columnaN7);
                tabla[i][j]=valor_columnaN7;
                j++;
            }
            
            token = strtok(NULL, ","); // Columna 8
            if (token != NULL) {
                int valor_columna8 = atoi(token);
                printf("Habilidades de comunicación: %d\n", valor_columna8);
                float valor_columnaN8=(((float)valor_columna8 - (float)minCom)/((float)maxCom - (float)minCom));
                printf("Habilidades de comunicación normalizado: %.2f\n", valor_columnaN8); 
                tabla[i][j]=valor_columnaN8;
                j++;  
            }
            
            token = strtok(NULL, ","); // Columna 9
            if (token != NULL) {
                int valor_columna9 = atoi(token);
                printf("Proyectos completados: %d\n", valor_columna9);
                float valor_columnaN9=(((float)valor_columna9 - (float)minProy)/((float)maxProy - (float)minProy));
                printf("Proyectos completados normalizado: %.2f\n", valor_columnaN9);
                tabla[i][j]=valor_columnaN9;
                j++;   
            }
            
            token = strtok(NULL, ","); // Columna 10
            if (token != NULL) {
                
                printf("Trabajo conseguido: %s\n", token);
                if(strcmp(token,"Yes\n")==0){
					tabla[i][j]=1.0;
					j++;
				}else{
					tabla[i][j]=0.0;
					j++;
				}
            }
            i++;
            
        }
    }
    /*for(j=0;j<=10000;j++){
		for (i=0;i<=8;i++){
			printf("%.2f ",tabla[j][i]);
		}
		printf("\n");
	}*/
	
	float estudiante[9];
	/*estudiante[0]=0.56;
	estudiante[1]=0.72;
	estudiante[2]=0.32;
	estudiante[3]=0.26;
	estudiante[4]=0.00;
	estudiante[5]=0.86;
	estudiante[6]=0.46;
	estudiante[7]=0.80;*/
	
	
	
	
	for(int l=1;l<=9;l++){
		int contFAcep=0;
		int contFDen=0;
		for (int a=9000;a<10000;a++){
			for(int b=0;b<8;b++){
				estudiante[b]=tabla[a][b];
			}
		
		
		
		
			objeto array[l]; 
			
			for (i=0;i<l;i++){
				array[i].dist=30;//Inicializamos el array con valores mayores al máximo posible
								 //para que siempre sean menores y entren a la tabla
			}
			
			
			float dist;
			for(i=0;i<9000;i++){
				dist=0;
				for (j=0;j<=7;j++){
					dist= dist + fabs(tabla[i][j] - estudiante[j]);
				}
				if(dist < array[0].dist){ 
					array[0].dist=dist;
					array[0].result=tabla[i][8];
					for (int k=1;k<l;k++){
						if(array[k-1].dist<array[k].dist){
							objeto aux;
							aux.dist=array[k-1].dist;
							aux.result=array[k-1].result;
							
							array[k-1].dist=array[k].dist;
							array[k-1].result=array[k].result;
							
							array[k].dist=aux.dist;
							array[k].result=aux.result;
						}
					}
					
				}
				
			}
			int contSi=0;
			int contNo=0;
			
			for(i=0;i<l;i++){
				
				if (array[i].result==1){
					contSi++;
				}else{
					contNo++;
				}
			}
			
			if(contSi>contNo){
				if(tabla[a][8]==0){
					
					contFAcep++;
				}
				
				
			}else if(contSi<contNo){
				if(tabla[a][8]==1){
					
					contFDen++;
				}
				
				
			}else{
				if(array[l-1].result==1){
					
					if(tabla[a][8]==0){
					
						contFAcep++;
					}
				}else{
					
					if(tabla[a][8]==1){
					
						contFDen++;
					}
				}
			}
		}
		
		float fiab = ((1000.0 - ((float)contFAcep + (float)contFDen))/10.0);
		int graf=(fiab-70);
		printf("k=%d  ",l);
		printf("%.02f  ",fiab);
		for(i=0;i<graf;i++){
			
			printf("*");
		}printf("\n");
		
	}
    fclose(archivo);
    return 0;
    
    
}

