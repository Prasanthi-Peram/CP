#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
vector<int> sz;

void dfs(int nn, int pp){
    sz[nn]=1; //In a bottom-up dp the parent knows the ch values..dfs,nn=f(ch,nn).

    for(auto u: g[nn]){
        if(u!=pp){
            dfs(u,nn);
            sz[nn]+=sz[u];
        }
    }
}
int main(){
    int n;
    cin>>n;
    g.assign(n+1,{});
    sz.assign(n+1,0);

    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1,-1);
    for(int i=1;i<=n;i++) cout<<sz[i]<<" ";
    return 0;
}