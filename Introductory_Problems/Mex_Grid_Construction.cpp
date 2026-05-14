#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<set<int>> rows(n), cols(n); // sets para cada linha e coluna
    vector<vector<int>> ans(n, vector<int>(n, 0));
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    queue<pair<int,int>> quadrado;
    quadrado.push({0,0});
    visited[0][0] = true;

    while(!quadrado.empty()) {
        auto [i,j] = quadrado.front();
        quadrado.pop();

        // achar o menor número não usado na linha nem na coluna
        int temp_ans = 0;
        while(rows[i].count(temp_ans) || cols[j].count(temp_ans)) temp_ans++;

        ans[i][j] = temp_ans;
        rows[i].insert(temp_ans);
        cols[j].insert(temp_ans);

        // adicionar filhos
        if(i+1 < n && !visited[i+1][j]) {
            quadrado.push({i+1,j});
            visited[i+1][j] = true;
        }
        if(j+1 < n && !visited[i][j+1]) {
            quadrado.push({i,j+1});
            visited[i][j+1] = true;
        }
    }

    // printar resultado
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}
