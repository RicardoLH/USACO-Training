/*
ID: t_a_k_e1
PROG: numtri
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
int triangulo[1001][1001];
int memo[1001][1001];
int ms( int i, int j ){ // i: FILA j: COLUMNA
    if( i > n ){
        return 0;
    }
    if( memo[i][j] == -1 ){
        memo[i][j] = max(ms(i+1,j),ms(i+1,j+1)) + triangulo[i][j];
    }
    return memo[i][j];

}
int main()
{
    ofstream fout ("numtri.out");
    ifstream fin ("numtri.in");
    fin>> n;
    for( int i = 0; i <= n; i++ ){
        for( int j = 0; j <= n; j++ ){
            memo[i][j] = -1;
        }
    }
    for( int i = 1;i <= n; i++ ){
        for( int j = 1; j <= i; j++ ){
            fin>>triangulo[i][j];
        }
    }
    fout<< ms(1,1)<<endl;


    return 0;
}
