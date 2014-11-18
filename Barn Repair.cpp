/*
ID: t_a_k_e1
PROG: barn1
LANG: C++
*/
#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <sstream>
#include <algorithm>

using namespace std;
int m;
int s;
int c;
int total;
struct Pesebre{
    int id;
    bool inicio;
    bool fin;
};
Pesebre pesebrera[202];
int ordenar[202];
bool comparar (int i,int j) {
     return (i<j);
}
int main() {
    ofstream fout ("barn1.out");
    ifstream fin ("barn1.in");
    fin>> m;
    fin>> s;
    fin>> c;
    for( int i = 0; i < c; i++ ){
        fin>> ordenar[i];
    }
    sort(ordenar, ordenar+c);
    for( int i = 0; i < c; i++ ){
        pesebrera[i].id = ordenar[i];
    }
    pesebrera[0].inicio = true;
    pesebrera[c-1].fin = true;
    total = pesebrera[c-1].id + 1 - pesebrera[0].id;
    int diferencia = 0;
    int temp = 0;
    int posicion = 0;

    for( int j = 2; j <= m; j++ ){
        for( int i = 0; i < c; i++ ){
            temp = pesebrera[i+1].id - pesebrera[i].id - 1;
            if( temp > diferencia && !pesebrera[i].fin && !pesebrera[i+1].inicio ){
                diferencia = temp;
                posicion = i;
            }
        }
        pesebrera[posicion].fin = true;
        pesebrera[posicion+1].inicio = true;
        total -= diferencia;
        diferencia = 0;
    }
    fout<< total<< endl;
    return 0;
}
