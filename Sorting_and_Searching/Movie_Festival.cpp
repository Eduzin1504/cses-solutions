#include <bits/stdc++.h>
using namespace std;

struct comparar {
    bool operator()(const pair<long long, long long> &a,
                    const pair<long long, long long> &b) const {
        return a.second < b.second;
    }
};

int main(){
    long long N; 
    cin >> N;
    vector<pair<long long, long long>> filmes(N);

    for(auto &filme : filmes){
        cin >> filme.first >> filme.second;
    }

    sort(filmes.begin(), filmes.end(), comparar());

    long long ans = 0;
    long long endi = 0;
    for(auto &filme : filmes){
        if(filme.first >= endi){
            ans++;
            endi = filme.second;
        }
    }

    cout << ans;
}
