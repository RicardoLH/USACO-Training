/*
ID: t_a_k_e1
PROG: gift1
LANG: C++
*/
#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;
struct Persona{
    int inicial;
    string nombre;
    int agregar;
    int restar;
};

Persona grupo[11];
int n;
int main() {
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    fin>> n;
    for( int i = 0; i < n; i++ ){
        fin>> grupo[i].nombre;

    }
    string temp;
    int p = 0;
    int cantidadP;
    for( int i = 0; i < n; i++ ){
        fin>> temp;
        for( int j = 0; j < n; j++ ){
            if( grupo[j].nombre == temp ){
                p = j;
            }
        }
        fin>> grupo[p].inicial;
        fin>> cantidadP;
        int total = 0;
        if( cantidadP != 0 ){
            total = grupo[p].inicial / cantidadP;
            grupo[p].restar += (total * cantidadP );
            string regalo = "";
            for( int j = 0; j < cantidadP; j++ ){
                fin>> regalo;
                for( int z = 0; z < n; z++ ){
                    if( regalo == grupo[z].nombre ){
                        grupo[z].agregar += total;
                        break;
                    }
                }
            }
        }

    }
    for( int i = 0; i < n; i++ ){
        int total = grupo[i].inicial + grupo[i].agregar - grupo[i].restar;
        fout<< grupo[i].nombre << " " <<total -grupo[i].inicial <<  endl;

    }

    return 0;
}
