#include <bits/stdc++.h>
using namespace std;

int main(){
    int X; cin >>X;
    for(int N = 1; N<X+1; N++){
        int quadrados_calc = N*N;
        int n_pode = 0;
        if(N==1){
            //retornar 0
            cout << "0"<< endl;
            continue;
        }
        if(N==2){
            //retornar 6
            cout << '6'<< endl;
            continue;
        }
        if(N>=3){
            //definir 4 cantos como 2
            quadrados_calc -= 4;
            n_pode += 4*2;
        }
        if(N==3){
            //retornar 28
            cout << "28"<< endl;
            continue;
        }
        if(N>=4){
            //definir 8 quase cantos como 3
            quadrados_calc -= 8;
            n_pode += 8*3;
            //definir 4 semicanttos como 4
            quadrados_calc -= 4;
            n_pode += 4*4;
        }
        if(N>=5){
            //definir (N-4) * 4 lados como 4
            quadrados_calc -= (N-4) * 4;
            n_pode += ((N-4) * 4) * 4;
            //definir (N-4) * 4 semilados como 6
            quadrados_calc -= (N-4) * 4;
            n_pode += ((N-4) * 4) * 6;
        }
        if(N>=5){
            //todos centros como 8
            n_pode += quadrados_calc * 8;
        }
        
        //com tudo isso, bloqueei todas as possíveis posições
        cout << ((long long)N*N * ((long long)N*N - 1) / 2) - ((long long)n_pode / 2) << endl;


    }
}