#include <bits/stdc++.h>
using namespace std;

void TowerOfHanoi(int n, int a, int b, int c)//                                              <-----.
{                   //                                                                             |
    if(n==0) return;//                                                                             |
    TowerOfHanoi(n-1,a,c,b); // Move os n-1 discos menores que estão em a para b com recursividade | (todos menos o maior)
    cout<<a<<" "<<c<<endl;
    TowerOfHanoi(n-1,b,a,c); // Pega 
}


int main(){
    int N; cin >> N;
    cout << (1 << N) -1 << endl; // qttd de movimentos é 2^N - 1
    TowerOfHanoi(N, 1, 2, 3);
}


/*
TowerOfHanoi(3, A, B, C)
│
├─ TowerOfHanoi(2, A, C, B)   // mover 2 discos de A para B
│   │
│   ├─ TowerOfHanoi(1, A, B, C)   // mover 1 disco de A para C
│   │   → move(A → C)
│   │
│   ├─ move(A → B)   // mover o maior dos 2 para B
│   │
│   └─ TowerOfHanoi(1, C, A, B)   // mover 1 disco de C para B
│       → move(C → B)
│
├─ move(A → C)   // mover o maior dos 3 para C
│
└─ TowerOfHanoi(2, B, A, C)   // mover 2 discos de B para C
    │
    ├─ TowerOfHanoi(1, B, C, A)   // mover 1 disco de B para A
    │   → move(B → A)
    │
    ├─ move(B → C)   // mover o maior dos 2 para C
    │
    └─ TowerOfHanoi(1, A, B, C)   // mover 1 disco de A para C
        → move(A → C)
*/