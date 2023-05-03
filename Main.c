#include<stdio.h>

int main(){
	
	int opcion;
	
	printf("Bienvenido a GAIA, seleccione unos de los 4 barrios que tenemos disponibles para consultar sus datos\n");
	printf("Pulse 1 para Atocha\n");
	printf("Pulse 2 para Lavapies\n");
	printf("Pulse 3 para \n");
	printf("Pulse 4 para \n");
	printf("Pulse cualquier otro numero para salir\n");
	
	scanf("%d",&opcion);
	if (opcion==1){
		printf("Ha seleccionado Atocha\n");
		
	} else if (opcion==2){
		printf("Ha seleccionado Lavapies\n");
		
	} else if (opcion==3){
		printf("Has seleccionado\n");
	} else if (opcion==4){
		printf("Has seleccionado \n");
	} else
	printf("¡Hasta pronto!\n");

	
	
	
	return 0;
}
