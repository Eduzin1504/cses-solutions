#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, K; cin >> N >> K;

    vector<int> kids(N);
    vector<bool> ja_foi(N);

    for(int i = 0; i<N; i++) {cin >> kids[i]; ja_foi[i] = false;}

    sort(kids.begin(), kids.end());
   
    int l = 0;
    int r = N-1;
    int ans = 0;
    while(l < N){ //O(N)
        if(ja_foi[l]){l++; continue;}
        while(r > l){ //O(N)
            if(ja_foi[r]){r--; continue;}
            if(kids[l] + kids[r] <= K){
                ja_foi[r] = true;
                break;
            }
            r--;
        }
        ja_foi[l] = true;
        ans++;
        l++;
    }
    cout << ans;
}