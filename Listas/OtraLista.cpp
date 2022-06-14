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

int da;
int buscar(int d);
void insertar(int dat);
void mostrar(void);
void borrar(void);
void menu (void);
void guardar(void);
void cargar(void);

main(){
	menu();
}

//metodo del menu
void menu(void){
	//vamos a crear un menu de 6 opciones
	int opc, da;
	do{
		//imprimir el menu
		cout<<"Ejemplo para una lista completa que";
		cout<<"\n 1-.Buscar Dato ";
		cout<<"\n 2-.Insertar Datos";
	 	cout<<"\n 3-.Mostrar el Dato ";
	 	cout<<"\n 4-.Borrar Datos ";
	 	cout<<"\n 5-.Guardar Datos en Archivo";
		cout<<"\n 6-.Cargar Datos en Archivo";
		cout<<"\n 7-.Salir ";

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
				guardar();
				break;
			case 6:
				cargar();
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
			default:
				cout<<"Aprenda a leer ¬¬";
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
	cout<<endl<<endl;
	while(p){
		//como si existe la lista la recorremos
		cout<<cont++<<"\nValor = "<<p->i<<endl;
		p = p->s;
	}
	cout<<"\n Fin de la lista";
	getch();
}

int buscar(int d){
	if (!i){
		cout<<"No hay datos en la lista!!!";
		getch();
		return(0);
	}
	//cuando si hay datos
	p=i;
	a=NULL;
	//recorrer los valores de lista;
	while(p->s && p->i<d){
		a=p;
		p=p->s;
	}
	return(p->i==d?1:0);
}

//insertar
void insertar(int dat){
	//si esta vacio
	if(!i){
		//hay que crear un nuevo nodo
		//porque se ingresa por primera vez 
		i = new(dato);
		i->s = NULL;
		i->i = dat;
		return;
	}
	//Saber si existe o no el dato
	if(buscar(dat)){
		cout<<"\nEl dato existe llegale T_T";
		getch();
		return;
	}
	/*
	Imaginemos que existen varios valores
	
	nodo 1 = -2, nodo 2 = 0, nodo 3 = 4, nodo 
	
	insertar 4 
	
	*/
	
	//primero creamos el nodo 
	e = new(dato);
	
	e->i = dat;
	
	if(p==i && p->s){
		e->s=p;
		i=e;
		return;
	}
	if(p==i && !p->s){
		if(p->i < e->i){
			p->s = e;
			e->s = NULL;
		}else{
			//enmedio
			e->s=p;
			i=e;
		}
		return;
	}
	if(p->s){ e;
		a->s=e;
		e->s=p;
		return;
	}
	if(e->i > p->i){
		e->s = NULL;
		p->s = e;
	}else{
		a->s = e;
		e->s = p;
	}
}
 
void borrar(void){
	cout<<"\nIngrese dato que deseas eliminar: ";
	cin>>da;
	//debo de buscar el dato
	if(buscar(da)){
		if(a){
		
		a->s=p->s;
		}else{
		
		i=p->s;
		}
		delete(p);
		cout<<"\nDato eliminado\n";
	}
	else
		cout<<"\nDato no se encuentra solo juguito T_T";
		getch();
}
 
void guardar(void){
	FILE *arch;
	arch=fopen("DATOS-A.TXT","w");
	if(!i){
		cout<<"\n\nNo hay lista para guardar";
		getch();
		return;
	}
	p=i;
	while(p){
		fprintf(arch,"%i\n",p->i);
		p=p->s;
	}
	cout<<"\n\nArchivo Guardado";
	fclose(arch);
	getch();
}
 
void cargar(void){
	int c,x;
	FILE *arch;
	arch=fopen("DATOS-A.TXT","r");
	if(!arch){
		cout<<"\nNo existe";
		getch();
		return;
	}
	do{
		c=fscanf(arch,"%i\n",&x);
		if(c!=EOF){
			insertar(x);
		}
	}
	while (c!=EOF);
	cout<<"\nArchivo Cargado";
	fclose(arch);
	getch();
}
