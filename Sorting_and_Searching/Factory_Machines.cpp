#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll fazer_todos(const vector<ll>& tempos, ll N){
    ll ans = 0;
    for(ll tempo: tempos){
        ans += N/tempo;
    }
    return ans;
}

int main(){
    ll n, t; cin >> n >> t;
    vector<ll> tempos(n);
    for(int i = 0; i<n; i++) cin >> tempos[i];

    ll teto = *min_element(tempos.begin(), tempos.end());
    ll l = 0, r = t * teto; 

    while(l < r){
        ll mei = (l+r)/2;
        if(fazer_todos(tempos, mei) >= t) r = mei;
        else l = mei+1;
    }

    cout << l;
}
