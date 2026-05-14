// Source: https://usaco.guide/general/io


// APRENDI A COMO GERAR TODAS AS POSSIBILIDADES USANDO RECURSIVIDADE
#include <bits/stdc++.h>
using namespace std;
int total = 0;



void chess_(int coluna, map<int, vector<int>> board){
    if(coluna == 9){
        total += 1;
        return;
    }
    for(int i : board[coluna]){
        //declaro a cópia
        map<int, vector<int>> board_copia = board;
        

        //remoção das próximas colunas e diagonais
        for (int x = coluna + 1; x < 9; x++) {
            int diferenca = x - coluna;

            // remove a linha (valor i)
            auto it = find(board_copia[x].begin(), board_copia[x].end(), i);
            if (it != board_copia[x].end()) {
                board_copia[x].erase(it);
            }

            // remove a diagonal (valor i + diferenca)
            if (i + diferenca < 9) {
                auto it2 = find(board_copia[x].begin(), board_copia[x].end(), i + diferenca);
                if (it2 != board_copia[x].end()) {
                    board_copia[x].erase(it2);
                }
            }

            // remove a diagonal (valor i - diferenca)
            if (i - diferenca >= 0) {
                auto it3 = find(board_copia[x].begin(), board_copia[x].end(), i - diferenca);
                if (it3 != board_copia[x].end()) {
                    board_copia[x].erase(it3);
                }
            }
        }

        chess_(coluna+1, board_copia);
    }
}



int main() {   
    // criação do map
    map<int, vector<int>> board;
    for(int i = 1; i < 9; i++){
        string temp; cin >> temp;
        for(int x = 1; x < 9; x++){
            if(temp[x-1] == '.'){
                board[i].push_back(x);
            }
        }
    }
    //rodar a função
    chess_(1, board);
    cout << total;
}
