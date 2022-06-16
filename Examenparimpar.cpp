#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int main (){
	int numero = 5 ;

	bool respuesta = false ;
	
	cout << "Introduce un numero para saber si es par o impar \n";
	cin >> numero;
	
	
	if(numero%2 == 0){
		cout<<"\n Es par \n";
	}else{
		cout <<"\n Es impar \n";
	}
	
	system("PAUSE");
}
