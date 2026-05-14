#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N; cin >> N;

    cout << N; // imprime o primeiro número da sequência
    while(N != 1){
        if(N%2 == 0){ // se for par
            N /= 2;
        }
        else { // se for ímpar
            N = N * 3 + 1;
        }
        cout << " " << N; // imprime os próximos números com espaço antes
    }
    cout << "\n";
}
