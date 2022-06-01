/*

Vamos a crear un ejemplo de una lista que 
puede contener un dato y manejo de 
apuntadores

*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<iostream>

/*

Conio es una libreria que da una extension
a stdio, como libreria standar, para el 
manejo de consola usando comando como
getch(), clrscr (), gotoxy(), textcolor(),
y otras 

stdlib es una libreria standar para el manejo 
de funciones de busqueda, ordenamiento,
arboles, pilas, colas, listas nos sirve 
para las estructuras de datos
*/

using namespace std;
//definimos la lista acorde a 
//un nodo, el acceso, el dato, el apuntador y siguiente

struct dato{//lista
	int i;
	dato *s;//siguiente	
}*a, *i, *p, *e;//inicio,dato,la cola, lista

//meter los metodos de accesos a la lista

int buscar(int d);
void insertar(int dat);
void mostrar(void);
void borrar(void);
void menu (void);

//void guardar(void);
//void cargar(void);

int main(){
	menu(menu);
}

//metodo del menu
void menu(void){
	//vamos a crear un menu de 6 opciones
	int opc, da;
	do{
		//imprimir el menu
		cout<<"Ejemplo para una lista completa que "
		cout<<"\n 1-.Buscar Datos: ";
		cout<<"\n 2-.Insertar Datos: ";
		cout<<"\n 3-.Mostrar Dato: ";
		cout<<"\n 4-.Borrar Datos: ";
		cout<<"\n 5-.Guardar Datos en Archivo: ";
		cout<<"\n 6-.Cargar Datos en Archivo: ";
		cout<<"\n 7-.Salir: ";
		cout<<"\n Seleccione la opcion deseada: ";
		cin>>opc;
		//menu
		switch(opc){
			case 1:
				//buscar
				cout<<"\n\n Ingresa el dato a buscar";
				cin>>da;
				if(buscar(da)){
					cout<<"Dato si existe wii";
				}else{
					cout<<"Dato no existe, solo juguito";
					getch();
				}
				break;
			case 2:
				//insertar
				cout<<"Ingresa el dato ";
				cin>>da;
				insertar(da);
				break;
			case 3:
				//mostrar
				mostrar();
				break;
			case 4:
				//borrar
				borrar();
				break;
			case 5:
				//guardar();
				break;
			case 6:
				//cargar();
				break;
			case 7:
				cout<<"\n\n Ayos uwu :3";
				getch();
				//borrar todos los datos de la lista
				p=i;
				while(p){
					a=p;
					p=p->s;
					delete(a);//metodo de la lista
				}
				exit(0);//se cierra
			default;
				cout<<"Aprenda a leer ��";
				getch();
				
		}
	}while(opc);
}

//mostrar

void mostrar(void){
	int cont = 1; 
	if (!i){
		//no hay lista que mostrar
		cout<<"No hay lista que mostrar.";
		getch ();
		return;
	}
	//si hay datos
	p = i;
	cout<<"\n\n";
	while(p){
		//como si existe la lista la recorremos
		cout<<cont++<<"\nValor = "<<p->i<<endl;
		p = p->s;
	}
	cout<<"\n Fin de la lista";
	getch();
}