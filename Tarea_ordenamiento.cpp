
#include <iostream>
#include <conio.h>
#include <string.h>
#include <stdio.h>
#define MAX 50

struct ordenamiento{
	int elem;
};


using namespace std;
void menu();
void leerarray(int, struct ordenamiento[]);
void burbuja(int, struct ordenamiento[]);
void mostrar(int, struct ordenamiento[]);

void menu (){
	char opcion;
	
	cout<<endl<<"\t     Menú ordenamiento";
	cout<<endl<<"\t1. Burbuja";
	cout<<endl<<"\t2. Selección directa";
	cout<<endl<<"\t3. Seleccion de insercion";
	cout<<endl<<"\t4. Salir";
	cout<<endl<<"Opción:";
	
	cin>>opcion;
	switch (opcion){
		case '1':
		break;
		case '2':
			int vector[4] = {3, 2, 5, 8};
	
			int i, j, k, aux;
			//necesitamos recorrer el vector
			for(k = 0; k <=2; k++){
				i = k;
				aux = vector[k];
				for(j = k+1; j<=3; j++){
					if(vector[j] < aux){
						i = j;
						aux = vector[i];
					}
				}
				//intercambio
				vector[i] = vector[k];
				vector[k] = aux;
			}	
			break;
			case '3':
			break;
			
}



int main(){
	int n;
	struct ordenamiento orden[MAX];
	
	cout<<"Ingresa el limite del arreglo: \n";
	cin>>n;
	
	leerarray(n, orden);
	burbuja(n, orden);
	
	cout<<"\n El arreglo ordenado es: \n";
	
	mostrar(n, orden);
	
	getch();
}


void leerarray(int n, struct ordenamiento a[]){
	//ingresar los valores del arreglo
	for(int i = 0; i < n; i++){
		cout<<"Ingrese el elemento:\n";
		cin>>a[i].elem;
	}
}

void burbuja(int n, struct ordenamiento a[]){
	int i, j;
	//aqui guardo los datos ordenados
	struct ordenamiento temp;
	
	//aplico burbuja
	for(i = 1; i < n; i++){
		for(j = n-1; j>=i; j--){
			//realizo la comparacion
			if(a[j-1].elem > a[j].elem){
				//aqui hacemos el intercambio de posiciones
				temp = a[j-1];
				a[j-1] = a[j];
				a[j] = temp;
			}
		}
	}
	
}

void mostrar(int n, struct ordenamiento a[]){
	//imprimir elemento por elemento
	for(int i = 0; i < n; i++){
		cout<<" "<<a[i].elem;
	}
}


