#include<iostream>

using namespace std;

//estructura
struct nodo{
	string color; 
	struct nodo *siguiente;
};

//estructura cola
struct cola{
	nodo *ultimo;
	nodo *primero;
};

//encolar
void encolar(struct cola &q, string c){
	//lo que hay adentro de la cola
	struct nodo *aux = new(struct nodo);
	
	aux ->color = c;
	aux ->siguiente = NULL;
	
	if(q.ultimo == NULL){
		q.ultimo = aux; //encolar el primer elemento
	}else{
		(q.primero)->siguiente = aux;
	}
	//el puntero siempre apunta al ultimo
	q.primero = aux;
}

//desencolar
string desencolar(struct cola &q){
	string col;
	struct nodo *aux;
	
	//aux apunte al inicio de la cola
	aux = q.ultimo;
	col = aux->color;
	q.ultimo = (q.ultimo)->siguiente;
	
	//dale delete a aux
	delete(aux);
	
	return col;
}

//mostrar colita
void muestracola(struct cola q){
	//nodo auxiliar
	struct nodo *aux;
	//siempre el nodo hasta delante
	aux = q.ultimo;
	//cola vacia
	while(aux!=NULL){
		cout<<aux->color<<" --> ";
		aux = aux->siguiente;
	}
}

//vaciar la cola, eliminar
void vaciarcola(struct cola &q){
	//auxiliar para eliminar cada elemento
	struct nodo *aux;
	//si esta vacia
	while(q.ultimo != NULL){
		aux = q.ultimo;
		q.ultimo = aux->siguiente;
		delete(aux);
	}
	q.ultimo = NULL;
	q.primero = NULL;
}

void menu(){
	cout<<"\n Colores\n";
	cout<<"\n 1. Encolar\n";
	cout<<"\n 2. Desencolar\n";
	cout<<"\n 3. Mostrar\n";
	cout<<"\n 4. Vaciar\n";
	cout<<"\n 5. Salir\n";
}

int main(){
	//primero declaramos la cola
	struct cola q;
	
	//defino la cola con sus apuntadores
	q.ultimo = NULL;
	q.primero = NULL;
	
	//datos
	string dato;
	int op;
	string x; //funcion de pop a la cola
	
	do{
		menu();
		cout<<"\n"; cin>>op;
		
		switch(op){
			case 1:
				cout<<"\n\n Ingresa color : ";
				cin>>dato;
				encolar(q,dato);
				cout<<"\n\n Color: "<<dato<<" encolado...\n";
			break;
			
			case 2:
				x = desencolar(q);
				cout<<"\n\n Color: "<<x<<" desencolado...\n";
			break;
			
			case 3:
				cout<<"\n\n Mostrar Cola: \n";
				//saber que no este null
				if(q.ultimo != NULL) muestracola(q);
				else cout<<"\n\t Cola Vacia...\n";
			break;
			
			case 4:
				vaciarcola(q);
				cout<<"\n\t Colita se Vacio...\n";
			break;
			
		}
	}while(op != 5);
	
	return 0;
}
