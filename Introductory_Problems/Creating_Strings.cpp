#include <bits/stdc++.h>
using namespace std;

long long fatorial(int n){
    long long res = 1;
    for(int i = 2; i <= n; i++) res *= i;
    return res;
}

int main(){
    string question; cin >> question;

    long long total = fatorial(question.size());
    map<char,int> freq;
    for(char c : question) freq[c]++;
    for(auto [c,f] : freq) total /= fatorial(f);

    cout << total << endl;

    sort(question.begin(), question.end());
    do{
        cout << question << endl;
    } while(next_permutation(question.begin(), question.end()));
}
