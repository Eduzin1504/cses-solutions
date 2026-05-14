#include <bits/stdc++.h>
using namespace std;

int main(){
    int N; 
    cin >> N;

    vector<pair<int, int>> range_ref;
    vector<pair<int, int>> original_ranges;
    map<pair<int, int>, bool> contem;
    map<pair<int, int>, bool> contido;
    vector<int> max_r;
    vector<int> min_r;
    
    for(int i = 0; i < N; i++){
        int l, r; 
        cin >> l >> r;
        range_ref.push_back({l, -r});
        original_ranges.push_back({l, -r});
        contem[{l, -r}] = false;
        contido[{l, -r}] = false;
    }

    sort(range_ref.begin(), range_ref.end());

    // inicializa os vetores com tamanho N
    max_r.resize(N);
    min_r.resize(N);

    // prefix: max de r (r positivo)
    for(int i = 0; i < N; ++i){
        int r = -range_ref[i].second;
        if(i == 0) max_r[i] = r;
        else max_r[i] = max(max_r[i-1], r);
    }

    // suffix: min de r (r positivo)
    for(int i = N-1; i >= 0; --i){
        int r = -range_ref[i].second;
        if(i == N-1) min_r[i] = r;
        else min_r[i] = min(min_r[i+1], r);
    }

    // achar se contém outro (mantendo tua estrutura condicional)
    for(int i = 0; i < N; i++){ 
        if(i == N-1){
            contem[range_ref[i]] = false; // último não pode conter ninguém à direita
            continue;
        }
        int r = -range_ref[i].second; // r positivo
        if(min_r[i+1] <= r){ // existe j>i com r_j <= r_i ?
            contem[range_ref[i]] = true;
        }
        else{
            contem[range_ref[i]] = false;
        }
    }

    // achar se é contido por outro (mantendo tua estrutura condicional)
    for(int i = 0; i < N; i++){ 
        if(i == 0){
            contido[range_ref[i]] = false; // primeiro não pode ser contido por ninguém à esquerda
            continue;
        }
        int r = -range_ref[i].second; // r positivo
        if(max_r[i-1] >= r){ // existe j<i com r_j >= r_i ?
            contido[range_ref[i]] = true;
        }
        else{
            contido[range_ref[i]] = false;
        }
    }

    // printar na ordem original
    for(int i = 0; i < N; ++i){
        cout << contem[original_ranges[i]] << (i+1==N? "" : " ");
    }
    cout << endl;
    for(int i = 0; i < N; ++i){
        cout << contido[original_ranges[i]] << (i+1==N? "" : " ");
    }
    cout << endl;

    return 0;
}
