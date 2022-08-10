#ifdef __MSDOS__
    #include <iostream.h>
    #include <stdlib.h>
#else
    #include <iostream>
    #include <cstdlib>
#endif
#include <conio.h>
#include <string.h>
using namespace std;
int main(){

string usuario;
string pin;
int estatus=0, cant_intentos=0;
do{
	system("cls");
	
cout<<"\nusuario:\n";
cin>>usuario;
cout<<"\npin:\n";
cin>>pin;
if(usuario!="XSCA"  && pin!="123456")
{ cant_intentos++;
	cout<<"\n datos erroneos";
	
}
else 
estatus=1;
}while(cant_intentos<2 &&estatus==0);
system("pause");
if(estatus==1){
	cout<<"\nbienvenido a cajero\n";
} 
else{
	cout<<"\n demasiados intentos";
}
}
int main (void)
{
    float IMC, altura_en_m, peso_en_kg;
    cout << "Ingresa el valor de altura en m: ";
    cin >> altura_en_m;
    cin.get();
    cout << "Ingresa el valor de peso en kg: ";
    cin >> peso_en_kg;
    cin.get();
    IMC=peso_en_kg/altura_en_m/altura_en_m;
    if(IMC<16)
        cout << "Criterio de ingreso en hospital." << endl;
    if(IMC>=16&&IMC<18)
        cout << "Bajo peso." << endl;
        cout << "Lacteos y derivados: uno de los alimentos mas adecuados " << endl ;
		cout << "para subir de peso es la leche entera, pues cuenta con " << endl ;
		cout << "un alto contenido en calorias, calcio y grasas saludables." << endl;
    if(IMC>=18&&IMC<25)
        cout << "Peso normal (saludable). Sigue comiendo bien y sigue haciendo ejercicio" << endl;
    if(IMC>=25&&IMC<30)
        cout << "Sobrepeso (obesidad de grado I)."<< endl; 
		cout << "Come abundantes frutas y verduras crudas" << endl ;
		cout << "o cocidas , lácteos desnatados, cereales integrales." << endl;
    if(IMC>=30&&IMC<35)
        cout << "Sobrepeso cronico (obesidad de grado II). " << endl;
		cout << "La comida debe ser simple, pero con suficiente valor nutricional." << endl ;
		cout << "El cuerpo del paciente no debe sufrir de una falta" << endl ;
		cout << "de vitaminas, microelementos, aminoácidos, etc." << endl;
    if(IMC>=35&&IMC<40)
        cout << "Obesidad grado III ." << endl;
		cout << "Realizar aeróbic acuático, gimnasia." << endl; 
		cout << "Es mejor empezar con una luz de deportes, aumentando" << endl ;
		cout << "gradualmente la carga. Inmediatamente hacer entrenamiento" << endl ; 
		cout << "de fuerza no se puede. Esto puede dañar el cuerpo." << endl;
    if(IMC>=40)
        cout << "Obesidad grado IV." << endl; 
		cout << "El tratamiento comienza con un examen completo " << endl;
		cout << "de todo el cuerpo para determinar todas las " << endl ;
		cout << "patologías que lo acompañan. Es necesario llevarlo" << endl ;
		cout << "a cabo bajo el control de los médicos: es un" << endl ;
		cout << "un cardiólogo con un nutricionista y un " << endl ;
		cout << "psicólogo, y así sucesivamente." << endl;
    cout << "Valor de IMC: " << IMC << endl;
    cout << endl;
    system ("pause");
    return EXIT_SUCCESS;
}
