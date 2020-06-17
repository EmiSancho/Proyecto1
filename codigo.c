/**
 * Hecho por Emilly Sancho y Daniegl Bogarin
 * para TI2402 - Algoritmos y estructuras de datos
 * Profesora: Maria Jose Artavia.
 * IS 2020 - Proyecto 1 - 16/06/2020
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct nodoEstudiante nodoEstudiante;
typedef struct nodoRecurso nodoRecurso;
typedef struct nodoSala nodoSala;

typedef struct estudiante
{
	int carnet;
	char nombre[50];
	char carrera[50];
	char email[50];
	int calificacion;
	int telefono;
}estudiante;

struct nodoEstudiante
{
	estudiante estudiante;
	nodoEstudiante *siguiente;
};

typedef struct listaEstudiantes
{
	nodoEstudiante *inicio;
}listaEstudiantes;

typedef struct hora
{
	int dia;
	int mes;
	int ano;
	int hora;
	int minutos;	
}hora;

typedef struct nodoRecurso
{
	char recurso[15];
	nodoRecurso *siguiente;
}nodoRecurso;

typedef struct listaRecursos
{
	nodoRecurso *inicio;	
}listaRecursos;

typedef struct sala
{
	char id[10];
	char ubicacion[50];
	int capMaxima;
	listaRecursos *recursos;
	int estado; 
	int calificacion;
}sala;

typedef struct listaSalas
{
	nodoSala *inicio;	
}listaSalas;


listaRecursos *listaRecursosNueva(){
	listaRecursos *L;
	L = (listaRecursos*)malloc(sizeof(listaRecursos));
	L->inicio = NULL;
	return L;
}

listaEstudiantes *listaEstudiantesNueva(){
	listaEstudiantes *L;
	L = (listaEstudiantes*) malloc(sizeof(listaEstudiantes));
	L->inicio = NULL;
	return L;
}

listaSalas *listaSalasNueva(){
	listaSalas *L;
	L = (listaSalas*)malloc(sizeof(listaSalas));
	L->inicio = NULL;
	return L;
}

void insertaSala(listaSalas *L, sala s){
	nodoSala *n, *aux;
	if(L->inicio == NULL){
		L->inicio = (nodoSala*)mallo(sizeof(nodoSala));
		L->inicio->sala = s;
		L->inicio->siguiente=NULL;
		return;
	}else{
		n = L->inicio;
		while(n!=NULL){
			aux = n;
			n = n->siguiente;
		}
	}

	aux->siguiente = (nodoSala*)malloc(sizeof(nodoSala));
	aux->siguiente->siguiente = NULL;
	aux->siguiente->sala = s;
}

void insertarEstudiante(listaEstudiantes *L, estudiante e){
	nodoEstudiante *n, *aux;

	if(L->inicio == NULL){
		L->inicio = (nodoEstudiante*) malloc(sizeof(nodoEstudiante));
		L->inicio->estudiante = e;
		L->inicio->siguiente = NULL;
		return;
	}else{
		n = L->inicio;
		while(n!=NULL){
			if(n->estudiante.carnet == e.carnet){
				printf("\n ESTE ESTUDIANTE YA ESTA REGISTRADO\n");
				return;
			}else{
				aux = n;
				n = n->siguiente;
			}
		}	

		aux->siguiente = (nodoEstudiante*)malloc(sizeof(nodoEstudiante));
		aux->siguiente->siguiente = NULL;
		aux->siguiente->estudiante = e;
	}
}

void mostrarEstudiantes(listaEstudiantes *L){
	
	printf("La listaEstudiantes de estudiantes es:\n");
	for (nodoEstudiante *i = L->inicio; i!=NULL; i = i->siguiente)
	{
		printf("Nombre: %s, carnet: %i, carrera: %s, email: %s, calificacion: %i, telefono: %i.\n", i->estudiante.nombre, i->estudiante.carnet, i->estudiante.carrera, i->estudiante.email, i->estudiante.calificacion, i->estudiante.telefono);

	}
	printf("\n");
}

void consultarEstudiante(listaEstudiantes *L, int c){
	nodoEstudiante *aux = L->inicio;
	while(aux != NULL){
		if(aux->estudiante.carnet == c){
			printf("Nombre: %s, carnet: %i, carrera: %s, email: %s, calificacion: %i, telefono: %i.\n", aux->estudiante.nombre, aux->estudiante.carnet, aux->estudiante.carrera, aux->estudiante.email, aux->estudiante.calificacion, aux->estudiante.telefono);
			return;
		}
		aux = aux->siguiente;
	}
	printf("El estudiante no esta registrado\n");
}

int main() {
	int accion;
	listaEstudiantes *L;
	L = listaEstudiantesNueva();
	estudiante temp;

	//------------------------------------
	estudiante p1 = {20201,"Gloria Delgado-Prichett","Estilismo", "gloria@gmail.com",89490000,100};			
	estudiante p2 = {20202,"Jay Prichett","Servicio al cliente", "jay@gmail.com",89490001,100};		
	estudiante p3 = {20203,"Joe Prichett","Ingenieria", "joe@gmail.com",89490003,100};	
	estudiante p4 = {20204,"Manny Delgado","Poesia", "manny@gmail.com",89490004,100};
	estudiante p5 = {20205,"Cameron Tucker","Educacion musical", "cameron@gmail.com",89490005,100};			
	estudiante p6 = {20206,"Mitchell Prichett","Derecho ambiental", "mitchell@gmail.com",89490006,100};			
	estudiante p7 = {20207,"Lily Tucker-Prichett","Medicina veterinaria", "lily@gmail.com",89490007,100};									
	estudiante p8 = {20208,"Claire Dunphy","Administracion de empresas", "claire@gmail.com",89490008,100};			
	estudiante p9 = {20209,"Phill Dunphy","Bienes raices", "phil@gmail.com",89490009,100};			
	estudiante p10 = {202010,"Alex Dunphy","Medicina y cirugia", "alex@gmail.com",89490010,100};			
	insertarEstudiante(L,p1);
	insertarEstudiante(L,p2);
	insertarEstudiante(L,p3);
	insertarEstudiante(L,p4);
	insertarEstudiante(L,p5);
	insertarEstudiante(L,p6);
	insertarEstudiante(L,p7);
	insertarEstudiante(L,p8);
	insertarEstudiante(L,p9);
	insertarEstudiante(L,p10);
	//------------------------------------


	while(free){
		printf("\n*** Menu principal: *** \n");
		printf("1\t Ingresar nuevo estudiante.\n");
		printf("2\t Consultar estudiante por carnet.\n");
		printf("3\t Mostrar lista de estudiantes.\n");
		printf("0\t Salir.\n");
		
		printf("Seleccione una accion a realizar: ");
		scanf("%i", &accion);

		if(accion == 0 || accion>3){
			break;
		}
		if(accion == 1){
			printf("\tInserte del NOMBRE del estudiante: ");
			fgets(temp.nombre, 50, stdin);
			scanf("%[^\n]", temp.nombre);
			
			printf("\tInserte del CARNET del estudiante: ");
			scanf("%i", &temp.carnet);
			
			printf("\tInserte la CARRERA del estudiante: ");
			fgets(temp.carrera, 50, stdin);
			scanf("%[^\n]", temp.carrera);
			

			printf("\tInserte el EMAIL del estudiante: ");
			fgets(temp.email, 50, stdin);
			scanf("%49s", temp.email);
			
			printf("\tInserte el NUMERO DE TELEFONO del estudiante: ");
			scanf("%i", &temp.telefono);
			
			temp.calificacion =100;

			insertarEstudiante(L,temp);			
		}

		if(accion == 2){
			printf("Inserte el carnet a buscar: ");
			int carnet;
			scanf("%i", &carnet);
			consultarEstudiante(L,carnet);
		}

		if(accion == 3){
			mostrarEstudiantes(L);	
		}

	}


    return 0;
}