#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// comparação para ordenar o vector de ranges
struct cmp2 {
    bool operator()(const pair<pair<long long,long long>, long long>& a, const pair<pair<long long,long long>, long long>& b) const {
        if (a.first.first != b.first.first) 
            return a.first.first < b.first.first;
        return a.first.second > b.first.second;
    }
};

// ordered_set padrão sem cmp customizado
template<class T>
using ordered_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;


int main(){
    long long N; cin >> N;
    vector<long long> contem;
    contem.assign(N, 0);
    vector<long long> contido;
    contido.assign(N, 0);
    vector<pair<pair<long long, long long>, long long>> ranges_ordenados;
    for(long long i = 0; i < N; i++){
        long long l, r; cin >> l >> r;
        ranges_ordenados.push_back({{l, r}, i});
    }
    sort(ranges_ordenados.begin(), ranges_ordenados.end(), cmp2());
    

    //achar contained
    ordered_set<pair<long long, long long>> ranges_contained;
    for(auto range : ranges_ordenados){
        // CONSULTA ANTES DE INSERIR — conta quantos já vistos têm r >= current.r
        contido[range.second] = ranges_contained.size() - ranges_contained.order_of_key({range.first.second, LLONG_MIN});
        // agora insere o atual
        ranges_contained.insert({range.first.second, range.second});
    }

    //achar contains
    ordered_set<pair<long long, long long>> ranges_contains;
    for(long long i = N-1; i >= 0; i--){
        auto range = ranges_ordenados[i];
        // CONSULTA ANTES DE INSERIR — conta quantos (dos posteriores) têm r <= current.r
        contem[range.second] = ranges_contains.order_of_key({range.first.second, LLONG_MAX});
        // agora insere o atual
        ranges_contains.insert({range.first.second, range.second});
    }

    for(long long ans : contem) cout << ans << " ";
    cout << endl;
    for(long long ans : contido) cout << ans << " ";
}
