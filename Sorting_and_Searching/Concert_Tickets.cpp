#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M; cin >> N >> M;
    multiset<int> tickets;

    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        tickets.insert(x);
    }

    for (int i = 0; i < M; i++) {
        int caba; cin >> caba;

        auto it = tickets.upper_bound(caba);
        if (it == tickets.begin()) {
            cout << -1 << "\n";
        } else {
            --it;
            cout << *it << "\n";
            tickets.erase(it);
        }
    }
}
