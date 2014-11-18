/*
ID: t_a_k_e1
PROG: dualpal
LANG: C++
*/
#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <sstream>

using namespace std;
string chars="0123456789ABCDEFGHIJ";
char caracteres[20] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J'};
int n;
int k;
int b;
int palindromos;
int actual;
string convertir(int a){
    string numero = "";
    while( a > 0 ){
        numero = caracteres[a%b] + numero;
        a /=b;
   }
   return numero;
}
bool esPalindromo( string palabra ){
    if( palabra.length() == 1 ){
        return true;
    }
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
    ofstream fout ("dualpal.out");
    ifstream fin ("dualpal.in");
    fin>> n;
    fin>> k;
    actual = k+1;
    string num = "";
    int contador = 0;
    while( palindromos < n ){
        contador = 0;
        for( int i = 2; i <= 10; i++ ){
            b = i;
            num = convertir(actual);
            if( esPalindromo(num) ){
                contador++;
            }
            if( contador == 2 ){
                palindromos++;
                fout<< actual << endl;
                break;
            }
        }
        actual++;

    }


    return 0;
}
