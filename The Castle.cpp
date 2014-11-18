/*
ID: t_a_k_e1
PROG: castle
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
int m;
int cont;
int cuartoMasGrande;
struct Modulo{
    bool norte;
    bool sur;
    bool este;
    bool oeste;
    long numCuarto;
    bool visitado;
};
Modulo castillo[52][52];
int cuartos[2502];
int encontrar( int i, int j ){
    if( castillo[i][j].visitado ){
        return 0;
    }
    //cout<<"visitando "<<i<<","<<j<<endl;
    castillo[i][j].visitado = true;
    castillo[i][j].numCuarto = cont;
    int area = 1;
    if( !castillo[i][j].este ){
        area += encontrar(i,j+1);
    }
    if( !castillo[i][j].norte ){
        area += encontrar(i-1,j);
    }
    if( !castillo[i][j].sur ){
        area += encontrar(i+1,j);
    }if( !castillo[i][j].oeste ){
        area += encontrar(i,j-1);
    }
    //cout<<"retornamos area: " << area<<endl;
    return area;
}
int main(){
    ofstream fout ("castle.out");
    ifstream fin ("castle.in");
    fin>>m;
    fin>>n;
    for( int i = 1; i <= n; i++ ){
        for( int j = 1; j <= m; j++ ){
            int dato = 0;
            fin>> dato;
            while( dato > 0 ){
                int ultimobit = dato &~(dato-1);
                if( ultimobit == 1 ){
                    castillo[i][j].oeste = true;
                }else if( ultimobit == 2 ){
                    castillo[i][j].norte = true;
                }else if( ultimobit == 4 ){
                    castillo[i][j].este = true;
                }else if( ultimobit == 8 ){
                    castillo[i][j].sur = true;
                }
                dato -= ultimobit;
            }
        }
    }
    for( int i = 1; i <= n; i++ ){
        for( int j = 1; j <= m; j++ ){
            if( !castillo[i][j].visitado ){
                cuartos[cont] = encontrar(i,j);
                if( cuartos[cont] > cuartoMasGrande ){
                    cuartoMasGrande = cuartos[cont];
                }
                cont++;
            }
        }
    }
    fout<<cont<<endl;
    fout<<cuartoMasGrande<<endl;
    int areaMayor = 0;
    int iTemp;
    int jTemp;
    char muro;

    for ( int j = 1; j <= m; j++ ) {
        for ( int i = n; i > 0; i-- ) {
            if( castillo[i][j].este && j < m  ){
                if( castillo[i][j].norte && i > 1){
                    if( castillo[i-1][j].numCuarto != castillo[i][j].numCuarto ){
                        int area = cuartos[castillo[i-1][j].numCuarto] + cuartos[castillo[i][j].numCuarto];
                        //cout<<" area  "<< area <<" en " << i<<","<<j<<" en el muro n"<<endl;
                        if( area > areaMayor ){
                            muro = 'N';
                            iTemp = i;
                            jTemp = j;
                             areaMayor = area;

                        }
                    }
                }
                if( castillo[i][j+1].numCuarto != castillo[i][j].numCuarto ){
                    int area = cuartos[castillo[i][j+1].numCuarto] + cuartos[castillo[i][j].numCuarto];
                    //cout<<" area  "<< area <<" en " << i<<","<<j<<" en el muro E"<<endl;
                    if( area > areaMayor ){
                        muro = 'E';
                        iTemp = i;
                        jTemp = j;
                        areaMayor = area;

                    }
                }
            }
            if( castillo[i][j].oeste && j > 1){
                if( castillo[i][j-1].numCuarto != castillo[i][j].numCuarto ){
                    int area = cuartos[castillo[i][j-1].numCuarto] + cuartos[castillo[i][j].numCuarto];
                    //cout<<" area  "<< area <<" en " << i<<","<<j<<" en el muro o"<<endl;
                    if( area > areaMayor ){
                        muro = 'W';
                        iTemp = i;
                        jTemp = j;
                         areaMayor = area;
                    }
                }
            }
            if( castillo[i][j].norte && i > 1){
                if( castillo[i-1][j].numCuarto != castillo[i][j].numCuarto ){
                    int area = cuartos[castillo[i-1][j].numCuarto] + cuartos[castillo[i][j].numCuarto];
                    //cout<<" area  "<< area <<" en " << i<<","<<j<<" en el muro n"<<endl;
                    if( area > areaMayor ){
                        muro = 'N';
                        iTemp = i;
                        jTemp = j;
                         areaMayor = area;

                    }
                }
            }
            if( castillo[i][j].sur && i < n){
                if( castillo[i+1][j].numCuarto != castillo[i][j].numCuarto ){
                    int area = cuartos[castillo[i+1][j].numCuarto] + cuartos[castillo[i][j].numCuarto];
                    //cout<<" area  "<< area <<" en " << i<<","<<j<<" en el muro s"<<endl;
                    if( area > areaMayor ){
                        muro = 'S';
                        iTemp = i;
                        jTemp = j;
                         areaMayor = area;

                    }
                }
            }
        }
    }
    fout<<areaMayor<<endl;
    fout<< iTemp <<" "<< jTemp << " " <<muro<<endl;
}
