#include <bits/stdc++.h>
using namespace std;

int main(){
    int N; cin >> N;
    vector<int> posicoes(N+1);
    for(int i = 0; i<N; i++){
        int atual;cin >> atual;
        posicoes[atual] = i;
    }
    int ans = 1;
    for(int i = 0; i<N; i++){
        if(posicoes[i] > posicoes[i+1]) ans++;
    }
    cout << ans;
}