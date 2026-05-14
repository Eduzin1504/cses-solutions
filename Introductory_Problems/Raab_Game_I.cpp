#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template<class T>
using ordered_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;

int main(){
    int T; cin >> T;

    for(int i = 0; i < T; i++){
        int n, a, b; cin >> n >> a >> b;

        //antes de qlqr coisa ver se ambos são 0 e printar os valores já empatando tudo
        if(a == 0 && b == 0){
            cout << "YES\n";
            for(int x = 1; x <= n; x++) cout << x << " ";
            cout << "\n";
            for(int x = 1; x <= n; x++) cout << x << " ";
            cout << "\n";
            continue;
        }

        //ver se é possível
        if ((a + b > n) || (a == 0 && b != 0) || (b == 0 && a != 0)){
            cout << "NO\n";
            continue;
        }
        else{
            cout << "YES\n";
        }

        //criar os dois sets
        ordered_set<int> set1; for(int x = 1; x<=n; x++){set1.insert(x);}
        ordered_set<int> set2; for(int x = 1; x<=n; x++){set2.insert(x);} 

        //hora de remover os "empates"
        vector<pair<int,int>> ans;
        while(a+b < (int)set1.size()){
            ans.push_back({*prev(set1.end()), *prev(set2.end())});
            set1.erase(*prev(set1.end()));
            set2.erase(*prev(set2.end()));
        }

        // ======= substituição mínima aqui: forma simples e correta =======
        // agora set1 e set2 têm os mesmos elementos, tamanho m = a + b
        vector<int> rem(set1.begin(), set1.end());
        int m = rem.size(); // = a + b, e aqui sabemos que m >= 2 (casos impossíveis já filtrados)

        // emparelhar rem[i] com rem[(i + a) % m] garante exatamente 'a' vitórias para jogador1
        for(int i = 0; i < m; ++i){
            int j = (i + a) % m;
            ans.push_back({rem[i], rem[j]});
        }
        // =================================================================

        //dou um jeito de printar agr as ans
        for(pair<int, int> par : ans){
            cout << par.first << " ";
        }
        cout << "\n";
        for(pair<int, int> par : ans){
            cout << par.second << " ";
        }
        cout << "\n";
    }
}
