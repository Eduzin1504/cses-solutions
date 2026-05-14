#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    long long max_ending_here = a[0];
    long long max_so_far = a[0];

    for (int i = 1; i < n; i++) {
        max_ending_here = max(a[i], max_ending_here + a[i]);
        max_so_far = max(max_so_far, max_ending_here);
    }

    cout << max_so_far << "\n";
}
