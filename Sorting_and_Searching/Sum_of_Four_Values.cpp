#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x; cin >> n >> x;

    vector<pair<int, int>> values(n);
    for(int i = 0; i<n; i++){
        cin >> values[i].first;
        values[i].second =  i+1;
    }
    sort(values.begin(), values.end());

    map<int, pair<int, int>> pares; 
    int l = 0;
    while(l < n){
        for(int r = l+1; r < n; r++){
            if(pares.count(x-(values[l].first + values[r].first))){
                cout << values[l].second << " " 
                     << values[r].second << " " 
                     << pares[x-(values[l].first + values[r].first)].first << " "
                     << pares[x-(values[l].first + values[r].first)].second;
                return 0;
            }
        }

        for(int b = l-1; b >= 0; b--){
            pares[values[l].first + values[b].first] = {values[l].second, values[b].second};
        }

        l++;
    }

    cout << "IMPOSSIBLE";
}
