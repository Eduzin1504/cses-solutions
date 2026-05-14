#include <bits/stdc++.h>
using namespace std;


int main(){
    long long n; cin >> n;

    vector<pair<long long, long long>> tasks(n);
    for(auto &task : tasks) cin >> task.first >> task.second;
    sort(tasks.begin(), tasks.end());
    
    long long tempo = 0;
    long long ans = 0;
    for(auto &task : tasks){
        tempo += task.first;
        ans += task.second - tempo;
    }

    cout << ans;
}