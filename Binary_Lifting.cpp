#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

//practise question : https://cses.fi/problemset/task/1687/

int up[200005][20];

void binaryLifting(vector<int> adj[],int node,int par){
    up[node][0] = par;
    for(int i = 1;i<20;i++){
        if(up[node][i-1] != -1){
            up[node][i] = up[up[node][i-1]][i-1];
        }
        else{
            up[node][i] = -1;
        }
    }
    for(auto child:adj[node]){
        if(child == par)continue;
        binaryLifting(adj,child,node);
    }
}

int lift_node(vector<int> adj[],int node,int jump_req){
    if(node == -1 || jump_req == 0){
        return node;
    }
    for(int i = 19;i>=0;i--){
        if(jump_req >= (1ll<<i)){
            return help(adj,up[node][i],jump_req-(1ll<<i));
        }
    }
    return 0;
}

void solve() {
    int n,q;
    cin >> n>>q;
    vector<int> adj[n + 1];
    for (int i = 2;i<=n; i++) {
        int u;cin>>u;
        adj[i].push_back(u);
        adj[u].push_back(i);
    }
    binaryLifting(adj,1,-1);
    while(q--){
        int node,k;cin>>node>>k;
        cout<<help(adj,node,k)<<endl;
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}
