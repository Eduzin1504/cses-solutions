#include <bits/stdc++.h>

using namespace std;



int main() {

    int n; cin >> n;

    vector<long long> coins(n);

    for (int i = 0; i < n; i++) cin >> coins[i];

    sort(coins.begin(), coins.end());



    long long target = 1;

    for (long long c : coins) {

        if (c > target) break; 

        target += c;

    }

    cout << target << "\n";

}
