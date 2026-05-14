#include <bits/stdc++.h>
using namespace std;

int main(){
    string string_to_reorder;
    cin >> string_to_reorder;
    int size = string_to_reorder.length();

    vector<int> alphabet(26, 0); // corrigido: inicializa o vetor com 26 zeros
    for(char letra : string_to_reorder){
        alphabet[letra -  'A']++; // conta frequência de cada letra
    }

    string ans;

    while((int) ans.length() < size){
        bool true_false = false;
        for(int i = 0; i<26; i++){
            if(alphabet[i] > 0 && (ans.empty() || ans.back() != ('A' + i))){ // bascicamente se tiver alguma letra e ele tiver vazio ou o último for igual ao prox
                alphabet[i]--;
                ans+= ('A' + i);
                // posso acabar com essa letra?
                int sufixo = size - (int)ans.length(); // a diferença
                bool da_pra_fechar = true;

                for(int j = 0; j<26; j++){ // testar essa letra se dá pra usar caa uma do alphabeto
                    if(i != j){ // verificar se dá pra repetir/é possível as outras letras
                        if(alphabet[j] > (sufixo+1)/2){ // se n der já passa pro prox
                            da_pra_fechar = false;
                            break;
                        }
                    }
                    else{
                        if(alphabet[j] > sufixo/2){ // msm teste só que para a própia letra
                            da_pra_fechar = false;
                            break;
                        }
                    }
                }

                if(da_pra_fechar){ // define se o algoritmo n parou em nenhum momento
                    true_false = true;
                    break;
                }
                else{
                    alphabet[i]++; // desfaz o adicionar se perceber que não dá pra colocar essa letra
                    ans.pop_back(); 
                }
            }
        }
        if(!true_false){
            break;
        }
    }
    if(ans.empty()){ // se não conseguiu gerar
        cout << "-1\n";
    }
    else{
        cout << ans << "\n";
    }
}
