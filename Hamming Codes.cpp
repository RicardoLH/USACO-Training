/*
ID: t_a_k_e1
PROG: hamming
LANG: C++
*/
#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <sstream>
#include <algorithm>
#include <math.h>

using namespace std;
int n;
int b;
int d;
int p;
int solucion[66];
int cont;
int hamm[260][260];
ofstream fout ("hamming.out");
    ifstream fin ("hamming.in");
int hamming( int a, int b ){
    int distancia = 0;
    while( a != 0 || b != 0 ){
        if( a % 2 != b % 2 ){
            distancia++;
        }
        a = a >> 1;
        b = b >> 1;
    }
    return distancia;
}
bool encuentra( int k ){
    if( cont == n ){
        for( int i = 1; i <= n; i++ ){
            if( i % 10 == 0 || i == n){
                fout<<solucion[i-1]<<endl;
            }else{
                fout<<solucion[i-1]<<" ";
            }
        }
        return true;
    }else{
        for( int i = 0; i < cont; i++ ){
            if( hamm[solucion[i]][k] < d ){
                return false;
            }
        }
        solucion[cont] = k;
        cont++;
        for( int i = (k+1); i <= p; i++ ){
            if( hamm[k][i] >= d ){
                if( encuentra(i) ){
                    break;
                }
            }
        }
    }
}
int main(){

    fin>>n;
    fin>>b;
    fin>>d;
    p = pow(2,b);
    for( int i = 0; i <= p; i++ ){
        for( int j = i+1; j <= p; j++ ){
            hamm[i][j] = hamming(i,j);
        }
    }
    encuentra(0);
}
