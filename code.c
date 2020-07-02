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
typedef struct nodoSala nodoSala;
typedef struct nodoReserva nodoReserva;
typedef struct nodoRecurso nodoRecurso;
typedef struct nodoHorario nodoHorario;
typedef struct nodoIncidente nodoIncidente;

//------ESTUDIANTE
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

listaEstudiantes *listaEstudiantesNueva(){
	listaEstudiantes *L;
	L = (listaEstudiantes*) malloc(sizeof(listaEstudiantes));
	L->inicio = NULL;
	return L;
}

//------RECURSO
typedef struct nodoRecurso
{
	char recurso[50];
	nodoRecurso *siguiente;
}nodoRecurso;

typedef struct listaRecursos
{
	nodoRecurso *inicio;	
}listaRecursos;

listaRecursos *listaRecursosNueva(){
	listaRecursos *R;
	R = (listaRecursos*)malloc(sizeof(listaRecursos));
	R->inicio = NULL;
	return R;
}

//------HORARIO
typedef struct horario
{
	char dia;
	int horaApertura;
	int horaCierre;
}horario;

struct nodoHorario
{
	horario horario;
	nodoHorario *siguiente;
};

typedef struct listaHorarios
{
	nodoHorario *inicio;
}listaHorarios;

listaHorarios *listaHorariosNueva(){
	listaHorarios *H;
	H = (listaHorarios*)malloc(sizeof(listaHorarios));
	H->inicio = NULL;
	return H;
}		

//------SALA
typedef struct sala
{
	char id[10];
	char ubicacion[50];
	int capMaxima;
	listaRecursos *recursos;
	int estado; 
	int calificacion;
	int reservas;
	listaHorarios *horarios;
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

listaSalas *listaSalasNueva(){
	listaSalas *L;
	L = (listaSalas*)malloc(sizeof(listaSalas));
	L->inicio = NULL;
	return L;
}

//------RESERVA
typedef struct reserva
{
	int carnetEstudiante;
	char idSala[10];
	char asunto[50];
	int id;
	char diaLetra;
	int dia;
	int mes;
	int horaInicio;
	int horaFinal;
	int capacidadMinima;
	char recurso[50];
	int prioridad;
	int estado;
}reserva;

struct nodoReserva
{
	reserva reserva;
	nodoReserva *siguiente;
};

typedef struct listaReservas
{
	nodoReserva *inicio;
}listaReservas;

listaReservas *listaReservasNueva(){
	listaReservas *C;
	C = (listaReservas*)malloc(sizeof(listaReservas));
	C->inicio = NULL;
	return C;
}

//------INCIDENTE
typedef struct incidente
{
	char idSala[10];
	int idReserva;
	char descripcion[150];
	time_t fecha;
}incidente;

struct nodoIncidente
{
	incidente incidente;
	nodoIncidente *siguiente;
};

 typedef struct listaIncidentes
 {
 	nodoIncidente *inicio;
 }listaIncidentes;

listaIncidentes *listaIncidentesNueva(){
	listaIncidentes *L;
	L = (listaIncidentes*)malloc(sizeof(listaIncidentes));
	L->inicio = NULL;
	return L;
}
//--------------- INSERCIONES

void insertarIncidente(listaIncidentes *L, incidente i){
	nodoIncidente *n, *aux;
	if(L->inicio == NULL){
		L->inicio = (nodoIncidente*)malloc(sizeof(nodoIncidente));
		L->inicio->incidente = i;
		L->inicio->siguiente = NULL;
		return;
	}else{
		n = L->inicio;
		while(n != NULL){
			aux = n;
			n = n->siguiente;
		}
	}
	aux->siguiente = (nodoIncidente*)malloc(sizeof(nodoIncidente));
	aux->siguiente->incidente = i;
	aux->siguiente->siguiente = NULL;
}

void insertarReserva(listaReservas *L, reserva r){
	nodoReserva *n, *aux;
	if(L->inicio == NULL){
		L->inicio = (nodoReserva*) malloc(sizeof(nodoReserva));
		L->inicio->reserva = r;
		L->inicio->siguiente = NULL;
		return;
	}else{
		n = L->inicio;
		while(n!=NULL){
				aux = n;
				n = n->siguiente;
		}	

		aux->siguiente = (nodoReserva*)malloc(sizeof(nodoReserva));
		aux->siguiente->siguiente = NULL;
		aux->siguiente->reserva = r;
	}
}

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
void insertarHorario(listaHorarios *L, horario h){
	nodoHorario *n, *aux;
	if(L->inicio == NULL){
		L->inicio = (nodoHorario*) malloc(sizeof(nodoHorario));
		L->inicio->horario = h;
		L->inicio->siguiente = NULL;
		return;
	}else{
		n = L->inicio;
		while(n!=NULL){
			if(n->horario.dia == h.dia && n->horario.horaApertura && h.horaApertura && n->horario.horaCierre == h.horaCierre){
				printf("\n ESTE HORARIO YA HA SIDO ASIGNADO\n");
				return;
			}else{
				aux = n;
				n = n->siguiente;
			}
		}	

		aux->siguiente = (nodoHorario*)malloc(sizeof(nodoHorario));
		aux->siguiente->siguiente = NULL;
		aux->siguiente->horario = h;
	}	
}	



//--------------- IMPRESIONES
void mostrarIncidentes(listaIncidentes *L){
	printf("\nLista de incidentes reportados:\n");
	for(nodoIncidente *i = L->inicio; i!=NULL; i = i->siguiente){
		printf("En la sala: %s, durante la reserva: %i, %s, el dia: %s.\n",i->incidente.idSala, i->incidente.idReserva, i->incidente.descripcion, ctime(&i->incidente.fecha) );
	}
}

void mostrarHorarios(listaHorarios *L){
	printf("\nLos horarios de operacion disponibles son:\n");
	int index = 0;
	for(nodoHorario *i = L->inicio; i!=NULL; i=i->siguiente){
		printf("\t %i \t %c de %i a %i.\n",index+1,i->horario.dia, i->horario.horaApertura,i->horario.horaCierre );
		index++;
	}
	printf("\n");
}
void mostrarHorariosDeSala(listaHorarios *L){
	printf(" Horarios:");
	int index = 0;
	for(nodoHorario *i = L->inicio; i!=NULL; i=i->siguiente){
		printf(" %c de %i a %i.",i->horario.dia, i->horario.horaApertura,i->horario.horaCierre );
		index++;
	}
	printf("\n");
}

void mostrarRecursos(listaRecursos *R){
	printf(" Recursos: ");
	for(nodoRecurso *i = R->inicio; i!=NULL; i = i->siguiente){
		printf(" %s", i->recurso);
	}
	printf(",");
	
}

void mostrarSalas(listaSalas *S){
	printf("La lista de salas es:\n");
	for(nodoSala *i = S->inicio; i!=NULL; i = i->siguiente){
		printf("Id: %s, Ubicacion: %s, Capacidad: %i, Estado: %i, Calificacion: %i,", i->sala.id, i->sala.ubicacion, i->sala.capMaxima, i->sala.estado, i->sala.calificacion );
		mostrarRecursos(i->sala.recursos);
		mostrarHorariosDeSala(i->sala.horarios);
	}
}

void mostrarEstudiantes(listaEstudiantes *L){
	
	printf("\nLa lista de estudiantes es:\n");
	for (nodoEstudiante *i = L->inicio; i!=NULL; i = i->siguiente)
	{
		printf("Nombre: %s, carnet: %i, carrera: %s, email: %s, calificacion: %i, telefono: %i.\n", i->estudiante.nombre, i->estudiante.carnet, i->estudiante.carrera, i->estudiante.email, i->estudiante.calificacion, i->estudiante.telefono);

	}
	printf("\n");
}

void mostrarReservas(listaReservas *C){
	nodoReserva *aux = C->inicio;
	printf("\nLa lista de reservas es:\n");
	for(nodoReserva *i = C->inicio; i!=NULL ; i=i->siguiente){
		printf("ID: %i, Estudiante: %i, sala: %s, asunto: %s, participantes: %i, fecha: %i/%i, inicia: %i, finaliza: %i, recurso: %s, estado: %i. \n",i->reserva.id ,i->reserva.carnetEstudiante, i->reserva.idSala, i->reserva.asunto,i->reserva.capacidadMinima,i->reserva.dia, i->reserva.mes, i->reserva.horaInicio, i->reserva.horaFinal, i->reserva.recurso, i->reserva.estado );
	}
	
}



//--------------- CONSULTAS / BUSQUEDAS
void consultarEstudiante(listaEstudiantes *L, int c){
	nodoEstudiante *aux = L->inicio;
	while(aux != NULL){
		if(aux->estudiante.carnet == c){
			printf("\nNombre: %s, carnet: %i, carrera: %s, email: %s, calificacion: %i, telefono: %i.\n", aux->estudiante.nombre, aux->estudiante.carnet, aux->estudiante.carrera, aux->estudiante.email, aux->estudiante.calificacion, aux->estudiante.telefono);
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

int buscarRecurso(listaRecursos *R, char recurso[50]){
	nodoRecurso *aux = R->inicio;
	while(aux != NULL){
		if(strcmp(aux->recurso,recurso) == 0){
			return 0;
		}
		aux = aux->siguiente;
	}
	return 1;
}

int buscarHorario(listaHorarios *L, int hi, int hf, char dia){
	nodoHorario *aux = L->inicio;
	while(aux != NULL){
		if(aux->horario.horaApertura <= hi && aux->horario.horaCierre >= hf && aux->horario.dia == dia){
			return 0;
		}
		aux = aux->siguiente;
	}

	return 1;
}

void consultarSala(listaSalas *S, char id[10]){
	nodoSala *aux = buscarSala(S, id);
	if(aux != NULL){
		printf("Sala: %s, Ubicacion: %s, Capacidad: %i, Estado: %i, Calificacion: %i,", id, aux->sala.ubicacion, aux->sala.capMaxima, aux->sala.estado, aux->sala.calificacion );
		mostrarRecursos(aux->sala.recursos);
		mostrarHorariosDeSala(aux->sala.horarios);
	}
}

void consultarIncidentesPorSala(listaIncidentes *L, char idSala[10]){
	nodoIncidente *i = L->inicio;
	printf("Lista de incidentes de la sala:\n");
	while(i != NULL){
		if(strcmp(i->incidente.idSala, idSala) == 0){
			printf("Id de reserva: %i, indicente: %s, fecha: %s. \n", i->incidente.idReserva, i->incidente.descripcion, ctime(&i->incidente.fecha));
		}
		i = i->siguiente;
	}
}

void consultarReservasPorEstudiante(listaReservas *L, int carnet){
	nodoReserva *i = L->inicio;
	printf("Las reservas en %i son: ", carnet);
	while(i != NULL){
		if(i->reserva.carnetEstudiante == carnet){
			printf("Sala: %s, asunto: %s, participantes: %i, fecha: %i/%i, inicia: %i, finaliza: %i, recurso: %s, estado: %i. \n", i->reserva.idSala, i->reserva.asunto,i->reserva.capacidadMinima,i->reserva.dia, i->reserva.mes, i->reserva.horaInicio, i->reserva.horaFinal, i->reserva.recurso, i->reserva.estado );
		}
		i = i->siguiente;
	}
}

void consultarReservasPorSala(listaReservas *L, char idSala[10]){
	nodoReserva *i = L->inicio;
	printf("Las reservas en %s son: ", idSala);
	while(i != NULL){
		if(strcmp(i->reserva.idSala,idSala) == 0){
			printf("Estudiante: %i, asunto: %s, participantes: %i, fecha: %i/%i, inicia: %i, finaliza: %i, recurso: %s, estado: %i. \n", i->reserva.carnetEstudiante, i->reserva.asunto,i->reserva.capacidadMinima,i->reserva.dia, i->reserva.mes, i->reserva.horaInicio, i->reserva.horaFinal, i->reserva.recurso, i->reserva.estado );
		}
		i = i->siguiente;
	}
	printf("\n");
}


void consultarSalaParaReserva(listaSalas *S, char recurso[50], int capacidad, int hi, int hc, char diaLetra){
	printf("\nLas salas que cumplen recurso, capacidad y horario son:\n");
	nodoSala *aux = S->inicio;
	while(aux != NULL){
		if(buscarRecurso(aux->sala.recursos, recurso) == 0 && aux->sala.capMaxima >= capacidad){
			if(buscarHorario(aux->sala.horarios,hi,hc, diaLetra) == 0){
				consultarSala(S, aux->sala.id);	
			}
		}
		aux = aux->siguiente;
	}
	printf("\n");
}

int getCarnetDeReserva(listaReservas *L, int id){
	nodoReserva *aux = L->inicio;
	while(aux != NULL){	
		if(aux->reserva.id == id){
			return aux->reserva.carnetEstudiante;
		}
		aux = aux->siguiente;
	}
	return 0;
}

//--------------- MODIFICACIONES
void modificarSala(listaSalas *S, char id[10], int estado, char ubicacion[50]){
	nodoSala *aux = buscarSala(S, id);
	if(aux != NULL){
		aux->sala.estado = estado;
		strcpy(aux->sala.ubicacion, ubicacion);
	}
}

void aumentarCantidadDeReservasDeLaSala(listaSalas *S, char id[10]){
	nodoSala *aux = buscarSala(S, id);
	if(aux != NULL){
		aux->sala.reservas++;
	}
}

void disminuirCalificacionDeEstudiante(listaEstudiantes *L, int carnet){
	nodoEstudiante *aux = L->inicio;
	while(aux != NULL){
		if(aux->estudiante.carnet == carnet){
			aux->estudiante.calificacion--;
		}
		aux = aux->siguiente;
	}
}

//--------------- ELIMINACIONES / CANCELACIONES
void cancelarReserva(listaReservas *L, int id){
	nodoReserva*aux = L->inicio;
	while(aux != NULL){
		if(aux->reserva.id == id){
			aux->reserva.estado = 3;
		}
		aux = aux->siguiente;
	}
}

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



//--------------- MAIN Y PRUEBAS
int main() {
	//---NECESARIOS
	// time_t my_time = time(NULL); 
 //    printf("%s", ctime(&my_time)); 
	srand(time(NULL));
	int accion;
	int IdReservas = 5;
	
	listaEstudiantes *L;
	listaSalas *S;
	listaHorarios *H;
	listaReservas *V;
	listaIncidentes *I;
	
	L = listaEstudiantesNueva();
	S = listaSalasNueva();
	H = listaHorariosNueva();
	V = listaReservasNueva();
	I = listaIncidentesNueva();

	char tempRecurso[50]; 
	char tempUbicacion[50];
	char tempSalaID[10]; 
	char tempDescripcion[150];   
	char tempDia;
	int tempCarnet = 0;
	int tempReservaID = 0;
	int tempEstado = 0;
	estudiante tempEstudiante;
	sala tempSala;
	horario tempHorario;
	reserva tempReserva; 
	incidente tempIncidente;

			
	
	//---------------- ESTO ES QUE LO QUE TIENE QUE SER CARGADO DESDE EL TXT
	//ESTUDIANTES
	estudiante p1 = {20201,"Gloria Delgado-Prichett","Biotecnologia", "gloria@gmail.com",100,89490000};			
	estudiante p2 = {20202,"Jay Prichett","Administracion de empresas", "jay@gmail.com",100,89490001};		
	estudiante p3 = {20203,"Joe Prichett","Computacion", "joe@gmail.com",100,89490003};	
	estudiante p4 = {20204,"Manny Delgado","Turismo sostenible", "manny@gmail.com",100,89490004};
	estudiante p5 = {20205,"Cameron Tucker","Matematica en entornos TEC", "cameron@gmail.com",100,89490005};			
	estudiante p6 = {20206,"Mitchell Prichett","ATI", "mitchell@gmail.com",100,89490006};			
	estudiante p7 = {20207,"Lily Tucker-Prichett","Agricola", "lily@gmail.com",100,89490007};									
	estudiante p8 = {20208,"Claire Dunphy","Ambiental", "claire@gmail.com",100,89490008};			
	estudiante p9 = {20209,"Phill Dunphy","Electronica", "phil@gmail.com",100,89490009};			
	estudiante p10 = {202010,"Alex Dunphy","Agronegocios", "alex@gmail.com",100,89490010};			
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
	
	//RECURSOS
	listaRecursos *r1; r1 = listaRecursosNueva();
	listaRecursos *r2; r2 = listaRecursosNueva();
	listaRecursos *r3; r3 = listaRecursosNueva();
	listaRecursos *r4; r4 = listaRecursosNueva();
	listaRecursos *r5; r5 = listaRecursosNueva();
	listaRecursos *r6; r6 = listaRecursosNueva();
	listaRecursos *r7;  r7 = listaRecursosNueva();
	listaRecursos *r8;  r8 = listaRecursosNueva();
	listaRecursos *r9;  r9 = listaRecursosNueva();
	listaRecursos *r10;  r10 = listaRecursosNueva();
	insertarRecurso(r10,"Hojas blancas"); insertarRecurso(r10,"Lapiz");
	insertarRecurso(r1,"TV");
	insertarRecurso(r2,"Pizarra"); insertarRecurso(r2,"Borrador");
	insertarRecurso(r3,"Pizarra"); insertarRecurso(r3,"12 Tizas");
	insertarRecurso(r4,"5 sillas"); insertarRecurso(r4,"1 mesa");
	insertarRecurso(r5,"Pizarra"); insertarRecurso(r5,"3 Marcadores");
	insertarRecurso(r6,"Mesa"); insertarRecurso(r6,"Bancos");
	insertarRecurso(r7,"Pizarra"); insertarRecurso(r7,"2 puff");
	insertarRecurso(r8,"Proyector"); insertarRecurso(r8,"Fondo blanco");
	insertarRecurso(r9,"Pantalla"); insertarRecurso(r9,"Computadora");
	
	//HORARIOS 
	horario l = {'L',7,21};
	horario k = {'K',7,21};
	horario m = {'M',7,21};
	horario j = {'J',9,23};
	horario v = {'V',9,23};
	horario s = {'S',9,17};
	horario d = {'D',12,17};
	insertarHorario(H,l);
	insertarHorario(H,k);
	insertarHorario(H,m);
	insertarHorario(H,j);
	insertarHorario(H,v);
	insertarHorario(H,s);
	insertarHorario(H,d);

	listaHorarios *h1; h1 = listaHorariosNueva();
	listaHorarios *h2; h2 = listaHorariosNueva();
	listaHorarios *h3; h3 = listaHorariosNueva();
	listaHorarios *h4; h4 = listaHorariosNueva();
	listaHorarios *h5; h5 = listaHorariosNueva();
	listaHorarios *h6; h6 = listaHorariosNueva();
	listaHorarios *h7; h7 = listaHorariosNueva();
	listaHorarios *h8; h8 = listaHorariosNueva();
	listaHorarios *h9; h9 = listaHorariosNueva();
	listaHorarios *h10; h10 = listaHorariosNueva();
	insertarHorario(h1,l); insertarHorario(h1,k);
	insertarHorario(h2,k); insertarHorario(h2,m);
	insertarHorario(h3,m); insertarHorario(h3,j);
	insertarHorario(h4,j); insertarHorario(h4,v);
	insertarHorario(h5,v); insertarHorario(h5,s);
	insertarHorario(h6,s); insertarHorario(h6,d);
	insertarHorario(h7,d); insertarHorario(h7,k);
	insertarHorario(h8,l); insertarHorario(h8,j);
	insertarHorario(h9,m); insertarHorario(h9,s);
	insertarHorario(h10,v); insertarHorario(h10,d);
	
	
	//SALAS
	sala s1 = {"SAL-001", "Contiguo puerta 1", 5, r1, 0,100,0,h1};
	sala s2 = {"SAL-002", "Contiguo puerta 2", 6, r2, 0,100,0,h2};
	sala s3 = {"SAL-003", "Contiguo puerta 3", 7, r3, 0,100,0,h3};
	sala s4 = {"SAL-004", "Contiguo puerta 4", 8, r4, 0,100,0,h4};
	sala s5 = {"SAL-005", "Contiguo puerta 5", 9, r5, 0,100,0,h5};
	sala s6 = {"SAL-006", "Contiguo puerta 6", 10, r6, 0,100,0,h6};
	sala s7 = {"SAL-007", "Contiguo puerta 7", 11, r7, 0,100,0,h7};
	sala s8 = {"SAL-008", "Contiguo puerta 8", 12, r8, 0,100,0,h8};
	sala s9 = {"SAL-009", "Contiguo puerta 9", 13, r9, 0,100,0,h9};
	sala s10 = {"SAL-010", "Contiguo puerta 10", 14, r10, 0,100,0,h10};
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

	//RESERVAS
	reserva n1 = {20201,"SAL-001","Estudiar Calculo",1,'L', 1, 7, 10,11,5,"Pantalla",1,0};
	reserva n2 = {20202,"SAL-002","Estudiar Discreta",2,'K', 2, 7, 11,12,6,"Borrador", 2,0};
	reserva n3 = {20203,"SAL-003","Jugar Halo",3,'M', 3, 7, 12,13,7,"12 Tizas", 1,0};
	reserva n4 = {20204,"SAL-004","Programar",4, 'J',4, 7, 13,15,8,"2 puff", 3,0};
	reserva n5 = {20205,"SAL-005","Investigar",5,'V', 5, 7, 14,17,9,"Pizarra", 1,0};
	reserva n6 = {20206,"SAL-001","Estudiar Calculo",6,'L', 1, 7, 11,12,5,"Pantalla",1,0};
	reserva n7 = {20201,"SAL-002","Estudiar Calculo",7,'K', 2, 7, 12,13,5,"Pantalla",2,0};
	reserva n8 = {20201,"SAL-002","Estudiar Calculo",8,'M', 3, 7, 12,14,5,"Pantalla",3,0};
	reserva n9 = {20201,"SAL-004","Estudiar Calculo",9,'J', 4, 7, 11,13,5,"Pantalla",1,0};
	insertarReserva(V,n1);
	insertarReserva(V,n2);
	insertarReserva(V,n3);
	insertarReserva(V,n4);
	insertarReserva(V,n5);
	insertarReserva(V,n6);
	insertarReserva(V,n7);
	insertarReserva(V,n8);
	insertarReserva(V,n9);


	//---------------- FIN DE LO QUE TIENE QUE SER CARGADO DESDE EL TXT
	
	
	//********************** MENU PRINCIPAL****************************
	while(free){ //while free significa peligro !OJO!
		printf("\n*** Menu principal: *** \n");
		printf("1\t Agregar nuevo estudiante.\n");
		printf("2\t Consultar estudiante por carnet.\n");
		printf("3\t Mostrar lista de estudiantes.\n");
		printf("4\t Agregar nueva sala de estudio.\n");
		printf("5\t Mostrar lista de salas.\n");
		printf("6\t Modificar datos de una sala.\n");
		printf("7\t Calificar una sala.\n");
		printf("8\t Consultar sala.\n");
		printf("9\t Crear una reserva.\n");
		printf("10\t Consultar reservas por numero de carnet.\n");
		printf("11\t Mostrar lista de reservas.\n");
		printf("12\t Cancelar reserva.\n");
		printf("13\t Atender reserva.\n");
		printf("14\t Registrar incidente.\n");
		printf("15\t Consultar incidente por sala.\n");
		printf("16\t Mostrar lista de incidentes.\n");	
		printf("17\t Reportes.\n");
		printf("0\t Salir.\n");
		printf("Seleccione una accion a realizar: ");
		scanf("%i", &accion);
	
		if(accion == 0 || accion > 16){
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
			scanf("%i", &tempCarnet);
			consultarEstudiante(L,tempCarnet);
			consultarReservasPorEstudiante(V, tempCarnet);
		}

		if(accion == 3){
			mostrarEstudiantes(L);	
		}
		
		if(accion == 4){
			//tienen que estar aqui para que casa sala tenga su lista independiente
			listaRecursos *R;
			R = listaRecursosNueva();
			listaHorarios *H1;
			H1 = listaHorariosNueva();
			
			printf("\tInserte del ID de la sala: ");
			scanf("%s", tempSala.id);
			
			printf("\tInserte la UBICACION de la sala: ");
			fgets(tempSala.ubicacion, 50, stdin);
			scanf("%[^\n]", tempSala.ubicacion);
			
			printf("\tInserte la CAPACIDAD MAXIMA de la sala: ");
			scanf("%i", &tempSala.capMaxima);
			
			tempSala.estado = 0;
			tempSala.calificacion = 100;
			tempSala.reservas = 0;
			

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
			
			mostrarHorarios(H);

			while(free){
				printf("\n \t1 \tAgregar un horario a la sala\n");
				printf("\t0 \tSalir\n");
				printf("\tSeleccione una accion a realizar: ");
				scanf("%i", &accion);
				
				if(accion == 1){
						printf("\n\tIngrese el dia: ");
						scanf(" %c", &tempHorario.dia);
						printf("\tIngrese la hora de inicio: ");
						scanf("%i", &tempHorario.horaApertura);
						printf("\tIngrese la hora de finalizacion ");
						scanf("%i", &tempHorario.horaCierre);
						insertarHorario(H1,tempHorario);
				}
				if(accion != 1){
						break;
				}
			}
			tempSala.horarios = H1;
		}
		
		if(accion == 5){
			mostrarSalas(S);
		}
		
		if(accion == 6){
			printf("\tInserte el ID de la sala a modificar: ");
			scanf("%10s", tempSalaID);
			
			printf("\tInserte la nueva UBICACION de la sala: ");
			fgets(tempUbicacion, 50, stdin);
			scanf("%[^\n]", tempUbicacion);
			
			printf("\tInserte el nuevo ESTADO de la sala: ");
			scanf("%i", &tempEstado);
			
			modificarSala(S, tempSalaID, tempEstado, tempUbicacion );
			
			nodoSala *mySala = buscarSala(S, tempSalaID);
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
					fgets(tempRecurso, 50, stdin);
					scanf("%[^\n]", tempRecurso);
					eliminarRecurso(mySala->sala.recursos, tempRecurso);
				}
				if(accion == 2){
					printf("\n\tNombre del recurso a agregar: ");
					fgets(tempRecurso, 50, stdin);
					scanf("%[^\n]", tempRecurso);
					insertarRecurso(mySala->sala.recursos, tempRecurso);
				}
				if(accion == 0){
					break;
				}
			}	
		}
		
		if(accion == 7){//INCOMPLETO 
			int calificacion;
			printf("\tInserte el ID de la sala a calificar: ");
			scanf("%10s", tempSalaID);
			nodoSala *mySala = buscarSala(S, tempSalaID);
			printf("\tInserte la calificacion: ");
			scanf("%i",&calificacion);
			mySala->sala.calificacion = calificacion;
		}
		
		if(accion == 8){
			printf("\tInserte el ID de la sala a consultar: ");
			
			scanf("%10s", tempSalaID);
			consultarSala(S,tempSalaID);
			consultarReservasPorSala(V,tempSalaID);	
		}
		
		if(accion == 9){
			printf("\tInserte el CARNET de la persona que hace la reserva: ");
			scanf("%i",&tempReserva.carnetEstudiante);

			printf("\tInserte DIA de la reserva (ejemplo L,K,M,J,V,S,D): ");
			scanf(" %c",&tempReserva.diaLetra);

			printf("\tInserte DIA de la reserva (ejemplo 1,2,3,4...): ");
			scanf("%i",&tempReserva.dia);

			printf("\tInserte MES de la reserva: ");
			scanf("%i",&tempReserva.mes);

			printf("\tInserte HORA DE INICIO de la reserva: ");
			scanf("%i",&tempReserva.horaInicio);
			
			printf("\tInserte HORA FINALIZACION de la reserva: ");
			scanf("%i",&tempReserva.horaFinal);

			printf("\tInserte CAPACIDAD MINIMA REQUERIDA para la reserva: ");
			scanf("%i",&tempReserva.capacidadMinima);

			printf("\tInserte algun RECURSO REQUERIDO para la reserva: ");
			fgets(tempReserva.recurso, 50, stdin);
			scanf("%[^\n]",tempReserva.recurso);

			printf("\tInserte el MOTIVO de la reserva: ");
			fgets(tempReserva.asunto, 50, stdin);
			scanf("%[^\n]",tempReserva.asunto);

			tempReserva.prioridad = rand()%3;
			consultarSalaParaReserva(S, tempReserva.recurso, tempReserva.capacidadMinima, tempReserva.horaInicio, tempReserva.horaFinal, tempReserva.diaLetra);		
			printf("\tInserte el ID de la sala que desea reservar: ");
			scanf("%10s", tempReserva.idSala);

			insertarReserva(V,tempReserva);			
		}
		
		if(accion == 10){
			printf("\tInserte el CARNET del estudiante a consultar: ");
			scanf("%i",&tempCarnet);
			consultarReservasPorEstudiante(V, tempCarnet);
		}

		if(accion == 11){
			mostrarReservas(V);
		}

		if(accion == 12){
			printf("\tInserte el ID de la reserva a cancelar: ");
			scanf("%i",&tempReservaID);
			cancelarReserva(V,tempReservaID);
			tempCarnet = getCarnetDeReserva(V,tempReservaID);
			disminuirCalificacionDeEstudiante(L,tempCarnet);
		}

		if(accion == 14){
			printf("\tInsert el ID DE LA SALA donde se dio el incidente: ");
			fgets(tempIncidente.idSala, 10, stdin);
			scanf("%10s", tempIncidente.idSala);
			
			printf("\tInsert el ID DE LA RESERVA durante la cual se dio el incidente: ");
			scanf("%i", &tempIncidente.idReserva);
			
			printf("\tDescriba el incidente: ");
			fgets(tempIncidente.descripcion, 150, stdin);
			scanf("%[^\n]", tempIncidente.descripcion);
			
			tempIncidente.fecha = time(NULL);
			insertarIncidente(I, tempIncidente);	
		}

		if(accion == 15){
			printf("\tInsert el ID DE LA SALA a consultar: ");
			fgets(tempSalaID, 10, stdin);
			scanf("%10s", tempSalaID);
			consultarIncidentesPorSala(I,tempSalaID);
		}

		if(accion == 16){
			mostrarIncidentes(I);
		}

		
	}
	

	return 0;
}
