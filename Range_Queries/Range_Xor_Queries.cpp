#include <bits/stdc++.h>
using namespace std;

long long n;
vector<long long> arvore;
long long neutro = 0;

long long f(long long a, long long b){
    return a ^ b;
}

void build(vector<long long> &a) {
    for(long long i = 0; i < n; i++) arvore[n+i] = a[i];
    for(long long i = n-1; i >= 1; i--) arvore[i] = f(arvore[2*i], arvore[2*i+1]);
}

long long query(long long l, long long r){
    l += n; r += n;
    long long ans = neutro;
    while(l <= r) {
        if(l%2 == 1) ans = f(ans, arvore[l++]);
        if(r%2 == 0) ans = f(ans, arvore[r--]);
        l /= 2; r /= 2;
    }
    return ans;
}

int main(){
    long long Q; 
    cin >> n >> Q;
    vector<long long> vetorzao(n);
    arvore.assign(2 * n, neutro);
    for(long long &valor : vetorzao) cin >> valor;
    build(vetorzao);
    while(Q--){
        long long a, b; 
        cin >> a >> b;
        a--; b--;
        cout << query(a, b) << endl;
    }
}
