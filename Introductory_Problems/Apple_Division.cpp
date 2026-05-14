#include <bits/stdc++.h>
using namespace std;
long long ans = 1e9;
long long total = 0;
long long N;
vector<long long> vetorzao;

void bruteforce(long long i, long long soma){
    ans = min(abs((total - soma) - soma), ans);
    if(i == N-1){
        return;
    }
    bruteforce(i+1, soma);
    bruteforce(i+1, soma + vetorzao[i]);
}

int main(){
    cin >> N;
    vetorzao.resize(N);
    for(long long &componente : vetorzao){cin >> componente; total += componente;} 
    bruteforce(0, 0);
    cout << ans;
}