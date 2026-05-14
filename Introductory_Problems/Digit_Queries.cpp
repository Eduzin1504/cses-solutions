#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; 
    cin >> N;

    vector<ll> digitos_totais(19, 0);

    for (int i = 1; i <= 18; i++) {
        ll qtd_numeros = 9 * (ll)pow(10, i - 1);
        ll total = qtd_numeros * i;
        digitos_totais[i] = digitos_totais[i-1] + total;
    }

    for(int i = 0; i<N; i++){
        ll k; cin >> k;
        ll atual_blocos_digitos = lower_bound(digitos_totais.begin(), digitos_totais.end(), k) - digitos_totais.begin();

        ll digitos_atualizados = k - digitos_totais[atual_blocos_digitos-1] - 1;
        
        long long numero = (long long)pow(10, atual_blocos_digitos - 1) + digitos_atualizados / atual_blocos_digitos;

        ll posicao_no_numero = digitos_atualizados % atual_blocos_digitos;

        string s = to_string(numero);
        cout << s[posicao_no_numero] << "\n";
    }
}
