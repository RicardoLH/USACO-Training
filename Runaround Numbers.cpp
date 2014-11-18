/*
ID: t_a_k_e1
PROG: runround
LANG: C++
*/
#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <sstream>
#include <algorithm>
#include <math.h>
#define ll unsigned long long int
using namespace std;
struct Digito{
    int a;
    bool inicio;
    bool visitado;
};
ll n;
ll k;
bool encontrado;
Digito digitos[10];
int cont;
void mapear( int num ){
    if( num < 10 ){
        digitos[cont].a = num;
        digitos[cont].visitado = false;
        cont++;
        return;
    }
    mapear( num/10 );
    digitos[cont].a = num%10;
    digitos[cont].visitado = false;
    cont++;
}
bool circular( int num ){
    digitos[0].visitado = true;
    digitos[0].inicio = true;
    for( int i = 0; i < cont; i++ ){
        if( digitos[i].a == 0 ){
            return false;
        }
    }
    for( int i = 0; i < cont; i++ ){
        for( int j = 0; j < cont; j++ ){
            if( digitos[i].a == digitos[j].a && i != j ) {
                return false;
            }
        }
    }
    int i = digitos[0].a;
    if( i >= cont ){
        i = i % cont;
    }
    int ant = 0;
    while( i != 0 ){
        if( !digitos[i].visitado && digitos[ant].a != digitos[i].a ){
            digitos[i].visitado = true;
            ant = i;
            i += digitos[i].a;
        }else{
            return false;
        }
        if( i >= cont ){
            i = i % cont;
        }
    }
    if ( digitos[ant].a == digitos[0].a ){
        return false;
    }
    for( int i = 1; i <cont; i++ ){
        if( !digitos[i].visitado ){
            return false;
        }
    }
    return true;
}
int main(){
    ofstream fout ("runround.out");
    ifstream fin ("runround.in");
    fin>>n;
    int k = n+1;
    while( !encontrado ){
        cont = 0;
        mapear(k);
        if( circular(k) ){
            fout<<k<<endl;
            break;
        }
        k++;
    }

}
