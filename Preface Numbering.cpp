/*
ID: t_a_k_e1
PROG: preface
LANG: C++
*/
#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <sstream>
#include <algorithm>
#include <math.h>

using namespace std;
int k;
int cubeta[7];

void aumenta( int n, int p ){
    if( p == 1 ){
        if( n == 1 || n == 2 || n == 3 ){
            cubeta[0] += n;
        }else if( n == 4 || n == 6 ){
            cubeta[0] += 1;
            cubeta[1] += 1;
        }else if( n == 5 ){
            cubeta[1] += 1;
        }else if( n == 7 ){
            cubeta[0] += 2;
            cubeta[1] += 1;
        }else if( n == 8 ){
            cubeta[0] += 3;
            cubeta[1] += 1;
        }else if( n == 9 ){
            cubeta[0] += 1;
            cubeta[2] += 1;
        }
    }else if( p == 2 ){
        if( n == 1 || n == 2 || n == 3 ){
            cubeta[2] += n;
        }else if( n == 4 || n == 6 ){
            cubeta[2] += 1;
            cubeta[3] += 1;
        }else if( n == 5 ){
            cubeta[3] += 1;
        }else if( n == 7 ){
            cubeta[2] += 2;
            cubeta[3] += 1;
        }else if( n == 8 ){
            cubeta[2] += 3;
            cubeta[3] += 1;
        }else if( n == 9 ){
            cubeta[2] += 1;
            cubeta[4] += 1;
        }
    }else if( p == 3 ){
        if( n == 1 || n == 2 || n == 3 ){
            cubeta[4] += n;
        }else if( n == 4 || n == 6 ){
            cubeta[4] += 1;
            cubeta[5] += 1;
        }else if( n == 5 ){
            cubeta[5] += 1;
        }else if( n == 7 ){
            cubeta[4] += 2;
            cubeta[5] += 1;
        }else if( n == 8 ){
            cubeta[4] += 3;
            cubeta[5] += 1;
        }else if( n == 9 ){
            cubeta[4] += 1;
            cubeta[6] += 1;
        }
    }else if( p == 4 ){
        cubeta[6] += n;
    }
}
int main(){

    ofstream fout ("preface.out");
    ifstream fin ("preface.in");
    fin>>k;
    for( int i = 1; i <= k; i++ ){
        int cont = 1;
        int temp = i;
        while( temp > 0 ){
            aumenta( temp % 10, cont);
            cont++;
            temp /= 10;
        }
    }
    if( cubeta[0] != 0 ){
        fout<<"I "<< cubeta[0]<<endl;
    }
    if( cubeta[1] != 0 ){
        fout<<"V "<< cubeta[1]<<endl;
    }
    if( cubeta[2] != 0 ){
        fout<<"X "<< cubeta[2]<<endl;
    }
    if( cubeta[3] != 0 ){
        fout<<"L "<< cubeta[3]<<endl;
    }
    if( cubeta[4] != 0 ){
        fout<<"C "<< cubeta[4]<<endl;
    }
    if( cubeta[5] != 0 ){
        fout<<"D "<< cubeta[5]<<endl;
    }
    if( cubeta[6] != 0 ){
        fout<<"M "<< cubeta[6]<<endl;
    }
}
