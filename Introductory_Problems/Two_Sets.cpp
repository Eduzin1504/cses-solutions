#include <bits/stdc++.h>
using namespace std;

int main(){
    int N; cin >> N;
    int total = 0; for(int i = 1; i<= N; i++){total+=i;}
    if(total%2 == 1){cout << "NO"; return 0;}
    cout << "YES" << endl;
    vector<int> set1; int t_set1 = 0;
    vector<int> set2; int t_set2 = 0;
    if(N%2 == 1){set2.push_back(N); N--;; t_set2++;}
    int l = 1;
    int r = N;
    int atual = 1;
    while(l < r){
        if(atual == 1){
            set1.push_back(l);
            set1.push_back(r);
            t_set1 += 2;
            atual = 2;
        }
        else if(atual == 2){
            set2.push_back(l);
            set2.push_back(r);
            atual = 1;
            t_set2 += 2;
        }
        l++;
        r--;
    }
    cout << t_set1 << endl;
    for(int x : set1){
        cout << x << " ";
    }
    cout << endl;
    cout << t_set2 << endl;
    for(int x : set2){
        cout << x << " ";
    }
}