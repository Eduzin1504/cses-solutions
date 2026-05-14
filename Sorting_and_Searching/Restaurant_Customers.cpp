#include <bits/stdc++.h>
using namespace std;

int main(){
    int N; cin >> N;
    map<int, int> tempo;
    for(int i = 0; i<N; i++){
        int in, out; cin >> in >> out;
        tempo[in] += 1;
        tempo[out] -= 1;
    }
    int atual = 0;
    int max_atual = 0;
    for(auto fds : tempo){
        int valor = fds.second;
        atual += valor;
        max_atual = max(atual, max_atual);
    }
    cout << max_atual;
}