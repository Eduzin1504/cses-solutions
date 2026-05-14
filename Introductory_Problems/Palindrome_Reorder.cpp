#include <bits/stdc++.h>
using namespace std;

int main(){
    string input; cin >> input;

    map<char, int> caracteres;

    for(char caracter : input){
        caracteres[caracter]++;
    }

    set<pair<int, char>> set_;
    char centro;
    bool tem_centro = false;
    for(pair<char, int> caracter : caracteres){
        if(caracter.second%2 == 1){
            if(!tem_centro){
                centro = caracter.first;
                set_.insert({caracter.second-1, caracter.first});
                tem_centro = true;
                continue;
            }
            else{
                cout << "NO SOLUTION";
                return 0;
            }
        }
        set_.insert({caracter.second, caracter.first});
    }

    deque<char> dequeueue;
    if(tem_centro) dequeueue.push_back(centro);
    for(pair<int, char>caracter : set_){
        int contador = 0;
        for(int i = 0; i < caracter.first; i++){
            if(contador == 0){
                dequeueue.push_front(caracter.second);
                contador = 1;
            }
            else if(contador == 1){
                dequeueue.push_back(caracter.second);
                contador = 0;
            }
        }
    }

    for(char caracter : dequeueue){
        cout << caracter;
    }
}