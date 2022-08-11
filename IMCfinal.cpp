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

#define USER "xime"
#define PASS "123456"

using namespace std;


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
void consultarci(ifstream &lec);
void agregarcita(ofstream &es);
bool c_vacia(Nodo *);

int main(){
	
	setlocale(LC_ALL,"");
	
	system("color 7");
    
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
		cout<<"\n\t Creado por:";
		cout<<"\n\t Ximena Martinez Sanchez";
		cout<<"\n\t Carlos Eduardo Ramirez Rios";
		cout<<"\n\t Sara Ixshel Cortes Hernandez";
		
		cout<<"\n\n";
		cout<<"\n\t   Bienvenido a la calculadora";
		
		
		cout<<"\n\t Usuario: ";
		getline(cin, usuario);
		cout<<"\t Password: ";
		
		char caracter;
		caracter = getch();
		
		password = "";
		
		while (caracter != 13){
			password.push_back(caracter);
			cout<<"*";
			caracter = getch();
		}
		
		cout<<"\n\t____________\n";
		
		if (usuario == USER && password == PASS){
			ingresa = true;
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
		cout<<"\n\t Demasiados Intentos "<<endl;
	}
}

void  menuadmin(){
	ofstream esc;
	char opcion;
	
	cout<<endl<<"\t     Menú ";
	cout<<endl<<"\t1. Citas";
	cout<<endl<<"\t2. Expediente Clinico";
	cout<<endl<<"\t3. Calcula tu IMC";
	cout<<endl<<"\t4. Salir";
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
				system("cls");
				char gen,imcr,Nmi;

float fdn;
double alt1,alt2,pes2,pes1,eda,imc,obj;
cout<<"Cuantos años tienes? :"<<endl;
	cin>>eda;
	if (eda>=100){
	cout<<"Cual es tu altura(m)? "<<endl;
	cin>>alt1;
	cout<<"Cuanto pesas (kg) ? : "<<endl;
	cin>>pes1;
	imc=pes1/(alt1*alt1);
	if (imc<18.5){
		cout<<"Tu IMC es "<<imc<<" ,estas bajo en tu masa corporal "<<endl;
		cout<<"Consejo:"<< endl;
		cout<<"Deberas checarte con un especialista." << endl ;
	}
	if (imc>18.5&&imc<24.9){
		cout<<"Tu IMC es "<<imc<<" eres una persona saludable"<<endl;
		cout<<"Consejo:"<< endl;
		cout<<"Comer saludable y hacer ejercicio." << endl ;
	}
	if (imc>25&&imc<29.9){
		cout<<"Tu IMC es "<<imc<<" tienes sobrepeso"<<endl;
	}
	if (imc>30&&imc<34.9){
		cout<<"Tu IMC es "<<imc<<" tienes obesidad de grado I"<<endl;
	}
	if (imc>35&&imc<39.9){
		cout<<"Tu IMC es "<<imc<<" tienes obesidad de grado II"<<endl;
	}
	if (imc>40&&imc<49.9){
		cout<<"Tu IMC es "<<imc<<" tienes obesidad de grado III"<<endl;
	}
	if (imc>50){
		cout<<"Tu IMC es "<<imc<<" tienes obesidad de grado IV"<<endl;
	}
}
else
{
	cout<<"Ingresa tu genero  m = masculino f = femenino:"<<endl;
	cin>>gen;
	
    if(gen=='m'){
	cout<<"Cual es tu altura(m)? : "<<endl;
	cin>>alt2;
	cout<<"Cuanto pesas (kg) ? : "<<endl;
	cin>>pes2;
	imc=pes2/(alt2*alt2);
	if (imc<18.5){
		cout<<"Tu IMC es "<<imc<<" ,estas bajo en tu masa corporal "<<endl;
		cout<<"Consejo:"<< endl;
		cout<<"Deberas checarte con un especialista." << endl ;
	}
	else if (imc>=18.5){
		cout<<"Tu IMC es "<<imc<<" eres una persona saludable"<<endl;
		cout<<"Consejo:"<< endl;
		cout<<"Comer saludable y hacer ejercicio." << endl ;
	}
	else if (imc>=25){
		cout<<"Tu IMC es "<<imc<<" tienes sobrepeso"<<endl;
	}
	else if (imc>=30){
		cout<<"Tu IMC es "<<imc<<" tienes obesidad de grado I"<<endl;
	}
	else if (imc>=35){
		cout<<"Tu IMC es "<<imc<<" tienes obesidad de grado II"<<endl;
	}
	else if (imc>=40){
		cout<<"Tu IMC es "<<imc<<" tienes obesidad de grado III"<<endl;
	}
	else if (imc>=50){
		cout<<"Tu IMC es "<<imc<<" tienes obesidad de grado IV"<<endl;
	}
}

	if(gen=='f'){
	
	cout<<"Cual es tu altura (m)? : "<<endl;
	cin>>alt1;
	cout<<"Cuanto pesas (kg) ? : "<<endl;
	cin>>pes1;
	imc=pes1/(alt1*alt1);
	if (imc<18.5){
		cout<<"Tu IMC es "<<imc<<" ,estas bajo en tu masa corporal "<<endl;
		cout<<"Consejo:"<< endl;
		cout<<"Deberas checarte con un especialista." << endl ;
	}
	else if (imc>=18.5){
		cout<<"Tu IMC es "<<imc<<" eres una persona saludable"<<endl;
		cout<<"Consejo:"<< endl;
		cout<<"Comer saludable y hacer ejercicio." << endl ;
	}
	else if (imc>=25){
		cout<<"Tu IMC es "<<imc<<" tienes sobrepeso"<<endl;
	}
	else if (imc>=30){
		cout<<"Tu IMC es "<<imc<<" tienes obesidad de grado I"<<endl;
	}
	else if (imc>=35){
		cout<<"Tu IMC es "<<imc<<" tienes obesidad de grado II"<<endl;
	}
	else if (imc>=40){
		cout<<"Tu IMC es "<<imc<<" tienes obesidad de grado III"<<endl;
	}
	else if (imc>=50){
		cout<<"Tu IMC es "<<imc<<" tienes obesidad de grado IV"<<endl;
	}
}
}
cout<<"Desea repetir la medicion (S/N):"<<endl;
cin>>Nmi;
do{
	cout<<"Cuantos años tienes ? : "<<endl;
	cin>>eda;
	if (eda>=100){
	cout<<"Cual es tu altura(m)? : "<<endl;
	cin>>alt1;
	cout<<"Cuanto pesas (kg) ? : "<<endl;
	cin>>pes1;
	imc=pes1/(alt1*alt1);
	if (imc<18.5){
		cout<<"Tu IMC es "<<imc<<" ,estas bajo en tu masa corporal "<<endl;
		cout<<"Consejo:"<< endl;
		cout<<"Deberas checarte con un especialista." << endl ;
	}
	if (imc>18.5&&imc<24.9){
		cout<<"Tu IMC es "<<imc<<" eres una persona saludable"<<endl;
		cout<<"Consejo:"<< endl;
		cout<<"Comer saludable y hacer ejercicio." << endl ;
	}
	if (imc>25&&imc<29.9){
		cout<<"Tu IMC es "<<imc<<" tienes sobrepeso"<<endl;
	}
	if (imc>30&&imc<34.9){
		cout<<"Tu IMC es "<<imc<<" tienes obesidad de grado I"<<endl;
	}
	if (imc>35&&imc<39.9){
		cout<<"Tu IMC es "<<imc<<" tienes obesidad de grado II"<<endl;
	}
	if (imc>40&&imc<49.9){
		cout<<"Tu IMC es "<<imc<<" tienes obesidad de grado III"<<endl;
	}
	if (imc>50){
		cout<<"Tu IMC es "<<imc<<" tienes obesidad de grado IV"<<endl;
	}
}
else
{
	cout<<"Ingresa tu genero  m = masculino f = femenino :"<<endl;
	cin>>gen;
	
    if(gen=='m'){
	cout<<"Cual es tu altura(m)? : "<<endl;
	cin>>alt2;
	cout<<"Cuanto pesas (kg) ?: "<<endl;
	cin>>pes2;
	imc=pes2/(alt2*alt2);
	if (imc<18.5){
		cout<<"Tu IMC es "<<imc<<" ,estas bajo en tu masa corporal "<<endl;
		cout<<"Consejo:"<< endl;
		cout<<"Deberas checarte con un especialista." << endl ;
	}
	else if (imc>=18.5){
		cout<<"Tu IMC es "<<imc<<" eres una persona saludable"<<endl;
		cout<<"Consejo:"<< endl;
		cout<<"Comer saludable y hacer ejercicio." << endl ;
	}
	else if (imc>=25){
		cout<<"Tu IMC es "<<imc<<" tienes sobrepeso"<<endl;
	}
	else if (imc>=30){
		cout<<"Tu IMC es "<<imc<<" tienes obesidad de grado I"<<endl;
	}
	else if (imc>=35){
		cout<<"Tu IMC es "<<imc<<" tienes obesidad de grado II"<<endl;
	}
	else if (imc>=40){
		cout<<"Tu IMC es "<<imc<<" tienes obesidad de grado III"<<endl;
	}
	else if (imc>=50){
		cout<<"Tu IMC es "<<imc<<" tienes obesidad de grado IV"<<endl;
	}
}

	if(gen=='f'){
	
	cout<<"Cual es tu altura(m) ? : "<<endl;
	cin>>alt1;
	cout<<"Cuanto pesas (kg) ? :"<<endl;
	cin>>pes1;
	imc=pes1/(alt1*alt1);
	if (imc<18.5){
		cout<<"Tu IMC es "<<imc<<" ,estas bajo en tu masa corporal "<<endl;
		cout<<"Consejo:"<< endl;
		cout<<"Deberas checarte con un especialista." << endl ;
		cout << "Puedes consumir lacteos y derivados: Son uno de los alimentos mas " << endl ;
		cout << "adecuados para subir de peso es la leche entera, pues cuenta con " << endl ;
		cout << "un alto contenido en calorias, calcio y grasas saludables." << endl;
	}
	else if (imc>=18.5){
		cout<<"Tu IMC es "<<imc<<" eres una persona saludable"<<endl;
		cout<<"Consejo:"<< endl;
		cout<<"Comer saludable y hacer ejercicio." << endl ;
	}
	else if (imc>=25){
		cout<<"Tu IMC es "<<imc<<" tienes sobrepeso"<<endl;
		cout<<"Consejo:"<< endl;
		cout << "Come abundantes frutas y verduras crudas" << endl ;
		cout << "o cocidas , lácteos desnatados, cereales integrales." << endl;
	}
	else if (imc>=30){
		cout<<"Tu IMC es "<<imc<<" tienes obesidad de grado I"<<endl;
		cout<<"Consejo:"<< endl;
		cout << "Come abundantes frutas y verduras crudas" << endl ;
		cout << "o cocidas , lácteos desnatados, cereales integrales." << endl;
	}
	else if (imc>=35){
		cout<<"Tu IMC es "<<imc<<" tienes obesidad de grado II"<<endl;
		cout<<"Consejo:"<< endl;
		cout << "La comida debe ser simple, pero con suficiente valor nutricional." << endl ;
		cout << "El cuerpo del paciente no debe sufrir de una falta" << endl ;
		cout << "de vitaminas, microelementos, aminoácidos, etc." << endl;
	}
	else if (imc>=40){
		cout<<"Tu IMC es "<<imc<<" tienes obesidad de grado III"<<endl;
		cout<<"Consejo:"<< endl;
		cout << "Realizar actividades como : aeróbic acuático y gimnasia." << endl; 

	}
	else if (imc>=50){
		cout<<"Tu IMC es "<<imc<<" tienes obesidad de grado IV"<<endl;
		cout<<"Consejo:"<< endl;
		cout << "Comenzar con un examen completo de todo el cuerpo" << endl;
		cout << "para determinar todas las patologías que acompañan. " << endl ;
		cout << "Es necesario checarte con algun cardiologo con un " << endl ;
		cout << "nutricioniste." << endl ;
	}
}
}
cout<<"Desea repetir la medicion (S/N):"<<endl;
cin>>Nmi;	
}while(Nmi=='s');
cout<<"Cual es su objetivo?"<<endl;
cout<<"1.-Perder Peso \n2.-Ganar Salud\n3.-Ponerse Fuerte"<<endl;
cin>>obj;
if (obj=1){
	cout<<"1"<<endl;
}
if(obj=2){
	cout<<"2"<<endl;
}
if(obj=3){
	 cout<<"3"<<endl;
}
			break;
						
			case '4':
				system("cls");
				login();
			break;
			
			default:
				cout<<"\n\tOpción Invalida \n";
				break;
		}
		cout<<"\n\tPresiona Cualquier Tecla\n";
	 	getch();
		system("cls");
	}while(opcion != '4');
}

void agregar(ofstream &es){
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
	
	string nomb, ape2, apeMa2, edad2, paren, gene2, esta2, peso2, ale2, en, dis2, san2, dom2, numEx2, numIn2;
	string numCel2, numaux, numaux2, correo2;
	

	string nomb2, ape3, apeMa3, edad3, paren2, gene3, esta3, peso3, ale3, en2, dis3, san3, dom3, numEx3, numIn3;
	string numeCel, numeaux, numeaux2, correo3;
	
	es.open("Expediente.txt", ios::out | ios::app);
	cout<<"\n\t Registro nuevo"<<endl;
	cout<<" Nº de Folio:  "<<endl;
	cin>>folio;
	cout<<" Nombre: "<<endl;
	cin>>nombre;
	cout<<" Apellido paterno: "<<endl;
	cin>>ape;
	cout<<" Apellido materno: "<<endl;
	cin>>apeMa;
	cout<<" Fecha de nacimiento(dd/mm/aa): "<<endl;
	cin>>edad;
	cout<<" Genero: "<<endl;
	cin>>gene;
	cout<<" Estatura: "<<endl;
	cin>>esta;
	cout<<" Peso: "<<endl;
	cin>>peso;
	cout<<" Alergias: "<<endl;
	cin>>ale;
	cout<<" Enfermedades cronicas: "<<endl;
	cin>>enfe;
	cout<<" Discapacidad: "<<endl;
	cin>>dis;
	cout<<" Tipo de sangre: "<<endl;
	cin>>san;
	cout<<" Calle: "<<endl;
	cin>>dom;
	cout<<" Numero exterior: "<<endl;
	cin>>numEx;
	cout<<" Numero interior: "<<endl;
	cin>>numIn;
	cout<<" Numero celular: "<<endl;
	cin>>numCel;
	cout<<" Numero de contacto: "<<endl;
	cin>>numAux;                              
	cout<<" Numero de contacto 2: "<<endl;
	cin>>numAux2;
	cout<<" Correo electronico: "<<endl;
	cin>>correo;

	cout<<"\t\t "<<endl;
	cout<<"\t\t "<<endl;
	cout<<"\t\t Historial familiar "<<endl;
	cout<<" Nombre: "<<endl;
	cin>>nomb;
	cout<<" Apellido paterno: "<<endl;
	cin>>ape2;
	cout<<" Apellido materno: "<<endl;
	cin>>apeMa2;
	cout<<" Fecha de nacimiento(dd/mm/aa): "<<endl;
	cin>>edad2;
	cout<<" Parentesco: "<<endl;
	cin>>paren;
	cout<<" Genero: "<<endl;
	cin>>gene2;
	cout<<" Estatura: "<<endl;
	cin>>esta2;
	cout<<" Peso: "<<endl;
	cin>>peso2;
	cout<<" Alergias: "<<endl;
	cin>>ale2;
	cout<<" Enfermedades cronicas: "<<endl;
	cin>>en;
	cout<<" Discapacidad: "<<endl;
	cin>>dis2;
	cout<<" Tipo de sangre: "<<endl;
	cin>>san2;
	cout<<" Calle: "<<endl;
	cin>>dom2;
	cout<<" Numero exterior: "<<endl;
	cin>>numEx2;
	cout<<" Numero interior: "<<endl;
	cin>>numIn2;
	cout<<" Numero celular: "<<endl;
	cin>>numCel2;
	cout<<" Numero de contacto: "<<endl;
	cin>>numaux;
	cout<<" Numero de contacto 2: "<<endl;
	cin>>numaux2;
	cout<<" Correo electronico: "<<endl;
	cin>>correo2;
	cout<<"\n\t                                      "<<endl;
	cout<<"\n\t                                      "<<endl;
	
	
	cout<<"\t\t "<<endl;
	cout<<"\t\t "<<endl;
	cout<<"\t\t Historial familiar "<<endl;
	cout<<" Nombre: "<<endl;
	cin>>nomb;
	cout<<" Apellido paterno: "<<endl;
	cin>>ape3;
	cout<<" Apellido materno: "<<endl;
	cin>>apeMa3;
	cout<<" Fecha de nacimiento(dd/mm/aa): "<<endl;
	cin>>edad3;
	cout<<" Parentesco: "<<endl;
	cin>>paren;
	cout<<" Genero: "<<endl;
	cin>>gene3;
	cout<<" Estatura: "<<endl;
	cin>>esta3;
	cout<<" Peso: "<<endl;
	cin>>peso3;
	cout<<" Alergias: "<<endl;
	cin>>ale3;
	cout<<" Enfermedades cronicas: "<<endl;
	cin>>en;
	cout<<" Discapacidad: "<<endl;
	cin>>dis3;
	cout<<" Tipo de sangre: "<<endl;
	cin>>san3;
	cout<<" Calle: "<<endl;
	cin>>dom3;
	cout<<" Numero exterior: "<<endl;
	cin>>numEx3;
	cout<<" Numero interior: "<<endl;
	cin>>numIn3;
	cout<<" Numero celular: "<<endl;
	cin>>numCel;
	cout<<" Numero de contacto: "<<endl;
	cin>>numaux;
	cout<<" Numero de contacto 2: "<<endl;
	cin>>numaux2;
	cout<<" Correo electronico: "<<endl;
	cin>>correo3;
	cout<<"\n\t                                      "<<endl;
	cout<<"\n\t                                      "<<endl;	
	
	es<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<edad<<" "<<gene<<" "<<esta<<" "<<peso<<" "<<ale<<" "<<enfe<<" "<<dis<<" "<<san<<" "<<dom<<" "<<numEx<<" "<<numIn<<" "<<numCel<<" "<<numAux<<" "<<numAux2<<" "<<correo<<"\n";
	
	es<<nomb<<" "<<ape2<<" "<<apeMa2<<" "<<edad2<<" "<<paren<<" "<<gene2<<" "<<esta2<<" "<<peso2<<" "<<ale2<<" "<<en<<" "<<dis2<<" "<<san2<<" "<<dom2<<" "<<numEx2<<" "<<numIn2<<" "<<numCel2<<" "<<numaux<<" "<<numaux2<<" "<<correo2<<"\n";
	
	es<<nomb2<<" "<<ape3<<" "<<apeMa3<<" "<<edad3<<" "<<paren<<" "<<gene3<<" "<<esta3<<" "<<peso3<<" "<<ale3<<" "<<en2<<" "<<dis3<<" "<<san3<<" "<<dom3<<" "<<numEx3<<" "<<numIn3<<" "<<numeCel<<" "<<numeaux<<" "<<numeaux2<<" "<<correo3<<"\n";
	
	es.close();
}

void menucita(){
	ifstream lec;
	char opcion;
	
	cout<<endl<<"\t    ";
	cout<<endl<<"\t    ";
	cout<<endl<<"\t  Menú Cita  ";
	cout<<endl<<"\t    ";
	cout<<endl<<"\t    ";
	cout<<endl<<"\t  1. Consultar Cita  ";
	cout<<endl<<"\t    ";
	cout<<endl<<"\t    ";
	cout<<endl<<"\t  2. Eliminar Cita   ";
	cout<<endl<<"\t    ";
	cout<<endl<<"\t    ";
	cout<<endl<<"\t  3. Editar Cita     ";
	cout<<endl<<"\t    ";
	cout<<endl<<"\t    ";
	cout<<endl<<"\t  4. Regresar        ";
	cout<<endl<<"\t    ";
	cout<<endl<<"\t    ";
	cout<<endl<<"Opción:";
	
	cin>>opcion;
	fflush(stdin);
	
	do{
		switch(opcion){
			case '1':
				tiempo ();
				consultar (lec);
				
				
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
				cout<<"\n\tOpción Invalida \n";
				break;
		}
		
		system("cls");
	}while(opcion != '4');
}

void menuexp(){
	ifstream lec;
	char opcion;
	
	cout<<endl<<"\t    ";
	cout<<endl<<"\t    ";
	cout<<endl<<"\t        Menú Expediente               ";
	cout<<endl<<"\t    ";
	cout<<endl<<"\t    ";
	cout<<endl<<"\t   1. Buscar Expediente Clinico  ";
	cout<<endl<<"\t    ";
	cout<<endl<<"\t    ";
	cout<<endl<<"\t   2. Consultar Expedientes      ";
	cout<<endl<<"\t    ";
	cout<<endl<<"\t    ";
	cout<<endl<<"\t   3. Regresar                   ";
	cout<<endl<<"\t    ";
	cout<<endl<<"\t    ";
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
				cout<<"\n\t Opción Invalida \n";
				break;
		}
		cout<<"\n\tPresiona Cualquier Tecla\n";
	 	getch();
		system("cls");
	}while(opcion != '4');
}

void consultar(ifstream &lec){
	system("cls");
	lec.open("Expediente.txt", ios::in);
	bool encontrado = false;
	string folioaux;
	string folio, nombre, ape, apeMa, edad,  gene, esta, peso, ale, enfe, dis, san, dom, numEx, numIn, numCel, numAux, numAux2, correo;
	string nomb, ape2, apeMa2, edad2, paren, gene2, esta2, peso2, ale2, en, dis2, san2, dom2, numEx2, numIn2, numCel2, numaux, numaux2, correo2;
	string nomb2, ape3, apeMa3, edad3, paren2, gene3, esta3, peso3, ale3, en2, dis3, san3, dom3, numEx3, numIn3, numeCel, numeaux, numeaux2, correo3;
	cout<<"\t "<<endl;
	cout<<"\t                       "<<endl;
	cout<<"\t Consultar expedientes "<<endl;
	cout<<"\t "<<endl;
	cout<<"\t Numero de folio a consultar: "<<endl;
	cout<<"\t "<<endl;
	cin>>folioaux;
	lec>>folio;
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
		
		if(folio == folioaux){
			system("cls");
			cout<<"\t "<<endl;
			cout<<"\t                                                        "<<endl;
			cout<<"\t Expediente clinico de"<<" "<<nombre<<endl;
			cout<<"\t "<<endl;
			cout<<"\t                                                        "<<endl;
			cout<<"\t Folio:"<<folio<<endl;
			cout<<"\t Nombre:"<<nombre<<endl;
			cout<<"\t Apellido paterno:"<<ape<<endl;
			cout<<"\t Apellido materno:"<<apeMa<<endl;
			cout<<"\t Fecha de nacimiento(dd/mm/aa):"<<edad<<endl;
			cout<<"\t Genero:"<<gene<<endl;
			cout<<"\t Estatura:"<<esta<<endl;
			cout<<"\t Peso:"<<peso<<endl;
			cout<<"\t Alergias:"<<ale<<endl;
			cout<<"\t Enfermedades cronicas:"<<enfe<<endl;
			cout<<"\t Discapacidades:"<<dis<<endl;
			cout<<"\t Tipo de sangre:"<<san<<endl;
			cout<<"\t Calle:"<<dom<<endl;
			cout<<"\t Numero exterior:"<<numEx<<endl;
			cout<<"\t Numero interior:"<<numIn<<endl;
			cout<<"\t Numero de celular:"<<numCel<<endl;
			cout<<"\t Numero de contacto:"<<numAux<<endl;
			cout<<"\t Numero de contacto:"<<numAux2<<endl;
			cout<<"\t Correo electronico:"<<correo<<endl;   
			cout<<"\t														"<<endl;

			cout<<"\t                                                       "<<endl;
			cout<<"\t "<<endl;
			cout<<"\t                                                       "<<endl;
			cout<<"\t Histrial familiar de"<<" "<<nombre <<endl;
			cout<<"\t "<<endl;
			cout<<"\t                                                       "<<endl;
			cout<<"\t Nombre: "<<nomb<<endl;
			cout<<"\t Apellido paterno: "<<ape2<<endl;
			cout<<"\t Apellido materno: "<<apeMa2<<endl;
			cout<<"\t Fecha de nacimiento(dd/mm/aa): "<<edad2<<endl;
			cout<<"\t Parentesco: "<<paren<<endl;
			cout<<"\t Genero: "<<gene2<<endl;
			cout<<"\t Estatura: "<<esta2<<endl;
			cout<<"\t Peso: "<<peso2<<endl;
			cout<<"\t Alergias: "<<ale2<<endl;
			cout<<"\t Enfermedades cronicas: "<<en<<endl;
			cout<<"\t Discapacidades: "<<dis2<<endl;
			cout<<"\t Tipo de sangre: "<<san2<<endl;
			cout<<"\t Calle: "<<dom2<<endl;
			cout<<"\t Numero exterior: "<<numEx2<<endl;
			cout<<"\t Numero interior: "<<numIn2<<endl;
			cout<<"\t Numero de celular: "<<numCel2<<endl;
			cout<<"\t Numero de contacto: "<<numaux<<endl;
			cout<<"\t Numero de contacto: "<<numaux2<<endl;
			cout<<"\t Correo electronico: "<<correo2<<endl;
			cout<<"\t                                                          "<<endl;
			cout<<"\t                                                          "<<endl;

			cout<<"\t                                                          "<<endl;
			cout<<"\t 														   "<<endl;
			cout<<"\t                                                          "<<endl;
			cout<<"\t Historial familiar de"<<" "<<nombre<<endl;
			cout<<"\t														   "<<endl;
			cout<<"\t                                                          "<<endl;
			cout<<"\t Nombre: "<<nomb2<<endl;
			cout<<"\t Apellido paterno: "<<ape3<<endl;
			cout<<"\t Apellido materno: "<<apeMa3<<endl;
			cout<<"\t Fecha de nacimiento(dd/mm/aa): "<<edad3<<endl;
			cout<<"\t Parentesco: "<<paren2<<endl;
			cout<<"\t Genero: "<<gene3<<endl;
			cout<<"\t Estatura: "<<esta3<<endl;
			cout<<"\t Peso: "<<peso3<<endl;
			cout<<"\t Alergias: "<<ale3<<endl;
			cout<<"\t Enfermedades cronicas: "<<en2<<endl;
			cout<<"\t Discapacidades: "<<dis3<<endl;
			cout<<"\t Tipo de sangre: "<<san3<<endl;
			cout<<"\t Calle: "<<dom3<<endl;
			cout<<"\t Numero exterior: "<<numEx3<<endl;
			cout<<"\t Numero interior: "<<numIn3<<endl;
			cout<<"\t Numero de celular: "<<numeCel<<endl;
			cout<<"\t Numero de contacto: "<<numeaux<<endl;
			cout<<"\t Numero de contacto: "<<numeaux2<<endl;
			cout<<"\t Correo electronico: "<<correo3<<endl;
			cout<<"\t                                                         "<<endl;
			cout<<"\t                                                          "<<endl;
			encontrado = true;
		}
		lec>>folio;
	}
	lec.close();
	
	if(!encontrado)
		cout<<"No existe "<<endl;
		system("pause");
}


void buscar(ifstream &lec){
	system("cls");
	lec.open("Expedientes.txt", ios::in);
	bool encontrado = false;
	string nombre, edad, gene, esta, peso, folio, folioaux;
	cout<<"Digite el folio: ";
	cin>>folioaux;
	lec>>folio;
	
	while(!lec.eof() && !encontrado){
		lec>>nombre;
		lec>>edad;
		lec>>gene;
		lec>>esta;
		lec>>peso;
		
		if(folio == folioaux){
			system("cls");
			cout<<"\t                                                  "<<endl;
			cout<<"\t												   "<<endl;
			cout<<"\t                                                  "<<endl;
			cout<<"\tRegistro de"<<" "<<nombre<<endl;
			cout<<"\t												   "<<endl;
			cout<<"Numero de folio: "<<folio<<endl;
			cout<<"Nombre: "<<nombre<<endl;
			cout<<"Edad: "<<edad<<endl;
			cout<<"Genero: "<<gene<<endl;
			cout<<"Estatura: "<<esta<<endl;
			cout<<"Peso: "<<peso<<endl;
			encontrado = true;
		}
		lec>>folio;
	}
	lec.close();
	
	if(!encontrado)
		cout<<"Dato no encontrado"<<endl;
		system("pause");
}

void agregarcita(ofstream &es){
	system("cls");
	string folio, nombre, ape, apeMa, fecha, gene, esta, peso;
	string date, fechaCit;
	es.open("Cita.txt", ios::out | ios::app);
	cout<<"\t 										   "<<endl;
	cout<<"\t                                          "<<endl;
	cout<<"\tCita Nueva"<<endl;
	cout<<"\t "<<endl;
	cout<<"\t                                         "<<endl;
	cout<<"\t Folio:                                  "<<endl;
	cin>>folio;
	cout<<"\t                                         "<<endl;
	cout<<"\t Nombre:                                 "<<endl;
	cin>>nombre;
	cout<<"\t                                         "<<endl;
	cout<<"\t Apellido paterno:                       "<<endl;
	cin>>ape;
	cout<<"\t                                         "<<endl;
	cout<<"\t Apellido materno:                       "<<endl;
	cin>>apeMa;
	cout<<"\t                                         "<<endl;
	cout<<"\t Genero:                                 "<<endl;
	cin>>gene;
	cout<<"\t                                         "<<endl;
	cout<<"\t Fecha de nacimiento(dd/mm/aa):          "<<endl;
	cin>>fecha;
	cout<<"\t                                         "<<endl;
	cout<<"\t Estatura:                               "<<endl;
	cin>>esta;
	cout<<"\t                                         "<<endl;
	cout<<"\t Peso:                                   "<<endl;
	cin>>peso;
	cout<<"\t                                         "<<endl;
	cout<<"\t Fecha actual(dd/mm/aa):                 "<<endl;
	cin>>date;
	cout<<"\t                                         "<<endl;
	cout<<"\t  Fecha de la proxima cita(dd/mm/aa):    "<<endl;
	cout<<"\t                                         "<<endl;
	cin>>fechaCit;

	es<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<gene<<" "<<fecha<<" "<<esta<<" "<<peso<<" "<<date<<" "<<fechaCit<<"\n";
	es.close();
}

void consultarci(ifstream &lec){
	system("cls");
	lec.open("Cita.txt", ios::in);
	bool encontrado = false;
	
	string folioaux1;

	string folio, nombre, ape, apeMa, gene, fecha, esta, peso;

	string date, fechaCit;
	cout<<"\t "<<endl;
	cout<<"\t "<<endl;
	cout<<"\t Consultar cita  "<<endl;
	cout<<"\t "<<endl;
	cout<<"\t "<<endl;
	cout<<"\tNumero de folio de la cita:        "<<endl;
	cout<<"\t                                    "<<endl;
	cout<<"\t                                    "<<endl;
	cin>>folioaux1;
	lec>>folio;

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

		if(folio == folioaux1){

			system("cls");
			cout<<"\t "<<endl;
			cout<<"\t "<<endl;
			cout<<"\t Citas de: "<<" "<<nombre <<endl;
			cout<<"\t "<<endl;
			cout<<"\t "<<endl;
			cout<<"\t "<<endl;
			cout<<"\t Folio: "<<folio<<endl;
			cout<<"\t Nombre: "<<nombre<<endl;
			cout<<"\t Apellido paterno: "<<ape<<endl;
			cout<<"\t Apellido materno: "<<apeMa<<endl;
			cout<<"\t Genero: "<<gene<<endl;
			cout<<"\t Fecha de nacimiento(dd/mm/aa): "<<fecha<<endl;
			cout<<"\t Estatura: "<<esta<<endl;
			cout<<"\t Peso: "<<peso<<endl;
			cout<<"\t Fecha de la visita(dd/mm/aa): "<<date<<endl;
			cout<<"\t Fecha de la proxima cita(dd/mm/aa): "<<fechaCit<<endl;
			cout<<"\t "<<endl;
			cout<<"\t "<<endl;
			encontrado = true;
		}
		lec>>folio;
	}
	lec.close();
	if(!encontrado)
		cout<<"No existe :c"<<endl;
		system("pause");
}

void editarcita(ifstream &lec){
	int opci;
	system("cls");
	
	string folioAux, nomAux2, apeAux2, apeMaAux2, fechaAux2, geneAux2, estaAux2, pesoAux2, dateAux2, fechaCitAux2;
	
	string folio, nombre, ape, apeMa, fecha, gene, esta, peso;

	string date, fechaCit;
	cout<<"\t 									 	    "<<endl;
	cout<<"\t	                                        "<<endl;
	cout<<"\t        	 	 Editar cita		        "<<endl;
	cout<<"\t  											"<<endl;
	cout<<"\t                                           "<<endl;
	cout<<"\t 1.Folio 								    "<<endl;
	cout<<"\t 2.Nombre								    "<<endl;
	cout<<"\t 3.Apellido paterno 					    "<<endl;
	cout<<"\t 4.Apellido materno 					    "<<endl;
	cout<<"\t 5.Genero								    "<<endl;
	cout<<"\t 6.Fecha de nacimiento(dd/mm/aa)		    "<<endl;
	cout<<"\t 7.Estatura							    "<<endl;
	cout<<"\t 8.Peso								    "<<endl;
	cout<<"\t 9.Fecha(dd/mm/aa)						    "<<endl;
	cout<<"\t 10.Fecha de la proxima cita(dd/mm/aa)	    "<<endl;
	cout<<"\t 11.Salir								    "<<endl;
	cout<<"\t Ingrese el dato: 						    "<<endl;                              
	cout<<"\t		  									"<<endl;
	cin>>opci;
	
	lec.open("Cita.txt", ios::in);
	ofstream editcita("EditarCita.txt", ios::out);

	switch(opci){

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



void borrarcita(ifstream &lec){
	
	string folioaux1;
	
	string folio, nombre, ape, apeMa, gene, fecha, esta, peso;

	string date, fechaCit;
	
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


void editarexp(ifstream &lec){
	int x;
	system("cls");
	
	
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


	string folio1, nomb2, apeAux1, apeMaAux1, edadAux1, geneAux1, estaAux1, pesoAux1, aleAux1, enfeAux1, disAux1, sanAux1, domAux1, numExAux1, numInAux1, numCelAux1, numaux1, numaux5, correoAux1;
    cout<<"\t "<<endl;
    cout<<"\t "<<endl;
	cout<<"\t             Editar expediente            "<<endl;
	cout<<"\t "<<endl;
	cout<<"\t 1.Folio                                  "<<endl;
	cout<<"\t 2.Nombre                                 "<<endl;
	cout<<"\t 3.Apellido paterno                       "<<endl;
	cout<<"\t 4.Apellido materno                       "<<endl;
	cout<<"\t 5.Fecha de nacimiento(dd/mm/aa)          "<<endl;
	cout<<"\t 6.Genero                                 "<<endl;
	cout<<"\t 7.Estatura                               "<<endl;
	cout<<"\t 8.Peso                                   "<<endl;
	cout<<"\t 9.Alergias                               "<<endl;
	cout<<"\t 10.Enfermedades cronicas                 "<<endl;
	cout<<"\t 11.Discapacidades                        "<<endl;
	cout<<"\t 12.Tipo de sangre                        "<<endl;
	cout<<"\t 13.Calle                                 "<<endl;
	cout<<"\t 14.Numero exterior                       "<<endl;
	cout<<"\t 15.Numero interior                       "<<endl;
	cout<<"\t 16.Numero de celular                     "<<endl;
	cout<<"\t 17.Numero de contacto                    "<<endl;
	cout<<"\t 18.Numero de contacto                    "<<endl;
	cout<<"\t 19.Correo electronico                    "<<endl;
	cout<<"\t 20.Salir                                 "<<endl;
	cout<<"\tIngrese la opcion a editar:"<<endl;
	cin>>x;                                    
	
	lec.open("Expediente.txt", ios::in);
	ofstream editexp("EditarExp.txt", ios::out);
	switch(x){
		
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


void borrarexp(ifstream &lec){
	
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
	
	string folio1;
	
	string nomb, ape2, apeMa2, edad2, paren, gene2, esta2, peso2, ale2, en, dis2, san2, dom2, numEx2, numIn2;
	string numCel2, numaux, numaux2, correo2;
	

	string nomb2, ape3, apeMa3, edad3, paren2, gene3, esta3, peso3, ale3, en2, dis3, san3, dom3, numEx3, numIn3;
	string numeCel, numeaux, numeaux2, correo3;
	
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

void calcular(ofstream &es){
	
}


void menuuser(){
	ofstream(esc);
	ifstream(lec);

	
	int opcion;
	
	system("cls");
	cout<<endl<<"\t ";
	cout<<endl<<"\t ";
	cout<<endl<<"\t        Menú Usuario       		 ";
	cout<<endl<<"\t ";
	cout<<endl<<"\t 1. Registrar Expediente          ";
	cout<<endl<<"\t ";
	cout<<endl<<"\t 2. Consultar Expediente          ";
	cout<<endl<<"\t ";
	cout<<endl<<"\t 3. Editar Expediente             ";
	cout<<endl<<"\t ";
	cout<<endl<<"\t 4. Borra Expediente              ";
	cout<<endl<<"\t ";
	cout<<endl<<"\t 5. Registrar Cita                ";
	cout<<endl<<"\t||";
	cout<<endl<<"\t 6. Consultar Cita                ";
	cout<<endl<<"\t ";
	cout<<endl<<"\t 7. Editar Cita                   ";
	cout<<endl<<"\t ";
	cout<<endl<<"\t 8. Borrar Cita                   ";
	cout<<endl<<"\t ";
	cout<<endl<<"\t 0. Salir                         ";
	cout<<endl<<"\t ";
	cout<<endl<<"\tOpcion:";
	cin>>opcion;

		switch(opcion){
			
			case 1:
				system("cls");
				agregar(esc);
				menuuser();
			
			break;
			
		
			case 2:
				system("cls");
				consultar(lec);
				menuuser();
				
			break;
			
		
			case 3:
				system("cls");
				editarexp(lec);
				menuuser();
			break;
			
		
			case 4:
				system("cls");
				borrarexp(lec);
				menuuser();
				
			break;
						
			
			case 5:
				system("cls");
				agregarcita(esc);
				menuuser();
			break;
			
			
			case 6:
				system("cls");
				consultarci(lec);
				menuuser();
			break;
				
			
			case 7:
				system("cls");
				editarcita(lec);
				menuuser();
			break;
				
			
			case 8:
				system("cls");
				borrarcita(lec);
				menuuser();
			break;
			
			
			case 0:
				
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
		cout<<"\n\t____________________________________________";
		foutput<<"\n___________________________________________";
		cout<<"\n\t|\n\t      Datos Generales       ";
		cout<<endl<<"\t                             ";
		foutput<<"\n\t|\n\t     Datos Generales     ";
		
		cout<<"\n\t|\n\tNombre: ";
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
		
		
		cout<<"\t|____________________________________";
		foutput<<"\n______|___________________________";
		
		
		cout<<"\n\t| Datos ingresados correctamente";
	
    	finput.close();
    	foutput.close();
		fflush(stdin);
    	menuuser();
	}else{
		cout<<"\n\t Error ";
	}
}

void insertarDatos(Nodo *&frente, Nodo *&fin, ICO pacientes){

	Nodo *n_nodo = new Nodo();
	
	n_nodo -> pacientes = pacientes;
	
	n_nodo -> siguiente = NULL;
	
	if(c_vacia(frente)){
		frente = n_nodo;
	}else{
		fin -> siguiente = n_nodo;
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

