/*
ID: t_a_k_e1
PROG: sort3
LANG: C++
*/
#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <sstream>
#include <algorithm>

using namespace std;
int n;
int numeros[1002];
int cubeta[4];
int cont;
void cambia( int numero, int posicion ){
    int inicio = 0;
    int pCambio = 0;
    int fin = cubeta[1];

    if( numero == 2 ){
        inicio = cubeta[1];
        fin = cubeta[1] + cubeta[2];
        pCambio = cubeta[1];
    }

    for( int i = inicio; i < fin; i++ ){
        if( numeros[i] > numeros[pCambio] ){
            pCambio = i;
        }
    }
    if( numeros[pCambio] != numero ){
        numeros[posicion] = numeros[pCambio];
        numeros[pCambio] = numero;
        cont++;
    }



}
int main(){
    ofstream fout ("sort3.out");
    ifstream fin ("sort3.in");
    fin>>n;
    for( int i = 0; i < n; i++ ){
        fin>>numeros[i];
        cubeta[numeros[i]]++;
    }
    for( int i = (n-1); i >= 0; i-- ){
        if( numeros[i] == 1 ){
            cambia(1, i );
        }
    }
    for( int i = (n-1); i >= 0; i-- ){
        if( numeros[i] == 2 ){
            cambia(2, i );
        }
    }
    fout<<cont<<endl;

}
