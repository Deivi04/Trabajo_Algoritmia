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
            
            // Obtiene y convierte los siguientes valores
            token = strtok(NULL, ","); // Columna 2
            if (token != NULL) {
                int valor_columna2 = atoi(token);
                float valor_columnaN2=(((float)valor_columna2 - (float)minIQ)/((float)maxIQ - (float)minIQ));
                tabla[i][j]=valor_columnaN2;
                j++;
                
            }
            
            token = strtok(NULL, ","); // Columna 3
            if (token != NULL) {
                float valor_columna3 = atof(token);
                float valor_columnaN3=((valor_columna3 - minTrim)/(maxTrim - minTrim));
                tabla[i][j]=valor_columnaN3;
                j++;
            }
            
            token = strtok(NULL, ","); // Columna 4
            if (token != NULL) {
                float valor_columna4 = atof(token);
                
                float valor_columnaN4=((valor_columna4 - minCGPA)/(maxCGPA - minCGPA));
               
                tabla[i][j]=valor_columnaN4;
                j++;
            }
            
            token = strtok(NULL, ","); // Columna 5
            if (token != NULL) {
                int valor_columna5 = atoi(token);
                float valor_columnaN5=(((float)valor_columna5 - (float)minRend)/((float)maxRend - (float)minRend));
                 tabla[i][j]=valor_columnaN5;
                j++;
            }
            
            token = strtok(NULL, ","); // Columna 6
            if (token != NULL) {
                
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
                float valor_columnaN7=(((float)valor_columna7 - (float)minCurr)/((float)maxCurr - (float)minCurr));
                tabla[i][j]=valor_columnaN7;
                j++;
            }
            
            token = strtok(NULL, ","); // Columna 8
            if (token != NULL) {
                int valor_columna8 = atoi(token);
                float valor_columnaN8=(((float)valor_columna8 - (float)minCom)/((float)maxCom - (float)minCom));
                tabla[i][j]=valor_columnaN8;
                j++;  
            }
            
            token = strtok(NULL, ","); // Columna 9
            if (token != NULL) {
                int valor_columna9 = atoi(token);
                float valor_columnaN9=(((float)valor_columna9 - (float)minProy)/((float)maxProy - (float)minProy));
                tabla[i][j]=valor_columnaN9;
                j++;   
            }
            
            token = strtok(NULL, ","); // Columna 10
            if (token != NULL) {
                
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
    int num;
	printf("Introduce con cuántos estudiantes comparar: ");
	scanf("%d",&num);
    
    objeto array[num]; 
    int indices[10000];
    int nelem=0;
    float estudiante[9];
    float dist;
    for(int e=0;e<9000;e++){
		
		for (i=0;i<num;i++){
			array[i].dist=30;//Inicializamos el array con valores mayores al máximo posible
							 //para que siempre sean menores y entren a la tabla
		}
		
		for(i=0;i<9000;i++){
			dist=0;
			for (j=0;j<=7;j++){
				dist= dist + fabs(tabla[i][j] - tabla[e][j]);
			}
			if(dist < array[0].dist && dist!= 0){ 
				array[0].dist=dist;
				array[0].result=tabla[i][8];
				for (int k=1;k<num;k++){
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
		for(i=0;i<num;i++){
			
			if (array[i].result==1){
				contSi++;
			}else{
				contNo++;
			}
		}
		
		if(contSi>contNo){
			if(tabla[e][8]==1.0){
				indices[nelem]=e;
				nelem++;
				
			}
			
			
		}else if(contSi<contNo){
			if(tabla[e][8]==0){
				indices[nelem]=e;
				nelem++;
			}
			
			
		}else{
			if( array[num-1].result==1){
				
				if(tabla[e][8]==1.0){
					indices[nelem]=e;
					nelem++;
				}
			}else{
				
				if(tabla[e][8]==0){
					indices[nelem]=e;
					nelem++;
				}
			}
		}
	}
	
	
	
	
	int contFAcep=0;
	int contFDen=0;
	
	for (int a=9000;a<10000;a++){
		for(int b=0;b<8;b++){
			estudiante[b]=tabla[a][b];
		}
	
	
		
		for (i=0;i<num;i++){
			array[i].dist=30;//Inicializamos el array con valores mayores al máximo posible
							 //para que siempre sean menores y entren a la tabla
		}
		
		
		int ind=0;
		for(i=0;i<nelem;i++){
			dist=0;
			ind=indices[i];
			
			for (j=0;j<=7;j++){
				dist= dist + fabs(tabla[ind][j] - estudiante[j]);
			}
			if(dist < array[0].dist){ 
				array[0].dist=dist;
				array[0].result=tabla[ind][8];
				for (int k=1;k<num;k++){
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
		
		for(i=0;i<num;i++){
			
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
			if( array[num-1].result==1){
				
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
	printf("Ha habido %d falsos aceptados\n",contFAcep);
	printf("Ha habido %d falsos denegados\n",contFDen);
	float fiab = 100*((1000.0 - ((float)contFAcep + (float)contFDen))/1000.0);
	printf("Tiene fiabilidad del %.02f %%\n",fiab);

    fclose(archivo);
    return 0;
    
    
}

