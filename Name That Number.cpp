/*
ID: t_a_k_e1
PROG: namenum
LANG: C++
*/
#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;
long long int n;
int digitos[13];
string nombres[3000];
int contador = -1;
int palabras = -1;
char caracterActual1;
char caracterActual2;
char caracterActual3;

void divide( long long int a){
    if( a <= 0 ){
        return;
    }
    divide(a/10);
    contador++;
    digitos[contador] = a%10;
}

void defineCaracteres(int k){
    if( k == 2 ){
        caracterActual1 = 'A';
        caracterActual2 = 'B';
        caracterActual3 = 'C';
    }else if( k == 3 ){
        caracterActual1 = 'D';
        caracterActual2 = 'E';
        caracterActual3 = 'F';
    }else if( k == 4 ){
        caracterActual1 = 'G';
        caracterActual2 = 'H';
        caracterActual3 = 'I';
    }else if( k == 5 ){
        caracterActual1 = 'J';
        caracterActual2 = 'K';
        caracterActual3 = 'L';
    }else if( k == 6 ){
        caracterActual1 = 'M';
        caracterActual2 = 'N';
        caracterActual3 = 'O';
    }else if( k == 7 ){
        caracterActual1 = 'P';
        caracterActual2 = 'R';
        caracterActual3 = 'S';
    }else if( k == 8 ){
        caracterActual1 = 'T';
        caracterActual2 = 'U';
        caracterActual3 = 'V';
    }else if( k == 9 ){
        caracterActual1 = 'W';
        caracterActual2 = 'W';
        caracterActual3 = 'Y';
    }
}


int main() {
    ofstream fout ("namenum.out");
    ifstream fin ("namenum.in");
    ifstream fe("dict.txt");
    fin>> n;

    divide(n);
    string temp;
    bool correcta = true;
    int correctas = 0;

    for( int i = 0; i < 4617; i++ ){
        fe>> temp;
        correcta = true;
        if( temp.length()-1 == contador ){
           for( int j = 0; j <= contador; j++ ){
                defineCaracteres(digitos[j]);
                if( caracterActual1 != temp.at(j) && caracterActual2 != temp.at(j) && caracterActual3 != temp.at(j) ){
                   correcta = false;
                   break;
                }
            }
            if( correcta ){
                fout<< temp << endl;
                correctas++;
            }
        }
    }
    if( correctas == 0 ){
        fout<< "NONE" << endl;
    }
    return 0;
}
