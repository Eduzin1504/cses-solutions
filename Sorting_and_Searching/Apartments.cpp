#include<bits/stdc++.h>
using namespace std;

int main(){
    int N, M, K; cin >> N >> M >> K;
    vector<int> candidatos(N);
    vector<int> apartamentos(M);
    int ans = 0;

    for(int i = 0; i < N; i++) cin >> candidatos[i];
    for(int i = 0; i < M; i++) cin >> apartamentos[i];

    sort(candidatos.begin(), candidatos.end());
    sort(apartamentos.begin(), apartamentos.end());

    int i = 0, j = 0;
    while(i < N && j < M){
        if(apartamentos[j] >= candidatos[i] - K && apartamentos[j] <= candidatos[i] + K){
            ans++;
            i++; j++;
        } else if(apartamentos[j] < candidatos[i] - K){
            j++;
        } else {
            i++;
        }
    }

    cout << ans;
}
