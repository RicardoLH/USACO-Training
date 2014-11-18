/*
ID: t_a_k_e1
PROG: calfflac
LANG: C++
*/
#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <algorithm>

using namespace std;
int mayor;
int pMayor;
int pFin;
struct caracter{
    char c;
    int p;
};
char original[20000];
caracter largo[20000];
int i;
int j;
int main() {
    ofstream fout ("calfflac.out");
    ifstream fin ("calfflac.in");
    char c;
    i = 0;
    j = 0;
    while ( fin.get(c) ) {
            original[i] = c;
            i++;
            if ( isalpha(c) ) {
                largo[j].c = tolower(c);
                largo[j].p = i;
                j++;
            }
    }
    mayor = 1;
    pMayor = 0;
    // impar
    for( int a = 1; a <= j; a++ ){
        int b = a+1;
        int c = a-1;
        int contador = 0;
        //cout<< "centro: "<<largo[a].c << endl;
        while( c >= 0 && b <= j && largo[b].c == largo[c].c ){
            c--;
            b++;
            contador += 2;
        }
        //cout<< "contador: "<< contador<<endl;
        if( contador > mayor ){
            mayor = contador +1;
            pMayor = c+1;
            pFin = b -1;
        }

        contador = 0;
        c = a;
        b = a+1;
        while( c >= 0 && b <= j && largo[b].c == largo[c].c ){
            contador += 2;
            c--;
            b++;
        }
        if( contador > mayor ){
            mayor = contador;
            pMayor = c+1;
            pFin = b -1;
        }
    }
    fout<< mayor << endl;
    int k = 0;
    for( int a = 0; a <= i; a++ ){
        if( isalpha(original[a]) ){
            if( k == pMayor ){
                int cont = pMayor;
                int i = a;
                while(cont <= pFin ){
                    if( isalpha(original[i]) ){
                        cont++;
                    }
                    fout<< original[i];
                    i++;
                }
            }
            k++;
        }

    }
    fout<< endl;

    return 0;
}

