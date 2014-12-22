/*
ID: t_a_k_e1
PROG: skidesign
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
int mountains[1002];
int total;
int minCost = 1000000000;
int main(){
    ofstream fout ("skidesign.out");
    ifstream fin ("skidesign.in");
    fin>>n;
    for( int i=0; i < n; i++ ){
        fin>>mountains[i];
    }
    sort(mountains, mountains+n);
    for( int i = 0;i <= 83; i++ ){
    	int max = i + 17;
    	for( int j = 0; j < n; j++ ){
    		if( mountains[j] < i ) total += (mountains[j]-i)*(mountains[j]-i);
    		if( mountains[j] > max ) total += (mountains[j]-max)*(mountains[j]-max);
    	}
    	if( total < minCost  ) minCost = total;
    	total = 0;
    }
    fout<<minCost<<endl;
    return 0;
