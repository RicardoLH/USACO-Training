/*
ID: t_a_k_e1
PROG: transform
LANG: C++
*/
#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;
int n;
char matriz[11][11];
char modificada[11][11];
char temp[11][11];

bool estaRotada90(){
    for( int i = 0; i < n; i++ ){
        for( int j = 0; j < n; j++ ){
            if( modificada[j][n-1-i] != matriz[i][j] ){
                return false;
            }
        }
    }
    return true;
}

bool estaRotada180(){
    for( int i = 0; i < n; i++ ){
        for( int j = 0; j < n; j++ ){
            if( modificada[n-1-i][n-1-j] != matriz[i][j] ){
                return false;
            }
        }
    }
    return true;
}
bool estaRotada270(){
    for( int i = 0; i < n; i++ ){
        for( int j = 0; j < n; j++ ){
            if( modificada[n-1-j][i] != matriz[i][j] ){
                return false;
            }
        }
    }
    return true;
}

bool noRotada(){
    for( int i = 0; i < n; i++ ){
        for( int j = 0; j < n; j++ ){
            if( modificada[i][j] != matriz[i][j] ){
                return false;
            }
        }
    }
    return true;
}

bool esEspejo(){
    for( int i = 0; i < n; i++ ){
        for( int j = 0; j < n; j++ ){
            if( modificada[j][n-1-i] != matriz[j][i] ){
                return false;
            }
        }
    }
    return true;

}

bool esCombinada(){
    for( int i = 0; i < n; i++ ){
        for( int j = 0; j < n; j++ ){
            temp[j][n-1-i] = matriz[j][i];
        }
    }
    bool combinada = true;

    for( int i = 0; i < n; i++ ){
        for( int j = 0; j < n; j++ ){
            if( modificada[j][n-1-i] != temp[i][j] ){
                combinada = false;
            }
        }
    }
    if( combinada ){
        return true;
    }else{
        combinada = true;
        for( int i = 0; i < n; i++ ){
        for( int j = 0; j < n; j++ ){
                if( modificada[n-1-i][n-1-j] != temp[i][j] ){
                    combinada = false;
                }
            }
        }
        if( combinada ){
            return true;
        }
        for( int i = 0; i < n; i++ ){
            for( int j = 0; j < n; j++ ){
                if( modificada[n-1-j][i] != temp[i][j] ){
                    return false;
                }
            }
        }
        return true;
    }
}
int main() {
    ofstream fout ("transform.out");
    ifstream fin ("transform.in");
    fin>> n;
    for( int i = 0; i < n; i++ ){
        for( int j = 0; j < n; j++ ){
            fin>>matriz[i][j];
        }
    }
    for( int i = 0; i < n; i++ ){
        for( int j = 0; j < n; j++ ){
            fin>>modificada[i][j];
        }
    }
    if( estaRotada90() ){
        fout<< 1 << endl;
    }else if( estaRotada180() ){
        fout<< 2 << endl;
    }else if( estaRotada270() ){
        fout<< 3 << endl;
    }else if( esEspejo() ){
        fout<< 4 << endl;
    }else if( esCombinada() ){
        fout<< 5 << endl;
    }else if( noRotada() ){
        fout<< 6 << endl;
    }else{
        fout<< 7 << endl;
    }
    return 0;
}
