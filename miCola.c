#include <stdio.h>
#include <stdlib.h>
#include <time.h>      
#include <string.h>

typedef struct nodoReserva nodoReserva;

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

void encolarReserva(colaReservas *C, nodoReserva *nuevo){
	C->tamano++;
	nodoReserva *aux, *atras;

	//caso 0 lista vacia
	if(C->delantero == NULL){
		C->delantero = nuevo;
		C->trasero = C->delantero;
		return;
	}
	
	C->trasero->siguiente = nuevo;
	C->trasero = C->trasero->siguiente;
}

int colaTamano(colaReservas *C){
	printf("El tamanos de la cola de Reservas es %i. \n", C->tamano);
	return C->tamano;

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

int main(void)
{
	char rec[]= "PANTALLA";

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
	n2 = nodoReservaNuevo(f1,h1,h2,5,"Pantalla", rand()%3);
	n3 = nodoReservaNuevo(f1,h1,h2,5,"Pantalla", rand()%3);
	n4 = nodoReservaNuevo(f1,h1,h2,5,"Pantalla", rand()%3);
	n5 = nodoReservaNuevo(f1,h1,h2,5,"Pantalla", rand()%3);

	C = colaReservasNueva();

	// printf("antes\n");
	//int tamano = colaTamano(C);
	encolarReserva(C, n1);
	encolarReserva(C, n2);
	encolarReserva(C, n3);
	encolarReserva(C, n4);
	encolarReserva(C, n5);
	//tamano = colaTamano(C);
	mostrarColaReserva(C);

	nodoReserva *nodo = desencolarReserva(C);
	nodoReserva *nodo2 = desencolarReserva(C);
	nodoReserva *nodo3 = desencolarReserva(C);
	nodoReserva *nodo4 = desencolarReserva(C);
	nodoReserva *nodo5 = desencolarReserva(C);
	//printf("El nodo de menor prioridad es: %i\n", nodo->prioridad);

	//mostrarColaReserva(C);
}	