#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAX_LENGHT 20
#define MAX_FUENTES 25
#define TAM 200
#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20
#define MAX_LINE_LENGTH 100
#define NUM_DISTRITOS 4

//DECLARACION FUNCIONES
void printBanner() { //Funcion para el banner
    printf("#########     ###     ########      ###    \n");
    printf("##     ##    ## ##       ##        ## ##   \n");
    printf("##          ##   ##      ##       ##   ##  \n");
    printf("##  ####   ##     ##     ##      ##     ## \n");
    printf("##    ##   #########     ##      ######### \n");
    printf("##    ##   ##     ##     ##      ##     ## \n");
    printf("########   ##     ##  ########   ##     ## \n");
    system("pause");
}


struct TFuente{
	char nombre[MAX_LENGHT];
	float ph;
	int conductividad;
	int turbidez;
	int coliformes;
};

struct TDistrito{
	char nombre[MAX_LENGHT];
	char archivo[MAX_LENGHT];
	struct TFuente fuentes[MAX_FUENTES];
	char *campos[5];
	int numFuentes;
};

int authenticateUser(char *usuario, char *contrasena) {
    FILE *file = fopen("usuarios.txt", "r");
    if (file == NULL) {
        printf("Error al abrir el archivo de usuarios.\n");
        return 0;
    }

    char line[MAX_USERNAME_LENGTH + MAX_PASSWORD_LENGTH + 2];
    while (fgets(line, sizeof(line), file) != NULL) {
        line[strcspn(line, "\n")] = '\0'; // Eliminar el salto de linea

        char storedUsername[MAX_USERNAME_LENGTH];
        char storedPassword[MAX_PASSWORD_LENGTH];

        sscanf(line, "%s %s", storedUsername, storedPassword);

        if (strcmp(storedUsername, usuario) == 0 && strcmp(storedPassword, contrasena) == 0) {
            fclose(file);
            return 1; // Credenciales validas
        }
    }

    fclose(file);
    return 0; // Credenciales invalidas
}

int userRegister(char *usuario, char * contrasena) {
	system("cls");	
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
    system("pause");
    fclose(file);
}

void startingMenu(char * usuario, char * contrasena) {
	int inicio = 0;
    while (!inicio) {
    	system("cls");
    	printf("=== Menu de Inicio de Sesion ===\n");
        printf("Usuario: ");
        scanf("%s", usuario);

        printf("Contrasena: ");
        scanf("%s", contrasena);

        if (authenticateUser(usuario, contrasena)) {
            printf("Inicio de sesion exitoso. ï¿½Bienvenido, %s!\n", usuario);
            inicio = 1;
        } else {
            printf("Credenciales invalidas. Intentalo de nuevo.\n");
        } 
		system("pause");       
    }
}

int selectZone(char * nombreZonas[], char * archivoZonas[], struct TDistrito * zona) {
	int opcion;
	char line[MAX_LINE_LENGTH];
	
	system("cls");
	printf("Seleccione unos de los 4 barrios que tenemos disponibles para consultar sus datos\n");
	int j;
	for (j = 0; j < NUM_DISTRITOS; j++)	{
		printf("Pulse [%d] para %s\n", j+1, nombreZonas[j]);		
	}
	printf("Pulse [0] para salir\n");
	
	scanf("%d", &opcion);
	opcion--;
	if (opcion == -1)
		return opcion;
		
	printf("Ha seleccionado %s \n", nombreZonas[opcion]);
 	printf("A continuacion se abrira un fichero con los datos de este municipio\n");
 	printf("\n");
 
	FILE *file = fopen(archivoZonas[opcion], "r");
	if (file == NULL) {
    	printf("Error al abrir el archivo.\n");
    	return -1;
	}
	printf("Contenido del archivo '%s': \n", archivoZonas[opcion]);
	
	strcpy(zona->nombre, nombreZonas[opcion]);
	strcpy(zona->archivo, archivoZonas[opcion]);
	int i = 0;
	int final = 0;
	fgets(line, "\n", file);
	printf("%s \t %s \t %s \t %s \t %s\n", zona->campos[0], zona->campos[1], zona->campos[2], zona->campos[3], zona->campos[4]);	
	while (i < MAX_FUENTES && final != EOF) {		
		final = fscanf(file, "%s", zona->fuentes[i].nombre);
		final = fscanf(file, "%f", &zona->fuentes[i].ph);		
		final = fscanf(file, "%d", &zona->fuentes[i].conductividad);
		final = fscanf(file, "%d", &zona->fuentes[i].turbidez);
		final = fscanf(file, "%d", &zona->fuentes[i].coliformes);
		printf ("%s:\t %.2f \t\t %d \t\t %d \t\t %d\n", zona->fuentes[i].nombre, zona->fuentes[i].ph, zona->fuentes[i].conductividad, zona->fuentes[i].turbidez, zona->fuentes[i].coliformes);
		zona->numFuentes++;
		i++;
	}
	fclose(file);
	return opcion;
}


char selectDataFrom() {
	fflush(stdin);
	char opcion;
	printf("Seleccione una de las siguientes operaciones acerca de los datos:\n");
	printf("\t [i] : informacion acerca del parametro\n\t [x] : para realizar operacion \"media\"\n");
	printf("\t [M] : para realizar operacion \"maximo\"\n");
	printf("\t [m] : para realizar operacion \"minimo\"\n");
	printf("\t [s] : salir\n");
	printf("Operacion seleccionada: ");
	scanf("%c", &opcion);
	fflush(stdin);
	return opcion;
}

int selectParameter() {
	int parametro;
	printf("Seleccione uno de los parametros de las fuentes sobre el que realizar la operacion:\n");
	printf("\t [1] : pH\n");
	printf("\t [2] : conductividad\n");
	printf("\t [3] : turbidez\n");
	printf("\t [4] : coliformes\n");
	printf("Parametro seleccionado: ");
	scanf("%d", &parametro);
	return parametro;
}

void printInfo(int parametro) {	
	switch(parametro) {
		case 1:
			printf("El pH del agua nos indica su nivel de acidez o alcalinidad.\n");
			printf("Se trata por tanto de un indicador esencial, que nos permite determinar la idoneidad o no del agua empleada durante el riego..\n");
			printf(" Para medir el pH del agua se utiliza una escala del 0 al 14, en la que 7.0 es considerada como la medida neutra..\n");
			break;
		case 2:
			printf("La conductividad se define como la capacidad del agua para conducir una corriente electrica a traves de los iones disueltos.\n");
			break;
		case 3:
			printf("La turbidez es una medida del grado en el cual el agua pierde su transparencia debido a la presencia de particulas en suspension.\n");
			printf("Cuantos mas solidos en suspension haya en el agua, mas sucia parecera, y mas alta sera la turbidez.\n");
			printf("La turbidez es considerada una buena medida de la calidad del agua.\n");
			break;
		case 4:
			printf("Las bacterias coliformes se utilizan frecuentemente como indicador bacteriano de la calidad sanitaria de los alimentos y el agua.\n");
			printf("Se definen como bacterias gramnegativas, con forma de baston, no formadoras de esporas, que pueden fermentar la lactosa con produccion de acido y gas cuando se las incuba a 35-37ºC.\n");
			break;
	}
}

float max(float a, int b) {
	if (a > b)
		return a;
	else b;
}

float min(float a, int b) {
	if (a > b)
		return b;
	else
		return a;
}

float mediaDe(struct TDistrito * zona, int parametro) {
	float media = 0;
	int i = 0;
	switch(parametro) {
		case 1:
			for (i = 0; i < zona->numFuentes; i++)
				media += zona->fuentes[i].ph;
			break;
		case 2:
			for (i = 0; i < zona->numFuentes; i++)
				media += zona->fuentes[i].conductividad;
			break;
		case 3:
			for (i = 0; i < zona->numFuentes; i++)
				media += zona->fuentes[i].turbidez;
			break;
		case 4:
			for (i = 0; i < zona->numFuentes; i++)
				media += zona->fuentes[i].coliformes;
			break;
	}
	media /= zona->numFuentes;
	return media;
}

float maximoDe(struct TDistrito * zona, int parametro) {
	float maxVal = 0;
	int i = 0;
	switch(parametro) {
		case 1:
			for (i = 0; i < zona->numFuentes; i++)
				maxVal = max(maxVal, zona->fuentes[i].ph);
			break;
		case 2:
			for (i = 0; i < zona->numFuentes; i++)
				maxVal = max(maxVal, zona->fuentes[i].conductividad);
			break;
		case 3:
			for (i = 0; i < zona->numFuentes; i++)
				maxVal = max(maxVal, zona->fuentes[i].turbidez);
			break;
		case 4:
			for (i = 0; i < zona->numFuentes; i++)
				maxVal = max(maxVal, zona->fuentes[i].coliformes);
			break;
	}
	return maxVal;
}

float minimoDe(struct TDistrito * zona, int parametro) {
	float minVal = 10000000;
	int i = 0;
	switch(parametro) {
		case 1:
			for (i = 0; i < zona->numFuentes; i++)
				minVal = min(minVal, zona->fuentes[i].ph);
			break;
		case 2:
			for (i = 0; i < zona->numFuentes; i++)
				minVal = min(minVal, zona->fuentes[i].conductividad);
			break;
		case 3:
			for (i = 0; i < zona->numFuentes; i++)
				minVal = min(minVal, zona->fuentes[i].turbidez);
			break;
		case 4:
			for (i = 0; i < zona->numFuentes; i++)
				minVal = min(minVal, zona->fuentes[i].coliformes);
			break;
	}
	return minVal;
}

int main(){
	char usuario[MAX_USERNAME_LENGTH];
    char contrasena[MAX_PASSWORD_LENGTH];
    char * nombreZonas[] = {"Atocha", "Lavapies", "Embajadores", "Malasana"};
    char * archivoZonas[] = {"atocha.txt", "lavapies.txt", "embajadores.txt", "malasana.txt"};
    char * valoresCampos[] = {"Fuente de agua", "pH", "Conductividad", "Turbidez", "Coliformes"};
    	
	system("color 8f");
	printBanner();	
	printf("\n\n");
    userRegister(usuario, contrasena);
    startingMenu(usuario, contrasena);
    
    int final = 0;
    struct TDistrito zonaElegida;
	zonaElegida.numFuentes = 0;
    int i;
    for (i = 0; i < 5; i++)
    	zonaElegida.campos[i] = valoresCampos[i];
    
	while (!final) {
		if (selectZone(nombreZonas, archivoZonas, &zonaElegida) != -1) {
			char operacion = selectDataFrom();
			while (operacion != 's') {
				int parametro = selectParameter();
				float data;
	    		switch(operacion) {
	    			case 'i':
	    				printInfo(parametro);
	    				break;
	    			case 'x':
	    				data = mediaDe(&zonaElegida, parametro);
	    				printf("%.2f\n", data);
						break;
	    			case 'M':
	    				data = maximoDe(&zonaElegida, parametro);
	    				printf("%.2f\n", data);
						break;
	    			case 'm':
					    data = minimoDe(&zonaElegida, parametro);
					    printf("%.2f\n", data);
						break;
					default :
						printf("Opcion invalida\n");
				}
				
				operacion = selectDataFrom();
			}
		}
		else {
			final = 1;
		}	
	}    
	printf("!Hasta pronto!\n");
	system("pause");
				return 0;
}
