#include  <bits/stdc++.h>
using namespace std;

long long elevado_mod(long long N, long long MOD){
    long long ans = 1;
    for(long long i = 1; i <= N; i++){
        ans = (ans * 2) % MOD;
    }
    return ans;
}

int main(){
    long long N; cin >> N;
    cout << elevado_mod(N, 1e9+7);
}
