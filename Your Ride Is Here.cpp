/*
ID: t_a_k_e1
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;
char palabra[7];
char palabra2[7];
int multi1 = 1;
int multi2 = 1;
int main() {
    FILE *fin  = fopen ("ride.in", "r");
    FILE *fout = fopen ("ride.out", "w");
    fscanf(fin, " %s", palabra );
    fscanf(fin, " %s", palabra2 );

    for( int i = 0; i < 6; i++ ){
        int letra = palabra[i];
        if( letra != 0 ){
            letra -= 64;
            multi1 *= (letra);
        }
    }
    for( int i = 0; i < 6; i++ ){
        int letra = palabra2[i];
        if( letra != 0 ){
            letra -= 64;
            multi2 *= (letra);
        }
    }
    if( multi1%47 == multi2%47 ){
        fprintf(fout, "GO\n");
    }else{
        fprintf(fout, "STAY\n");
    }
    return 0;
}
