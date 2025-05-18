#include <bits/stdc++.h>
using namespace std;
#define INF 1000000007

#define F first
#define S second
using state= pair<int,int>;
vector<int> dx={1,0,-1,0};
vector<int> dy={0,1,0,-1};

vector<string> g;
vector<vector<int>> vis;
vector<vector<int>> dist;
vector<vector<state>> par;
int n,m;

bool isValid(int i,int j){
    return (i>=0 && i<n && j>=0 && j<m);
}

vector<state> neighbors(state curr){
    vector<state> val;
    for(int d=0;d<4;d++){
        int nx= curr.F+dx[d];
        int ny= curr.S+dy[d];

        if(isValid(nx,ny) && g[nx][ny]!='#'){
            val.push_back({nx,ny});
        }
    }
    return val;
}
void bfs(state st){
    queue<state> q;
    q.push(st);

    while(!q.empty()){
        state curr= q.front();
        q.pop();

        for(auto u: neighbors(curr)){
            if(!vis[u.F][u.S]){
                //cout<<u.F<<" "<<u.S<<endl;
                vis[u.F][u.S]=1;
                dist[u.F][u.S]=dist[curr.F][curr.S]+1;
                par[u.F][u.S]=curr;

                q.push(u);
            }
        }
    }
}

int main(){
    //int n,m;
    cin>>n>>m;

    g.resize(n);
    vis.assign(n,vector<int>(m,0));
    dist.assign(n,vector<int>(m,-INF));
    par.assign(n,vector<state>(m,{-1,-1}));

    state st,en;

    for(int i=0;i<n;i++) cin>>g[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(g[i][j]=='A') st={i,j};
            else if(g[i][j]=='B') en={i,j};
        }
    }
    
    dist[st.F][st.S]=0;
    vis[st.F][st.S]=1;
    bfs(st); 
    if(vis[en.F][en.S]){
         cout<<"YES"<<endl;

    //For printing we traverse backwards
    vector<state> path;
    state curr=en;
    while(curr.F!=-1 && curr.S!=-1){
        path.push_back(curr);
        curr= par[curr.F][curr.S];
    }

    cout<<path.size()-1<<endl;
    reverse(path.begin(),path.end());
    
    for(int i=0;i<path.size()-1;i++){
      int dx=path[i+1].F-path[i].F;
      int dy=path[i+1].S-path[i].S;

      if(dx==1) cout<<"D";
      else if(dx==-1) cout<<"U";
      else if(dy==1) cout<<"R";
      else if(dy==-1) cout<<"L";
    }cout<<endl;
}
else cout<<"NO"<<endl;

    return 0;

}