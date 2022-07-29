#include <iostream>
using namespace std;

int main ()
{
    int acd = 1, numLineas;
    cout << "Ingrese el numero de lineas para su arbol: ";
    cin >> numLineas;
    for (int x = numLineas; x != 0; x--){
        cout.width(x);
        for (int n = 0; n < acd; n++){
            cout << "*";
        }
        acd += 2;
        cout << endl;
    }
    for (int x = ((acd - 2) / 2 - 3) / 2; x != 0; x--){
        cout.width((acd * 40) / 100);
        for (int n = 0; n < (acd * 20) / 100; n++){
            cout << "*";
        }
        cout << endl;
    }
    for (int x = 2; x != 0; x--){
        cout.width((acd * 30) / 100);
        for (int n = 0; n < (acd * 40) / 100; n++){
            cout << "*";
        }
        cout << endl;
    }
   
    return 0;
}
