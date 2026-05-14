#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    queue<int> q;
    for (int i = 1; i <= N; i++) q.push(i);

    while (!q.empty()) {
        // passa a primeira pessoa para o fim (pula)
        q.push(q.front());
        q.pop();

        // elimina a próxima
        cout << q.front() << " ";
        q.pop();
    }
}
