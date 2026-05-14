#include <bits/stdc++.h>
using namespace std;
const int max_n = 1000;

int grid[max_n][max_n];
bool visited[max_n][max_n];
int row_col;
int dx[8] = {-2, -2, -1, -1,  1, 1,  2, 2};
int dy[8] = {-1,  1, -2,  2, -2, 2, -1, 1};


void bfs_cabalo(){
    queue<pair<pair<int, int>, int>> q_de_cabalos;
    q_de_cabalos.push({{0, 0}, 0});
    visited[0][0] = true; //se tiver no grid e n tiver sido visitado
    while(!q_de_cabalos.empty()){
        auto cabalos = q_de_cabalos.front();
        q_de_cabalos.pop();
        int atual_x = cabalos.first.first;
        int atual_y = cabalos.first.second;
        int valor = cabalos.second;
        grid[atual_x][atual_y] = valor;
        for(int i = 0; i<8; i++){
            int novo_x = atual_x + dx[i]; //onde ele vai no x
            int novo_y = atual_y + dy[i]; //onde ele vai no y
            if(novo_x >= 0 && novo_y >= 0 && novo_x < row_col && novo_y < row_col && !visited[novo_x][novo_y]){ //se tiver no grid e n tiver sido visitado
                visited[novo_x][novo_y] = true;
                q_de_cabalos.push({{novo_x, novo_y}, valor+1});
            }
        }
    }
}

int main(){
    cin >> row_col;
    bfs_cabalo();

    for(int i = 0; i < row_col; i++){
        for(int j = 0; j< row_col; j++){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}
