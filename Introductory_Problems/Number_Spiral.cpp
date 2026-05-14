#include <bits/stdc++.h>
using namespace std;

int main(){
    long long N; cin >> N;
    for(long long i = 0; i < N; i++){
        long long row, col; cin >> row >> col;

        if(row == col){
            cout << row * col - (row - 1) << endl;
        }
        else{
            long long valor_max = max(row, col);
            long long diagonal = (valor_max * valor_max) - (valor_max - 1);
            long long dif;
            if(row > col){
                if(row % 2 == 0){
                    dif = row - col;
                }
                else{
                    dif = -(row - col);
                }
            }
            else{
                if(col % 2 == 0){
                    dif = -(col - row);
                }
                else{
                    dif = col - row;
                }
            }
            cout << diagonal + dif << endl;
        }
    }
}
