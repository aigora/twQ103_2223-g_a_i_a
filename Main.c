#include <stdio.h>
#define TAM 200

//DECLARACIÓN FUNCIONES

// funcion media
// funcion mayor parametro
// funcion menor parametro


int main(){
	
	// DECLARACIÓN DE ESTRUTURAS:
	struct agua{
		char fuentesAgua[30];
		float ph;
		int conductividad;
		int turbidez;
		int coliformes;
	};
	
	struct inicioSesion{
		char nombre[10];
		char apellido[20];
		int codigoPostal;
		int numTelf;
	};
	
	struct agua fuentes[TAM];
	struct inicioSesion usuario[TAM];
	
	int opcion,i;
	
	
	printf("Bienvenido a GAIA\n");
	printf("Registrese antes de comenzar!\n");
	
	printf("\n");
	
	printf("Introduce su nombre\n");
	fflush(stdin);
	gets(usuario[i].nombre);
	printf("Introduzca su apellido\n");
	fflush(stdin);
	gets(usuario[i].apellido);
	printf("Introduce su codigo postal\n");
	scanf("%d",&usuario[i].codigoPostal);
	printf("Introduce su numero de telefono\n");
	scanf("%d",&usuario[i].numTelf);
	
	printf("\n");
	
	printf("Seleccione unos de los 4 barrios que tenemos disponibles para consultar sus datos\n");
	printf("Pulse [1] para Atocha\n");
	printf("Pulse [2] para Lavapies\n");
	printf("Pulse [3] para Malasana\n");
	printf("Pulse [4] para Embajadores\n");
	printf("Pulse cualquier otro numero para salir\n");
	
	scanf("%d",&opcion);
	
	
	
	if (opcion == 1){
	 printf("Ha seleccionado Atocha\n\n");
	 printf("A continuacion se abrira un fichero con los datos de este municipio\n");
	 printf("\n \n \n");
	 
		FILE *fichero;
	    fichero = fopen("atocha.txt", "r"); 
	
	    if (fichero == NULL) {
		printf("Error, no puede abrir el fichero.\n");
		return 0;
	    }	
	i = 0;
	while (fscanf(fichero,"%s %f %d %d %d", &fuentes[i].fuentesAgua, &fuentes[i].ph,&fuentes[i].conductividad,&fuentes[i].turbidez,&fuentes[i].coliformes) != EOF){
		printf("%s\t\t %.2f\t\t\t %d\t\t %d\t\t %d\n", &fuentes[i].fuentesAgua, fuentes[i].ph,fuentes[i].conductividad,fuentes[i].turbidez,fuentes[i].coliformes);
	}
	
	
	fclose(fichero);
		  
		  
	} else if (opcion == 2){
		printf("Ha seleccionado Lavapies\n");
		printf("A continuacion se abrira un fichero con los datos de este municipio\n");
		
	} else if (opcion == 3){
		printf("Has seleccionado Malasana\n");
		printf("A continuacion se abrira un fichero con los datos de este municipio\n");
	} else if (opcion ==4 ){
		printf("Has seleccionado Embajadores\n");
		printf("A continuacion se abrira un fichero con los datos de este municipio\n");
	} else
	printf("¡Hasta pronto!\n");

	
	
	
	return 0;
}
