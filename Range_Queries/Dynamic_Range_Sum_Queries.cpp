#include <bits/stdc++.h>
using namespace std;

long long n;
vector<long long> arvore;
long long neutro = 0;

long long f(long long x, long long y){
    return x+y;
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

void update(long long pos, long long val){
    pos = n + pos;
    arvore[pos] = val;
    for(pos /= 2; pos >= 1; pos /= 2)
        arvore[pos] = f(arvore[2*pos], arvore[2*pos+1]);
}

int main(){
    long long Q; 
    cin >> n >> Q;
    vector<long long> vetorzao(n);
    arvore.assign(2 * n, neutro);
    for(long long &valor : vetorzao) cin >> valor;
    build(vetorzao);
    while(Q--){
        long long q, a, b; 
        cin >> q >> a >> b;
        if(q == 2){
            a--; b--;
            cout << query(a, b) << endl;
        }
        else{
            a--;
            update(a, b);
        }
    }
}
