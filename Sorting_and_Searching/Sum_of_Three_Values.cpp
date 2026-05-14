#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x; cin >> n >> x;
    
    vector<pair<int, int>> valores(n);

    for(int i = 0; i<n; i++){
        cin >> valores[i].first;
        valores[i].second = i+1; // +1 se quiser índices 1-based
    }

    sort(valores.begin(), valores.end());

    for(int p = 0; p<n; p++){
        int l = 0, r = n-1;
        while(l < r){
            if(l == p){ l++; continue; }
            if(r == p){ r--; continue; }

            int soma = valores[p].first + valores[l].first + valores[r].first;
            if(soma == x){
                cout << valores[p].second << " " << valores[l].second << " " << valores[r].second << "\n";
                return 0;
            }
            if(soma > x) r--;
            else l++;
        }
    }

    cout << "IMPOSSIBLE\n";
}
