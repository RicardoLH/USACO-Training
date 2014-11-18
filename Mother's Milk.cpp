/*
ID: t_a_k_e1
PROG: milk3
LANG: C++
*/
#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <sstream>
#include <algorithm>

using namespace std;
short A;
short B;
short C;
short soluciones[50];
short cont = -1;
bool visitados[22][22][22];

void busca(short i, short j, short k ){
    if( !visitados[i][j][k] ){
        visitados[i][j][k] = true;
        if( i == 0 ){
            cont++;
            soluciones[cont] = k;
        }
        short a = i, b = j, c = k;
        if( b != 0 ){
            // De 2 a 1
            a += b;
            b = 0;
            if( a > A ){
                b = a - A;
                a = A;
            }
            busca(a,b,c);
            a = i;
            b = j;
            c = k;
            // de 2 a 3
            c += b;
            b = 0;
            if( c > C ){
                b = c - C;
                c = C;
            }
            busca(a,b,c);
        }
        if( a != 0 ){
            // de 1 a 2
            a = i;
            b = j;
            c = k;
            b += a;
            a = 0;
            if( b > B ){
                a = b - B;
                b = B;
            }
            busca(a,b,c);
            a = i;
            b = j;
            c = k;
            // de 1 a 3
            c += a;
            a = 0;
            if( c > C ){
                a = c - C;
                c = C;
            }
            busca(a,b,c);

        }
        if( c != 0 ){
            a = i;
            b = j;
            c = k;
            // de 3 a 1
            a += c;
            c = 0;
            if( a > A ){
                c = a - A;
                a = A;
            }
            busca(a,b,c);
            // de 3 a 2
            a = i;
            b = j;
            c = k;
            b += c;
            c = 0;
            if( b > B ){
                c = b - B;
                b = B;
            }
            busca(a,b,c);
        }

    }
}
bool criterio(short a, short b){
    return a < b;
}
int main()
{
    ofstream fout ("milk3.out");
    ifstream fin ("milk3.in");
    fin>>A>>B>>C;
    busca(0,0,C);
    sort(soluciones, soluciones+cont+1,criterio);

    for( int i = 0; i < cont; i++ ){
        fout<< soluciones[i]<<" ";
    }
    fout<<soluciones[cont]<<endl;
    return 0;
}
