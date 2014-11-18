/*
ID: t_a_k_e1
PROG: zerosum
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
int num[30];
ofstream fout ("zerosum.out");
ifstream fin ("zerosum.in");
void zeroSum( int k, int o ){
    if( o > 2 ){
        return;
    }
    if( k >= (n-1)*2 ){
        int operadorActual = 1;
        int numeroActual = 1;
        int suma = 0;
        for( int i = 1; i <= ((n-1)*2)+1; i+=2){
            if( num[i] == 1 || num[i] == 2 || i == ((n-1)*2)+1 ){
                if( operadorActual == 1 ){
                    suma += numeroActual;
                }else{
                    suma -= numeroActual;
                }
                numeroActual = num[i+1];
                operadorActual = num[i];
            }else{
                numeroActual = (numeroActual*10) + num[i+1];
            }
        }
        if( suma == 0 ){
            for( int i = 0; i <= ((n-1)*2); i++ ){
                if( i%2 != 0 ){
                    if( num[i] == 0 ){
                        fout<<" ";
                    }else if( num[i] == 1 ){
                        fout<<"+";
                    }else{
                        fout<<"-";
                    }
                }else{
                    fout<<num[i];
                }
            }
            fout<<endl;
        }
        return;
    }
    num[k] = o;
    zeroSum(k+2,0);
    zeroSum(k,o+1);
}
int main()
{
    fin>>n;
    num[0] = 1;
    int j = 2;
    for( int i = 2; i <= ((n-1)*2); i+=2 ){
        num[i] = j;
        j++;
    }
   zeroSum(1,0);
   return 0;
}
