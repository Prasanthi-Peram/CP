#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<string> a;
vector<vector<int>> vis;

using state= pair<int,int>;
vector<int> dx={1,0,-1,0};
vector<int> dy={0,1,0,-1};

bool isValid(int i,int j){
    return (i >= 0 && i < n && j >= 0 && j < m);
}
vector<state> neighbors(int i,int j){
    vector<state> val;
    //int nx,ny;
    for(int d=0;d<4;d++){

      int nx=i+dx[d];
      int ny=j+dy[d];

        if(isValid(nx,ny)&& a[nx][ny]!='#'){
            val.push_back({nx,ny});
        }
    }
    return val;
}

void dfs(int i,int j){

    vis[i][j]=1;

    for(auto u: neighbors(i,j)) {
        if(!vis[u.first][u.second])
        dfs(u.first,u.second);
    }
}
int main(){
   // int n,m;
    cin>>n>>m;
    a.resize(n);
    vis.assign(n,vector<int>(m,0));
    for(int i=0;i<n;i++) cin>>a[i];

    int comp=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j]==0 && a[i][j]=='.'){
                //cout<<i<<" "<<j;
                comp++;
                //cout<<" "<<comp<<endl;
                dfs(i,j);
            }
        }
    }
    cout<<comp<<endl;

    return 0;
}