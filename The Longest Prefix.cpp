/*
ID: t_a_k_e1
PROG: prefix
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <sstream>
#include <algorithm>
#include <math.h>
#include <string>
#include <string.h>
using namespace std;
string prefijos[202];
char texto[2000002];
int memo[200002];
int cont;
int len;
int maximo;
bool coincide( int kPref, int p ){
    int longitud = prefijos[kPref].length();
    int i = 0;
    while( i < longitud ){
        if( texto[p++] != prefijos[kPref].at(i++) ){
            return false;
        }
    }
    return true;
}
void prefijoMasLargo(){
    for( int i = len-2; i >= 0 ; i-- ){
        for( int k = 0; k < cont; k++ ){
            int actual = 0;
            if( (len-i) >= prefijos[k].length() ){
                if( coincide(k,i) ){
                    actual = prefijos[k].length() + memo[i+prefijos[k].length()];
                }
            }
            memo[i] = max( memo[i], actual );
        }
    }
}
int main(){
    ofstream fout ("prefix.out");
    ifstream fin ("prefix.in");

    fin>>prefijos[cont];
    while( prefijos[cont] != "."){
        cont++;
        fin>>prefijos[cont];
    }
    int i = 0;
    char temp;
    while(!fin.eof()){
        fin>>temp;
        if( temp != '\n' ){
            texto[i++] = temp;
            temp++;
        }

    }
    len = strlen(texto);
    prefijoMasLargo();
    fout<<memo[0]<<endl;
}
