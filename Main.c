#include <stdio.h>

// funcion media
// funcion mayor parametro
// funcion menor parametro

int main(){
	
	int opcion;
	
	printf("Bienvenido a GAIA, seleccione unos de los 4 barrios que tenemos disponibles para consultar sus datos\n");
	printf("Pulse [1] para Atocha\n");
	printf("Pulse [2] para Lavapies\n");
	printf("Pulse [3] para \n");
	printf("Pulse [4] para \n");
	printf("Pulse cualquier otro numero para salir\n");
	
	scanf("%d",&opcion);
	
	if (opcion==1){
		printf("Ha seleccionado Atocha\n");
		 printf("A continuacion se abrira un fichero con los datos de este municipio\n");
		 FILE * fentrada;
		  fentrada = fopen("atocha.txt", "r");
		  if(fentrada == NULL){
		  printf("Error en la apertura del fichero\n");
		  return 0;
		  }
	} else if (opcion==2){
		printf("Ha seleccionado Lavapies\n");
		printf("A continuacion se abrira un fichero con los datos de este municipio\n");
		 FILE * fentrada;
		  fentrada = fopen("lavapies.txt", "r");
		  if(fentrada == NULL){
		  printf("Error en la apertura del fichero\n");
		  return 0;
		  }
	} else if (opcion==3){
		printf("Has seleccionado\n");
		printf("A continuacion se abrira un fichero con los datos de este municipio\n");
	} else if (opcion==4){
		printf("Has seleccionado \n");
		printf("A continuacion se abrira un fichero con los datos de este municipio\n");
	} else
	printf("¡Hasta pronto!\n");

	
	
	
	return 0;
}
