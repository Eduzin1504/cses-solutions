#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long X;
    int N;
    cin >> X >> N;

    set<long long> semaforos;
    multiset<long long> intervalos;

    semaforos.insert(0);
    semaforos.insert(X);
    intervalos.insert(X);

    for(int i = 0; i < N; i++) {
        long long p;
        cin >> p;

        auto it = semaforos.lower_bound(p);
        long long prox = *it;
        long long ant = *prev(it);

        semaforos.insert(p);

        intervalos.erase(intervalos.find(prox - ant));
        intervalos.insert(p - ant);
        intervalos.insert(prox - p);

        cout << *intervalos.rbegin() << " ";
    }

    cout << "\n";
}
