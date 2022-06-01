#include<iostream>
#include<conio.h>
using namespace std;
int main(){
	int numeros[3][3];
	
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
		
		cout<<"Digite un numero ["<<i<<"]["<<j<<"]: ";
		cin>>numeros[i][j];
	}
}
cout<<"Matriz Original\n";
for(int i=0;i<4;i++){
	for (int j=0;j<4;j++){
		cout<<numeros[i][j]<<" ";
	}
	cout<<"\n";
}


cout<<"\nMariz Transpuesta\n";
for(int i=0;i<4;i++){
	for(int j=0;j<4;j++){
		cout<<numeros[j][i]<<" ";
	}
	cout<<"\n";
}
	
	getch();
	return 0;
}
