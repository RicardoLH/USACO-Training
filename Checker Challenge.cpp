/*
ID: t_a_k_e1
PROG: checker
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
int k;
bool diagonal1[148];
bool diagonal2[148];
bool fila[15];
int soluciones[15];

ofstream fout ("checker.out");
ifstream fin ("checker.in");
void marcaDiagonal( int i, int j){
    diagonal1[j+i] = true;
    diagonal2[(n-j-1)+i] = true;
}
bool sePuedeDiagonal( int i, int j ){
    return !( diagonal1[j+i] || diagonal2[(n-j-1)+i] );
}
void desmarcaDiagonal( int i, int j ){
    diagonal1[j+i] = false;
    diagonal2[(n-j-1)+i] = false;
}

void marcaFila( int i ){
    fila[i] = true;
}
void desmarcaFila( int i ){
    fila[i] = false;
}
bool sePuedeFila( int i ){
    return !(fila[i]);
}
void coloca( int c ){
    if( c == n ){
        if( k < 3 ){
            for( int i = 0; i < n-1; i++ ){
                fout<<(soluciones[i])+1<<" ";
            }
            fout<<(soluciones[n-1])+1;
            fout<<endl;
        }
        k++;
        return;
    }else{
        for( int i = 0; i < n; i++ ){
            if( sePuedeDiagonal(i,c) && sePuedeFila(i) ){
                marcaFila(i);
                marcaDiagonal(i,c);
                soluciones[c] = i;
                coloca(c+1);
                desmarcaFila(i);
                desmarcaDiagonal(i,c);
            }
        }
    }
}
int main(){
    fin>>n;
    coloca(0);
    fout<<k<<endl;
}
