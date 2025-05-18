#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
vector<int> vis;

void dfs(int node){
    vis[node]=1;

    for(auto u: g[node]){
        if(!vis[u]) dfs(u);
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    g.resize(n+1);
    vis.assign(n+1,0);

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    //The idea is to find the number of connected components(nc) and build nc-1 nodes

    int cc_size=0;
    vector<int> roads;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            roads.push_back(i);
            cc_size++;
            dfs(i);
        }
    }
    cout<<cc_size-1<<endl;
    for(int i=0;i<roads.size()-1;i++){
        cout<<roads[i]<<" "<<roads[i+1]<<endl;
    }
    return 0;
}