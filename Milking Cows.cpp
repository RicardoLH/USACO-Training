/*
ID: t_a_k_e1
PROG: milk2
LANG: C++
*/
#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;
int n;
int continuo;
int mayorContinuo;
int mayorDiscontinuo;
int discontinuo;
struct Intervalo{
    int inicio;
    int fin;
};
struct Monticulo{
    Intervalo intervalo;
    bool existe;
};
Intervalo anterior;
Monticulo monticulo[5003];
int contador = 0;
int iAnterior;
int fAnterior;
void inserta( int in, int f ){
    contador++;
    monticulo[contador].intervalo.inicio = in;
    monticulo[contador].intervalo.fin = f;
    monticulo[contador].existe = true;
    for( int i = contador; monticulo[i/2].intervalo.inicio > in; i /= 2 ){
        if( i/2 == 0 ){
            break;
        }else{
            int iTemp = monticulo[i/2].intervalo.inicio;
            int fTemp = monticulo[i/2].intervalo.fin;
            monticulo[i/2].intervalo.inicio = monticulo[i].intervalo.inicio;
            monticulo[i/2].intervalo.fin = monticulo[i].intervalo.fin;
            monticulo[i].intervalo.inicio = iTemp;
            monticulo[i].intervalo.fin = fTemp;
        }
    }
}

Intervalo saca(){
    Intervalo mayor = monticulo[1].intervalo;
    Intervalo ultimo = monticulo[contador].intervalo;
    monticulo[1].intervalo = ultimo;
    monticulo[contador].existe =false;
    contador--;
    bool derecha = false;
    int i = 1;
    while( monticulo[i*2].intervalo.inicio <= ultimo.inicio || monticulo[(i*2)+1].intervalo.inicio <= ultimo.inicio ){
        if( monticulo[i*2].intervalo.inicio <=  monticulo[(i*2)+1].intervalo.inicio && monticulo[i*2].existe ){
            Intervalo temp = monticulo[i*2].intervalo;
            monticulo[i*2].intervalo = monticulo[i].intervalo;
            monticulo[i].intervalo = temp;
            derecha = false;
        }else if( monticulo[(i*2)+1].intervalo.inicio <=  monticulo[i*2].intervalo.inicio && monticulo[(i*2)+1].existe ){
            Intervalo temp = monticulo[(i*2)+1].intervalo;
            monticulo[(i*2)+1].intervalo = monticulo[i].intervalo;
            monticulo[i].intervalo = temp;
            derecha = true;
        }
        i *= 2;
        if( derecha ){
            i++;
        }
        if( i*2 > n +1 ){
            break;
        }
    }
    return mayor;
}
void procesa(){
    Intervalo temp = saca();
    if( temp.fin > fAnterior && temp.inicio <= fAnterior ){
        fAnterior = temp.fin;
        continuo = fAnterior - iAnterior;
        if( continuo > mayorContinuo ){
            mayorContinuo = continuo;
        }
    }else if( temp.inicio > fAnterior ){
        discontinuo = temp.inicio - fAnterior;
        if( discontinuo > mayorDiscontinuo ){
            mayorDiscontinuo = discontinuo;
        }
        continuo = temp.fin - temp.inicio;
        if( continuo > mayorContinuo ){
            mayorContinuo = continuo;
        }
        iAnterior = temp.inicio;
        fAnterior = temp.fin;

    }

}

int main() {
    ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");
    fin>> n;
    int a;
    int b;
    for( int i = 0; i < n; i++ ){
        fin>> a;
        fin>> b;
        inserta(a,b);
    }
    Intervalo primero = saca();
    iAnterior = primero.inicio;
    fAnterior = primero.fin;
    discontinuo = 0;
    continuo = fAnterior - iAnterior;
    mayorContinuo = continuo;
    mayorDiscontinuo = discontinuo;
    for( int i = 1; i < n; i++ ){
        procesa();
    }

    fout<< mayorContinuo << " " << mayorDiscontinuo<< endl;

    return 0;
}

/*#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;
typedef int (*compfn)(const void*, const void*);

struct Intervalo{
    int valor;
    int inicio;
    int fin;
};

Intervalo intervalos[100003];
int contador;
int n;

int compare(struct Intervalo *elem1, struct Intervalo *elem2){
    if ( elem1->inicio < elem2->inicio){
        return -1;
    }else if (elem1->inicio > elem2->inicio){
        return 1;
    }else{
        if( elem1->fin < elem2->fin ){
            return -1;
        }else{
            return 1;
        }
    }
}


int main(){
    cin>> n;
    int mayor = 0;
    for( int i = 0; i < n; i++ ){
        cin>> intervalos[i].inicio;
        cin>> intervalos[i].fin;
        cin>> intervalos[i].valor;
        if( intervalos[i] > mayor ){
            mayor = intervalos[i];
        }
    }
    qsort( (void *) &intervalos,n,sizeof(struct Intervalo),(compfn)compare );



    return 0;
}
*/
