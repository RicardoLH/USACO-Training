/*
ID: t_a_k_e1
PROG: money
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;
int n;
int k;
int mon[30];
long long int cont;
long long int memo[10005][27];
int main() {
    ofstream fout ("money.out");
    ifstream fin ("money.in");
    fin>>k;
    fin>>n;
    for( int i = 0; i < k; i++ ){
        fin>>mon[i];
    }
    for( int j = 0; j < k; j++ ){
        memo[0][j] = 1;
    }

    for( int i = 1; i <= n; i++ ){
        for( int j = k-1; j >= 0; j-- ){
            long long int toma = 0;
            long long int nToma = 0;
            if(  i - mon[j] >= 0 ){
                toma = memo[i-mon[j]][j];
            }
            if( (j+1) < k ){
                nToma = memo[i][j+1];
            }
            memo[i][j] = toma + nToma;
        }
    }
    fout<<memo[n][0]<<endl;

}
