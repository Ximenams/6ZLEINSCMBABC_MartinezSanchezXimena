#include<wchar.h>
#include<locale.h>
#include<fstream>
#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include <string>
#include <cstdlib>
#include <time.h>
#include<windows.h>

#define USER "Admin"
#define PASS "123"
#define user "User"
#define pass "123"

using namespace std;

//estructura de la cola

struct ICO{
	char nombre[10];
	char app[10];
	char apm[10];
	char fechanac[10];
	char genero[10];
	float peso, altura, imc, muneca, brazo, antebrazo, muslo, pantorrilla, cintura, cadera, humero, biceps, triceps, subescapular, suprailiaco;
};

struct Nodo{
	ICO pacientes;
	Nodo *siguiente;
};



//metodos
void login();
void menuadmin();
void menuuser();
void menucita();
void menuexp();
void tiempo();
void agregarDatos(ICO &);
void insertarDatos(Nodo *&, Nodo *&, ICO);
void buscarDatos(Nodo *, ICO);
void modificarDato(Nodo *, ICO);
void eliminarDatos(Nodo *&, Nodo *&, ICO);
void consultar(ifstream &lec);
void buscar(ifstream &lec);
void agregar(ofstream &es);
void editarexp(ifstream &loec);
void borrarexp(ifstream &lec);
bool c_vacia(Nodo *);

int main(){
	
	setlocale(LC_ALL,"");
	
	system("color 0");
    
    login();
	
	return 0;
}

void login(){
	string usuario, password;
	int contador = 0;
	bool ingresa = false;
	bool ingresa1 = false;
	
	do{
		system("cls");
		cout<<"\n\t    INICIO DE SESION ";
		cout<<"\n\t      Iniciando ";
		cout<<"\n\t";
		cout<<"\n\t Usuario: ";
		getline(cin, usuario);
		cout<<"\t Contraseña: ";
		
		char caracter;
		caracter = getch();
		
		password = "";
		
		while (caracter != 13){
			password.push_back(caracter);
			cout<<"*";
			caracter = getch();
		}
		
		cout<<"\n\t|_________________________\n";
		
		if (usuario == USER && password == PASS){
			ingresa = true;
			system("cls");
		}else if(usuario == user && password == pass){
			ingresa1 = true;
			system("cls");
		}else{
			cout<<"\n\t El Usuario y/o Password son incorrectos\n"<<endl;
			contador++;
			system("pause");
		}
	}while ((ingresa == false && contador < 3) && (ingresa1 == false && contador < 3));
	
	if(ingresa != false){
		menuadmin();
	}else if(ingresa1 != false){
		menuuser();
	}else{
		system("cls");
		cout<<"\n\t Demasiados Intentos comuniquese con TI"<<endl;
	}
}

void  menuadmin(){
	ofstream esc;
	char opcion;
	
	cout<<endl<<"\t____________________________________";
	cout<<endl<<"\t|                                  |";
	cout<<endl<<"\t|      ***Menú Especialista***     |";
	cout<<endl<<"\t|__________________________________|";
	cout<<endl<<"\t|1. Citas                          |";
	cout<<endl<<"\t|__________________________________|";
	cout<<endl<<"\t|2. Expediente Clinico             |";
	cout<<endl<<"\t|__________________________________|";
	cout<<endl<<"\t|3. IMC                            |";
	cout<<endl<<"\t|__________________________________|";
	cout<<endl<<"\t|4. Salir                          |";
	cout<<endl<<"\t|__________________________________|";
	cout<<endl<<"Opción:";
	
	cin>>opcion;
	fflush(stdin);
		
	do{
		switch(opcion){
			case '1':
				system("cls");
				menucita();
			break;
			
			case '2':
				system("cls");
				agregar(esc);
				menuexp();
			break;
			
			case '3':
				
			break;
						
			case '4':
				system("cls");
				login();
			break;
			
			default:
				cout<<"\n\tOpción Invalida T-T\n";
				break;
		}
		cout<<"\n\tPresiona Cualquier Tecla\n";
	 	getch();
		system("cls");
	}while(opcion != '4');
}

//Agregar al registro
void agregar(ofstream &es){
	//"cls" funciona para que limpie la consola
	system("cls");
	string nombre;
	string ape;
	string apeMa;
	string edad;
	string gene;
	string esta;
	string peso;
	string ale;
	string enfe;
	string dis;
	string san;
	string dom;
	string numEx;
	string numIn;
	string numCel;
	string numAux;
	string numAux2;
	string correo;
	string folio;
	
	//String del historial familiar
	string nomb, ape2, apeMa2, edad2, paren, gene2, esta2, peso2, ale2, en, dis2, san2, dom2, numEx2, numIn2;
	string numCel2, numaux, numaux2, correo2;
	
	//string del historial familiar 2
	string nomb2, ape3, apeMa3, edad3, paren2, gene3, esta3, peso3, ale3, en2, dis3, san3, dom3, numEx3, numIn3;
	string numeCel, numeaux, numeaux2, correo3;
	
	//Esta linea sirve para guardar los usuarios
	es.open("Expediente.txt", ios::out | ios::app);
	cout<<"\t\t__________________________________"<<endl;
	cout<<"\t\t|<--------Nuevo Registro-------->|"<<endl;
	cout<<"\t\t|________________________________|"<<endl;
	cout<<"\t\t|Folio:                          |"<<endl;
    cout<<"\t\t|                                |"<<endl;
	cin>>folio;
	cout<<"\t\t|                                |"<<endl;
	cout<<"\t\t|Nombre:                         |"<<endl;
	cout<<"\t\t|                                |"<<endl;
	cin>>nombre;
	cout<<"\t\t|                                |"<<endl;
	cout<<"\t\t|Apellido paterno:               |"<<endl;
	cout<<"\t\t|                                |"<<endl;
	cin>>ape;
	cout<<"\t\t|                                |"<<endl;
	cout<<"\t\t|Apellido materno:               |"<<endl;
	cout<<"\t\t|                                |"<<endl;
	cin>>apeMa;
	cout<<"\t\t|                                |"<<endl;
	cout<<"\t\t|Fecha de nacimiento(dd/mm/aa):  |"<<endl;
	cout<<"\t\t|                                |"<<endl;
	cin>>edad;
	cout<<"\t\t|                                |"<<endl;
	cout<<"\t\t|Genero:                         |"<<endl;
	cout<<"\t\t|                                |"<<endl;
	cin>>gene;
	cout<<"\t\t|                                |"<<endl;
	cout<<"\t\t|Estatura:                       |"<<endl;
	cout<<"\t\t|                                |"<<endl;
	cin>>esta;
	cout<<"\t\t|                                |"<<endl;
	cout<<"\t\t|Peso:                           |"<<endl;
	cout<<"\t\t|                                |"<<endl;
	cin>>peso;
	cout<<"\t\t|                                |"<<endl;
	cout<<"\t\t|Alergias:                       |"<<endl;
	cout<<"\t\t|                                |"<<endl;
	cin>>ale;
	cout<<"\t\t|                                |"<<endl;
	cout<<"\t\t|Enfermedades cronicas:          |"<<endl;
	cout<<"\t\t|                                |"<<endl;
	cin>>enfe;
	cout<<"\t\t|                                |"<<endl;
	cout<<"\t\t|Discapacidad:                   |"<<endl;
	cout<<"\t\t|                                |"<<endl;
	cin>>dis;
	cout<<"\t\t|                                |"<<endl;
	cout<<"\t\t|Tipo de sangre:                 |"<<endl;
	cout<<"\t\t|                                |"<<endl;
	cin>>san;
	cout<<"\t\t|                                |"<<endl;
	cout<<"\t\t|Calle:                          |"<<endl;
	cout<<"\t\t|                                |"<<endl;
	cin>>dom;
	cout<<"\t\t|                                |"<<endl;
	cout<<"\t\t|Numero exterior:                |"<<endl;
	cout<<"\t\t|                                |"<<endl;
	cin>>numEx;
	cout<<"\t\t|                                |"<<endl;
	cout<<"\t\t|Numero interior:                |"<<endl;
	cout<<"\t\t|                                |"<<endl;
	cin>>numIn;
	cout<<"\t\t|                                |"<<endl;
	cout<<"\t\t|Numero celular:                 |"<<endl;
	cout<<"\t\t|                                |"<<endl;
	cin>>numCel;
	cout<<"\t\t|                                |"<<endl;
	cout<<"\t\t|Numero de contacto:             |"<<endl;
	cout<<"\t\t|                                |"<<endl;
	cin>>numAux; 
	cout<<"\t\t|                                |"<<endl;                               
	cout<<"\t\t|Numero de contacto 2:           |"<<endl;
	cout<<"\t\t|                                |"<<endl;
	cin>>numAux2;
	cout<<"\t\t|                                |"<<endl;
	cout<<"\t\t|Correo electronico:             |"<<endl;
	cout<<"\t\t|                                |"<<endl;
	cin>>correo;
	cout<<"\t\t|                                |"<<endl;
    cout<<"\t\t|                                |"<<endl;
    cout<<"\t\t|________________________________|"<<endl;
    cout<<"\t\t                                      "<<endl;
    cout<<"\t\t                                      "<<endl;
	cout<<"\t\t______________________________________"<<endl;
	cout<<"\t\t|                                    |"<<endl;
	cout<<"\t\t|<--------Historial familiar-------->|"<<endl;
	cout<<"\t\t|____________________________________|"<<endl;
	cout<<"\t\t|                                    |"<<endl;
	cout<<"\t\t|Nombre:                             |"<<endl;
	cout<<"\t\t|                                    |"<<endl;
	cin>>nomb;
	cout<<"\t\t|                                    |"<<endl;
	cout<<"\t\t||Apellido paterno:                  |"<<endl;
	cout<<"\t\t|                                    |"<<endl;
	cin>>ape2;
	cout<<"\t\t|                                    |"<<endl;
	cout<<"\t\t|Apellido materno:                   |"<<endl;
	cout<<"\t\t|                                    |"<<endl;
	cin>>apeMa2;
	cout<<"\t\t|                                    |"<<endl;
	cout<<"\t\t|Fecha de nacimiento(dd/mm/aa):      |"<<endl;
	cout<<"\t\t|                                    |"<<endl;
	cin>>edad2;
	cout<<"\t\t|                                    |"<<endl;
	cout<<"\t\t|Parentesco:                         |"<<endl;
	cout<<"\t\t|                                    |"<<endl;
	cin>>paren;
	cout<<"\t\t|                                    |"<<endl;
	cout<<"\t\t|Genero:                             |"<<endl;
	cout<<"\t\t|                                    |"<<endl;
	cin>>gene2;
	cout<<"\t\t|                                    |"<<endl;
	cout<<"\t\t|Estatura:                           |"<<endl;
	cout<<"\t\t|                                    |"<<endl;
	cin>>esta2;
	cout<<"\t\t|                                    |"<<endl;
	cout<<"\t\t|Peso:                               |"<<endl;
	cout<<"\t\t|                                    |"<<endl;
	cin>>peso2;
	cout<<"\t\t|                                    |"<<endl;
	cout<<"\t\t|Alergias:                           |"<<endl;
	cout<<"\t\t|                                    |"<<endl;
	cin>>ale2;
	cout<<"\t\t|                                    |"<<endl;
	cout<<"\t\t|Enfermedades cronicas:              |"<<endl;
	cout<<"\t\t|                                    |"<<endl;
	cin>>en;
	cout<<"\t\t|                                    |"<<endl;
	cout<<"\t\t|Discapacidad:                       |"<<endl;
	cout<<"\t\t|                                    |"<<endl;
	cin>>dis2;
	cout<<"\t\t|                                    |"<<endl;
	cout<<"\t\t|Tipo de sangre:                     |"<<endl;
	cout<<"\t\t|                                    |"<<endl;
	cin>>san2;
	cout<<"\t\t|                                    |"<<endl;
	cout<<"\t\t|Calle:                              |"<<endl;
	cout<<"\t\t|                                    |"<<endl;
	cin>>dom2;
	cout<<"\t\t|                                    |"<<endl;
	cout<<"\t\t|Numero exterior:                    |"<<endl;
	cout<<"\t\t|                                    |"<<endl;
	cin>>numEx2;
	cout<<"\t\t|                                    |"<<endl;
	cout<<"\t\t|Numero interior:                    |"<<endl;
	cout<<"\t\t|                                    |"<<endl;
	cin>>numIn2;
	cout<<"\t\t|                                    |"<<endl;
	cout<<"\t\t|Numero celular:                     |"<<endl;
	cout<<"\t\t|                                    |"<<endl;
	cin>>numCel2;
	cout<<"\t\t|                                    |"<<endl;
	cout<<"\t\t|Numero de contacto:                 |"<<endl;
	cout<<"\t\t|                                    |"<<endl;
	cin>>numaux;
	cout<<"\t\t|                                    |"<<endl;
	cout<<"\t\t|Numero de contacto 2:               |"<<endl;
	cout<<"\t\t|                                    |"<<endl;
	cin>>numaux2;
	cout<<"\t\t|                                    |"<<endl;
	cout<<"\t\t|Correo electronico:                 |"<<endl;
	cout<<"\t\t|                                    |"<<endl;
	cin>>correo2;
	cout<<"\t\t|____________________________________|"<<endl;
	cout<<"\t\t                                      "<<endl;
	cout<<"\t\t                                      "<<endl;
	cout<<"\t\t                                      "<<endl;
	cout<<"\t\t________________________________________"<<endl;
    cout<<"\t\t|                                      |"<<endl;
	cout<<"\t\t| <--------Historial familiar--------> |"<<endl;
	cout<<"\t\t|______________________________________|"<<endl;
	cout<<"\t\t|                                      |"<<endl;
	cout<<"\t\t|Nombre:                               |"<<endl;
	cout<<"\t\t|                                      |"<<endl;
	cin>>nomb2;
	cout<<"\t\t|                                      |"<<endl;
	cout<<"\t\t|Apellido paterno:                     |"<<endl;
	cout<<"\t\t|                                      |"<<endl;
	cin>>ape3;
	cout<<"\t\t|                                      |"<<endl;
	cout<<"\t\t|Apellido materno:                     |"<<endl;
	cout<<"\t\t|                                      |"<<endl;
	cin>>apeMa3;
	cout<<"\t\t|                                      |"<<endl;
	cout<<"\t\t|Fecha de nacimiento (dd/mm/aa):       |"<<endl;
	cout<<"\t\t|                                      |"<<endl;
	cin>>edad3;
	cout<<"\t\t|                                      |"<<endl;
	cout<<"\t\t|Parentesco:                           |"<<endl;
	cout<<"\t\t|                                      |"<<endl;
	cin>>paren2;
	cout<<"\t\t|                                      |"<<endl;
	cout<<"\t\t|Genero:                               |"<<endl;
	cout<<"\t\t|                                      |"<<endl;
	cin>>gene3;
	cout<<"\t\t|                                      |"<<endl;
	cout<<"\t\t|Estatura:                             |"<<endl;
	cout<<"\t\t|                                      |"<<endl;
	cin>>esta3;
	cout<<"\t\t|                                      |"<<endl;
	cout<<"\t\t|Peso:                                 |"<<endl;
	cout<<"\t\t|                                      |"<<endl;
	cin>>peso3;
	cout<<"\t\t|                                      |"<<endl;
	cout<<"\t\t|Alergias:                             |"<<endl;
	cout<<"\t\t|                                      |"<<endl;
	cin>>ale3;
	cout<<"\t\t|                                      |"<<endl;
	cout<<"\t\t|Enfermedades cronicas:                |"<<endl;
	cout<<"\t\t|                                      |"<<endl;
	cin>>en2;
	cout<<"\t\t|                                      |"<<endl;
	cout<<"\t\t|Discapacidad:                         |"<<endl;
	cout<<"\t\t|                                      |"<<endl;
	cin>>dis3;
	cout<<"\t\t|                                      |"<<endl;
	cout<<"\t\t|Tipo de sangre:                       |"<<endl;
	cout<<"\t\t|                                      |"<<endl;
	cin>>san3;
	cout<<"\t\t|                                      |"<<endl;
	cout<<"\t\t|Calle:                                |"<<endl;
	cout<<"\t\t|                                      |"<<endl;
	cin>>dom3;
	cout<<"\t\t|                                      |"<<endl;
	cout<<"\t\t|Numero exterior:                      |"<<endl;
	cout<<"\t\t|                                      |"<<endl;
	cin>>numEx3;
	cout<<"\t\t|                                      |"<<endl;
	cout<<"\t\t|Numero interior:                      |"<<endl;
	cout<<"\t\t|                                      |"<<endl;
	cin>>numIn3;
	cout<<"\t\t|                                      |"<<endl;
	cout<<"\t\t|Numero celular:                       |"<<endl;
	cout<<"\t\t|                                      |"<<endl;
	cin>>numeCel;
	cout<<"\t\t|                                      |"<<endl;
	cout<<"\t\t|Numero de contacto:                   |"<<endl;
	cout<<"\t\t|                                      |"<<endl;
	cin>>numeaux;
	cout<<"\t\t|                                      |"<<endl;
	cout<<"\t\t|Numero de contacto 2:                 |"<<endl;
	cout<<"\t\t|                                      |"<<endl;
	cin>>numeaux2;
	cout<<"\t\t|                                      |"<<endl;
	cout<<"\t\t|Corrreo electronico:                  |"<<endl;
	cout<<"\t\t|                                      |"<<endl;
	cin>>correo3;
	cout<<"\t\t|                                      |"<<endl;
	cout<<"\t\t|______________________________________|"<<endl;
	cout<<"------------------------------------------------------------------------";
	//escritura del paciente
	es<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<edad<<" "<<gene<<" "<<esta<<" "<<peso<<" "<<ale<<" "<<enfe<<" "<<dis<<" "<<san<<" "<<dom<<" "<<numEx<<" "<<numIn<<" "<<numCel<<" "<<numAux<<" "<<numAux2<<" "<<correo<<"\n";
	//escritura del historial familiar
	es<<nomb<<" "<<ape2<<" "<<apeMa2<<" "<<edad2<<" "<<paren<<" "<<gene2<<" "<<esta2<<" "<<peso2<<" "<<ale2<<" "<<en<<" "<<dis2<<" "<<san2<<" "<<dom2<<" "<<numEx2<<" "<<numIn2<<" "<<numCel2<<" "<<numaux<<" "<<numaux2<<" "<<correo2<<"\n";
	//escritura del historial familiar 2
	es<<nomb2<<" "<<ape3<<" "<<apeMa3<<" "<<edad3<<" "<<paren<<" "<<gene3<<" "<<esta3<<" "<<peso3<<" "<<ale3<<" "<<en2<<" "<<dis3<<" "<<san3<<" "<<dom3<<" "<<numEx3<<" "<<numIn3<<" "<<numeCel<<" "<<numeaux<<" "<<numeaux2<<" "<<correo3<<"\n";
	es.close();
}

void menucita(){
	
	char opcion;
	
	cout<<endl<<"\t____________________________________";
	cout<<endl<<"\t|                                  |";
	cout<<endl<<"\t|          ***Menú Cita***         |";
	cout<<endl<<"\t|__________________________________|";
	cout<<endl<<"\t|                                  |";
	cout<<endl<<"\t| 1. Consultar Cita                |";
	cout<<endl<<"\t|__________________________________|";
	cout<<endl<<"\t|                                  |";
	cout<<endl<<"\t| 2. Eliminar Cita                 |";
	cout<<endl<<"\t|__________________________________|";
	cout<<endl<<"\t|                                  |";
	cout<<endl<<"\t| 3. Editar Cita                   |";
	cout<<endl<<"\t|__________________________________|";
	cout<<endl<<"\t|                                  |";
	cout<<endl<<"\t| 4. Regresar                      |";
	cout<<endl<<"\t|__________________________________|";
	cout<<endl<<"Opción:";
	
	cin>>opcion;
	fflush(stdin);
	
	do{
		switch(opcion){
			case '1':
				
			break;
			
			case '2':
				
			break;
			
			case '3':
				
			break;
						
			case '4':
				system("cls");
				menuadmin();
			break;
			
			default:
				cout<<"\n\tOpción Invalida T-T\n";
				break;
		}
		cout<<"\n\tPresiona Cualquier Tecla\n";
	 	getch();
		system("cls");
	}while(opcion != '4');
}

void menuexp(){
	ifstream lec;
	char opcion;
	
	cout<<endl<<"\t____________________________________";
	cout<<endl<<"\t|                                  |";
	cout<<endl<<"\t|      ***Menú Expediente***       |";
	cout<<endl<<"\t|__________________________________|";
	cout<<endl<<"\t|                                  |";
	cout<<endl<<"\t| 1. Buscar Expediente Clinico     |";
	cout<<endl<<"\t|__________________________________|";
	cout<<endl<<"\t|                                  |";
	cout<<endl<<"\t| 2. Consultar Expedientes         |";
	cout<<endl<<"\t|__________________________________|";
	cout<<endl<<"\t|                                  |";
	cout<<endl<<"\t| 3. Regresar                      |";
	cout<<endl<<"\t|__________________________________|";
	cout<<endl<<"Opción:";
	
	cin>>opcion;
	fflush(stdin);
		
	do{
		switch(opcion){
			case '1':				
				system("cls");
				tiempo();
				buscar(lec);
				menucita();
			break;
			
			case '2':
				tiempo();
				consultar(lec);
			break;
						
			case '3':
				system("cls");
				menuadmin();
			break;
			
			default:
				cout<<"\n\tOpción Invalida T-T\n";
				break;
		}
		cout<<"\n\tPresiona Cualquier Tecla\n";
	 	getch();
		system("cls");
	}while(opcion != '4');
}

//Consultar expediante
void consultar(ifstream &lec){
	system("cls");
	lec.open("Expediente.txt", ios::in);
	bool encontrado = false;
	//strin de busqueda
	string folioaux;
	//string del user
	string folio, nombre, ape, apeMa, edad,  gene, esta, peso, ale, enfe, dis, san, dom, numEx, numIn, numCel, numAux, numAux2, correo;
	//string del historial familiar
	string nomb, ape2, apeMa2, edad2, paren, gene2, esta2, peso2, ale2, en, dis2, san2, dom2, numEx2, numIn2, numCel2, numaux, numaux2, correo2;
	//string del historial familiar 2
	string nomb2, ape3, apeMa3, edad3, paren2, gene3, esta3, peso3, ale3, en2, dis3, san3, dom3, numEx3, numIn3, numeCel, numeaux, numeaux2, correo3;
	cout<<"\t________________________________________"<<endl;
	cout<<"\t|                                      |"<<endl;
	cout<<"\t|<--------Consultar expedientes------->|"<<endl;
	cout<<"\t|______________________________________|"<<endl;
	cout<<"\tNumero de folio a consultar:            "<<endl;
	cout<<"\t                                        "<<endl;
	cin>>folioaux;
	lec>>folio;
	//Este while esta para la busqueda siempre y cuando "encontrado" este en un valor de false
	while(!lec.eof() && !encontrado){
		lec>>nombre;
		lec>>ape;
		lec>>apeMa;
		lec>>edad;
		lec>>gene;
		lec>>esta;
		lec>>peso;
		lec>>ale;
		lec>>enfe;
		lec>>dis;
		lec>>san;
		lec>>dom;
		lec>>numEx;
		lec>>numIn;
		lec>>numCel;
		lec>>numAux;
		lec>>numAux2;
		lec>>correo;
		//Lectura de los datos del historial familiar
		lec>>nomb;
		lec>>ape2;
		lec>>apeMa2;
		lec>>edad2;
		lec>>paren;
		lec>>gene2;
		lec>>esta2;
		lec>>peso2;
		lec>>ale2;
		lec>>en;
		lec>>dis2;
		lec>>san2;
		lec>>dom2;
		lec>>numEx2;
		lec>>numIn2;
		lec>>numCel2;
		lec>>numaux;
		lec>>numaux2;
		lec>>correo2;
		//Lectura de los datos del historial familiar 2
		lec>>nomb2;
		lec>>ape3;
		lec>>apeMa3;
		lec>>edad3;
		lec>>paren2;
		lec>>gene3;
		lec>>esta3;
		lec>>peso3;
		lec>>ale3;
		lec>>en2;
		lec>>dis3;
		lec>>san3;
		lec>>dom3;
		lec>>numEx3;
		lec>>numIn3;
		lec>>numeCel;
		lec>>numeaux;
		lec>>numeaux2;
		lec>>correo3;
		//este if es para comparar e imprimirlo en la pantalla 
		if(folio == folioaux){
			system("cls");
			cout<<"\t__________________________________________________________"<<endl;
			cout<<"\t|                                                        |"<<endl;
			cout<<"\t|<--------Expediente clinico de"<<" "<<nombre<<"-------->|"<<endl;
			cout<<"\t|________________________________________________________|"<<endl;
			cout<<"\t|                                                         "<<endl;
			cout<<"\t|Folio:"<<folio<<endl;
			cout<<"\t|Nombre:"<<nombre<<endl;
			cout<<"\t|Apellido paterno:"<<ape<<endl;
			cout<<"\t|Apellido materno:"<<apeMa<<endl;
			cout<<"\t|Fecha de nacimiento(dd/mm/aa):"<<edad<<endl;
			cout<<"\t|Genero:"<<gene<<endl;
			cout<<"\t|Estatura:"<<esta<<endl;
			cout<<"\t|Peso:"<<peso<<endl;
			cout<<"\t|Alergias:"<<ale<<endl;
			cout<<"\t|Enfermedades cronicas:"<<enfe<<endl;
			cout<<"\t|Discapacidades:"<<dis<<endl;
			cout<<"\t|Tipo de sangre:"<<san<<endl;
			cout<<"\t|Calle:"<<dom<<endl;
			cout<<"\t|Numero exterior:"<<numEx<<endl;
			cout<<"\t|Numero interior:"<<numIn<<endl;
			cout<<"\t|Numero de celular:"<<numCel<<endl;
			cout<<"\t|Numero de contacto:"<<numAux<<endl;
			cout<<"\t|Numero de contacto:"<<numAux2<<endl;
			cout<<"\t|Correo electronico:"<<correo<<endl;   
			cout<<"\t|________________________________________________________"<<endl;
			//Imprimir el historil familiar
			cout<<"\t                                                          "<<endl;
			cout<<"\t__________________________________________________________"<<endl;
			cout<<"\t|                                                        |"<<endl;
			cout<<"\t| <-------Histrial familiar de"<<" "<<nombre<<"--------> |"<<endl;
			cout<<"\t|________________________________________________________|"<<endl;
			cout<<"\t|                                                         "<<endl;
			cout<<"\t|Nombre: "<<nomb<<endl;
			cout<<"\t|Apellido paterno: "<<ape2<<endl;
			cout<<"\t|Apellido materno: "<<apeMa2<<endl;
			cout<<"\t|Fecha de nacimiento(dd/mm/aa): "<<edad2<<endl;
			cout<<"\t|Parentesco: "<<paren<<endl;
			cout<<"\t|Genero: "<<gene2<<endl;
			cout<<"\t|Estatura: "<<esta2<<endl;
			cout<<"\t|Peso: "<<peso2<<endl;
			cout<<"\t|Alergias: "<<ale2<<endl;
			cout<<"\t|Enfermedades cronicas: "<<en<<endl;
			cout<<"\t|Discapacidades: "<<dis2<<endl;
			cout<<"\t|Tipo de sangre: "<<san2<<endl;
			cout<<"\t|Calle: "<<dom2<<endl;
			cout<<"\t|Numero exterior: "<<numEx2<<endl;
			cout<<"\t|Numero interior: "<<numIn2<<endl;
			cout<<"\t|Numero de celular: "<<numCel2<<endl;
			cout<<"\t|Numero de contacto: "<<numaux<<endl;
			cout<<"\t|Numero de contacto: "<<numaux2<<endl;
			cout<<"\t|Correo electronico: "<<correo2<<endl;
			cout<<"\t                                                          "<<endl;
			cout<<"\t                                                          "<<endl;
			//Imprimir el segundo historial familiar

			cout<<"\tHistorial familiar de"<<" "<<nombre<<"-"<<endl;
			cout<<"\tNombre: "<<nomb2<<endl;
			cout<<"\tApellido paterno: "<<ape3<<endl;
			cout<<"\tApellido materno: "<<apeMa3<<endl;
			cout<<"\tFecha de nacimiento(dd/mm/aa): "<<edad3<<endl;
			cout<<"\tParentesco: "<<paren2<<endl;
			cout<<"\tGenero: "<<gene3<<endl;
			cout<<"\tEstatura: "<<esta3<<endl;
			cout<<"\tPeso: "<<peso3<<endl;
			cout<<"\tAlergias: "<<ale3<<endl;
			cout<<"\tEnfermedades cronicas: "<<en2<<endl;
			cout<<"\tDiscapacidades: "<<dis3<<endl;
			cout<<"\tTipo de sangre: "<<san3<<endl;
			cout<<"\tCalle: "<<dom3<<endl;
			cout<<"\tNumero exterior: "<<numEx3<<endl;
			cout<<"\tNumero interior: "<<numIn3<<endl;
			cout<<"\tNumero de celular: "<<numeCel<<endl;
			cout<<"\tNumero de contacto: "<<numeaux<<endl;
			cout<<"\tNumero de contacto: "<<numeaux2<<endl;
			cout<<"\tCorreo electronico: "<<correo3<<endl;
			//cuando nombre y nombreaux sean el mismo se mandara un true a "encontrado"
			encontrado = true;
		}
		lec>>folio;
	}
	lec.close();
	
	//Si no existe el dato imprime este mensaje
	if(!encontrado)
		cout<<"No existe :c"<<endl;
		system("pause");
}

//Buscar en el registro
void buscar(ifstream &lec){
	system("cls");
	lec.open("Expedientes.txt", ios::in);
	bool encontrado = false;
	string nombre, edad, gene, esta, peso, folio, folioaux;
	cout<<"Digite el folio: ";
	cin>>folioaux;
	lec>>folio;
	//Este while esta para la busqueda siempre y cuando "encontrado" este en un valor de false
	while(!lec.eof() && !encontrado){
		lec>>nombre;
		lec>>edad;
		lec>>gene;
		lec>>esta;
		lec>>peso;
		//este if es para comparar e imprimirlo en la pantalla 
		if(folio == folioaux){
			system("cls");
			cout<<"\t-Registro de"<<" "<<nombre<<"-"<<endl;
			cout<<"Numero de folio: "<<folio<<endl;
			cout<<"Nombre: "<<nombre<<endl;
			cout<<"Edad: "<<edad<<endl;
			cout<<"Genero: "<<gene<<endl;
			cout<<"Estatura: "<<esta<<endl;
			cout<<"Peso: "<<peso<<endl;
			cout<<"-------------------"<<endl;
			//cuando nombre y nombreaux sean el mismo se mandara un true a "encontrado"
			encontrado = true;
		}
		lec>>folio;
	}
	lec.close();
	
	//Si no existe el dato imprime este mensaje
	if(!encontrado)
		cout<<"Dato no encontrado"<<endl;
		system("pause");
}

//Agregar cita
void agregarcita(ofstream &es){
	//limpiamos la consola
	system("cls");
	//string de los datos basicos
	string folio, nombre, ape, apeMa, fecha, gene, esta, peso;
	//string de los datos de la cita
	string date, fechaCit;
	//Asignamos donde guardar los datos de la cita
	es.open("Cita.txt", ios::out | ios::app);
	//Datos que se guardaran de la cita
	cout<<"\tCita Nueva"<<endl;
	cout<<"\tFolio:"<<endl;
	cin>>folio;
	cout<<"\tNombre"<<endl;
	cin>>nombre;
	cout<<"\tApellido paterno:"<<endl;
	cin>>ape;
	cout<<"\tApellido materno:"<<endl;
	cin>>apeMa;
	cout<<"\tGenero"<<endl;
	cin>>gene;
	cout<<"\tFecha de nacimiento(dd/mm/aa):"<<endl;
	cin>>fecha;
	cout<<"\tEstatura:"<<endl;
	cin>>esta;
	cout<<"\tPeso:"<<endl;
	cin>>peso;
	cout<<"\tFecha actual(dd/mm/aa)"<<endl;
	cin>>date;
	cout<<"\tFecha de la proxima cita(dd/mm/aa)"<<endl;
	cin>>fechaCit;
	//escritura de la cita
	es<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<gene<<" "<<fecha<<" "<<esta<<" "<<peso<<" "<<date<<" "<<fechaCit<<"\n";
	es.close();
}

//consultar cita
void consultarci(ifstream &lec){
	system("cls");
	lec.open("Cita.txt", ios::in);
	bool encontrado = false;
	//strin de busqueda
	string folioaux1;
	//Strings de los datos basicos
	string folio, nombre, ape, apeMa, gene, fecha, esta, peso;
	//string de los datos de la cita
	string date, fechaCit;
	cout<<"\t____________________________________"<<endl;
	cout<<"\t|                                  |"<<endl;
	cout<<"\t| <--------Consultar cita--------> |"<<endl;
	cout<<"\t|                                  |"<<endl;
	cout<<"\t|__________________________________|"<<endl;
	cout<<"\tNumero de folio de la cita:        "<<endl;
	cout<<"\t                                    "<<endl;
	cout<<"\t                                    "<<endl;
	cin>>folioaux1;
	lec>>folio;
	//Este while esta para la busqueda siempre y cuando "encontrado" este en un valor de false
	while(!lec.eof() && !encontrado){
		lec>>nombre;
		lec>>ape;
		lec>>apeMa;
		lec>>gene;
		lec>>fecha;
		lec>>esta;
		lec>>peso;
		lec>>date;
		lec>>fechaCit;
		//este if es para comparar e imprimirlo en la pantalla 
		if(folio == folioaux1){
			//limpiamos la consola
			system("cls");
			cout<<"\t____________________________________________________________"<<endl;
			cout<<"\t|                                                          |"<<endl;
			cout<<"\t|       <-------Citas de: "<<" "<<nombre<<"------->        |"<<endl;
			cout<<"\t|                                                          |"<<endl;
			cout<<"\t|__________________________________________________________|"<<endl;
			cout<<"\t|                                                           "<<endl;
			cout<<"\t|Folio: "<<folio<<endl;
			cout<<"\t|Nombre: "<<nombre<<endl;
			cout<<"\t|Apellido paterno: "<<ape<<endl;
			cout<<"\t|Apellido materno: "<<apeMa<<endl;
			cout<<"\t|Genero: "<<gene<<endl;
			cout<<"\t|Fecha de nacimiento(dd/mm/aa): "<<fecha<<endl;
			cout<<"\t|Estatura: "<<esta<<endl;
			cout<<"\t|Peso: "<<peso<<endl;
			cout<<"\t|Fecha de la visita(dd/mm/aa): "<<date<<endl;
			cout<<"\t|Fecha de la proxima cita(dd/mm/aa): "<<fechaCit<<endl;
			cout<<"\t|                                                           "<<endl;
			cout<<"\t|___________________________________________________________"<<endl;
			//cuando folio y folioaux1 sean el mismo se mandara un true a "encontrado"
			encontrado = true;
		}
		lec>>folio;
	}
	lec.close();
	//Si no existe el dato imprime este mensaje
	if(!encontrado)
		cout<<"No existe :c"<<endl;
		system("pause");
}

//editar cita
void editarcita(ifstream &lec){
	int opci;
	system("cls");
	//string para editar
	string folioAux, nomAux2, apeAux2, apeMaAux2, fechaAux2, geneAux2, estaAux2, pesoAux2, dateAux2, fechaCitAux2;
	//string de los datos basicos
	string folio, nombre, ape, apeMa, fecha, gene, esta, peso;
	//string de los datos de la cita
	string date, fechaCit;
	cout<<"\tEditar cita"<<endl;
	cout<<"\t1.Folio "<<endl;
	cout<<"\t2.Nombre"<<endl;
	cout<<"\t3.Apellido paterno "<<endl;
	cout<<"\t4.Apellido materno "<<endl;
	cout<<"\t5.Genero"<<endl;
	cout<<"\t6.Fecha de nacimiento(dd/mm/aa)"<<endl;
	cout<<"\t7.Estatura"<<endl;
	cout<<"\t8.Peso"<<endl;
	cout<<"\t9.Fecha(dd/mm/aa)"<<endl;
	cout<<"\t10.Fecha de la proxima cita(dd/mm/aa)"<<endl;
	cout<<"\t11.Salir";
	cout<<"\tIngrese el dato: ";                                         
	cin>>opci;
	//abrir txt
	lec.open("Cita.txt", ios::in);
	ofstream editcita("EditarCita.txt", ios::out);
	//switch
	switch(opci){
		//editar folio
		case 1:
			system("cls");
			if(lec.is_open()){
				cout<<"\n\tIngrese el folio que desea editar: ";
				cin>>folioAux;
				lec>>folio;
				while(!lec.eof()){
					lec>>nombre;
					lec>>ape;
					lec>>apeMa;
					lec>>gene;
					lec>>fecha;
					lec>>esta;
					lec>>peso;
					lec>>date;
					lec>>fechaCit;
						if(folio == folioAux){
							cout<<"\tNuevo folio: ";
							cin>>folioAux;
							editcita<<folioAux<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<gene<<" "<<fecha<<" "<<esta<<" "<<peso<<" "<<date<<" "<<fechaCit<<"\n";
						}else{
							editcita<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<gene<<" "<<fecha<<" "<<esta<<" "<<peso<<" "<<date<<" "<<fechaCit<<"\n";
					}
					lec>>folioAux;
				}
				lec.close();
				editcita.close();
			}else
				cout<<"Error"<<endl;
				remove("Cita.txt");
				rename("EditarCita.txt", "Cita.txt");
		break;
		
		//editar nombre
		case 2:
			system("cls");
			if(lec.is_open()){
				cout<<"\n\tIngrese el folio: ";
				cin>>folioAux;
				lec>>folio;
				cout<<"\n\tIngrese el nombre a editar: ";
				cin>>nomAux2;
				while(!lec.eof()){
					lec>>nombre;
					lec>>ape;
					lec>>apeMa;
					lec>>gene;
					lec>>fecha;
					lec>>esta;
					lec>>peso;
					lec>>date;
					lec>>fechaCit;
						if(nombre == nomAux2){
							cout<<"\tNuevo Nombre: ";
							cin>>nomAux2;
							editcita<<folio<<" "<<nomAux2<<" "<<ape<<" "<<apeMa<<" "<<gene<<" "<<fecha<<" "<<esta<<" "<<peso<<" "<<date<<" "<<fechaCit<<"\n";
						}else{
							editcita<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<gene<<" "<<fecha<<" "<<esta<<" "<<peso<<" "<<date<<" "<<fechaCit<<"\n";
					}
					lec>>nomAux2;
				}
				lec.close();
				editcita.close();
			}else
				cout<<"Error"<<endl;
				remove("Cita.txt");
				rename("EditarCita.txt", "Cita.txt");
		break;
		
		//editar apellido paterno
		case 3:
			system("cls");
			if(lec.is_open()){
				cout<<"\n\tIngrese el folio: ";
				cin>>folioAux;
				lec>>folio;
				cout<<"\n\tIngrese el Apellido a editar: ";
				cin>>apeAux2;
				while(!lec.eof()){
					lec>>nombre;
					lec>>ape;
					lec>>apeMa;
					lec>>gene;
					lec>>fecha;
					lec>>esta;
					lec>>peso;
					lec>>date;
					lec>>fechaCit;
						if(ape == apeAux2){
							cout<<"\tNuevo Nombre: ";
							cin>>apeAux2;
							editcita<<folio<<" "<<nombre<<" "<<apeAux2<<" "<<apeMa<<" "<<gene<<" "<<fecha<<" "<<esta<<" "<<peso<<" "<<date<<" "<<fechaCit<<"\n";
						}else{
							editcita<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<gene<<" "<<fecha<<" "<<esta<<" "<<peso<<" "<<date<<" "<<fechaCit<<"\n";
					}
					lec>>apeAux2;
				}
				lec.close();
				editcita.close();
			}else
				cout<<"Error"<<endl;
				remove("Cita.txt");
				rename("EditarCita.txt", "Cita.txt");
		break;
		
		//editar apellido materno
		case 4:
			system("cls");
			if(lec.is_open()){
				cout<<"\n\tIngrese el folio: ";
				cin>>folioAux;
				lec>>folio;
				cout<<"\n\tIngrese el apellido a editar: ";
				cin>>apeMaAux2;
				while(!lec.eof()){
					lec>>nombre;
					lec>>ape;
					lec>>apeMa;
					lec>>gene;
					lec>>fecha;
					lec>>esta;
					lec>>peso;
					lec>>date;
					lec>>fechaCit;
						if(apeMa == apeMaAux2){
							cout<<"\tApellido materno: ";
							cin>>apeMaAux2;
							editcita<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMaAux2<<" "<<gene<<" "<<fecha<<" "<<esta<<" "<<peso<<" "<<date<<" "<<fechaCit<<"\n";
						}else{
							editcita<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<gene<<" "<<fecha<<" "<<esta<<" "<<peso<<" "<<date<<" "<<fechaCit<<"\n";
					}
					lec>>apeMaAux2;
				}
				lec.close();
				editcita.close();
			}else
				cout<<"Error"<<endl;
				remove("Cita.txt");
				rename("EditarCita.txt", "Cita.txt");
		break;
		
		//editar genero
		case 5:
			system("cls");
			if(lec.is_open()){
				cout<<"\n\tIngrese el folio: ";
				cin>>folioAux;
				lec>>folio;
				cout<<"\n\tIngrese el genero a editar: ";
				cin>>geneAux2;
				while(!lec.eof()){
					lec>>nombre;
					lec>>ape;
					lec>>apeMa;
					lec>>gene;
					lec>>fecha;
					lec>>esta;
					lec>>peso;
					lec>>date;
					lec>>fechaCit;
						if(gene == geneAux2){
							cout<<"\tGenero: ";
							cin>>geneAux2;
							editcita<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<geneAux2<<" "<<fecha<<" "<<esta<<" "<<peso<<" "<<date<<" "<<fechaCit<<"\n";
						}else{
							editcita<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<gene<<" "<<fecha<<" "<<esta<<" "<<peso<<" "<<date<<" "<<fechaCit<<"\n";
					}
					lec>>geneAux2;
				}
				lec.close();
				editcita.close();
			}else
				cout<<"Error"<<endl;
				remove("Cita.txt");
				rename("EditarCita.txt", "Cita.txt");
		break;
		
		//editar la fecha de nacimiento
		case 6:
			system("cls");
			if(lec.is_open()){
				cout<<"\n\tIngrese el folio: ";
				cin>>folioAux;
				lec>>folio;
				cout<<"\n\tIngrese el fecha de nacimiento a editar: ";
				cin>>fechaAux2;
				while(!lec.eof()){
					lec>>nombre;
					lec>>ape;
					lec>>apeMa;
					lec>>gene;
					lec>>fecha;
					lec>>esta;
					lec>>peso;
					lec>>date;
					lec>>fechaCit;
						if(fecha == fechaAux2){
							cout<<"\tFecha de nacimiento(dd/mm/aa): ";
							cin>>fechaAux2;
							editcita<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<gene<<" "<<fechaAux2<<" "<<esta<<" "<<peso<<" "<<date<<" "<<fechaCit<<"\n";
						}else{
							editcita<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<gene<<" "<<fecha<<" "<<esta<<" "<<peso<<" "<<date<<" "<<fechaCit<<"\n";
					}
					lec>>fechaAux2;
				}
				lec.close();
				editcita.close();
			}else
				cout<<"Error"<<endl;
				remove("Cita.txt");
				rename("EditarCita.txt", "Cita.txt");
		break;
		
		//Estatura
		case 7:
			system("cls");
			if(lec.is_open()){
				cout<<"\n\tIngrese el folio: ";
				cin>>folioAux;
				lec>>folio;
				cout<<"\n\tIngrese la estatura a editar: ";
				cin>>estaAux2;
				while(!lec.eof()){
					lec>>nombre;
					lec>>ape;
					lec>>apeMa;
					lec>>gene;
					lec>>fecha;
					lec>>esta;
					lec>>peso;
					lec>>date;
					lec>>fechaCit;
						if(esta == estaAux2){
							cout<<"\tNueva estatura: ";
							cin>>estaAux2;
							editcita<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<gene<<" "<<fecha<<" "<<estaAux2<<" "<<peso<<" "<<date<<" "<<fechaCit<<"\n";
						}else{
							editcita<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<gene<<" "<<fecha<<" "<<esta<<" "<<peso<<" "<<date<<" "<<fechaCit<<"\n";
					}
					lec>>estaAux2;
				}
				lec.close();
				editcita.close();
			}else
				cout<<"Error"<<endl;
				remove("Cita.txt");
				rename("EditarCita.txt", "Cita.txt");
		break;
		
		//editar el peso
		case 8:
			system("cls");
			if(lec.is_open()){
				cout<<"\n\tIngrese el folio: ";
				cin>>folioAux;
				lec>>folio;
				cout<<"\n\tIngrese el peso a editar: ";
				cin>>pesoAux2;
				while(!lec.eof()){
					lec>>nombre;
					lec>>ape;
					lec>>apeMa;
					lec>>gene;
					lec>>fecha;
					lec>>esta;
					lec>>peso;
					lec>>date;
					lec>>fechaCit;
						if(peso == pesoAux2){
							cout<<"\tNuevo Peso: ";
							cin>>pesoAux2;
							editcita<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<gene<<" "<<fecha<<" "<<esta<<" "<<pesoAux2<<" "<<date<<" "<<fechaCit<<"\n";
						}else{
							editcita<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<gene<<" "<<fecha<<" "<<esta<<" "<<peso<<" "<<date<<" "<<fechaCit<<"\n";
					}
					lec>>pesoAux2;
				}
				lec.close();
				editcita.close();
			}else
				cout<<"Error"<<endl;
				remove("Cita.txt");
				rename("EditarCita.txt", "Cita.txt");
		break;
		
		//editar fecha de visita
		case 9:
			system("cls");
			if(lec.is_open()){
				cout<<"\n\tIngrese el folio: ";
				cin>>folioAux;
				lec>>folio;
				cout<<"\n\tIngrese la fecha a editar: ";
				cin>>dateAux2;
				while(!lec.eof()){
					lec>>nombre;
					lec>>ape;
					lec>>apeMa;
					lec>>gene;
					lec>>fecha;
					lec>>esta;
					lec>>peso;
					lec>>date;
					lec>>fechaCit;
						if(date == dateAux2){
							cout<<"\tNueva fecha: ";
							cin>>dateAux2;
							editcita<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<gene<<" "<<fecha<<" "<<esta<<" "<<peso<<" "<<dateAux2<<" "<<fechaCit<<"\n";
						}else{
							editcita<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<gene<<" "<<fecha<<" "<<esta<<" "<<peso<<" "<<date<<" "<<fechaCit<<"\n";
					}
					lec>>dateAux2;
				}
				lec.close();
				editcita.close();
			}else
				cout<<"Error"<<endl;
				remove("Cita.txt");
				rename("EditarCita.txt", "Cita.txt");
		break;
		
		//editar fecha de cita
		case 10:
			system("cls");
			if(lec.is_open()){
				cout<<"\n\tIngrese el folio: ";
				cin>>folioAux;
				lec>>folio;
				cout<<"\n\tIngrese la fecha de la cita a editar: ";
				cin>>fechaCitAux2;
				while(!lec.eof()){
					lec>>nombre;
					lec>>ape;
					lec>>apeMa;
					lec>>gene;
					lec>>fecha;
					lec>>esta;
					lec>>peso;
					lec>>date;
					lec>>fechaCit;
						if(fechaCit == fechaCitAux2){
							cout<<"\tFecha de la cita: ";
							cin>>fechaCitAux2;
							editcita<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<gene<<" "<<fecha<<" "<<esta<<" "<<peso<<" "<<date<<" "<<fechaCitAux2<<"\n";
						}else{
							editcita<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<gene<<" "<<fecha<<" "<<esta<<" "<<peso<<" "<<date<<" "<<fechaCit<<"\n";
					}
					lec>>fechaCitAux2;
				}
				lec.close();
				editcita.close();
			}else
				cout<<"Error"<<endl;
				remove("Cita.txt");
				rename("EditarCita.txt", "Cita.txt");
		break;
	}
}


//borrar cita
void borrarcita(ifstream &lec){
	//strin de busqueda
	string folioaux1;
	//Strings de los datos basicos
	string folio, nombre, ape, apeMa, gene, fecha, esta, peso;
	//string de los datos de la cita
	string date, fechaCit;
	//abrir txt
	lec.open("Cita.txt", ios::in);
	ofstream editcita("EditarCita.txt", ios::out);
	if(lec.is_open()){
		cout<<"\n\tIngrese el folio: ";
		cin>>folioaux1;
		lec>>folio;
		while(!lec.eof()){
			lec>>nombre;
			lec>>ape;
			lec>>apeMa;
			lec>>gene;
			lec>>fecha;
			lec>>esta;
			lec>>peso;
			lec>>date;
			lec>>fechaCit;
			if(folio == folioaux1){
				cout<<"Eliminado correctamente :D";
				//Esta es la linea que hace la funcion de eliminar 
				Sleep(1500);
			}else{
				editcita<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<gene<<" "<<fecha<<" "<<esta<<" "<<peso<<" "<<date<<" "<<fechaCit<<"\n";
			}
			lec>>folioaux1;
		}
		lec.close();
		editcita.close();
	}else
	cout<<"Error"<<endl;
	remove("Cita.txt");
	rename("EditarCita.txt", "Cita.txt");
}

//void para editarel expediente
void editarexp(ifstream &lec){
	int x;
	system("cls");
	//String de los datos personales
	string folio;
	string nombre;
	string ape;
	string apeMa;
	string edad;
	string gene;
	string esta;
	string peso;
	string ale;
	string enfe;
	string dis;
	string san;
	string dom;
	string numEx;
	string numIn;
	string numCel;
	string numAux;
	string numAux2;
	string correo;
	//Sting para editar
	string folio1, nomb2, apeAux1, apeMaAux1, edadAux1, geneAux1, estaAux1, pesoAux1, aleAux1, enfeAux1, disAux1, sanAux1, domAux1, numExAux1, numInAux1, numCelAux1, numaux1, numaux5, correoAux1;
  
	cout<<"\tEditar expediente"<<endl;
	cout<<"\t1.Folio"<<endl;
	cout<<"\t2.Nombre"<<endl;
	cout<<"\t3.Apellido paterno"<<endl;
	cout<<"\t4.Apellido materno"<<endl;
	cout<<"\t5.Fecha de nacimiento(dd/mm/aa)"<<endl;
	cout<<"\t6.Genero"<<endl;
	cout<<"\t7.Estatura"<<endl;
	cout<<"\t8.Peso"<<endl;
	cout<<"\t9.Alergias"<<endl;
	cout<<"\t10.Enfermedades cronicas"<<endl;
	cout<<"\t11.Discapacidades"<<endl;
	cout<<"\t12.Tipo de sangre"<<endl;
	cout<<"\t13.Calle"<<endl;
	cout<<"\t14 Numero exterior"<<endl;
	cout<<"\t15.Numero interior"<<endl;
	cout<<"\t16.Numero de celular"<<endl;
	cout<<"\t17.Numero de contacto"<<endl;
	cout<<"\t18.Numero de contacto"<<endl;
	cout<<"\t19.Correo electronico"<<endl;
	cout<<"\t20.Salir"<<endl;
	cout<<"\tIngrese la opcion a editar:";                                     
	ofstream editexp("EditarExp.txt", ios::out);
	switch(x){
		//editar folio
		case 1:
			system("cls");
			if(lec.is_open()){
				cout<<"\n\tIngrese el folio que desea editar: ";
				cin>>folio1;
				lec>>folio;
				while(!lec.eof()){
					lec>>nombre;
					lec>>ape;
					lec>>apeMa;
					lec>>edad;
					lec>>gene;
					lec>>esta;
					lec>>peso;
					lec>>ale;
					lec>>enfe;
					lec>>dis;
					lec>>san;
					lec>>dom;
					lec>>numEx;
					lec>>numIn;
					lec>>numCel;
					lec>>numAux;
					lec>>numAux2;
					lec>>correo;
					if(folio == folio1){
						cout<<"\tNuevo folio: ";
						cin>>folio1;
						editexp<<folio1<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<edad<<" "<<gene<<" "<<esta<<" "<<peso<<" "<<ale<<" "<<enfe<<" "<<dis<<" "<<san<<" "<<dom<<" "<<numEx<<" "<<numIn<<" "<<numCel<<" "<<numAux<<" "<<numAux2<<" "<<correo<<"\n";
					}else{
						editexp<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<edad<<" "<<gene<<" "<<esta<<" "<<peso<<" "<<ale<<" "<<enfe<<" "<<dis<<" "<<san<<" "<<dom<<" "<<numEx<<" "<<numIn<<" "<<numCel<<" "<<numAux<<" "<<numAux2<<" "<<correo<<"\n";
					}
					lec>>folio;
				}
				lec.close();
				editexp.close();
			}else
				cout<<"Error"<<endl;
				remove("Expediente.txt");
				rename("EditarExp.txt", "Expediente.txt");
		break;
			
		//editar nombre
		case 2:
			system("cls");
			if(lec.is_open()){
				cout<<"\tIngrese el folio: ";
				cin>>folio1;
				lec>>folio;
				cout<<"\n\tIngrese el nombre: ";
				cin>>nomb2;
				while(!lec.eof()){
					lec>>nombre;
					lec>>ape;
					lec>>apeMa;
					lec>>edad;
					lec>>gene;
					lec>>esta;
					lec>>peso;
					lec>>ale;
					lec>>enfe;
					lec>>dis;
					lec>>san;
					lec>>dom;
					lec>>numEx;
					lec>>numIn;
					lec>>numCel;
					lec>>numAux;
					lec>>numAux2;
					lec>>correo;
					if(nombre == nomb2){
						cout<<"\tNuevo nombre: ";
						cin>>nomb2;
						editexp<<folio<<" "<<nomb2<<" "<<ape<<" "<<apeMa<<" "<<edad<<" "<<gene<<" "<<esta<<" "<<peso<<" "<<ale<<" "<<enfe<<" "<<dis<<" "<<san<<" "<<dom<<" "<<numEx<<" "<<numIn<<" "<<numCel<<" "<<numAux<<" "<<numAux2<<" "<<correo<<"\n";
					}else{
						editexp<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<edad<<" "<<gene<<" "<<esta<<" "<<peso<<" "<<ale<<" "<<enfe<<" "<<dis<<" "<<san<<" "<<dom<<" "<<numEx<<" "<<numIn<<" "<<numCel<<" "<<numAux<<" "<<numAux2<<" "<<correo<<"\n";
					}
					lec>>nombre;
				}
				lec.close();
				editexp.close();
			}else
				cout<<"Error"<<endl;
				remove("Expediente.txt");
				rename("EditarExp.txt", "Expediente.txt");
		break;	
		
		//editar apellido paterno
		case 3:
			system("cls");
			if(lec.is_open()){
				cout<<"\tIngrese el folio: ";
				cin>>folio1;
				lec>>folio;
				cout<<"\n\tIngrese el Apellido Paterno: ";
				cin>>apeAux1;
				while(!lec.eof()){
					lec>>nombre;
					lec>>ape;
					lec>>apeMa;
					lec>>edad;
					lec>>gene;
					lec>>esta;
					lec>>peso;
					lec>>ale;
					lec>>enfe;
					lec>>dis;
					lec>>san;
					lec>>dom;
					lec>>numEx;
					lec>>numIn;
					lec>>numCel;
					lec>>numAux;
					lec>>numAux2;
					lec>>correo;
					if(ape == apeAux1){
						cout<<"\tNuevo Apellido paterno: ";
						cin>>apeAux1;
						editexp<<folio<<" "<<nombre<<" "<<apeAux1<<" "<<apeMa<<" "<<edad<<" "<<gene<<" "<<esta<<" "<<peso<<" "<<ale<<" "<<enfe<<" "<<dis<<" "<<san<<" "<<dom<<" "<<numEx<<" "<<numIn<<" "<<numCel<<" "<<numAux<<" "<<numAux2<<" "<<correo<<"\n";
					}else{
						editexp<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<edad<<" "<<gene<<" "<<esta<<" "<<peso<<" "<<ale<<" "<<enfe<<" "<<dis<<" "<<san<<" "<<dom<<" "<<numEx<<" "<<numIn<<" "<<numCel<<" "<<numAux<<" "<<numAux2<<" "<<correo<<"\n";
					}
					lec>>apeAux1;
				}
				lec.close();
				editexp.close();
			}else
				cout<<"Error"<<endl;
				remove("Expediente.txt");
				rename("EditarExp.txt", "Expediente.txt");
		break;
		
		case 4:
			system("cls");
			if(lec.is_open()){
				cout<<"\tIngrese el folio: ";
				cin>>folio1;
				lec>>folio;
				cout<<"\n\tIngrese el Apellido Materno: ";
				cin>>apeMaAux1;
				while(!lec.eof()){
					lec>>nombre;
					lec>>ape;
					lec>>apeMa;
					lec>>edad;
					lec>>gene;
					lec>>esta;
					lec>>peso;
					lec>>ale;
					lec>>enfe;
					lec>>dis;
					lec>>san;
					lec>>dom;
					lec>>numEx;
					lec>>numIn;
					lec>>numCel;
					lec>>numAux;
					lec>>numAux2;
					lec>>correo;
					if(apeMa == apeMaAux1){
						cout<<"\tNuevo Apellido paterno: ";
						cin>>apeMaAux1;
						editexp<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMaAux1<<" "<<edad<<" "<<gene<<" "<<esta<<" "<<peso<<" "<<ale<<" "<<enfe<<" "<<dis<<" "<<san<<" "<<dom<<" "<<numEx<<" "<<numIn<<" "<<numCel<<" "<<numAux<<" "<<numAux2<<" "<<correo<<"\n";
					}else{
						editexp<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<edad<<" "<<gene<<" "<<esta<<" "<<peso<<" "<<ale<<" "<<enfe<<" "<<dis<<" "<<san<<" "<<dom<<" "<<numEx<<" "<<numIn<<" "<<numCel<<" "<<numAux<<" "<<numAux2<<" "<<correo<<"\n";
					}
					lec>>apeMaAux1;
				}
				lec.close();
				editexp.close();
			}else
				cout<<"Error"<<endl;
				remove("Expediente.txt");
				rename("EditarExp.txt", "Expediente.txt");
		break;
		
		//Editar fecha de nacimiento
		case 5:
			system("cls");
			if(lec.is_open()){
				cout<<"\tIngrese el folio: ";
				cin>>folio1;
				lec>>folio;
				cout<<"\n\tIngrese la fecha de nacimiento(dd/mm/aa): ";
				cin>>edadAux1;
				while(!lec.eof()){
					lec>>nombre;
					lec>>ape;
					lec>>apeMa;
					lec>>edad;
					lec>>gene;
					lec>>esta;
					lec>>peso;
					lec>>ale;
					lec>>enfe;
					lec>>dis;
					lec>>san;
					lec>>dom;
					lec>>numEx;
					lec>>numIn;
					lec>>numCel;
					lec>>numAux;
					lec>>numAux2;
					lec>>correo;
					if(edad == edadAux1){
						cout<<"\tNueva fecha de nacimiento(dd/mm/aa): ";
						cin>>edadAux1;
						editexp<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<edadAux1<<" "<<gene<<" "<<esta<<" "<<peso<<" "<<ale<<" "<<enfe<<" "<<dis<<" "<<san<<" "<<dom<<" "<<numEx<<" "<<numIn<<" "<<numCel<<" "<<numAux<<" "<<numAux2<<" "<<correo<<"\n";
					}else{
						editexp<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<edad<<" "<<gene<<" "<<esta<<" "<<peso<<" "<<ale<<" "<<enfe<<" "<<dis<<" "<<san<<" "<<dom<<" "<<numEx<<" "<<numIn<<" "<<numCel<<" "<<numAux<<" "<<numAux2<<" "<<correo<<"\n";
					}
					lec>>edadAux1;
				}
				lec.close();
				editexp.close();
			}else
				cout<<"Error"<<endl;
				remove("Expediente.txt");
				rename("EditarExp.txt", "Expediente.txt");
		break;
		
		//editar genero
		case 6:
			system("cls");
			if(lec.is_open()){
				cout<<"\tIngrese el folio: ";
				cin>>folio1;
				lec>>folio;
				cout<<"\n\tIngrese el genero: ";
				cin>>geneAux1;
				while(!lec.eof()){
					lec>>nombre;
					lec>>ape;
					lec>>apeMa;
					lec>>edad;
					lec>>gene;
					lec>>esta;
					lec>>peso;
					lec>>ale;
					lec>>enfe;
					lec>>dis;
					lec>>san;
					lec>>dom;
					lec>>numEx;
					lec>>numIn;
					lec>>numCel;
					lec>>numAux;
					lec>>numAux2;
					lec>>correo;
					if(gene == geneAux1){
						cout<<"\tIngrese el nuevo genero: ";
						cin>>geneAux1;
						editexp<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<edad<<" "<<geneAux1<<" "<<esta<<" "<<peso<<" "<<ale<<" "<<enfe<<" "<<dis<<" "<<san<<" "<<dom<<" "<<numEx<<" "<<numIn<<" "<<numCel<<" "<<numAux<<" "<<numAux2<<" "<<correo<<"\n";
					}else{
						editexp<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<edad<<" "<<gene<<" "<<esta<<" "<<peso<<" "<<ale<<" "<<enfe<<" "<<dis<<" "<<san<<" "<<dom<<" "<<numEx<<" "<<numIn<<" "<<numCel<<" "<<numAux<<" "<<numAux2<<" "<<correo<<"\n";
					}
					lec>>geneAux1;
				}
				lec.close();
				editexp.close();
			}else
				cout<<"Error"<<endl;
				remove("Expediente.txt");
				rename("EditarExp.txt", "Expediente.txt");
		break;
		
		//editar estatura
		case 7:
			system("cls");
			if(lec.is_open()){
				cout<<"\tIngrese el folio: ";
				cin>>folio1;
				lec>>folio;
				cout<<"\n\tIngrese la estatura: ";
				cin>>estaAux1;
				while(!lec.eof()){
					lec>>nombre;
					lec>>ape;
					lec>>apeMa;
					lec>>edad;
					lec>>gene;
					lec>>esta;
					lec>>peso;
					lec>>ale;
					lec>>enfe;
					lec>>dis;
					lec>>san;
					lec>>dom;
					lec>>numEx;
					lec>>numIn;
					lec>>numCel;
					lec>>numAux;
					lec>>numAux2;
					lec>>correo;
					if(esta == estaAux1){
						cout<<"\tNueva estatura: ";
						cin>>estaAux1;
						editexp<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<edad<<" "<<gene<<" "<<estaAux1<<" "<<peso<<" "<<ale<<" "<<enfe<<" "<<dis<<" "<<san<<" "<<dom<<" "<<numEx<<" "<<numIn<<" "<<numCel<<" "<<numAux<<" "<<numAux2<<" "<<correo<<"\n";
					}else{
						editexp<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<edad<<" "<<gene<<" "<<esta<<" "<<peso<<" "<<ale<<" "<<enfe<<" "<<dis<<" "<<san<<" "<<dom<<" "<<numEx<<" "<<numIn<<" "<<numCel<<" "<<numAux<<" "<<numAux2<<" "<<correo<<"\n";
					}
					lec>>estaAux1;
				}
				lec.close();
				editexp.close();
			}else
				cout<<"Error"<<endl;
				remove("Expediente.txt");
				rename("EditarExp.txt", "Expediente.txt");
		break;
		
		//editar peso
		case 8:
			system("cls");
			if(lec.is_open()){
				cout<<"\tIngrese el folio: ";
				cin>>folio1;
				lec>>folio;
				cout<<"\n\tIngrese el peso: ";
				cin>>pesoAux1;
				while(!lec.eof()){
					lec>>nombre;
					lec>>ape;
					lec>>apeMa;
					lec>>edad;
					lec>>gene;
					lec>>esta;
					lec>>peso;
					lec>>ale;
					lec>>enfe;
					lec>>dis;
					lec>>san;
					lec>>dom;
					lec>>numEx;
					lec>>numIn;
					lec>>numCel;
					lec>>numAux;
					lec>>numAux2;
					lec>>correo;
					if(peso == pesoAux1){
						cout<<"\tNuevo peso: ";
						cin>>pesoAux1;
						editexp<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<edad<<" "<<gene<<" "<<esta<<" "<<pesoAux1<<" "<<ale<<" "<<enfe<<" "<<dis<<" "<<san<<" "<<dom<<" "<<numEx<<" "<<numIn<<" "<<numCel<<" "<<numAux<<" "<<numAux2<<" "<<correo<<"\n";
					}else{
						editexp<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<edad<<" "<<gene<<" "<<esta<<" "<<peso<<" "<<ale<<" "<<enfe<<" "<<dis<<" "<<san<<" "<<dom<<" "<<numEx<<" "<<numIn<<" "<<numCel<<" "<<numAux<<" "<<numAux2<<" "<<correo<<"\n";
					}
					lec>>pesoAux1;
				}
				lec.close();
				editexp.close();
			}else
				cout<<"Error"<<endl;
				remove("Expediente.txt");
				rename("EditarExp.txt", "Expediente.txt");
		break;
		
		//editar alergias
		case 9:
			system("cls");
			if(lec.is_open()){
				cout<<"\tIngrese el folio: ";
				cin>>folio1;
				lec>>folio;
				cout<<"\n\tIngrese si tiene o no alergias: ";
				cin>>aleAux1;
				while(!lec.eof()){
					lec>>nombre;
					lec>>ape;
					lec>>apeMa;
					lec>>edad;
					lec>>gene;
					lec>>esta;
					lec>>peso;
					lec>>ale;
					lec>>enfe;
					lec>>dis;
					lec>>san;
					lec>>dom;
					lec>>numEx;
					lec>>numIn;
					lec>>numCel;
					lec>>numAux;
					lec>>numAux2;
					lec>>correo;
					if(ale == aleAux1){
						cout<<"\tPadece de alergias: ";
						cin>>aleAux1;
						editexp<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<edad<<" "<<gene<<" "<<esta<<" "<<peso<<" "<<aleAux1<<" "<<enfe<<" "<<dis<<" "<<san<<" "<<dom<<" "<<numEx<<" "<<numIn<<" "<<numCel<<" "<<numAux<<" "<<numAux2<<" "<<correo<<"\n";
					}else{
						editexp<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<edad<<" "<<gene<<" "<<esta<<" "<<peso<<" "<<ale<<" "<<enfe<<" "<<dis<<" "<<san<<" "<<dom<<" "<<numEx<<" "<<numIn<<" "<<numCel<<" "<<numAux<<" "<<numAux2<<" "<<correo<<"\n";
					}
					lec>>aleAux1;
				}
				lec.close();
				editexp.close();
			}else
				cout<<"Error"<<endl;
				remove("Expediente.txt");
				rename("EditarExp.txt", "Expediente.txt");
		break;
		
		//editar enfermedades cronicas
		case 10:
			system("cls");
			if(lec.is_open()){
				cout<<"\tIngrese el folio: ";
				cin>>folio1;
				lec>>folio;
				cout<<"\n\tIngrese si tiene o no enfermedades cronicas: ";
				cin>>enfeAux1;
				while(!lec.eof()){
					lec>>nombre;
					lec>>ape;
					lec>>apeMa;
					lec>>edad;
					lec>>gene;
					lec>>esta;
					lec>>peso;
					lec>>ale;
					lec>>enfe;
					lec>>dis;
					lec>>san;
					lec>>dom;
					lec>>numEx;
					lec>>numIn;
					lec>>numCel;
					lec>>numAux;
					lec>>numAux2;
					lec>>correo;
					if(enfe == enfeAux1){
						cout<<"\tPadece de enfermedades cronicas: ";
						cin>>enfeAux1;
						editexp<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<edad<<" "<<gene<<" "<<esta<<" "<<peso<<" "<<ale<<" "<<enfeAux1<<" "<<dis<<" "<<san<<" "<<dom<<" "<<numEx<<" "<<numIn<<" "<<numCel<<" "<<numAux<<" "<<numAux2<<" "<<correo<<"\n";
					}else{
						editexp<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<edad<<" "<<gene<<" "<<esta<<" "<<peso<<" "<<ale<<" "<<enfe<<" "<<dis<<" "<<san<<" "<<dom<<" "<<numEx<<" "<<numIn<<" "<<numCel<<" "<<numAux<<" "<<numAux2<<" "<<correo<<"\n";
					}
					lec>>enfeAux1;
				}
				lec.close();
				editexp.close();
			}else
				cout<<"Error"<<endl;
				remove("Expediente.txt");
				rename("EditarExp.txt", "Expediente.txt");
		break;
		
		//editar discapacidades
		case 11:
			system("cls");
			if(lec.is_open()){
				cout<<"\tIngrese el folio: ";
				cin>>folio1;
				lec>>folio;
				cout<<"\n\tIngrese el dato que desea cambiar: ";
				cin>>disAux1;
				while(!lec.eof()){
					lec>>nombre;
					lec>>ape;
					lec>>apeMa;
					lec>>edad;
					lec>>gene;
					lec>>esta;
					lec>>peso;
					lec>>ale;
					lec>>enfe;
					lec>>dis;
					lec>>san;
					lec>>dom;
					lec>>numEx;
					lec>>numIn;
					lec>>numCel;
					lec>>numAux;
					lec>>numAux2;
					lec>>correo;
					if(dis == disAux1){
						cout<<"\tIngrese el nuevo dato: ";
						cin>>disAux1;
						editexp<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<edad<<" "<<gene<<" "<<esta<<" "<<peso<<" "<<ale<<" "<<enfe<<" "<<disAux1<<" "<<san<<" "<<dom<<" "<<numEx<<" "<<numIn<<" "<<numCel<<" "<<numAux<<" "<<numAux2<<" "<<correo<<"\n";
					}else{
						editexp<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<edad<<" "<<gene<<" "<<esta<<" "<<peso<<" "<<ale<<" "<<enfe<<" "<<dis<<" "<<san<<" "<<dom<<" "<<numEx<<" "<<numIn<<" "<<numCel<<" "<<numAux<<" "<<numAux2<<" "<<correo<<"\n";
					}
					lec>>disAux1;
				}
				lec.close();
				editexp.close();
			}else
				cout<<"Error"<<endl;
				remove("Expediente.txt");
				rename("EditarExp.txt", "Expediente.txt");
		break;
		
		//editar tipo de sangre
		case 12:
			system("cls");
			if(lec.is_open()){
				cout<<"\tIngrese el folio: ";
				cin>>folio1;
				lec>>folio;
				cout<<"\n\tIngrese el dato que desea cambiar: ";
				cin>>sanAux1;
				while(!lec.eof()){
					lec>>nombre;
					lec>>ape;
					lec>>apeMa;
					lec>>edad;
					lec>>gene;
					lec>>esta;
					lec>>peso;
					lec>>ale;
					lec>>enfe;
					lec>>dis;
					lec>>san;
					lec>>dom;
					lec>>numEx;
					lec>>numIn;
					lec>>numCel;
					lec>>numAux;
					lec>>numAux2;
					lec>>correo;
					if(san == sanAux1){
						cout<<"\tTipo de sangre: ";
						cin>>sanAux1;
						editexp<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<edad<<" "<<gene<<" "<<esta<<" "<<peso<<" "<<ale<<" "<<enfe<<" "<<dis<<" "<<sanAux1<<" "<<dom<<" "<<numEx<<" "<<numIn<<" "<<numCel<<" "<<numAux<<" "<<numAux2<<" "<<correo<<"\n";
					}else{
						editexp<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<edad<<" "<<gene<<" "<<esta<<" "<<peso<<" "<<ale<<" "<<enfe<<" "<<dis<<" "<<san<<" "<<dom<<" "<<numEx<<" "<<numIn<<" "<<numCel<<" "<<numAux<<" "<<numAux2<<" "<<correo<<"\n";
					}
					lec>>sanAux1;
				}
				lec.close();
				editexp.close();
			}else
				cout<<"Error"<<endl;
				remove("Expediente.txt");
				rename("EditarExp.txt", "Expediente.txt");
		break;
		
		//editar calle
		case 13:
			system("cls");
			if(lec.is_open()){
				cout<<"\tIngrese el folio: ";
				cin>>folio1;
				lec>>folio;
				cout<<"\n\tIngrese el dato anterior: ";
				cin>>domAux1;
				while(!lec.eof()){
					lec>>nombre;
					lec>>ape;
					lec>>apeMa;
					lec>>edad;
					lec>>gene;
					lec>>esta;
					lec>>peso;
					lec>>ale;
					lec>>enfe;
					lec>>dis;
					lec>>san;
					lec>>dom;
					lec>>numEx;
					lec>>numIn;
					lec>>numCel;
					lec>>numAux;
					lec>>numAux2;
					lec>>correo;
					if(dom == domAux1){
						cout<<"\tCalle: ";
						cin>>domAux1;
						editexp<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<edad<<" "<<gene<<" "<<esta<<" "<<peso<<" "<<ale<<" "<<enfe<<" "<<dis<<" "<<san<<" "<<domAux1<<" "<<numEx<<" "<<numIn<<" "<<numCel<<" "<<numAux<<" "<<numAux2<<" "<<correo<<"\n";
					}else{
						editexp<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<edad<<" "<<gene<<" "<<esta<<" "<<peso<<" "<<ale<<" "<<enfe<<" "<<dis<<" "<<san<<" "<<dom<<" "<<numEx<<" "<<numIn<<" "<<numCel<<" "<<numAux<<" "<<numAux2<<" "<<correo<<"\n";
					}
					lec>>domAux1;
				}
				lec.close();
				editexp.close();
			}else
				cout<<"Error"<<endl;
				remove("Expediente.txt");
				rename("EditarExp.txt", "Expediente.txt");
		break;
		
		//editar numero exterior
		case 14:
			system("cls");
			if(lec.is_open()){
				cout<<"\tIngrese el folio: ";
				cin>>folio1;
				lec>>folio;
				cout<<"\n\tIngrese el dato anterior: ";
				cin>>numExAux1;
				while(!lec.eof()){
					lec>>nombre;
					lec>>ape;
					lec>>apeMa;
					lec>>edad;
					lec>>gene;
					lec>>esta;
					lec>>peso;
					lec>>ale;
					lec>>enfe;
					lec>>dis;
					lec>>san;
					lec>>dom;
					lec>>numEx;
					lec>>numIn;
					lec>>numCel;
					lec>>numAux;
					lec>>numAux2;
					lec>>correo;
					if(numEx == numExAux1){
						cout<<"\tNumero exterior: ";
						cin>>numExAux1;
						editexp<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<edad<<" "<<gene<<" "<<esta<<" "<<peso<<" "<<ale<<" "<<enfe<<" "<<dis<<" "<<san<<" "<<dom<<" "<<numExAux1<<" "<<numIn<<" "<<numCel<<" "<<numAux<<" "<<numAux2<<" "<<correo<<"\n";
					}else{
						editexp<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<edad<<" "<<gene<<" "<<esta<<" "<<peso<<" "<<ale<<" "<<enfe<<" "<<dis<<" "<<san<<" "<<dom<<" "<<numEx<<" "<<numIn<<" "<<numCel<<" "<<numAux<<" "<<numAux2<<" "<<correo<<"\n";
					}
					lec>>numExAux1;
				}
				lec.close();
				editexp.close();
			}else
				cout<<"Error"<<endl;
				remove("Expediente.txt");
				rename("EditarExp.txt", "Expediente.txt");
		break;
		
		//Editar numero interior
		case 15:
			system("cls");
			if(lec.is_open()){
				cout<<"\tIngrese el folio: ";
				cin>>folio1;
				lec>>folio;
				cout<<"\n\tIngrese el dato anterior: ";
				cin>>numInAux1;
				while(!lec.eof()){
					lec>>nombre;
					lec>>ape;
					lec>>apeMa;
					lec>>edad;
					lec>>gene;
					lec>>esta;
					lec>>peso;
					lec>>ale;
					lec>>enfe;
					lec>>dis;
					lec>>san;
					lec>>dom;
					lec>>numEx;
					lec>>numIn;
					lec>>numCel;
					lec>>numAux;
					lec>>numAux2;
					lec>>correo;
					if(numIn == numInAux1){
						cout<<"\tNumero interior: ";
						cin>>numInAux1;
						editexp<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<edad<<" "<<gene<<" "<<esta<<" "<<peso<<" "<<ale<<" "<<enfe<<" "<<dis<<" "<<san<<" "<<dom<<" "<<numEx<<" "<<numInAux1<<" "<<numCel<<" "<<numAux<<" "<<numAux2<<" "<<correo<<"\n";
					}else{
						editexp<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<edad<<" "<<gene<<" "<<esta<<" "<<peso<<" "<<ale<<" "<<enfe<<" "<<dis<<" "<<san<<" "<<dom<<" "<<numEx<<" "<<numIn<<" "<<numCel<<" "<<numAux<<" "<<numAux2<<" "<<correo<<"\n";
					}
					lec>>numInAux1;
				}
				lec.close();
				editexp.close();
			}else
				cout<<"Error"<<endl;
				remove("Expediente.txt");
				rename("EditarExp.txt", "Expediente.txt");
		break;
		
		//Editar numero de celular
		case 16:
			system("cls");
			if(lec.is_open()){
				cout<<"\tIngrese el folio: ";
				cin>>folio1;
				lec>>folio;
				cout<<"\n\tIngrese el dato anterior: ";
				cin>>numCelAux1;
				while(!lec.eof()){
					lec>>nombre;
					lec>>ape;
					lec>>apeMa;
					lec>>edad;
					lec>>gene;
					lec>>esta;
					lec>>peso;
					lec>>ale;
					lec>>enfe;
					lec>>dis;
					lec>>san;
					lec>>dom;
					lec>>numEx;
					lec>>numIn;
					lec>>numCel;
					lec>>numAux;
					lec>>numAux2;
					lec>>correo;
					if(numCel == numCelAux1){
						cout<<"\tNumero de celular: ";
						cin>>numCelAux1;
						editexp<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<edad<<" "<<gene<<" "<<esta<<" "<<peso<<" "<<ale<<" "<<enfe<<" "<<dis<<" "<<san<<" "<<dom<<" "<<numEx<<" "<<numIn<<" "<<numCelAux1<<" "<<numAux<<" "<<numAux2<<" "<<correo<<"\n";
					}else{
						editexp<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<edad<<" "<<gene<<" "<<esta<<" "<<peso<<" "<<ale<<" "<<enfe<<" "<<dis<<" "<<san<<" "<<dom<<" "<<numEx<<" "<<numIn<<" "<<numCel<<" "<<numAux<<" "<<numAux2<<" "<<correo<<"\n";
					}
					lec>>numCelAux1;
				}
				lec.close();
				editexp.close();
			}else
				cout<<"Error"<<endl;
				remove("Expediente.txt");
				rename("EditarExp.txt", "Expediente.txt");
		break;
		
		//editar numero de contacto
		case 17:
			system("cls");
			if(lec.is_open()){
				cout<<"\tIngrese el folio: ";
				cin>>folio1;
				lec>>folio;
				cout<<"\n\tIngrese el dato anterior: ";
				cin>>numaux1;
				while(!lec.eof()){
					lec>>nombre;
					lec>>ape;
					lec>>apeMa;
					lec>>edad;
					lec>>gene;
					lec>>esta;
					lec>>peso;
					lec>>ale;
					lec>>enfe;
					lec>>dis;
					lec>>san;
					lec>>dom;
					lec>>numEx;
					lec>>numIn;
					lec>>numCel;
					lec>>numAux;
					lec>>numAux2;
					lec>>correo;
					if(numAux == numaux1){
						cout<<"\tNumero de contacto: ";
						cin>>numaux1;
						editexp<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<edad<<" "<<gene<<" "<<esta<<" "<<peso<<" "<<ale<<" "<<enfe<<" "<<dis<<" "<<san<<" "<<dom<<" "<<numEx<<" "<<numIn<<" "<<numCel<<" "<<numaux1<<" "<<numAux2<<" "<<correo<<"\n";
					}else{
						editexp<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<edad<<" "<<gene<<" "<<esta<<" "<<peso<<" "<<ale<<" "<<enfe<<" "<<dis<<" "<<san<<" "<<dom<<" "<<numEx<<" "<<numIn<<" "<<numCel<<" "<<numAux<<" "<<numAux2<<" "<<correo<<"\n";
					}
					lec>>numaux1;
				}
				lec.close();
				editexp.close();
			}else
				cout<<"Error"<<endl;
				remove("Expediente.txt");
				rename("EditarExp.txt", "Expediente.txt");
		break;
		
		//editar numero de contacto 2
		case 18:
			system("cls");
			if(lec.is_open()){
				cout<<"\tIngrese el folio: ";
				cin>>folio1;
				lec>>folio;
				cout<<"\n\tIngrese el dato anterior: ";
				cin>>numaux5;
				while(!lec.eof()){
					lec>>nombre;
					lec>>ape;
					lec>>apeMa;
					lec>>edad;
					lec>>gene;
					lec>>esta;
					lec>>peso;
					lec>>ale;
					lec>>enfe;
					lec>>dis;
					lec>>san;
					lec>>dom;
					lec>>numEx;
					lec>>numIn;
					lec>>numCel;
					lec>>numAux;
					lec>>numAux2;
					lec>>correo;
					if(numAux2 == numaux5){
						cout<<"\tNumero de contacto 2: ";
						cin>>numaux5;
						editexp<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<edad<<" "<<gene<<" "<<esta<<" "<<peso<<" "<<ale<<" "<<enfe<<" "<<dis<<" "<<san<<" "<<dom<<" "<<numEx<<" "<<numIn<<" "<<numCel<<" "<<numAux<<" "<<numaux5<<" "<<correo<<"\n";
					}else{
						editexp<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<edad<<" "<<gene<<" "<<esta<<" "<<peso<<" "<<ale<<" "<<enfe<<" "<<dis<<" "<<san<<" "<<dom<<" "<<numEx<<" "<<numIn<<" "<<numCel<<" "<<numAux<<" "<<numAux2<<" "<<correo<<"\n";
					}
					lec>>numaux5;
				}
				lec.close();
				editexp.close();
			}else
				cout<<"Error"<<endl;
				remove("Expediente.txt");
				rename("EditarExp.txt", "Expediente.txt");
		break;
		
		//editar correo
		case 19:
			system("cls");
			if(lec.is_open()){
				cout<<"\tIngrese el folio: ";
				cin>>folio1;
				lec>>folio;
				cout<<"\n\tIngrese el dato anterior: ";
				cin>>correoAux1;
				while(!lec.eof()){
					lec>>nombre;
					lec>>ape;
					lec>>apeMa;
					lec>>edad;
					lec>>gene;
					lec>>esta;
					lec>>peso;
					lec>>ale;
					lec>>enfe;
					lec>>dis;
					lec>>san;
					lec>>dom;
					lec>>numEx;
					lec>>numIn;
					lec>>numCel;
					lec>>numAux;
					lec>>numAux2;
					lec>>correo;
					if(correo == correoAux1){
						cout<<"\tNumero exterior: ";
						cin>>correoAux1;
						editexp<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<edad<<" "<<gene<<" "<<esta<<" "<<peso<<" "<<ale<<" "<<enfe<<" "<<dis<<" "<<san<<" "<<dom<<" "<<numEx<<" "<<numIn<<" "<<numCel<<" "<<numAux<<" "<<numAux2<<" "<<correoAux1<<"\n";
					}else{
						editexp<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<edad<<" "<<gene<<" "<<esta<<" "<<peso<<" "<<ale<<" "<<enfe<<" "<<dis<<" "<<san<<" "<<dom<<" "<<numEx<<" "<<numIn<<" "<<numCel<<" "<<numAux<<" "<<numAux2<<" "<<correo<<"\n";
					}
					lec>>correoAux1;
				}
				lec.close();
				editexp.close();
			}else
				cout<<"Error"<<endl;
				remove("Expediente.txt");
				rename("EditarExp.txt", "Expediente.txt");
		break;
	}
}

//borrar expediente
void borrarexp(ifstream &lec){
	//limpiar la consola
	system("cls");
	string nombre;
	string ape;
	string apeMa;
	string edad;
	string gene;
	string esta;
	string peso;
	string ale;
	string enfe;
	string dis;
	string san;
	string dom;
	string numEx;
	string numIn;
	string numCel;
	string numAux;
	string numAux2;
	string correo;
	string folio;
	//busqueda
	string folio1;
	//String del historial familiar
	string nomb, ape2, apeMa2, edad2, paren, gene2, esta2, peso2, ale2, en, dis2, san2, dom2, numEx2, numIn2;
	string numCel2, numaux, numaux2, correo2;
	
	//string del historial familiar 2
	string nomb2, ape3, apeMa3, edad3, paren2, gene3, esta3, peso3, ale3, en2, dis3, san3, dom3, numEx3, numIn3;
	string numeCel, numeaux, numeaux2, correo3;
	//abrir archivos
	lec.open("Expediente.txt", ios::in);
	ofstream editexp("EditarExp.txt", ios::out);
	if(lec.is_open()){
				cout<<"\tIngrese el folio: ";
				cin>>folio1;
				lec>>folio;
				while(!lec.eof()){
					lec>>nombre;
					lec>>ape;
					lec>>apeMa;
					lec>>edad;
					lec>>gene;
					lec>>esta;
					lec>>peso;
					lec>>ale;
					lec>>enfe;
					lec>>dis;
					lec>>san;
					lec>>dom;
					lec>>numEx;
					lec>>numIn;
					lec>>numCel;
					lec>>numAux;
					lec>>numAux2;
					lec>>correo;
					//Lectura de los datos del historial familiar
					lec>>nomb;
					lec>>ape2;
					lec>>apeMa2;
					lec>>edad2;
					lec>>paren;
					lec>>gene2;
					lec>>esta2;
					lec>>peso2;
					lec>>ale2;
					lec>>en;
					lec>>dis2;
					lec>>san2;
					lec>>dom2;
					lec>>numEx2;
					lec>>numIn2;
					lec>>numCel2;
					lec>>numaux;
					lec>>numaux2;
					lec>>correo2;
					//Lectura de los datos del historial familiar 2
					lec>>nomb2;
					lec>>ape3;
					lec>>apeMa3;
					lec>>edad3;
					lec>>paren2;
					lec>>gene3;
					lec>>esta3;
					lec>>peso3;
					lec>>ale3;
					lec>>en2;
					lec>>dis3;
					lec>>san3;
					lec>>dom3;
					lec>>numEx3;
					lec>>numIn3;
					lec>>numeCel;
					lec>>numeaux;
					lec>>numeaux2;
					lec>>correo3;
						if(folio == folio1){
							cout<<"\tEliminado correctamente :D";
							//Esta es la linea que hace la funcion de eliminar 
							Sleep(1500);
						}else{
							editexp<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<edad<<" "<<gene<<" "<<esta<<" "<<peso<<" "<<ale<<" "<<enfe<<" "<<dis<<" "<<san<<" "<<dom<<" "<<numEx<<" "<<numIn<<" "<<numCel<<" "<<numAux<<" "<<numAux2<<" "<<correo<<"\n";
						}
						lec>>folio;
					}
					lec.close();
					editexp.close();
				}else
					cout<<"Error"<<endl;
					remove("Expediente.txt");
					rename("EditarExp.txt", "Expediente.txt");
}

void menuuser(){
	ofstream(esc);
	ifstream(lec);
	ICO pacientes;
	Nodo *frente = NULL;
	Nodo *fin = NULL;
	
	int opcion;
	
	system("cls");
	cout<<endl<<"\tMenú Usuario";
	cout<<endl<<"\t1. Registrar Expediente";
	cout<<endl<<"\t2. Consultar Expediente";
	cout<<endl<<"\t3. Editar Expediente";
	cout<<endl<<"\t4. Borra Expediente";
	cout<<endl<<"\t5. Registrar Cita";
	cout<<endl<<"\t6. Consultar Cita";
	cout<<endl<<"\t7. Editar Cita";
	cout<<endl<<"\t8. Borrar Cita";
	cout<<endl<<"\t0. Salir";
	cout<<endl<<"\tOpción:";
	
	cin>>opcion;
	fflush(stdin);
	
	
	//Nodo *aux = frente;

		switch(opcion){
			//Registar expediente
			case 1:
				system("cls");
				agregar(esc);
				menuuser();
				//agregarDatos(pacientes);
				//insertarDatos(frente, fin, pacientes);
			break;
			
			//Consultar expediente
			case 2:
				consultar(lec);
				menuuser();
				/*
				if(aux != NULL){
					cout<<endl<<"\t|________________________|";
					cout<<endl<<"\t|Folio |Nombre\t|Sexo\t        |Peso kg\t|Altura m\n";
					while (aux!=NULL){
						cout<<"\t|"<<aux->pacientes.nombre<<"\t|"<<aux->pacientes.genero<<"\t|"<<aux->pacientes.peso<<"\t|"<<aux->pacientes.altura<<endl;
						aux = aux->siguiente;
					}
				}else{
					cout<<"\n\t***Sin Registros***\n";
					system("pause");
					system("cls");
					menuuser();
				}*/
			break;
			
			//Editar expediente
			case 3:
				editarexp(lec);
				menuuser();
				/*if(aux != NULL){
					cout<<"\n\tBuscar Paciente\n";
					buscarDatos(frente, pacientes);
				}else{
					cout<<"\n\t***Sin Registros***\n";
					system("pause");
					system("cls");
					menuuser();
					
				}*/
			break;
			
			//Borrar expediente
			case 4:
				system("cls");
				borrarexp(lec);
				menuuser();
				/*agregarDatos(pacientes);
				insertarDatos(frente, fin, pacientes);*/
			break;
						
			//Agregar cita
			case 5:
				agregarcita(esc);
				menuuser();
			break;
			
			//Consultar cita
			case 6:
				consultarci(lec);
				menuuser();
				break;
				
			//editar cita
			case 7:
				editarcita(lec);
				menuuser();
				break;
				
			//Borra cita
			case 8:
				borrarcita(lec);
				menuuser();
			break;
			
			//IMC
			case 9:
				
			break;
		}
}

void agregarDatos(ICO &pacientes){
	
	ofstream foutput;
	ifstream finput;
	
	foutput.open ("Expedientes.txt",ios::app);
    finput.open ("Expedientes.txt");
	
	if(finput.is_open()){
		
		int nacimiento, edad;
		
		tiempo();
		
		cout<<"\n\t|\n\tDatos Generales";
		cout<<endl<<"\t";
		foutput<<"\n\t|\n\tDatos Generales";
		
		cout<<"\n\t|\n\tNombre:";
		cin.getline(pacientes.nombre, 10, '\n');
		foutput<<"\n\t|\n\tNombre: "<< pacientes.nombre;
		
		cout<<"\tApellido Paterno: ";
		cin.getline(pacientes.app, 10, '\n');
		foutput<<"\t\t Apellido Paterno: "<< pacientes.app;
		
		cout<<"\tApellido Materno: ";
		cin.getline(pacientes.apm, 10, '\n');
		foutput<<"\t\tApellido Materno: "<< pacientes.apm;
		
		cout<<"\tGénero: ";
		cin.getline(pacientes.genero, 10, '\n');
		foutput<<"\t\tGenero: " << pacientes.genero;
		
		cout<<"\tFecha de Nacimiento (dd/mm): ";
		cin.getline(pacientes.fechanac, 10, '\n');
		foutput<<"\n\t|\n\tFecha de Nacimiento: " << pacientes.fechanac;
		
    	printf("Año de Nacimiento: ");
    	scanf("%d", &nacimiento);
    	printf("Edad: ", edad);
		
		
		
		/*
		cout<<"\t| Folio de Expediente Clinico: ";
		cin>>pacientes.folio;
		foutput<<"\t\t| Folio: " << pacientes.folio;
	
		cout<<"\t| Ingresa Peso del Paciente en kilogramos: ";
		cin>>pacientes.peso;
		foutput<<"\n\t| Peso: " << pacientes.peso <<" kg.";
		
		cout<<"\t| Ingresa Altura del Paciente en metros: ";
		cin>>pacientes.altura;
		foutput<<"\t\t| Altura: " << pacientes.altura <<" m.";
		
		cout<<"\t| Ingresa Fecha de Nacimiento: ";
		cin>>pacientes.fecha;
		foutput<<"\t\t| Fecha de Nacimiento: "<< pacientes.fecha;
		
		cout<<"\t|\n\t|_________Indicadores Antropométricos___________";
		foutput<<"\n\t|\n\t|_______Indicadores Antropométricos________";
		cout<<"\n\t|Los siguientes datos se registran en cm";
		
		cout<<"\t|\n\t| Meñeca del Paciente: ";
		cin>>pacientes.muneca;
		foutput<<"\n\t| Muñeca: "<< pacientes.muneca <<"cm.";
		
		cout<<"\t| Brazo del Paciente: ";
		cin>>pacientes.brazo;
		foutput<<"\t| Brazo: "<< pacientes.brazo <<"cm.";
		
		cout<<"\t| Antebrazo del Paciente: ";
		cin>>pacientes.antebrazo;
		foutput<<"\t\t| Antebrazo: "<< pacientes.antebrazo <<"cm.";
		
		cout<<"\t| Muslo del Paciente: ";
		cin>>pacientes.muslo;
		foutput<<"\n\t| Muslo: "<< pacientes.muslo <<"cm.";
		
		cout<<"\t| Pantorrilla del Paciente: ";
		cin>>pacientes.pantorrilla;
		foutput<<"\t| Pantorrilla: "<< pacientes.pantorrilla <<"cm.";
		
		cout<<"\t| Cintura del Paciente: ";
		cin>>pacientes.cintura;
		foutput<<"\t| Cintura: "<< pacientes.cintura <<"cm.";
		
		cout<<"\t| Cadera del Paciente: ";
		cin>>pacientes.cadera;
		foutput<<"\n\t| Cadera: "<< pacientes.cadera <<"cm.";
		
		cout<<"\t| Humero del Paciente: ";
		cin>>pacientes.humero;
		foutput<<"\t| Humero: "<< pacientes.humero <<"cm.";
		
		cout<<"\t|----------Pliegues o Panículos-----------";
		foutput<<"\n\t|\n\t|----------Pliegues o Panículos------------";
		cout<<"\t|\n\t| tLos siguientes datos se registran en mm";
		
		cout<<"\t|\n\t| Biceps del Paciente: ";
		cin>>pacientes.biceps;
		foutput<<"\n\n\t| Biceps: "<< pacientes.biceps <<"mm.";
		
		cout<<"\t| Subescapular del Paciente: ";
		cin>>pacientes.subescapular;
		foutput<<"\t\t| Subescapular: "<< pacientes.subescapular <<"mm.";
		
		cout<<"\t| Triceps del Paciente: ";
		cin>>pacientes.triceps;
		foutput<<"\n\t| Triceps: "<< pacientes.triceps <<"mm.";
		
		cout<<"\t| Suprialiaco del Paciente: ";
		cin>>pacientes.suprailiaco;
		foutput<<"\t\t| Suprailiaco: "<< pacientes.suprailiaco <<"mm.";
		*/
		cout<<"\t|____________________________________";
		foutput<<"\n______|___________________________";
		
		
		cout<<"\n\tDatos ingresados correctamente";
	
    	finput.close();
    	foutput.close();
		fflush(stdin);
    	menuuser();
	}else{
		cout<<"\n\t***Error en Archivo***";
	}
}

void insertarDatos(Nodo *&frente, Nodo *&fin, ICO pacientes){
	//Declaro mi nuevo nodo
	Nodo *n_nodo = new Nodo();
	
	//Asignar los valores de los datos
	n_nodo -> pacientes = pacientes;
	
	//siguiente apunte a null
	n_nodo -> siguiente = NULL;
	
	//Primero verificar si esta vacia
	if(c_vacia(frente)){
		frente = n_nodo;
		//si la cola esta vacia frente = nuevo nodo
	}else{
		fin -> siguiente = n_nodo;//si la cola esta vacia
	}
	fin = n_nodo;
}

void eliminarDatos(Nodo *&frente, Nodo *&fin, ICO pacientes){
	pacientes = frente->pacientes;
	Nodo *aux = frente;
	
	if(frente == fin){
		frente = NULL;
		fin = NULL;
	}else{
		frente = frente -> siguiente;
	}
	
	delete aux;
}

void buscarDatos(Nodo *frente, ICO pacientes){
	
	bool band = false;
	
	Nodo *actual = new Nodo();
	actual = frente;
	
	cout<<"\n\tIngrese Folio del Paciente: ";
	cin>>pacientes.nombre;
	
		while((actual != NULL) && (actual->pacientes.nombre <= pacientes.nombre)){
		if(actual->pacientes.nombre == pacientes.nombre){
			cout<<"\n\tPaciente: "<<actual->pacientes.nombre<<"; Sexo ("<<actual->pacientes.genero<<"; Peso: "<<actual->pacientes.peso<<" Si a sido encontrado en Registros\n";
		band = true;
		}
		actual = actual->siguiente;
	}
	if(band == true){
		
	}else{
	cout<<"\n\tPaciente: "<<actual->pacientes.nombre<<" No a sido endontrado en Registros\n";
	}
}

void modificarDato(Nodo *frente, ICO pacientes){
	
	bool band = false;
	
	Nodo* actual = new Nodo();
	actual = frente;
	
	cout<<"\n\tIngresa Folio del Paciente: ";
	cin>>pacientes.nombre;
		
		while(actual!=NULL && band != true){
			
				if(actual->pacientes.nombre == pacientes.nombre){
					cout << "\n\tPaciente Encontrado";
					cout << "\n\tNombre del Paciente: " << actual->pacientes.nombre;
					cout << "\n\tIngrese Nuevo Nombre para este Paciente: ";
					cin >> actual -> pacientes.nombre;
				
					cout << "\n\tSexo del Paciente: "<< actual->pacientes.genero;
					cout << "\n\tIngrese Nuevo Sexo para este Paciente: ";
					cin >> actual -> pacientes.genero;
				
					cout << "\n\tPeso del Paciente: "<< actual->pacientes.peso;
					cout << "\n\tIngrese Nuevo Peso para este Paciente: ";
					cin >> actual -> pacientes.peso;
				
					cout << "\n\tPaciente Modificado\n\n";
					band = true;
			}
			
			actual = actual->siguiente;
		}
		if(!band){
			cout << "\n\tPaciente No Encontrado\n\n";
		}		
}

bool c_vacia(Nodo *frente){
	//Operador Ternario para saber si esta vacia
	return(frente == NULL)? true:false;
}

void tiempo(){
	int hours, minutes, seconds, day, month, year;

	time_t now;

	time(&now);

	struct tm *local = localtime(&now);

	hours = local->tm_hour;
	minutes = local->tm_min;
	seconds = local->tm_sec;

	day = local->tm_mday;
	month = local->tm_mon + 1;
	year = local->tm_year + 1900;

	if (hours < 12) {
		printf("Hora: %02d:%02d:%02d am\n", hours, minutes, seconds);
	}
	else {
		printf("Hora: %02d:%02d:%02d pm\n", hours - 12, minutes, seconds);
	}
	printf("Fecha: %02d/%02d/%d\n", day, month, year);
}

void edadreal(){
	
	
}

