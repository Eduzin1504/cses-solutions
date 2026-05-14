#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; 
    cin >> n;

    priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, greater<pair<pair<int, int>, int>>> tempo; // par<tempo, entrada/saida, quem>
    vector<int> clientes(n);

    for(int i = 0; i<n; i++){
        int in, out; 
        cin >> in >> out;
        tempo.push({{in, 0}, i});
        tempo.push({{out, 1}, i});
    } 

    priority_queue<int, vector<int>, greater<int>> quartos; 
    for(int i = 1; i<=n; i++) quartos.push(i);

    int qtd = 0;
    int max_qtd = 0;
    
    while(!tempo.empty()){
        int acao = tempo.top().first.second;
        int cliente = tempo.top().second;
        tempo.pop();

        if(acao == 0){ 
            qtd += 1;
            clientes[cliente] = quartos.top();
            quartos.pop();
        }
        else{
            quartos.push(clientes[cliente]);
            qtd -= 1;
        }
        max_qtd = max(max_qtd, qtd);
    }

    cout << max_qtd << "\n";
    for(int i = 0; i<n; i++){
        cout << clientes[i] << " ";
    }
}
