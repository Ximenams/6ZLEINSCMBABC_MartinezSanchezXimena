#include <iostream>

using namespace std;
 
void calcularEdad( int anioAct , int mesAct, int diaAct, int anioNac, int mesNac, int diaNac);

 

int main ()

{

    int anioAct;  //Año Actual

    int mesAct; //Mes actual

    int diaAct; //Fecha actual

 

    int anioNac; //Año de nacimiento

    int mesNac; //Mes de nacimiento

    int diaNac; //Fecha de nacimiento

 

    cout << "\n\n Programa que calcula la Edad, Mes y Dia\n\n";

    cout << "Ingrese Año Actual: ";   cin >> anioAct;

    cout << "Ingrese Mes Actual: ";   cin >> mesAct;

    cout << "Ingrese Dia Actual: ";  cin >> diaAct;

 

    cout << "\n Ingrese Año Nacimiento: ";  cin >> anioNac;

    cout << "\n Ingrese Mes de Nacimiento: ";  cin >> mesNac;

    cout << "\nIngrese Dia de Nacimiento: ";  cin >> diaNac;

 

    calcularEdad( anioAct , mesAct, diaAct, anioNac, mesNac, diaNac);

 

    return 0;

}
 

//Definicion de la Funcion

void calcularEdad( int anioAct , int mesAct, int diaAct, int anioNac, int mesNac, int diaNac)

{

    int respFech , respMes;

 

    if ( diaAct < diaNac  )

    {   //En caso de ser menor la fecha actual que el nacimiento

        diaAct = diaAct + 30; 

        mesAct = mesAct - 1; 

        respFech =  diaAct - diaNac;

    }

    else //En caso de ser mayor la fecha actual que el nacimiento

        respFech =  diaAct - diaNac; 

 

    if( mesAct < mesNac )

    {   //En caso de ser menor el mes actual que el nacimiento

        mesAct = mesAct + 12; 

        anioAct = anioAct - 1 ; 

        respMes = mesAct - mesNac; 

    } else 

        respMes = mesAct - mesNac; 

 
    cout << "\nUd. tiene:\n";

    cout << " Edad: " <<anioAct - anioNac << endl; 

    cout << " Mes: " << respMes << endl; 

    cout << " Dia: " << respFech << endl; 

}
