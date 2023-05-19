#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 20
#define TAM 200
#define MAX_USUARIO 20
#define MAX_CONTRASENA 20
#define MAX_LINE_LENGTH 100

//DECLARACI�N DE FUNCIONES:
void printBanner();
int inicioSesion(char *usuario, char *contrasena);


void printBanner() { //Funci�n para el banner
    printf("#########     ###     ########      ###    \n");
    printf("##     ##    ## ##       ##        ## ##   \n");
    printf("##          ##   ##      ##       ##   ##  \n");
    printf("##  ####   ##     ##     ##      ##     ## \n");
    printf("##    ##   #########     ##      ######### \n");
    printf("##    ##   ##     ##     ##      ##     ## \n");
    printf("########   ##     ##  ########   ##     ## \n");
}

int inicioSesion(char *usuario, char *contrasena) { // Funci�n para registrar un usuario o iniciar sesi�n
    FILE *file = fopen("usuarios.txt", "r");
    if (file == NULL) {
        printf("Error al abrir el archivo de usuarios.\n");
        return 0;
    }

    char line[MAX_USUARIO + MAX_CONTRASENA + 2];
    while (fgets(line, sizeof(line), file) != NULL) {
        line[strcspn(line, "\n")] = '\0';

        char storedUsername[MAX_USUARIO];
        char storedPassword[MAX_CONTRASENA];

        sscanf(line, "%s %s", storedUsername, storedPassword);

        if (strcmp(storedUsername, usuario) == 0 && strcmp(storedPassword, contrasena) == 0) {
            fclose(file);
            return 1; // Credenciales v�lidas
        }
    }
    fclose(file);
    return 0; // Credenciales inv�lidas
}

// DECLARACI�N DE ESTRUTURAS:
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
    struct TDistrito{
    char parametros[200];
    float ph;
    int conductividad;
    int turbidez;
    int coliformes;
    };

void imprimirMes(struct TDistrito [], int, FILE* , FILE*); // Mirar esto

int main(){
	// DECLARACI�N DE VARIABLES
	char opcion1,opcion2,opcion3,opcion4;
	char opciones1,opciones2,opciones3,opciones4;
	
	char filename[] = "atocha.txt";
	char filename1[] = "lavapies.txt";
	char filename2[] = "embajadores.txt";
	char filename3[] = "malasana.txt";
	
	char line[MAX_LINE_LENGTH];
	char line1[MAX_LINE_LENGTH];
	char line2[MAX_LINE_LENGTH];
	char line3[MAX_LINE_LENGTH];
	
	char usuario[MAX_USUARIO];
    char contrasena[MAX_CONTRASENA];
	
	struct agua fuentes[TAM];
	struct TDistrito distrito[TAM];
	
	int i,opcion,opciones;
	
	printBanner();
	
	printf("\n \n");
	
    system("color 9f");
    
	
	printf("=== Registro de Usuario ===\n");

    printf("Ingrese un nombre de usuario: ");
    scanf("%s", usuario);

    printf("Ingrese una contrasena: ");
    scanf("%s", contrasena);

    FILE *file = fopen("usuarios.txt", "w");
    if (file == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }

    fprintf(file, "%s %s\n", usuario, contrasena);
    printf("El nombre de usuario y la contrasena se han guardado en correctamente.\n");
    system("cls");

    fclose(file);


    printf("=== Menu de inicio de sesion ===\n");

    while (1) {
        printf("Usuario: ");
        scanf("%s", usuario);

        printf("Contrasena: ");
        scanf("%s", contrasena);

        if (authenticateUser(usuario, contrasena)) {
            printf("Inicio de sesion exitoso. ¡Bienvenido, %s!\n", usuario);
            break;
        } else {
            printf("Credenciales invalidas. Intentalo de nuevo.\n");
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
	 
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
     printf("Error al abrir el archivo.\n");
        return 1;
    }

    printf("Contenido del archivo '%s':\n", filename);

    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }

    fclose(file);
	  
		  
		  
	} else if (opcion == 2){
	printf("Ha seleccionado Lavapies\n");
	printf("A continuacion se abrira un fichero con los datos de este municipio\n");
	printf("\n \n \n");
	 
    FILE *file = fopen(filename1, "r");
    if (file == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }

    printf("Contenido del archivo '%s':\n", filename1);

    while (fgets(line1, sizeof(line1), file) != NULL) {
        printf("%s", line1);
    }

    fclose(file);
	
	
		
	} else if (opcion == 3){
	printf("Has seleccionado Malasana\n");
	printf("A continuacion se abrira un fichero con los datos de este municipio\n");
	printf("\n \n \n");
	 
    FILE *file = fopen(filename2, "r");
    if (file == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }

    printf("Contenido del archivo '%s':\n", filename2);

    while (fgets(line2, sizeof(line1), file) != NULL) {
        printf("%s", line2);
    }

    fclose(file);
    
    
    
	} else if (opcion ==4 ){
	printf("Has seleccionado Embajadores\n");
	printf("A continuacion se abrira un fichero con los datos de este municipio\n");
	printf("\n \n \n");
	 
    FILE *file = fopen(filename3, "r");
    if (file == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }

    printf("Contenido del archivo '%s':\n", filename3);

    while (fgets(line3, sizeof(line3), file) != NULL) {
        printf("%s", line3);
    }

    fclose(file);
    
    
    
	} else
	printf("¡Hasta pronto!\n");
    
	
	
	
	switch (opciones){
		case '1':
			printf("Seleccione 'i' si desea imprimir los datos de ph  \n");
			printf("Seleccione 'r' para conocer más acerca del efecto ph en el agua\n");
			scanf("%c",&opciones1);
			switch(opciones1){
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
			scanf("%c",&opciones2);
			int als;

			switch(opciones2){
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
			scanf("%c",&opciones3);
			switch(opciones3){
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
			scanf("%c",&opciones4);
			switch(opciones4){
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
