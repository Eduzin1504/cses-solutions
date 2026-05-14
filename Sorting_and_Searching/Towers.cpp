#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;
    int ans = 0;
    multiset<int> topos;
    for(int i = 0; i<N; i++){
        int atual; cin >> atual;
        auto it = topos.upper_bound(atual);
        if(it == topos.end()){
            topos.insert(atual);
            ans++;
        }
        else{
            topos.erase(it);
            topos.insert(atual);
        }
    }       
    cout << ans;
}