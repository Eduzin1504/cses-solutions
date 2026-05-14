#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M; cin >> N >> M;
    vector<long long> valores(N);
    vector<long long> prefix_sum(N);
    for(int i = 0; i < N; i++) {
        cin >> valores[i];
        prefix_sum[i] = valores[i] + (i > 0 ? prefix_sum[i-1] : 0);
    }
    for(int i = 0; i < M; i++) {
        int l, r; cin >> l >> r;
        l--; r--;
        cout << prefix_sum[r] - (l > 0 ? prefix_sum[l-1] : 0) << endl;
    }
}
