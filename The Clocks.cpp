/*
ID: t_a_k_e1
PROG: clocks
LANG: C++
*/
#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <sstream>
#include <algorithm>

using namespace std;
int A,B,C,D,E,F,G,H,I;
int tempA,tempB,tempC,tempD,tempE,tempF,tempG,tempH,tempI;
int soluciones[30];
int maxLong = 1000;

void resetea(){
    tempA = A;
    tempB = B;
    tempC = C;
    tempD = D;
    tempE = E;
    tempF = F;
    tempG = G;
    tempH = H;
    tempI = I;
}
int regresa( int m ){
    if( m > 12 ){
        return m % 12;
    }
    return m;
}
void primeraForma(int n){
    tempA = regresa(tempA+(3*n));
    tempB = regresa(tempB+(3*n));
    tempD = regresa(tempD+(3*n));
    tempE = regresa(tempE+(3*n));
}
void segundaForma(int n){
    tempA = regresa(tempA+(3*n));
    tempB = regresa(tempB+(3*n));
    tempC = regresa(tempC+(3*n));
}
void terceraForma(int n){
    tempB = regresa(tempB+(3*n));
    tempC = regresa(tempC+(3*n));
    tempE = regresa(tempE+(3*n));
    tempF = regresa(tempF+(3*n));
}
void cuartaForma( int n ){
    tempA = regresa(tempA+(3*n));
    tempD = regresa(tempD+(3*n));
    tempG = regresa(tempG+(3*n));
}
void quintaForma(int n){
    tempB = regresa(tempB+(3*n));
    tempD = regresa(tempD+(3*n));
    tempE = regresa(tempE+(3*n));
    tempF = regresa(tempF+(3*n));
    tempH = regresa(tempH+(3*n));
}
void sextaForma( int n ){
    tempC = regresa(tempC+(3*n));
    tempF = regresa(tempF+(3*n));
    tempI = regresa(tempI+(3*n));
}
void septimaForma( int n ){
    tempD = regresa(tempD+(3*n));
    tempE = regresa(tempE+(3*n));
    tempG = regresa(tempG+(3*n));
    tempH = regresa(tempH+(3*n));
}
void octavaForma( int n ){
    tempG = regresa(tempG+(3*n));
    tempH = regresa(tempH+(3*n));
    tempI = regresa(tempI+(3*n));
}
void novenaForma( int n ){
    tempE = regresa(tempE+(3*n));
    tempF = regresa(tempF+(3*n));
    tempH = regresa(tempH+(3*n));
    tempI = regresa(tempI+(3*n));
}
bool todoCorrecto(){
    return (tempA + tempB + tempC + tempD + tempE + tempF + tempG + tempH + tempI ) == 108;
}
int main()
{
    ofstream fout ("clocks.out");
    ifstream fin ("clocks.in");
    fin>>A>>B>>C>>D>>E>>F>>G>>H>>I;
    for( int a = 0; a < 4; a++ )
    for( int b = 0; b < 4; b++ )
    for( int c = 0; c < 4; c++ )
    for( int d = 0; d < 4; d++ )
    for( int e = 0; e < 4; e++ )
    for( int f = 0; f < 4; f++ )
    for( int g = 0; g < 4; g++ )
    for( int h = 0; h < 4; h++ )
    for( int i = 0; i < 4; i++ ){
        resetea();
        primeraForma(i);
        segundaForma(h);
        terceraForma(g);
        cuartaForma(f);
        quintaForma(e);
        sextaForma(d);
        septimaForma(c);
        octavaForma(b);
        novenaForma(a);
        if( todoCorrecto() ){
            int suma = a + b + c + d + e + f + g + h + i;
            if( suma < maxLong ){
                int cont = 0;
                maxLong = suma;
                for( int j = 0; j < i; j++, cont++ )
                    soluciones[cont] = 1;
                for( int j = 0; j < h; j++, cont++ )
                    soluciones[cont] = 2;
                for( int j = 0; j < g; j++, cont++ )
                    soluciones[cont] = 3;
                for( int j = 0; j < f; j++, cont++ )
                    soluciones[cont] = 4;
                for( int j = 0; j < e; j++, cont++ )
                    soluciones[cont] = 5;
                for( int j = 0; j < d; j++, cont++ )
                    soluciones[cont] = 6;
                for( int j = 0; j < c; j++, cont++ )
                    soluciones[cont] = 7;
                for( int j = 0; j < b; j++, cont++ )
                    soluciones[cont] = 8;
                for( int j = 0; j < a; j++, cont++ )
                    soluciones[cont] = 9;
            }
        }
    }
    for( int i = 0; i < maxLong-1; i++ ){
        fout<< soluciones[i]<< " ";
    }
    fout<<soluciones[maxLong -1 ]<<endl;
    return 0;
}
