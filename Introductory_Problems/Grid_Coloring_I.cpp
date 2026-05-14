#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m; cin >> n >> m;
    char grid[n][m];
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> grid[i][j];
        }
    }

    char ans[n][m]; // apenas declarar, não inicializar com "X"

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            set<char> referencia{'A', 'B', 'C', 'D'};
            
            if(i+1 < n){if(referencia.count(ans[i+1][j])) referencia.erase(ans[i+1][j]);}//remover o vizinho de cima
            if(i-1 >= 0){if(referencia.count(ans[i-1][j])) referencia.erase(ans[i-1][j]);}//remover o vizinho de baixo
            if(j+1 < m){if(referencia.count(ans[i][j+1])) referencia.erase(ans[i][j+1]);}//remover o vizinho da equerda
            if(j-1 >= 0){if(referencia.count(ans[i][j-1])) referencia.erase(ans[i][j-1]);}//remover o vizinho da direita
            
            if(referencia.count(grid[i][j])) referencia.erase(grid[i][j]);//remover o atual no grid inicial
            
            if(referencia.empty()){cout << "IMPOSSIBLE"; return 0;} else{
                ans[i][j] = *referencia.begin();
            }
        }
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cout << ans[i][j];
        }
        cout << endl;
    }

}
