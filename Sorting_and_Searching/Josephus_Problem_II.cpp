#include <bits/stdc++.h>
using namespace std;
 
//build a sum segtree with size n. each leaf has value 1.
void build(vector<int>& tree){
    int n = tree.size() / 2;
    for(int i = n; i < 2 * n; i++){
        tree[i] = 1;
    }
    for(int i = n-1; i > 0; i--){
        tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }
}
 
int query(vector<int>& tree, int lo, int hi){
    lo += tree.size() / 2;
    hi += tree.size() / 2;
    int res = 0;
    while(lo < hi){
        if(lo & 1   )res += tree[lo++];
        if(!(hi & 1))res += tree[hi--];
        lo >>= 1;
        hi >>= 1;
    }
    if(lo == hi)res += tree[lo];
    return res;
}
 
//if you start at leaf number start, what leaf do you need to be at to traverse amt nodes?
int findnext(vector<int>& tree, int start, int amt){
 
    if(start != 0){
        int to_end = query(tree, start, tree.size()/2);
        if(to_end < amt) return findnext(tree, 0, amt - to_end);
    }
 
    int node = start + tree.size()/2;
 
 
    //find the FIRST lowest leaf that is greater than or equal to amt, then step back down to search.
    while(tree[node] < amt){
        if(node & 1){
            amt -= tree[node++];
        }
        node >>= 1;
    }
    while(node < tree.size() / 2){
        if(tree[node * 2] < amt){
            amt -= tree[node * 2];
            node = node * 2 + 1;
        }else{
            node = node * 2;
        }
    }
    return node - tree.size() / 2;
}
 
//update the idxth leaf to amt
void update(vector<int>& tree, int idx, int amt){
    int node = idx + tree.size() / 2;
    int diff = amt - tree[node];
    while(node >= 1){
        tree[node] += diff;
        node >>= 1;
    }
}
 
void solve(){
    int n, k;
    cin >> n >> k;
    k++;
    vector<int> tree(2 * n);
    build(tree);
 
    int location = 0;
    for(int remaining_nodes = n; remaining_nodes >= 1; remaining_nodes--){
        //k isn't the one that you take, it's the one after: so it's effectively one indexed and you have to convert to 0 and back
        int take_node = findnext(tree, location, ((k-1) % remaining_nodes) + 1);
        cout << take_node + 1;
        if(remaining_nodes != 1)cout << " ";
        update(tree, take_node, 0);
        //find the next 1 element, that's where you should start
        if(remaining_nodes != 1)location = findnext(tree, take_node, 1);
    }
    cout << "\n";
    return;
}
 
int main() {
    // make I/O operations faster
    std::ios::sync_with_stdio(false);
    // untie std::cin from std::cout
    std::cin.tie(nullptr);
 
    solve();
 
    return 0;
}