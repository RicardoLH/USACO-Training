/*
ID: t_a_k_e1
PROG: sprime
LANG: C++
*/

// SE PUEDE REALIZAR DE MANERA RECURSIVA, PROBANDO INICIAR CON 2,3,5,7.. MULTIPLICAR POR 10, Y SUMARLE 1,3,7,9, CHECAR SI ES PRIMO Y LLAMAR RECURSIVO DENUEVO
#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <sstream>
#include <algorithm>
#include <math.h>

using namespace std;
int n;

int primos[500];
int dp[6] = {1,2,3,5,7,9};
int dp2[5] = {1,3,7,9};
int dp3[6] = {2,3,5,7,9};
int cont = -1;

bool esPrimo(int n){
    if( n == 2 || n == 5 || n == 5 || n == 7 || n == 13 || n == 11 || n == 17 || n == 19 ){
        return true;
    }
    if( n == 1 || n%2 == 0   ){
        return false;
    }
    for( int i = 3; i <= sqrt(n); i += 2 ){
        if( n% i == 0 && n != i){
            return false;
        }
    }
    return true;
}
void imprime(int n){
    if( n == 1){
        for( int i = 0; i <= 5; i++ ){
            if( esPrimo(dp[i]) ){
                 cont++;
                primos[cont] = dp[i];
            }
        }
    }else if( n == 2 ){
        for( int d1 = 0; d1 <= 5; d1 ++ ){
            for( int d2 = 0; d2 <= 5; d2 ++ ){
                int num = dp[d2]*10 + dp[d1];
                if( esPrimo(num) ){
                    cont++;
                    primos[cont] = num;
                }
            }
        }
    }else if( n == 3 ){
        for( int d1 = 0; d1 <= 5; d1 ++ ){
            for( int d2 = 0; d2 <= 5; d2++){
                for( int d3 = 0; d3 <= 5; d3++ ){
                    int num = (dp[d3]*100) + (dp[d2]*10) + dp[d1];
                    if( esPrimo(num) && esPrimo(num/10) && esPrimo(num/100) ){
                        cont++;
                        primos[cont] = num;
                    }
                }
            }
        }
    }else if( n == 4 ){
        for( int d1 = 0; d1 <= 5; d1 ++ )
        for( int d2 = 0; d2 <= 5; d2 ++ )
        for( int d3 = 0; d3 <= 5; d3++ )
        for( int d4 = 0; d4 <= 5; d4++ ){
            int num = (dp[d4] * 1000)+(dp[d3]*100) + (dp[d2]*10) + dp[d1];
            if( esPrimo(num) && esPrimo(num/10) && esPrimo(num/100) && esPrimo(num/1000) ){
                cont++;
                primos[cont] = num;
            }
        }
    }else if( n == 5 ){
        for( int d1 = 0; d1 <= 5; d1 ++ )
        for( int d2 = 0; d2 <= 5; d2 ++ )
        for( int d3 = 0; d3 <= 5; d3++ )
        for( int d4 = 0; d4 <= 5; d4++ )
        for( int d5 = 0; d5 <= 5; d5++ ){
            int num = (dp[d5]*10000) + (dp[d4] * 1000)+(dp[d3]*100) + (dp[d2]*10) + dp[d1];
            if( esPrimo(num) && esPrimo(num/10) && esPrimo(num/100) && esPrimo(num/1000) && esPrimo(num/10000)){
                cont++;
                primos[cont] = num;
            }
        }
    }else if( n == 6 ){
        for( int d1 = 0; d1 <= 5; d1++ )
        for( int d2 = 0; d2 <= 5; d2++ )
        for( int d3 = 0; d3 <= 5; d3++ )
        for( int d4 = 0; d4 <= 5; d4++ )
        for( int d5 = 0; d5 <= 5; d5++ )
        for( int d6 = 0; d6 <= 5; d6++){
            int num = (dp[d6]*100000) + (dp[d5]*10000) + (dp[d4] * 1000)+(dp[d3]*100) + (dp[d2]*10) + dp[d1];
            if( esPrimo(num) && esPrimo(num/10) && esPrimo(num/100) && esPrimo(num/1000) && esPrimo(num/10000) && esPrimo(num/100000) ){
                cont++;
                primos[cont] = num;
            }
        }
    }else if( n == 7 ){
        for( int d1 = 0; d1 < 5; d1 ++ )
        for( int d2 = 0; d2 < 5; d2 ++ )
        for( int d3 = 0; d3 < 5; d3++ )
        for( int d4 = 0; d4 < 5; d4++ )
        for( int d5 = 0; d5 < 5; d5++)
        for( int d6 = 0; d6 < 5; d6++ )
        for( int d7 = 0; d7 <= 5; d7++){
            int num = (dp[d7] * 1000000)+(dp2[d6]*100000) + (dp2[d5]*10000) + (dp2[d4] * 1000)+(dp2[d3]*100) + (dp2[d2]*10) + dp2[d1];
            if( esPrimo(num) && esPrimo(num/10) && esPrimo(num/100) && esPrimo(num/1000) && esPrimo(num/10000) && esPrimo(num/100000) && esPrimo(num/1000000) ){
                cont++;
                primos[cont] = num;
            }
        }
    }else if( n == 8 ){
        for( int d1 = 0; d1 < 4; d1 ++ )
        for( int d2 = 0; d2 < 4; d2 ++ )
        for( int d3 = 0; d3 < 4; d3++ )
        for( int d4 = 0; d4 < 4; d4++ )
        for( int d5 = 0; d5 < 4; d5++ )
        for( int d6 = 0; d6 < 4; d6++ )
        for( int d7 = 0; d7 < 4; d7++ )
        for( int d8 = 0; d8 <= 4; d8++ ){
            int num = (dp3[d8]*10000000)+(dp2[d7] * 1000000)+(dp2[d6]*100000) + (dp2[d5]*10000) + (dp2[d4] * 1000)+(dp2[d3]*100) + (dp2[d2]*10) + dp2[d1];
            if( esPrimo(num/1000000) )
            if( esPrimo(num/100000) )
            if( esPrimo(num/10000) )
            if(esPrimo(num/1000) )
            if( esPrimo(num/100))
            if( esPrimo(num/10))
            if( esPrimo(num)){
                cont++;
                primos[cont] = num;
            }
        }
    }

}
bool compara( int num1, int num2 ){
    bool rel = num1 < num2;
    return rel;
}
int main()
{
    ofstream fout ("sprime.out");
    ifstream fin ("sprime.in");
    fin>>n;
    imprime(n);
    sort(primos,primos+cont+1,compara);
    for( int i = 0; i <= cont; i++ ){
        fout<<primos[i]<<endl;
    }

    return 0;
}
