#include <bits/stdc++.h>
using namespace std;

int N; 

void code_de_vdd(string o_de_agr, int numero, bool inverso=false){
    if(numero == N){
        cout << o_de_agr << endl;
        return;
    }
    if(!inverso){
        o_de_agr.push_back('0');
        code_de_vdd(o_de_agr, numero+1, false);
        o_de_agr.back() = '1';
        code_de_vdd(o_de_agr, numero+1, true);
    } else {
        o_de_agr.push_back('1');
        code_de_vdd(o_de_agr, numero+1, false);
        o_de_agr.back() = '0';
        code_de_vdd(o_de_agr, numero+1, true);
    }
}

int main(){
    cin >> N;
    string nada = "";
    code_de_vdd(nada, 0);
}
