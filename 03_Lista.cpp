
/*

Es una estructura de datos que deriva de una secuencia 
conectada de nodos, y cada uno de los cuales contiene 
un dato 

Hay un nodo llamado la cabez o frente 
Hay un nodo de termino llamado la cola o atras

La lista solo ppuede ser recorrida en secuencia atras
o hacia adelante 

Operaciones de la estructura

Añadir o insertar elemento 
Eliminar o Borrar elemento
Moverme atraves de la lista desde el primero al ultimo
Buscar elementos
*elemento apuntador memoria (direccion de memoria/el peso) 
.elemento

list  es una clase templete que nos permite crear listas que contengan
cualquier tipo de objeto 

incluye las operaciones

push meter 

pop sacar

begin()
end()

size()

empty() vacio 


*/



#include<iostream>

using namespace std;
//definir la estrctura de la lista
struct Nodo{
	//los datos de la lista
	int valor;
	Nodo *siguiente;
	
};

//metodo para insertar
void insertarLista(Nodo *&, int);
	void mostrarlista(nodo *);
	
int main(){
	//declarar mi variable de la lista
	Nodo *lista = NULL;
	
	//variables
	int op = 1,c,i= 0,valores;
	
	cout<<"Trabajando con listas (simples, doblemente enlazadas, circulares y circulares dobles)"<<endl;
	while(op!=3){
		cout<<"Ejemplo de la lista simple"<<endl;
		cout<<"1.- Insertar nuevo valor de la lista"<<endl;
		cout<<"2.- Ver la lista"<<endl;
		cout<<"3.- Salir"<<endl;
		cin>>op;
		
		switch(op){
			case 1: 
			    cout<<"Indica el numero de valores a introducir\n";
			    cin>>valores;
			    while(i<valores){
			    	cout<<"Valor["<<i<<"]\n";
			    	cin>>c;
			    	//mando a llamar al metodo para insertarlo
			    	insertarLista(lista, c);
			    	i++;
				}
				break;
			case 2:
				cout<<"Ver elementos de la lista";
				cout<<"Pendiente";
				break;
			default:
				cout<<"Gracias por estar aqui uwu";
			
		}
		
	}
	return 0;
	
}

void insertarLista(Nodo *&lista, int c){
		Nodo*inslista = new Nodo();
		lista->valor = c;
		//necesito un auxiliar para encadenar los valores de la lista 
		Nodo *aux = lista;
		Nodo *aux2;
		
		//se meten ordenados los datos
		while((aux!=NULL)&&(aux->valor<c)){
			aux2=aux;
			aux = aux->siguiente;
		}
		
		if(inslista == aux){
			lista = inslista;
		}else{
			aux2->siguiente = inslista;
		}
		
		inslista->siguiente=aux;
		cout<<"Elemento: "<<c<<" insertado"<<endl;
	}
	
	
	void mostrarLista(nodo*lista){
		Nodo * recurso = new Nodo();
		recurso = lista;
		
		//imprimir los valores
		while(recurso!=NULL){
			cout<<recurso->valor<<endl;
			recurso=recurso->siguiente;
		}
	}
	

