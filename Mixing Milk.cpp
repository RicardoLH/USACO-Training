/*
ID: t_a_k_e1
PROG: milk
LANG: C++
*/
#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <sstream>

using namespace std;
int n;
int m;
struct Granja{
    int precio;
    int maximo;
    bool existe;
};
Granja monticulo[20000];
int contador = 0;
void inserta( int precio, int maximo ){
    contador++;
    monticulo[contador].precio = precio;
    monticulo[contador].maximo = maximo;
    monticulo[contador].existe = true;
    for( int i = contador; monticulo[i/2].precio > precio; i /=2 ){
        if( i/2 == 0 ){
            break;
        }
        Granja temp = monticulo[i/2];
        monticulo[i/2] = monticulo[i];
        monticulo[i] = temp;
    }
}
Granja saca(){
    Granja primer = monticulo[1];
    Granja ultimo = monticulo[contador];
    monticulo[1] = ultimo;
    monticulo[contador].existe = 0;
    contador--;
    int i = 1;
    bool derecha = false;
    while( (monticulo[i*2].precio <= ultimo.precio && monticulo[i*2].existe) || (monticulo[i*2+1].precio <= ultimo.precio && monticulo[i*2+1].existe) ){
        if( monticulo[i*2].precio <= monticulo[i*2+1].precio ){
            Granja temp = monticulo[i*2];
            monticulo[i*2] = monticulo[i];
            monticulo[i] = temp;
            derecha = false;
        }else{
            Granja temp = monticulo[i*2+1];
            monticulo[i*2+1] = monticulo[i];
            monticulo[i] = temp;
            derecha = true;
        }
        i *= 2;
        if( derecha ){
            i++;
        }
        if( i > 5002 ){
            break;
        }
    }
    return primer;

}
int main() {
    ofstream fout ("milk.out");
    ifstream fin ("milk.in");
    fin>> n;
    fin>> m;
    int tPrecio = 0;
    int tMaximo = 0;
    for( int i = 0; i < m; i++ ){
        fin>> tPrecio;
        fin>> tMaximo;
        inserta(tPrecio,tMaximo);
    }
    int dinero = 0;
    int litros = 0;
    while( litros != n ){
        Granja actual = saca();
        litros += actual.maximo;
        if( litros > n ){
            int diferencia = litros - n;
            litros = n;
            dinero += (actual.maximo - diferencia) * actual.precio;
        }else{
            dinero += actual.maximo * actual.precio;
        }

    }
    fout<< dinero << endl;
    return 0;
}
