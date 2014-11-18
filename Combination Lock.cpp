/*
ID: t_a_k_e1
LANG: C++
TASK: combo
*/
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <bits/stdc++.h>
using namespace std;

struct Tupla{
    int x,y,z;
};
set<Tupla> validos;
int n;
bool operator<( Tupla a, Tupla b ){
     if( a.x == b.x ){
        if( a.y == b.y ){
            return a.z < b.z;
        }else{
            return a.y < b.y;
        }
    }else{
        return a.x < b.x;
    }
}
bool operator==( Tupla a, Tupla b ){
   return a.x == b.x && ( a.y == b.y && a.z == b.z);
}
int operaCor( int x ){
    if( x > n ){
        return ( x % n );
    }else if( x <= 0 ){
        return ( n + x );
    }else{
        return x;
    }
}
int main(){
    ofstream fout ("combo.out");
    ifstream fin ("combo.in");
    fin>>n;
    Tupla primera;
    fin>>primera.x;
    fin>>primera.y;
    fin>>primera.z;
    Tupla segunda;
    fin>>segunda.x;
    fin>>segunda.y;
    fin>>segunda.z;
    for( int i = -2; i <= 2; i++ ){
        for( int j = -2; j <= 2; j++ ){
            for( int k = -2; k <= 2 ; k++ ){
                Tupla nueva;
                nueva.x = operaCor( primera.x + i );
                nueva.y = operaCor( primera.y + j );
                nueva.z = operaCor( primera.z + k );
                //cout<<nueva.x<< " "<< nueva.y<<" "<<nueva.z<<endl;
                if( nueva.x > 0 && ( nueva.y > 0 && nueva.z > 0 ) )
                    validos.insert(nueva);
            }
        }
    }
    for( int i = -2; i <= 2; i++ ){
        for( int j = -2; j <= 2; j++ ){
            for( int k = -2; k <= 2 ; k++ ){
                Tupla nueva;
                nueva.x = operaCor( segunda.x + i );
                nueva.y = operaCor( segunda.y + j );
                nueva.z = operaCor( segunda.z + k );
                if( nueva.x > 0 && ( nueva.y > 0 && nueva.z > 0 ) )
                    validos.insert(nueva);
            }
        }
    }
    fout<<validos.size()<<endl;
    return 0;
}
