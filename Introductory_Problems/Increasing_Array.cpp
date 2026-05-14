#include <bits/stdc++.h>
using namespace std;

int main(){
    long long N; cin >> N;
    long long ans = 0;
    vector<long long> sequencia(N);
    for(long long i = 0; i < N; i++){
        cin >> sequencia[i];
        if(i > 0){
            if(sequencia[i] < sequencia[i-1]){
                ans += sequencia[i-1] - sequencia[i];
                sequencia[i] = sequencia[i-1];
            }
        }
    }
    cout << ans;
}