/*
ID: t_a_k_e1
PROG: palsquare
LANG: C++
*/
#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <sstream>

using namespace std;
int b;
string chars="0123456789ABCDEFGHIJ";
string convertir( int n){
    string numero = "";
    while(n>0){
        numero= chars.at(n%b) + numero;
        n/=b;
   }
   return numero;
}
bool esPalindromo( string palabra ){
    int inicio = 0;
    int fin = palabra.length()-1;
    while( inicio != fin && fin > inicio){
        if( palabra.at(inicio) != palabra.at(fin) ){
            return false;
        }
        fin--;
        inicio++;
    }
    return true;
}

int main() {
    ofstream fout ("palsquare.out");
    ifstream fin ("palsquare.in");
    fin>> b;
    string cuadrado = "";
    string raiz = "";
    for( int i = 1; i <= 300; i++ ){
        cuadrado = convertir(i*i);
        if( esPalindromo(cuadrado) ){
            raiz = convertir(i);
            fout<< raiz << " " << cuadrado << endl;
        }
    }
    return 0;
}
