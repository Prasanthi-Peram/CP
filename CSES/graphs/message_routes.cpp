#include <bits/stdc++.h>
using namespace std;
#define INF 1000000007

vector<vector<int>> g;
vector<int> vis;
vector<int> dist;

void bfs(int node){
    queue<int>
}

int main(){
    int n,m;
    cin>>n>>m;

    g.resize(n+1);
    vis.assign(n+1,0);
    dist.assign(n+1,-INF);

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;

        g[a].push_back(b);
        g[b].push_back(a);
        
    }

    vis[1]=true;
    bfs(1);
    return 0;
}