/*
ID: t_a_k_e1
PROG: friday
LANG: C++
*/
#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;
int temp[9];
int n;
int main() {
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");
    fin>> n;

    int limite = 0;
    int dia = 3;
    for( int i = 1900; i <= 1899 + n; i++ ){
        int biciesto = 0;
        if( i % 4 == 0 ){
            biciesto = 1;
            if( i % 10 == 0 && i % 100 == 0 ){
                if( i % 400 != 0 ){
                    biciesto = 0;
                }
            }
        }
        for( int j = 1; j <= 12; j++ ){
            if( biciesto && j == 2 ){
                limite = 29;
            }else if( j == 2 ){
                limite = 28;
            }else if( j == 1 || j == 3 || j == 5 || j == 7 || j == 8 || j ==  12 || j == 10 ){
                limite = 31;
            }else{
                limite = 30;
            }
            for( int z = 1; z <= limite; z++ ){
                if( z == 13 ){
                    temp[dia]++;

                }
                dia++;
                if( dia > 7 ){
                    dia = 1;
                }

            }
        }


    }
    for( int i = 1; i <= 7; i++ ){
        fout<< temp[i];
        if( i == 7 ){
          fout<< endl;
        }else{
            fout<< " ";
        }
    }

    return 0;
}
