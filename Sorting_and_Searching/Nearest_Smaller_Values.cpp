#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n;
    vector<int> x(n+1);
    for (int i = 1; i <= n; i++) cin >> x[i];

    vector<int> ans(n+1);
    stack<pair<int,int>> st; // {valor, posicao}

    for (int i = 1; i <= n; i++) {
        while (!st.empty() && st.top().first >= x[i]) {
            st.pop();
        }

        if (st.empty()) ans[i] = 0;
        else ans[i] = st.top().second;

        st.push({x[i], i});
    }

    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << "\n";
}
