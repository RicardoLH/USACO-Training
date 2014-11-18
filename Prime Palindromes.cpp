/*
ID: t_a_k_e1
PROG: pprime
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
int a;
int b;
ofstream fout ("pprime.out");
ifstream fin ("pprime.in");

bool esPrimo(int n){
    for( int i = 3; i <= sqrt(n); i += 2 ){
        if( n% i == 0 ){
            return false;
        }
    }
    return true;
}
void genera( int n ){
    if( n == 1 ){
        for( int i = a; i <= 9; i++ ){
            if( i == 5 || i== 7 || i == 2 || i == 3  ){
                fout<<i<<endl;
            }
        }
    }else if( n == 2 ){
        for( int d1 = 1; d1 <= 9; d1 +=2 ){
            int num = d1*10 + d1;
            if( esPrimo(num) && num >= a && num <=b ){
                fout<<num<<endl;
            }
        }
    }else if( n == 3 ){
        for( int d1 = 1; d1 <= 9; d1 += 2 ){
            for( int d2 = 0; d2 <= 9; d2++ ){
                int num = (d1*100) + (d2*10) + (d1);
                if( esPrimo(num) && num >= a && num <=b ){
                    fout<<num<<endl;
                }
            }
        }
    }else if( n == 4 ){
        for( int d1 = 1; d1 <= 9; d1 += 2 ){
            for( int d2 = 0; d2 <= 9; d2++ ){
                int num = (d1*1000) + (d2*100) +(d2*10) + (d1);
                if( esPrimo(num) && num >= a && num <=b  ){
                    fout<<num<<endl;
                }
            }
        }
    }else if( n == 5 ){
        for( int d1 = 1; d1 <= 9; d1 += 2 ){
            for( int d2 = 0; d2 <= 9; d2++ ){
                for( int d3 = 0; d3 <= 9; d3++ ){
                    int num = (d1*10000) + (d2*1000) + (d3*100) +(d2*10) + (d1);
                    if( esPrimo(num) && num >= a && num <=b  ){
                        fout<<num<<endl;
                    }
                }
            }
        }
    }else if( n == 6 ){
        for( int d1 = 1; d1 <= 9; d1 += 2 ){
            for( int d2 = 0; d2 <= 9; d2++ ){
                for( int d3 = 0; d3 <= 9; d3++ ){
                    int num = (d1*100000) + (d2*10000) + (d3*1000) + (d3*100) +(d2*10) + (d1);
                    if( esPrimo(num) && num >= a && num <=b  ){
                        fout<<num<<endl;
                    }
                }
            }
        }
    }else if( n == 7 ){
        for( int d1 = 1; d1 <= 9; d1 += 2 ){
            for( int d2 = 0; d2 <= 9; d2++ ){
                for( int d3 = 0; d3 <= 9; d3++ ){
                    for( int d4 = 0; d4 <= 9; d4++ ){
                        int num = (d1*1000000) + (d2*100000) + (d3*10000) + (d4*1000) + (d3*100) +(d2*10) + (d1);
                        if( esPrimo(num) && num >= a && num <=b  ){
                            fout<<num<<endl;
                        }
                    }

                }
            }
        }
    }else{
        for( int d1 = 1; d1 <= 9; d1 += 2 ){
            for( int d2 = 0; d2 <= 9; d2++ ){
                for( int d3 = 0; d3 <= 9; d3++ ){
                    for( int d4 = 0; d4 <= 9; d4++ ){
                        int num = (d1*10000000) + (d2*1000000) + (d3*100000) + (d4*10000) +(d4*1000) + (d3*100) +(d2*10) + (d1);
                        if( esPrimo(num) && num >= a && num <=b  ){
                            fout<<num<<endl;
                        }
                    }

                }
            }
        }
    }
}

int digitos( int n ){
    if( n < 1 ){
        return 0;
    }
    return digitos(n/10) + 1;
}
int main()
{

    fin>>a>>b;
    int d = digitos(b);
    for( int i = 1; i <= d; i++ ){
        genera(i);
    }


    return 0;
}
