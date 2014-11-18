/*
ID: t_a_k_e1
PROG: crypt1
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
int p[10];
int contador;
bool rValido( int num ){
    if( num/10000 != 0 ){
        return false;
    }else{
        bool encontrado = false;
        while( num > 0 ){
            encontrado = false;
            for( int i = 0; i < n; i++ ){
                if( num%10 == p[i] ){
                    encontrado = true;
                }
            }
            if( !encontrado ){
                return false;
            }

            num /=10;
        }
        return true;
    }
}
bool esValido(int num){
    if( num/1000 != 0 ){
        return false;
    }else{
        bool encontrado = false;
        while( num > 0 ){
            encontrado = false;
            for( int i = 0; i < n; i++ ){
                if( num%10 == p[i] ){
                    encontrado = true;
                }
            }
            if( !encontrado ){
                return false;
            }

            num /=10;
        }
        return true;
    }
}
int main() {
    ofstream fout ("crypt1.out");
    ifstream fin ("crypt1.in");
    fin>> n;
    for( int i = 0; i < n; i++ ){
        fin>> p[i];
    }
    for( int A = 0; A < n; A++ ){//
        for( int B = 0; B < n; B++ ){
            for( int C = 0; C < n; C++ ){
                for( int D = 0; D < n; D++ ){
                    for( int E = 0; E < n; E++ ){
                        int ABC = 100*p[A] + 10*p[B] + p[C];
                        int DE = 10*p[E] + p[D];
                        if( esValido(ABC*p[D]) && esValido(ABC*p[E]) && rValido(ABC*DE) ){
                            contador++;
                        }

                    }
                }
            }
        }
    }
    fout<< contador << endl;
    /*
        ABC
        x ED
        ----
        FGH
       IJK
      -------
      2 2 2
    x   2 2
     ------
      4 4 4
    4 4 4
  ---------
    4 8 8 4
    */
    return 0;
}
