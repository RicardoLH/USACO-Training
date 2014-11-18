/*
ID: t_a_k_e1
PROG: frac1
LANG: C++
*/
#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <sstream>
#include <algorithm>

using namespace std;

struct Fraccion{
    double a;
    double b;
    double valor;
};
Fraccion fracciones[13000];
int cont;
int n;
bool ordenar( Fraccion a, Fraccion b ){
    bool val;
    val = a.valor < b.valor;
    return val;
}
int mcd( int a, int b ){
    if( b == 0 ){
        return a;
    }
    return mcd( b,a%b );
}
int main(){
    ofstream fout ("frac1.out");
    ifstream fin ("frac1.in");
    fin>>n;

    for( int i = 1; i <= n; i++ ){
        for( int j = 1; j <= i; j++ ){
            fracciones[cont].a = j;
            fracciones[cont].b = i;
            fracciones[cont].valor = fracciones[cont].a  / fracciones[cont].b;
            cont++;
        }
    }
    sort(fracciones, fracciones + cont,ordenar);
    fout<<"0/1"<<endl;
    fout<<fracciones[0].a<<"/"<<fracciones[0].b<<endl;
    for( int i = 1; i < cont; i++ ){
        if( fracciones[i].valor != fracciones[i-1].valor ){
            int num = mcd(fracciones[i].a,fracciones[i].b);
            fout<<(fracciones[i].a / num ) <<"/"<<(fracciones[i].b / num ) <<endl;
        }

    }

}
