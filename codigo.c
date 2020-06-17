/**
 * Hecho por Emilly Sancho y Daniegl Bogarin
 * para TI2402 - Algoritmos y estructuras de datos
 * Profesora: Maria Jose Artavia.
 * IS 2020 - Proyecto 1 - 16/06/2020
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//--------------- DEFINICION DE ESTRUCTURAS

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

struct nodoSala
{	
	sala sala;
	nodoSala *siguiente;
};

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

//--------------- INSERCIONES

void insertarRecurso(listaRecursos *R, char recurso[15]){
	nodoRecurso *n, *aux;
	if(R->inicio == NULL){
		R->inicio = (nodoRecurso*)malloc(sizeof(nodoRecurso));
		strcpy(R->inicio->recurso, recurso);
		R->inicio->siguiente = NULL;
		return;

	}else{
		n = R->inicio;
		while(n!=NULL){
			aux = n;
			n = n->siguiente;
		}
	}

	aux->siguiente = (nodoRecurso*)malloc(sizeof(nodoRecurso));
	aux->siguiente->siguiente = NULL;
	strcpy(aux->siguiente->recurso, recurso);
	
}

void insertarSala(listaSalas *L, sala s){
	nodoSala *n, *aux;

	if(L->inicio == NULL){
		L->inicio = (nodoSala*)malloc(sizeof(nodoSala));
		L->inicio->sala = s;
		L->inicio->siguiente=NULL;
		return;

	}else{
		n = L->inicio;
		while(n!=NULL){
			if(strcmp(n->sala.id,s.id) == 0 ){
				printf("\nESTA SALA YA ESTA REGISTRADA\n");
				return;
			}else{
				aux = n;
				n = n->siguiente;
			}
		}
	aux->siguiente = (nodoSala*)malloc(sizeof(nodoSala));
	aux->siguiente->siguiente = NULL;
	aux->siguiente->sala = s;

	}
	
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

//--------------- IMPRESIONES

void mostrarRecursos(listaRecursos *R){
	printf("Recursos: ");
	for(nodoRecurso *i = R->inicio; i!=NULL; i = i->siguiente){
		printf("%s ", i->recurso);
	}
	printf("\n");
}

void mostrarSalas(listaSalas *S){
	printf("La lista de salas es:\n");
	for(nodoSala *i = S->inicio; i!=NULL; i = i->siguiente){
		printf("Id: %s, Ubicacion: %s, Capacidad: %i, Estado: %i, Calificacion: %i,", i->sala.id, i->sala.ubicacion, i->sala.capMaxima, i->sala.estado, i->sala.calificacion );
		mostrarRecursos(i->sala.recursos);
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

//--------------- CONSULTAS

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

//--------------- MAIN Y PRUEBAS

int main() {
	int accion;
	listaEstudiantes *L;
	listaRecursos *R;
	listaSalas *S;

	L = listaEstudiantesNueva();
	R = listaRecursosNueva();
	S = listaSalasNueva();

	estudiante tempEstudiante;
	sala tempSala;
	char tempRecurso[15];


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


	sala s1 = {"SAL-001", "Contiguo puerta 1", 11, R, 0,100};
	sala s2 = {"SAL-002", "Contiguo puerta 2", 12, R, 0,100};
	sala s3 = {"SAL-003", "Contiguo puerta 3", 13, R, 0,100};
	sala s4 = {"SAL-004", "Contiguo puerta 4", 14, R, 0,100};
	sala s5 = {"SAL-005", "Contiguo puerta 5", 15, R, 0,100};
	sala s6 = {"SAL-006", "Contiguo puerta 6", 16, R, 0,100};
	sala s7 = {"SAL-007", "Contiguo puerta 7", 17, R, 0,100};
	sala s8 = {"SAL-008", "Contiguo puerta 8", 18, R, 0,100};
	sala s9 = {"SAL-009", "Contiguo puerta 9", 19, R, 0,100};
	sala s10 = {"SAL-010", "Contiguo puerta 10", 20, R, 0,100};
	insertarSala(S,s1);
	insertarSala(S,s2);
	insertarSala(S,s3);
	insertarSala(S,s4);
	insertarSala(S,s5);
	insertarSala(S,s6);
	insertarSala(S,s7);
	insertarSala(S,s8);
	insertarSala(S,s9);
	insertarSala(S,s10);


	//------------------------------------


	while(free){
		printf("\n*** Menu principal: *** \n");
		printf("1\t Ingresar nuevo estudiante.\n");
		printf("2\t Consultar estudiante por carnet.\n");
		printf("3\t Mostrar lista de estudiantes.\n");
		printf("4\t Ingresar nueva sala de estudio.\n");
		printf("5\t Mostrar lista de salas.\n");
		printf("0\t Salir.\n");
		
		printf("Seleccione una accion a realizar: ");
		scanf("%i", &accion);

		if(accion == 0 || accion>5){
			break;
		}
		if(accion == 1){
			printf("\tInserte del NOMBRE del estudiante: ");
			fgets(tempEstudiante.nombre, 50, stdin);
			scanf("%[^\n]", tempEstudiante.nombre);
			
			printf("\tInserte del CARNET del estudiante: ");
			scanf("%i", &tempEstudiante.carnet);
			
			printf("\tInserte la CARRERA del estudiante: ");
			fgets(tempEstudiante.carrera, 50, stdin);
			scanf("%[^\n]", tempEstudiante.carrera);
			

			printf("\tInserte el EMAIL del estudiante: ");
			fgets(tempEstudiante.email, 50, stdin);
			scanf("%49s", tempEstudiante.email);
			
			printf("\tInserte el NUMERO DE TELEFONO del estudiante: ");
			scanf("%i", &tempEstudiante.telefono);
			
			tempEstudiante.calificacion =100;

			insertarEstudiante(L,tempEstudiante);			
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

		if(accion == 4){
			printf("\tInserte del ID de la sala: ");
			scanf("%s", tempSala.id);
			
			printf("\tInserte la UBICACION de la sala: ");
			fgets(tempSala.ubicacion, 50, stdin);
			scanf("%[^\n]", tempSala.ubicacion);
			
			printf("\tInserte la CAPACIDAD MAXIMA de la sala: ");
			scanf("%i", &tempSala.capMaxima);
			
			tempSala.estado = 0;
			tempSala.calificacion = 100;

			while(free){
				printf("\n \t1 \tAgregar recurso a la sala\n");
				printf("\t0 \tSalir\n");
				printf("\tSeleccione una accion a realizar: ");
				scanf("%i", &accion);

				if(accion == 1){
					printf("\n\tNombre del recurso: ");
					fgets(tempRecurso, 50, stdin);
					scanf("%[^\n]", tempRecurso);
					insertarRecurso(R, tempRecurso);
				}
				if(accion != 1){
					break;
				}
			}	

			tempSala.recursos = R;
			insertarSala(S,tempSala);	
		}

		if(accion == 5){
			mostrarSalas(S);
		}

	}


    return 0;
}