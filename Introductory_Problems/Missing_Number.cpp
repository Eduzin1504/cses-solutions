#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N; cin >> N;
    unordered_set<long long> sequencia;
    for(long long i = 0; i < N; i++) {
        long long temp; cin >> temp;
        sequencia.insert(temp);
    }
    for(long long i = 1; i <= N + 1; i++) {
        if(!sequencia.count(i)) {
            cout << i << "\n";
            break;
        }
    }
}
