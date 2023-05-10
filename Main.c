#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 20
#define TAM 200

//DECLARACION FUNCIONES
void printBanner() { //Funcion para el banner
    printf("#########     ###     ########      ###    \n");
    printf("##     ##    ## ##       ##        ## ##   \n");
    printf("##          ##   ##      ##       ##   ##  \n");
    printf("##  ####   ##     ##     ##      ##     ## \n");
    printf("##    ##   #########     ##      ######### \n");
    printf("##    ##   ##     ##     ##      ##     ## \n");
    printf("########   ##     ##  ########   ##     ## \n");
}
// funcion media
// funcion mayor parametro
// funcion menor parametro
#define MAX_LENGTH 20

typedef struct { //USUARIOS
    char usuario[MAX_LENGTH];
    char clave[MAX_LENGTH];
} User;

void createUser(FILE *file) {
    User newUser;

    printf("\nNuevo usuario\n");
    printf("Nombre de usuario: ");
    scanf("%s", newUser.usuario);

    printf("Contrasena: ");
    scanf("%s", newUser.clave);

    fprintf(file, "%s %s\n", newUser.usuario, newUser.clave);

    printf("Usuario registrado con exito.\n");
}

int loginUser(FILE *file) {
    char usuario[MAX_LENGTH];
    char clave[MAX_LENGTH];

    printf("\nInicio de sesion\n");
    printf("Nombre de usuario: ");
    scanf("%s", usuario);

    printf("Contrasena: ");
    scanf("%s", clave);

    char fileUsername[MAX_LENGTH];
    char filePassword[MAX_LENGTH];

    rewind(file);

    while (fscanf(file, "%s %s", fileUsername, filePassword) != EOF) {
        if (strcmp(usuario, fileUsername) == 0 && strcmp(clave, filePassword) == 0) {
            printf("Inicio de sesion exitoso. ¡Bienvenido, %s!\n", usuario);
            return 1;
        }
    }

    printf("Nombre de usuario o contrasena incorrectos. Por favor, intenta de nuevo.\n");
    return 0;
}

struct TDistrito{
    char parametros[200];
    float ph;
    int conductividad;
    int turbidez;
    int coliformes;
};

void imprimirMes(struct TDistrito [], int, FILE* , FILE*);

int main(){
	char opcion1,opcion2,opcion3,opcion4;
	
	
	// DECLARACION DE ESTRUTURAS:
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
	struct TDistrito distrito[TAM];
	int opcion,i;
	
	printBanner();
	
	printf("\n \n");
	
    system("color 9f");
	
    FILE *file = fopen("Usuarios.txt", "a+");

    if (file == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }

    int option;

    while (1) {
        printf("\nMenu principal\n");
        printf("1. Crear usuario\n");
        printf("2. Iniciar sesion\n");
        printf("3. Salir\n");
        printf("-------------------------\n");
        printf("Selecciona una opcion: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                createUser(file);
                break;
            case 2:
                if (loginUser(file))
                    fclose(file);
                break;
            case 3:
                fclose(file);
                printf("Hasta pronto.\n");
                return 0;
            default:
                printf("Opcion invalida.\n");
                break;
        }
    }

	
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
	 
 
	  FILE*fichero;
	  fichero=fopen ("atocha.txt","r"); 

    

      FILE *fentrada, *fsalida;
      struct TDistrito mes[26] = {0};
      char nombrefichero[100];
      fclose(fentrada);
      fclose(fsalida);
   



void imprimirMes(struct TDistrito mes[], int dim, FILE *fsalida, FILE *fentrada) {
    int i;
    char titulo1[50], titulo2[50], titulo3[50], titulo4[50], titulo5[50];
    
    printf("\n\t\t\t----DOCUMENTO----\n\n");
    for (i = 0; i < 1; i++) {
        fscanf(fentrada, "%s%s%s%s%s", titulo1, titulo2, titulo3, titulo4, titulo5);
    }
    
	while (fscanf(fentrada, "%s%f%d%d%d", mes[i].parametros, &mes[i].ph, &mes[i].conductividad, &mes[i].turbidez, &mes[i].coliformes) != EOF) {
		i++;
	}
	
    for (i = 0; i < 1; i++) {
        printf("%s\t%s\t%s\t%s\t%s\n", titulo1,titulo2, titulo3, titulo4, titulo5);
    }
    
    for (i = 1; i < dim; i++) {
        printf("%s\t%.2f\t%d\t%d\t%d\n", mes[i].parametros, mes[i].ph, mes[i].conductividad, mes[i].turbidez, mes[i].coliformes);
    }
}
	 
	    if (fentrada == NULL) {
		printf("Error, no puede abrir el fichero.\n");
		return 0;
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

		switch (opcion){
		case '1':
			printf("Seleccione 'i' si desea imprimir los datos de ph  \n");
			printf("Seleccione 'r' para conocer más acerca del efecto ph en el agua\n");
			scanf("%c",&opcion1);
			switch(opcion1){
				do{
				
					case 'R':
					case 'r':
						system("cls");
						printf("El pH del agua nos indica su nivel de acidez o alcalinidad.\n");
						printf("Se trata por tanto de un indicador esencial, que nos permite determinar la idoneidad o no del agua empleada durante el riego..\n");
						printf(" Para medir el pH del agua se utiliza una escala del 0 al 14, en la que 7.0 es considerada como la medida neutra..\n");
						printf("J1 introduzca su nombre de usuario:\n");
						fflush(stdin);
						//Aqui va lo que falta
				
						system("cls");
					
						break;
			
					case 'I':
					case 'i':
						printf("El pH del agua nos indica su nivel de acidez o alcalinidad.\n");
						printf("Se trata por tanto de un indicador esencial, que nos permite determinar la idoneidad o no del agua empleada durante el riego..\n");
						
						
						
			}while('r'||'i');
		}
		case '2'://Ahorcado
			while(1){
			while(1){
		
			system("cls");

			printf("Seleccione 'i' si desea ver los datos de conductividad \n");
			printf("Seleccione 'r' si desea saber mas acerca de la conductividad del agua \n");
			scanf("%c",&opcion2);
			int als;

			switch(opcion2){
					case 'r':
					case 'R':
						system("cls");
						printf("La conductividad se define como la capacidad del agua para conducir una corriente eléctrica a través de los iones disueltos.\n");
						
						fflush(stdin);
						fflush(stdin);
						break;

					case 'I':
					case 'i':
						system("cls");
							
						printf("El pH del agua nos indica su nivel de acidez o alcalinidad.\n");
						printf("Se trata por tanto de un indicador esencial, que nos permite determinar la idoneidad o no del agua empleada durante el riego..\n");
			
						fflush(stdin);
				
		    
					

						system("cls");

					
			}}
			
		case '3':
			printf("Seleccione 'i' si desea imprimir los datos de ,turbidez,coliformes \n");
			printf("Seleccione 'r' para conocer más acerca del efecto la turbidez en el agua\n");
			scanf("%c",&opcion3);
			switch(opcion3){
				do{
				
					case 'R':
					case 'r':
						system("cls");
						printf("La turbidez es una medida del grado en el cual el agua pierde su transparencia debido a la presencia de partículas en suspensión.\n");
						printf("Cuantos más sólidos en suspensión haya en el agua, más sucia parecerá ésta y más alta será la turbidez.\n");
						printf("La turbidez es considerada una buena medida de la calidad del agua.\n");
		
						fflush(stdin);
						//Aqui va lo que falta
				
						system("cls");
					
						break;
			
					case 'I':
					case 'i':
						printf("El pH del agua nos indica su nivel de acidez o alcalinidad.\n");
						printf("Se trata por tanto de un indicador esencial, que nos permite determinar la idoneidad o no del agua empleada durante el riego..\n");
						
						
			}while('r'||'i');
		}
		
		case '4'://Snake
			printf("Seleccione 'i' si desea imprimir los datos de coliformes \n");
			printf("Seleccione 'r' para conocer más acerca de los coliformes en el agua\n");
			scanf("%c",&opcion4);
			switch(opcion4){
				do{
				
					case 'R':
					case 'r':
						system("cls");
						printf("Las bacterias coliformes se utilizan frecuentemente como indicador bacteriano de la calidad sanitaria de los alimentos y el agua.\n");
						printf("Se definen como bacterias gramnegativas, con forma de bastón, no formadoras de esporas, que pueden fermentar la lactosa con producción de ácido y gas cuando se las incuba a 35–37 °C.\n");
			
						fflush(stdin);
						//Aqui va lo que falta
				
						system("cls");
					
						break;
			
					case 'I':
					case 'i':
						
					printf("El pH del agua nos indica su nivel de acidez o alcalinidad.\n");
						printf("Se trata por tanto de un indicador esencial, que nos permite determinar la idoneidad o no del agua empleada durante el riego..\n");
						
			}while('r'||'i');
		}	

		
	   	case'5'://Abandonar juego
			printf("Hasta la proxima!!!!!!!!\n");
			return 0;
		default:
		    printf("la opcion es incorrecta:\n");
		    break;
			return 0;//salir del programa
	}
	
	i++;
	
	

}
return 0;
}
