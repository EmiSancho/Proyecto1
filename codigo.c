/**
 * Hecho por Emilly Sancho y Daniegl Bogarin
 * para TI2402 - Algoritmos y estructuras de datos
 * Profesora: Maria Jose Artavia.
 * IS 2020 - Proyecto 1 - 16/06/2020
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>     

//--------------- DEFINICION DE ESTRUCTURAS

typedef struct nodoEstudiante nodoEstudiante;
typedef struct nodoRecurso nodoRecurso;
typedef struct nodoSala nodoSala;
typedef struct nodoReserva nodoReserva;


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

typedef struct nodoRecurso
{
	char recurso[50];
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

typedef struct hora
{
	int hora;
	int minutos;
}hora;

typedef struct fecha
{
	int dia;
	int mes;
	int ano;
}fecha;

struct nodoReserva
{
	fecha fecha;
	hora horaInicio;
	hora horaFinal;
	int capacidadMinima;
	char recurso[50];
	int prioridad;
	nodoReserva *siguiente;
};

typedef struct colaReservas
{
	nodoReserva *delantero;
	nodoReserva *trasero;
	int tamano;
}colaReservas;

typedef struct horario
{
	char dia;
	int horaApertura;
	int horaCierre;
}horario;


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

colaReservas *colaReservasNueva(){
	colaReservas *C;
	C = (colaReservas*)malloc(sizeof(colaReservas));
	C->delantero = NULL;
	C->trasero = NULL;
	C->tamano = 0;
	return C;
}

nodoReserva* nodoReservaNuevo(fecha fecha, hora horaInicio, hora horaFinal, int capacidadMinima, char recurso[50], int prioridad){
	nodoReserva *nuevo;
	nuevo = (nodoReserva*)malloc(sizeof(nodoReserva));
	nuevo->siguiente = NULL;
	nuevo->fecha = fecha;
	nuevo->horaInicio = horaInicio;
	nuevo->horaFinal = horaFinal;
	nuevo->capacidadMinima = capacidadMinima;
	strcpy(nuevo->recurso, recurso);
	nuevo->prioridad = prioridad;
	return nuevo;
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

void encolarReserva(colaReservas *C, nodoReserva *nuevo){
	C->tamano++;
	nodoReserva *aux, *atras;

	if(C->delantero == NULL){
		C->delantero = nuevo;
		C->trasero = C->delantero;
		return;
	}
	
	C->trasero->siguiente = nuevo;
	C->trasero = C->trasero->siguiente;
}



//--------------- IMPRESIONES

void mostrarRecursos(listaRecursos *R){
	printf(" Recursos: ");
	for(nodoRecurso *i = R->inicio; i!=NULL; i = i->siguiente){
		printf(" %s", i->recurso);
	}
	printf(".");
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
	
	printf("\nLa listaEstudiantes de estudiantes es:\n");
	for (nodoEstudiante *i = L->inicio; i!=NULL; i = i->siguiente)
	{
		printf("Nombre: %s, carnet: %i, carrera: %s, email: %s, calificacion: %i, telefono: %i.\n", i->estudiante.nombre, i->estudiante.carnet, i->estudiante.carrera, i->estudiante.email, i->estudiante.calificacion, i->estudiante.telefono);

	}
	printf("\n");
}

void mostrarReservas(colaReservas *C){
	nodoReserva *aux = C->delantero;
	printf("Prioridades de la cola de Reservas: ");
	while(aux!=NULL){
		printf(" %i", aux->prioridad );
		aux = aux->siguiente;
	}
	printf(".\n");
}

int colaTamano(colaReservas *C){
	printf("El tamanos de la cola de Reservas es %i. \n", C->tamano);
	return C->tamano;
}

//--------------- CONSULTAS E IMPRESIONES 

void consultarEstudiante(listaEstudiantes *L, int c){
	nodoEstudiante *aux = L->inicio;
	while(aux != NULL){
		if(aux->estudiante.carnet == c){
			printf("Nombre: %s, carnet: %i, carrera: %s, email: %s, calificacion: %i, telefono: %i.\n", aux->estudiante.nombre, aux->estudiante.carnet, aux->estudiante.carrera, aux->estudiante.email, aux->estudiante.calificacion, aux->estudiante.telefono);
			return;
		}
		aux = aux->siguiente;
	}
	printf("\nEste estudiante no esta REGISTRADO\n");
}

nodoSala* buscarSala(listaSalas *S, char id[10]){
	nodoSala *aux = S->inicio;
	while(aux != NULL){
		if(strcmp(aux->sala.id, id) == 0){
			return aux;
		}
		aux = aux->siguiente;
	}
	printf("\nLa sala no esta registrada\n");
	return NULL;
}

void consultarSala(listaSalas *S, char id[10]){
	nodoSala *aux = buscarSala(S, id);
	if(aux != NULL){
		printf("Sala: %s, Ubicacion: %s, Capacidad: %i, Estado: %i, Calificacion: %i,", id, aux->sala.ubicacion, aux->sala.capMaxima, aux->sala.estado, aux->sala.calificacion );
		mostrarRecursos(aux->sala.recursos);
	}
}

void mostrarColaReserva(colaReservas *C){
	nodoReserva *aux = C->delantero;
	printf("Prioridades de la cola de Reservas: ");
	while(aux!=NULL){
		printf(" %i", aux->prioridad );
		aux = aux->siguiente;
	}
	printf(".\n");
}

void mostrarHorarios(horario horarios[]){
	printf("Los horarios de operacion son:\n");
	for(int i = 0; i<7; i++){
		printf("\t %c de %i a %i.\n",horarios[i].dia, horarios[i].horaApertura,horarios[i].horaCierre );
	}
}

//--------------- MODIFICACIONES

void modificarSala(listaSalas *S, char id[10], int estado, char ubicacion[50]){
	nodoSala *aux = buscarSala(S, id);
	if(aux != NULL){
		aux->sala.estado = estado;
		strcpy(aux->sala.ubicacion, ubicacion);
	}
}



//--------------- ELIMINACIONES

void eliminarRecurso(listaRecursos *R, char recurso[50]){
	nodoRecurso *aux = R->inicio, *anterior = NULL;

	if(R->inicio == NULL){
		printf("La lista de recursos esta vacia.\n");
	}else{
		if(strcmp(R->inicio->recurso,recurso) == 0){
			aux = R->inicio;
			R->inicio = R->inicio->siguiente;
		}else{
			while(aux != NULL){
				if(strcmp(aux->recurso,recurso) == 0){
					anterior->siguiente = aux->siguiente;
					break;
				}else{
					anterior = aux;
					aux = aux->siguiente;
				}
			}
		}
	}

	free(aux);
}

nodoReserva* desencolarReserva(colaReservas *C){
	C->tamano--;
	int min = C->delantero->prioridad;
	nodoReserva *aux = C->delantero, *anterior, *menor;
	menor = aux;

	if(C->delantero == NULL){
		printf("La cola de reservas esta vacia.\n");
	}else{
		
		aux = C->delantero;
		while(aux!=NULL){
			if(aux->prioridad < min){
				min = aux->prioridad;
				menor = aux;
			}
			aux = aux->siguiente;	
		}

		aux = C->delantero;
		if(C->delantero->prioridad == min){
			aux = C->delantero;
			C->delantero = C->delantero->siguiente;
		}else{
			while(aux!=NULL){
				if(aux->prioridad == min){
					anterior->siguiente = aux->siguiente;
					break;
				}else{
					anterior = aux;
					aux = aux->siguiente;
				}
			}
		}
		free(aux);
	}
	printf("Reserva con prioridad %i eliminada.\n", menor->prioridad );
	return menor;
}

//--------------- MAIN Y PRUEBAS

int main() {
	int accion;
	listaEstudiantes *L;
	
	listaSalas *S;

	L = listaEstudiantesNueva();
	
	S = listaSalasNueva();

	estudiante tempEstudiante;
	sala tempSala;
	
	horario l = {'L',7,21};
	horario k = {'K',7,21};
	horario m = {'M',7,21};
	horario j = {'J',9,23};
	horario v = {'V',9,23};
	horario s = {'S',9,17};
	horario d = {'D',12,17};
	horario horarios[7] = {l,k,m,j,v,s,d};
	mostrarHorarios(horarios);


	//------------------------------------
	estudiante p1 = {20201,"Gloria Delgado-Prichett","Estilismo", "gloria@gmail.com",100,89490000};			
	estudiante p2 = {20202,"Jay Prichett","Servicio al cliente", "jay@gmail.com",100,89490001};		
	estudiante p3 = {20203,"Joe Prichett","Ingenieria", "joe@gmail.com",100,89490003};	
	estudiante p4 = {20204,"Manny Delgado","Poesia", "manny@gmail.com",100,89490004};
	estudiante p5 = {20205,"Cameron Tucker","Educacion musical", "cameron@gmail.com",100,89490005};			
	estudiante p6 = {20206,"Mitchell Prichett","Derecho ambiental", "mitchell@gmail.com",100,89490006};			
	estudiante p7 = {20207,"Lily Tucker-Prichett","Medicina veterinaria", "lily@gmail.com",100,89490007};									
	estudiante p8 = {20208,"Claire Dunphy","Administracion de empresas", "claire@gmail.com",100,89490008};			
	estudiante p9 = {20209,"Phill Dunphy","Bienes raices", "phil@gmail.com",100,89490009};			
	estudiante p10 = {202010,"Alex Dunphy","Medicina y cirugia", "alex@gmail.com",100,89490010};			
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


	listaRecursos *r1; r1 = listaRecursosNueva();
	insertarRecurso(r1,"TV");
	listaRecursos *r2; r2 = listaRecursosNueva();
	insertarRecurso(r2,"Pizarra"); insertarRecurso(r2,"Borrador");
	listaRecursos *r3; r3 = listaRecursosNueva();
	insertarRecurso(r3,"Pizarra"); insertarRecurso(r3,"12 Tizas");
	listaRecursos *r4; r4 = listaRecursosNueva();
	insertarRecurso(r4,"5 sillas"); insertarRecurso(r4,"1 mesa");
	listaRecursos *r5; r5 = listaRecursosNueva();
	insertarRecurso(r5,"Pizarra"); insertarRecurso(r5,"3 Marcadores");
	listaRecursos *r6; r6 = listaRecursosNueva();
	insertarRecurso(r6,"Mesa"); insertarRecurso(r6,"Bancos");
	listaRecursos *r7;  r7 = listaRecursosNueva();
	insertarRecurso(r7,"Libros"); insertarRecurso(r7,"2 puff");
	listaRecursos *r8;  r8 = listaRecursosNueva();
	insertarRecurso(r8,"Proyector"); insertarRecurso(r8,"Fondo blanco");
	listaRecursos *r9;  r9 = listaRecursosNueva();
	insertarRecurso(r9,"Pantalla"); insertarRecurso(r9,"Computadora");
	listaRecursos *r10;  r10 = listaRecursosNueva();
	insertarRecurso(r10,"Hojas blancas"); insertarRecurso(r10,"Lapices");
	
	sala s1 = {"SAL-001", "Contiguo puerta 1", 11, r1, 0,100};
	sala s2 = {"SAL-002", "Contiguo puerta 2", 12, r2, 0,100};
	sala s3 = {"SAL-003", "Contiguo puerta 3", 13, r3, 0,100};
	sala s4 = {"SAL-004", "Contiguo puerta 4", 14, r4, 0,100};
	sala s5 = {"SAL-005", "Contiguo puerta 5", 15, r5, 0,100};
	sala s6 = {"SAL-006", "Contiguo puerta 6", 16, r6, 0,100};
	sala s7 = {"SAL-007", "Contiguo puerta 7", 17, r7, 0,100};
	sala s8 = {"SAL-008", "Contiguo puerta 8", 18, r8, 0,100};
	sala s9 = {"SAL-009", "Contiguo puerta 9", 19, r9, 0,100};
	sala s10 = {"SAL-010", "Contiguo puerta 10", 20, r10, 0,100};
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

	srand(time(NULL));
	colaReservas *C;
	nodoReserva *n1;
	nodoReserva *n2;
	nodoReserva *n3;
	nodoReserva *n4;
	nodoReserva *n5;


	fecha f1 = {01,02,2020};
	hora h1 = {12,45};
	hora h2 = {15,45};
	int prioridad = rand()%4;

	n1 = nodoReservaNuevo(f1,h1,h2,5,"Pantalla", rand()%3);
	n2 = nodoReservaNuevo(f1,h1,h2,5,"Borrador", rand()%3);
	n3 = nodoReservaNuevo(f1,h1,h2,5,"12 Tizas", rand()%3);
	n4 = nodoReservaNuevo(f1,h1,h2,5,"2 puff", rand()%3);
	n5 = nodoReservaNuevo(f1,h1,h2,5,"Pizarra", rand()%3);

	C = colaReservasNueva();

	encolarReserva(C, n1);
	encolarReserva(C, n2);
	encolarReserva(C, n3);
	encolarReserva(C, n4);
	encolarReserva(C, n5);
	//mostrarColaReserva(C);

	// nodoReserva *nodo = desencolarReserva(C);
	// nodoReserva *nodo2 = desencolarReserva(C);
	// nodoReserva *nodo3 = desencolarReserva(C);
	// nodoReserva *nodo4 = desencolarReserva(C);
	// nodoReserva *nodo5 = desencolarReserva(C);
	// printf("El nodo de menor prioridad es: %i\n", nodo->prioridad);

	//------------------------------------


	while(free){
		printf("\n*** Menu principal: *** \n");
		printf("1\t Ingresar nuevo estudiante.\n");
		printf("2\t Consultar estudiante por carnet.\n");
		printf("3\t Mostrar lista de estudiantes.\n");
		printf("4\t Ingresar nueva sala de estudio.\n");
		printf("5\t Mostrar lista de salas.\n");
		printf("6\t Modificar una sala.\n");
		printf("7\t Calificar una sala.\n");
		printf("8\t Consultar sala.\n");
		printf("9\t Crear una reserva.\n");
		printf("0\t Salir.\n");
		
		printf("Seleccione una accion a realizar: ");
		scanf("%i", &accion);

		if(accion == 0 || accion>10){
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
			printf("Inserte el numero de carnet a consultar: ");
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

			listaRecursos *R;
			R = listaRecursosNueva();
			char tempRecurso[50];

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

		if(accion == 6){
			char id[10];
			char ubicacion[50]; 
			int estado = 0;
			char recurso[50];

			printf("\tInserte el ID de la sala a modificar: ");
			scanf("%10s", id);
			
			printf("\tInserte la nueva UBICACION de la sala: ");
			fgets(ubicacion, 50, stdin);
			scanf("%[^\n]", ubicacion);
			
			printf("\tInserte el nuevo ESTADO de la sala: ");
			scanf("%i", &estado);
			
			modificarSala(S, id, estado, ubicacion );
			nodoSala *mySala = buscarSala(S, id);


			while(free){
				printf("\n");
				mostrarRecursos(mySala->sala.recursos);
				printf("\n \t1 \tEliminar recurso de la sala\n");
				printf("\t2 \tAgregar recurso a la sala\n");
				printf("\t0 \tSalir\n");
				printf("\tSeleccione una accion a realizar: ");

				scanf("%i", &accion);

				if(accion == 1){
					printf("\n\tNombre del recurso a eliminar: ");
					fgets(recurso, 50, stdin);
					scanf("%[^\n]", recurso);
					eliminarRecurso(mySala->sala.recursos, recurso);
				}
				if(accion == 2){
					printf("\n\tNombre del recurso a agregar: ");
					fgets(recurso, 50, stdin);
					scanf("%[^\n]", recurso);
					insertarRecurso(mySala->sala.recursos, recurso);
				}
				if(accion == 0){
					break;
				}
			}	
		}

		if(accion == 7){
			char id[10];
			int calificacion;
			printf("\tInserte el ID de la sala a calificar: ");
			scanf("%10s", id);
			nodoSala *mySala = buscarSala(S, id);
			printf("\tInserte la calificacion: ");
			scanf("%i",&calificacion);
			mySala->sala.calificacion = calificacion;
		}
		
		if(accion == 8){
			printf("\tInserte el ID de la sala a consultar: ");
			char id[10];
			scanf("%10s", id);
			consultarSala(S,id);	
		}



		if(accion == 9){
			printf("\tInserte DIA de la reserva: ");
			printf("\tInserte MES de la reserva: ");
			printf("\tInserte AÑO de la reserva: ");
			printf("\tInserte HORA DE INICIO de la reserva: ");
			printf("\tInserte HORA FINALIZACION de la reserva: ");
			printf("\tInserte CAPACIDAD REQUERIDA para la reserva: ");

			
		}


	}


    return 0;
}
