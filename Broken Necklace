/*
ID: t_a_k_e1
LANG: C++
TASK: beads
*/
#include <iostream>
#include <fstream>

using namespace std;
char collar[1000];
int mayor = 1;
bool alternado;
int n;
int contador = 1;
int main(){
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");
    fin>> n;
    for( int i = 0; i < n; i++ ){
        fin>> collar[i];
        collar[n+i] = collar[i];
    }
    char actual = collar[0];
    for( int i = 1; i < 2*n; i++ ){
        if( collar[i] == actual || collar[i] == 'w' ){
            contador++;
            if( contador > mayor ){
                mayor = contador;
            }
        }else if( !alternado ){
            alternado = true;
            actual = collar[i];
            contador++;
        }else{
            alternado = false;
            if( contador > mayor ){
                mayor = contador;
            }
            contador = 1;
            actual = collar[i];
            for( int j = i-1; j >= 0; j-- ){
                if( collar[j] == 'w' ){
                    contador++;
                }else{
                    break;
                }
            }
        }
    }
    //------
    int contador = 0;
    actual = collar[n];
    for( int i = n; collar[i] == actual || collar[i] == 'w' ; i++ ){
        contador++;
    }
    alternado = false;


    for( int i = n-1; i >= 0; i-- ){
        if( collar[i] == actual || collar[i] == 'w' ){
            contador++;
        }else if( !alternado ){
            alternado = true;
            actual = collar[i];
            contador++;
        }else{
            break;
        }
    }
    if( contador > n ){
        contador /= 2;
    }
    if( contador > mayor ){
        mayor = contador;
    }

    if( mayor > n ){
        fout<< mayor / 2 << endl;
    }else{
        fout<< mayor << endl;
    }




    return 0;
}
