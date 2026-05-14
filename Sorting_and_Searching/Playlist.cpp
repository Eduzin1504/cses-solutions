#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    // compressão de valores
    vector<int> comp = A;
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());

    for (int i = 0; i < N; i++) {
        A[i] = lower_bound(comp.begin(), comp.end(), A[i]) - comp.begin();
    }

    vector<int> freq(N, 0); // freq de cada valor
    int inicio = 0, max_len = 0, distintos = 0;

    for (int fim = 0; fim < N; fim++) {
        if (freq[A[fim]] == 0) distintos++;
        freq[A[fim]]++;

        while (freq[A[fim]] > 1) {
            freq[A[inicio]]--;
            if (freq[A[inicio]] == 0) distintos--;
            inicio++;
        }

        max_len = max(max_len, fim - inicio + 1);
    }

    cout << max_len << "\n";
}
