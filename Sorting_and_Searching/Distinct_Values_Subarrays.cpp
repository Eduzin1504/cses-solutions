#include <bits/stdc++.h>
using namespace std;
/*
BASICAMENTE É UMA LÓGICA MTO FODA ONDE
VC VAI POR CADA "SUBARRAY" OU SEJA ATÉ O ELEMENTO SE REPETIR USANDO UMA SLIDING WINDOW

QUE FUNCIONA O SEGUINTE

COMEÇA A WINDOW L E R EM 0 E VAI ANDANDO O R CO
*/

long long countDistinctSubarrays(const vector<int>& arr) {
    unordered_set<int> seen;
    long long total = 0;
    int l = 0;
    int n = arr.size();

    for (int r = 0; r < n; r++) {
        while (seen.count(arr[r])) {
            seen.erase(arr[l]);
            l++;
        }
        seen.insert(arr[r]);
        total += r - l + 1;
    }

    return total;
}

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];

    cout << countDistinctSubarrays(A) << "\n";

    return 0;
}
