/*
ID: t_a_k_e1
PROG: packrec
LANG: C++
*/
#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <algorithm>

using namespace std;

struct Rectangulo{
    int ancho;
    int largo;
};
struct Soluciones{
    int p;
    int q;
};

Rectangulo rect[4];
Soluciones sol[200];
int contador;
int menor = 1000*1000;

void checaArea(int area, int ancho, int largo ){

    if( area < menor ){
        sol[contador].p = 51;
        sol[contador].q = 51;
        contador = 0;
        menor = area;
        sol[contador].p = ancho;
        sol[contador].q = largo;
    }else if( area == menor ){
        contador++;
        sol[contador].p = ancho;
        sol[contador].q = largo;
    }
}
Rectangulo rota( Rectangulo a ){
    a.ancho ^= a.largo;
    a.largo ^= a.ancho;
    a.ancho ^= a.largo;
    return a;
}
void coloca(Rectangulo a, Rectangulo b, Rectangulo c, Rectangulo d, int l ){
    int largo = 1;
    int ancho = 1;
    int anchoT = 1;
    int largoT = 1;

    if( l == 1 ){ // TODOS ALINEADOS
        if( a.largo > largo ){
            largo = a.largo;
        }
        if( b.largo > largo ){
            largo = b.largo;
        }
        if( c.largo > largo ){
            largo = c.largo;
        }
        if( d.largo > largo ){
            largo = d.largo;
        }
        ancho = a.ancho + b.ancho + c.ancho + d.ancho;
        checaArea(largo*ancho,ancho,largo);
    }else if( l == 2 ){ // 3 ALINEADOS ARRIBA DE 1 A: ABAJO B: ARRIBA1 C:ARRIBA2 D: ARRIBA3
        if( b.largo > largo ){
            largo = b.largo;
        }
        if( c.largo > largo ){
            largo = c.largo;
        }
        if( d.largo > largo ){
            largo = d.largo;
        }
        largo += a.largo;
        anchoT = b.ancho + c.ancho + d.ancho;
        ancho = a.ancho;
        if( ancho < anchoT ){
            ancho = anchoT;
        }
        checaArea(largo*ancho,ancho,largo);

    }else if( l == 3 ){ // 2 ARRIBA DE 1,EL RESTANTE A UN LADO A: ABAJO B: ARRIBA1 C:ARRIBA2 D: A UN LADO
        anchoT = b.ancho + c.ancho;
        ancho = a.ancho;
        if( ancho < anchoT ){
            ancho = anchoT;
        }
        ancho += d.ancho;
        largoT = b.largo;
        largo = c.largo;
        if( largo < largoT ){
            largo = largoT;
        }
        largo += a.largo;
        largoT = d.largo;
        if( largo < largoT ){
            largo = largoT;
        }
        checaArea(largo*ancho,ancho,largo);
    }else if( l == 4 ){// DOS A LOS LADOS, UNO EN MEDIO, Y OTRO ARRIBA DEL DE ENMEDIO..A:Primero B.Abajo C. arriba d. ultimo
        ancho = b.ancho;
        anchoT = c.ancho;
        if( ancho < anchoT ){
            ancho = anchoT;
        }
        ancho = ancho + a.ancho + d.ancho;
        largoT = b.largo + c.largo;
        if( a.largo > d.largo ){
            largo = a.largo;
        }else{
            largo = d.largo;
        }
        if( largo < largoT ){
            largo = largoT;
        }
        checaArea(largo*ancho,ancho,largo);
    }else if( l == 5 ){// UNO ARRIBA DE OTRO, LOS OTROS 2 PEGADOS
        anchoT = b.ancho;
        ancho = a.ancho;
        if( ancho < anchoT ){
            ancho = anchoT;
        }
        ancho = ancho + c.ancho + d.ancho;
        largo = (a.largo + b.largo);
        largoT = c.largo;
        if( largo < largoT ){
            largo = largoT;
        }
        largoT = d.largo;
        if( largo < largoT ){
            largo = largoT;
        }
        checaArea(largo*ancho,ancho,largo);
    }else if( l == 6 ){ // 2 RECTANGULOS ARRIBA DE LOS OTROS 2 A: ABAJO1 B: ABAJO2 C:ARRIBA1 D: ARRIBA2
        largo = a.largo + b.largo;
        largoT = c.largo + d.largo;

        if( largo < largoT ){
            largo = largoT;
        }
        anchoT = b.ancho;
        ancho = a.ancho;
        if( ancho < anchoT ){
            ancho = anchoT;
        }
        int anchoTT = d.ancho;
        anchoT = c.ancho;
        if( anchoT < anchoTT ){
            anchoT = anchoTT;
        }
        ancho += anchoT;
        if( a.largo - c.largo != 0 ){
            if( a.largo > c.largo ){
                if( b.ancho > d.ancho ){
                   if( (a.ancho + c.ancho - b.ancho) == d.ancho  ){
                        ancho = a.ancho + c.ancho;
                    }
                }
            }else{
                if( d.ancho > b.ancho ){
                   if( (a.ancho + c.ancho - b.ancho) == d.ancho  ){
                        ancho = a.ancho + c.ancho;
                    }
                }
            }

        }



        checaArea(largo*ancho,ancho,largo);
    }
}
void permuta(int n){
    int i = 0;
    Rectangulo aux;
    if( n == 0 ){
        for( int i = 1; i <= 6; i++ ){
            coloca(rect[0],rect[1],rect[2],rect[3],i); //0000
            coloca(rect[0],rect[1],rect[2],rota(rect[3]),i);//0001
            coloca(rect[0],rect[1],rota(rect[2]),rect[3],i); // 0010
            coloca(rect[0],rect[1],rota(rect[2]),rota(rect[3]),i); //0011
            coloca(rect[0],rota(rect[1]),rect[2],rect[3],i);//0100
            coloca(rect[0],rota(rect[1]),rect[2],rota(rect[3]),i);//0101
            coloca(rect[0],rota(rect[1]),rota(rect[2]),rect[3],i);//0110
            coloca(rect[0],rota(rect[1]),rota(rect[2]),rota(rect[3]),i);//0111
            coloca(rota(rect[0]),rect[1],rect[2],rect[3],i); //1000
            coloca(rota(rect[0]),rect[1],rect[2],rota(rect[3]),i);//1001
            coloca(rota(rect[0]),rect[1],rota(rect[2]),rect[3],i); // 1010
            coloca(rota(rect[0]),rect[1],rota(rect[2]),rota(rect[3]),i); //1011
            coloca(rota(rect[0]),rota(rect[1]),rect[2],rect[3],i);//1100
            coloca(rota(rect[0]),rota(rect[1]),rect[2],rota(rect[3]),i);//1101
            coloca(rota(rect[0]),rota(rect[1]),rota(rect[2]),rect[3],i);//1110
            coloca(rota(rect[0]),rota(rect[1]),rota(rect[2]),rota(rect[3]),i);//1111
        }
    }else{
        for( i = 0; i < n; i++ ){
            aux = rect[n-1];
            rect[n-1] = rect[i];
            rect[i] = aux;
            permuta(n-1);
            aux = rect[n-1];
            rect[n-1] = rect[i];
            rect[i] = aux;
        }
    }
}
bool compara(Soluciones a, Soluciones b){
    return a.p < b.p;
}

int main() {
    ofstream fout ("packrec.out");
    ifstream fin ("packrec.in");
    for( int i = 0; i < 4; i++ ){
        fin>>rect[i].ancho;
        fin>>rect[i].largo;
    }
    permuta(4);
    fout<< menor << endl;
    for( int i = 0; i <= contador; i++ ){
        if( sol[i].p > sol[i].q ){
            sol[i].p ^= sol[i].q;
            sol[i].q ^= sol[i].p;
            sol[i].p ^= sol[i].q;
        }
    }
    sort(sol, sol+contador+1,compara);
    int pT = sol[0].p;
    fout<< pT<< " "<<sol[0].q<<endl;
    for( int i = 1; i <= contador; i++ ){
        if( sol[i].p != pT ){
            fout<<sol[i].p <<" "<<sol[i].q<<endl;
            pT = sol[i].p;
        }
    }


    return 0;
}

