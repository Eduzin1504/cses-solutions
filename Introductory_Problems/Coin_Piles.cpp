#include <bits/stdc++.h>
using namespace std;

int main(){
    int N; cin >>N;
    while(N--){
        int A, B; cin >> A >> B;
        if((A+B) % 3 == 0 && A/2 <= B && B/2 <= A){
            cout<< "YES"<< endl;
        }
        else{
            cout<< "NO" << endl;
        }
    }
}