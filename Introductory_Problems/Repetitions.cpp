#include <bits/stdc++.h>
using namespace std;

int main(){
    string n; cin >> n;
    int max_contagem = 0;
    char last_char = 'X';
    int contagem = 1;
    for(char cu : n){
        if(cu == last_char){
            contagem++;
        }
        else{
            last_char = cu;
            contagem = 1;
        }
        max_contagem = max(contagem, max_contagem);
    }
    cout << max_contagem;
}