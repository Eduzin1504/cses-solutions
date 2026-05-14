#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N; 
    cin >> N;
    long long ans = 0;

    while (N > 0) {
        long long carry = (N % 10 >= 5);        // 1 se o último dígito é 5..9
        N = (N / 10) * 2 + carry;               // N = floor(N/5)
        ans += N;                                // soma floor(N/5)
    }

    cout << ans;
}
