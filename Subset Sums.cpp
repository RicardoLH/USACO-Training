/*
ID: t_a_k_e1
PROG: subset
LANG: C++
*/
#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <sstream>
#include <algorithm>
#include <math.h>
#define ll long long int
using namespace std;
int n;
ll memo[780][40];
int suma;
bool llego = false;
ll busqueda( ll a, ll k ){
    if( a == suma/2 ){
        return 1;
    }
    if( k == n+1 ) {
        return 0;
    }
    if( memo[a][k]== 0 ){
        memo[a][k] = busqueda(a+k,k+1) + busqueda(a,k+1);
    }
    return memo[a][k];
}
int main(){
    ofstream fout ("subset.out");
    ifstream fin ("subset.in");
    fin>>n;
    suma = (n*(n+1)/2);
    if( suma % 2 != 0 ){
        fout<<0<<endl;
    }else{
        fout<<busqueda(0,1)/2<<endl;
    }

}
