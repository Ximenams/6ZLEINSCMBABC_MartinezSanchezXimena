
#include <stdio.h>
#include <algorithm>
#include <cstring>

#define MAX 1005  

int padre[ MAX ]; 

void MakeSet( int n ){
    for( int i = 1 ; i <= n ; ++i ) padre[ i ] = i;
}

int Find( int x ){
    return ( x == padre[ x ] ) ? x : padre[ x ] = Find( padre[ x ] );
}

void Union( int x , int y ){
    padre[ Find( x ) ] = Find( y );
}

bool sameComponent( int x , int y ){
    if( Find( x ) == Find( y ) ) return true;
    return false;
}

int V , E;     
struct Edge{
    int origen;     
    int destino;    
    int peso;      
    Edge(){}

    bool operator<( const Edge &e ) const {
        return peso < e.peso;
    }
}arista[ MAX ];     
Edge MST[ MAX ];     

void Kruskal(){
    int origen , destino , peso;
    int total = 0;          //Peso total del MST
    int numAristas = 0;     //Numero de Aristas del MST

    MakeSet( V );           //Inicializamos cada componente
    std::sort( arista , arista + E );    //Ordenamos las aristas por su comparador

    for( int i = 0 ; i < E ; ++i ){     //Recorremos las aristas ya ordenadas por peso
        origen = arista[ i ].origen;    //V?rtice origen de la arista actual
        destino = arista[ i ].destino;  //V?rtice destino de la arista actual
        peso = arista[ i ].peso;        //Peso de la arista actual

        if( !sameComponent( origen , destino ) ){  //Evito ciclos
            total += peso;              //Incremento el peso total del MST
            MST[ numAristas++ ] = arista[ i ];  //Agrego al MST la arista actual
            Union( origen , destino );  //Union de ambas componentes en una sola
        }
    }

  
    if( V - 1 != numAristas ){
        puts("No existe MST valido para el grafo ingresado, el grafo debe ser conexo.");
        return;
    }
    puts( "-----El MST encontrado contiene las siguientes aristas-----");
    for( int i = 0 ; i < numAristas ; ++i )
        printf("( %d , %d ) : %d\n" , MST[ i ].origen , MST[ i ].destino , MST[ i ].peso ); //( vertice u , vertice v ) : peso

    printf( "El costo minimo de todas las aristas del MST es : %d\n" , total );
}

int main(){
    int mst;

    scanf("%d %d" , &V , &E );

    for( int i = 0 ; i < E ; ++i )
        scanf("%d %d %d" , &arista[ i ].origen , &arista[ i ].destino , &arista[ i ].peso );

    Kruskal();

    return 0;
}
