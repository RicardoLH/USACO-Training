/*
ID: t_a_k_e1
PROG: lamps
LANG: C++
*/

/*
	SOY DEMASIADO NOOB Y NO HICE LA BUSQUEDA EN AMPLITUD EN BUSQUEDA DE LAS SOLUCIONES, SOLO HAY 16 COMBINACIONES POSIBLES DE LAS SOLUCIONES
*/
#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <sstream>
#include <algorithm>
#include <math.h>
#define ll unsigned long long int
#define ES_SOLUCION if( esSolucion() ) cont++ ;

using namespace std;
int n;
int c;
bool soluciones[20][102];
int estadoT[102];
int estadoF[102];
int cont;
int ext1 = 0;
int ext2 = 0;
void aplica( int k ){
    if( k == 1 ){
        for( int i = 1; i <= n; i++ ){
            soluciones[cont][i] = !soluciones[cont][i];
        }
    }else if( k == 2 ){
        for( int i = 1; i <= n; i += 2 ){
            soluciones[cont][i] = !soluciones[cont][i];
        }
    }else if( k == 3 ){
        for( int i = 2; i <= n; i += 2 ){
            soluciones[cont][i] = !soluciones[cont][i];
        }
    }else if( k == 4 ){
        for( int i = 0; i <= n; i ++ ){
            soluciones[cont][(3*i)+1] = !soluciones[cont][(3*i)+1];
        }
    }
}
// 1, 12, 13, 14, 1234,124,123,134,2,23,234,24,34,3,4
void inicializa(){
    for( int i = 1; i <= n; i++ ){
        soluciones[cont][i] = true;
    }
}
void muestra(){
    cout<<endl;
    for( int i = 1; i <= n; i++ ){
        cout<<soluciones[cont][i];
    }
    cout<<endl;
}
bool esSolucion(){
    muestra();
    for( int i = 0; i < ext1; i++ ){
        if( !soluciones[cont][estadoT[i]] ){
            return false;
        }
    }
    for( int i = 0; i < ext2; i++ ){
        if( soluciones[cont][estadoF[i]] ){
            return false;
        }
    }
    for( int i = 0; i < cont; i++ ){
        bool igual = true;
        for( int j = 1; j <= n; j++ ){
            if( soluciones[cont][j] != soluciones[i][j] ){
                igual = false;
            }
        }
        if( igual ){
            return false;
        }
    }
    return true;
}

void encuentra(){
    if( c % 2 != 0 && c >= 1 ){
        inicializa();
        aplica(1);
        ES_SOLUCION
    }
    if( c % 2 == 0 && c >= 2 ){
        inicializa();
        aplica(2);aplica(3);
        ES_SOLUCION
    }
    if( c % 2 == 0 && c >= 2 ){
        inicializa();
        aplica(3);aplica(4);
         ES_SOLUCION
    }
    if( c % 2 != 0 && c >= 3 ){
        inicializa();
        aplica(1);aplica(2);aplica(4);
        ES_SOLUCION
    }
    if( c % 2 != 0 && c >= 1 ){
        inicializa();
        aplica(2);
        ES_SOLUCION
    }

    if( c % 2 == 0 && c >= 2 ){
        inicializa();
        aplica(1);aplica(3);
        ES_SOLUCION
    }
    if( c % 2 != 0 && c >= 1 ){
        inicializa();
        aplica(4);

        ES_SOLUCION
    }
    if( c % 2 == 0 && c >= 4 ){
        inicializa();
        aplica(1);aplica(2);aplica(3);aplica(4);
        ES_SOLUCION
    }
    if( c % 2 == 0 && c >= 2 ){
        inicializa();
        aplica(1);aplica(4);
        ES_SOLUCION
    }
    if( c % 2 != 0 && c >= 3 ){
        inicializa();
        aplica(2);aplica(3);aplica(4);
        ES_SOLUCION
    }
    if( c % 2 != 0 && c >= 1 ){
        inicializa();
        aplica(3);
        ES_SOLUCION
    }
    if( c % 2 == 0 && c >= 2 ){
        inicializa();
        aplica(1);aplica(2);
        ES_SOLUCION
    }
    if( c % 2 == 0 && c >= 2 ){
        inicializa();
        aplica(2);aplica(4);
        ES_SOLUCION
    }
    if( c % 2 != 0 && c >= 3 ){
        inicializa();
        aplica(1);aplica(3);aplica(4);
        ES_SOLUCION
    }
    if( c % 2 != 0 && c >= 3 ){
        inicializa();
        aplica(1);aplica(2);aplica(3);
        ES_SOLUCION
    }
    if( c % 2 == 0 && c >= 0 ){
        inicializa();
        ES_SOLUCION
    }

}
int main(){
    ofstream fout ("lamps.out");
    ifstream fin ("lamps.in");
    fin>>n;
    fin>>c;
    int temp = 0;
    fin>>temp;
    while( temp != -1 ){
        estadoT[ext1] = temp;
        ext1++;
        fin>> temp;
    }
    temp = 0;
    fin>>temp;
    while( temp != -1 ){
        estadoF[ext2] = temp;
        ext2++;
        fin>> temp;
    }
    encuentra();
    if( cont == 0 ){
        fout<<"IMPOSSIBLE"<<endl;
    }else{
        for( int i = 0; i < cont; i++ ){
            for( int j = 1; j <= n; j++ ){
                fout<<soluciones[i][j];
            }
            fout<<endl;
        }
    }
}
