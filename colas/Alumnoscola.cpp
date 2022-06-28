#include<stdio.h>
#include<stdlib.h>
//Libreria para poder usar new y delete 
#include<string.h>
#include<iostream>
#include<iostream>
//Esta libreria es para la entrada y salida de un archivo
#include<fstream>
//Biblioteca de window

using namespace std;



//Imprimir el menu 
int menu(){
	int x;
	system("cls");
	    cout<<"1.Agregar datos del alumno"<<endl
	    <<"2.Buscar datos del alumno"<<endl
	    <<"3.Mostrar datos de los alumnos"<<endl
	    <<"4.Borrar datos de los alumnos"<<endl
	    <<"5.Cargar datos de los alumnos"<<endl
	    <<"6.Guardar datos de los alumnos"<<endl
	    <<"7.Salir del programa"<<endl
	    <<"Ingresar el numero de opcion que desea: ";
	    	cin>>x;
	        return x; 
}
//La funcion que tiene que hacer agregar
void agregar(ofstream &es){
	//"cls" funciona para que limpie la consola
	system("cls");
	string nombre;
	string grupo;
	string materias;
	string calificaciones;
	//Esta linea sirve para guardar los usuarios
	es.open("Registros.txt", ios::out | ios::app);
	cout<<"Nombre: ";
	cin>>nombre;
	cout<<"Grupo: ";
	cin>>grupo;
	cout<<"Materias: ";
	cin>>materias;
	cout<<"Calificaciones: ";
	cin>>calificaciones;
	es<<nombre<<" "<<grupo<<" "<<materias<<" "<<calificaciones<<"\n";
	es.close();
}
//Buscar en el registro
void buscar(ifstream &lec){
	system("cls");
	lec.open("Registros.txt", ios::in);
	bool encontrado = false;
	string nombre, grado, materias, calificaciones, nombreaux;
	cout<<"Digite el nombre que desea buscar: ";
	cin>>nombreaux;
	lec>>nombre;
	//Este while esta para la busqueda siempre y cuando "encontrado" este en un valor de false
	while(!lec.eof() && !encontrado){
		lec>>grado;
		lec>>materias;
		lec>>calificaciones;
		//este if es para comparar e imprimirlo en la pantalla 
		if(nombre == nombreaux){
			cout<<"Nombre: "<<nombre<<endl;
			cout<<"Grado: "<<grado<<endl;
			cout<<"Materias: "<<materias<<endl;
			cout<<"Calificaciones: "<<calificaciones<<endl;
			cout<<"-------------------"<<endl;
			//cuando nombre y nombreaux sean el mismo se mandara un true a "encontrado"
			encontrado = true;
		}
		lec>>nombre;
	}
	lec.close();
	
	//Si no existe el dato imprime este mensaje
	if(!encontrado)
		cout<<"Dato no encontrado"<<endl;
		system("pause");
}

//Ver los registros
void verRegistro(ifstream &lec){
	system("cls");
	string nombre;
	string grado;
	string materias;
	string calificaciones;
	//ESta linea es para entrar al archivo 
	lec.open("Registros.txt", ios::in);
	//Este es un apuntador para busqueda
	lec>>nombre;
	//Este while es para ejecutar el ciclo simpre y cuando no llegue al final del archivo
	while(!lec.eof()){
		//EStos son apuntadores para la busqueda
		lec>>grado;
		lec>>materias;
		lec>>calificaciones;
		cout<<"Nombre: "<<nombre<<endl;
		cout<<"Grado: "<<grado<<endl;
		cout<<"Materias: "<<materias<<endl;
		cout<<"Calificaciones: "<<calificaciones<<endl;
		cout<<"-------------------"<<endl;
		lec>>nombre;
	}
	lec.close();
	system("pause");
}

int main(){
	ofstream esc;
	ifstream lec;
	int op;
	do{
		//esta funcion es de windows
		system("cls");
		op = menu();
		switch(op){
			case 1:
				agregar(esc);
				break;
				
			case 2:
				buscar(lec);
				break;
				
			case 3:
				verRegistro(lec);
				break;
		}
	}while(op != 7);
	return 0;
}
