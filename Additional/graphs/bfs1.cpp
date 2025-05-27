/*Given an n*m grid with directions you need to follow along to reach from (1,1)->(n,m) If it is not feasible consider reversing the arrows in some parts that'll cost you one unit. Find the minimum cost*/

//Each node has a state and weight to be stored
#include<bits/stdc++.h>
using namespace std;
const int INF=1e9;
int n,m;
vector<vector<char>>arr;

using state=pair<int,int>;
#define F first
#define S second
state st;

int dx[]={1,0,-1,0};
int dy[]={0,-1,0,1};
char dirs[]={'v','<','^','>'};

bool isinside(int x,int y){
    if(x>=0 && x<n &&y>=0 && y<m) return 1;
    else return 0;
}

vector<vector<int>>vis,dist;
vector<vector<state>>parent;

void bfs01(state st){
    vis.assign(n, vector<int>(m,0));
    dist.assign(n, vector<int>(m, INF));
    parent.assign(n, vector<state>(m,{-1,-1}));
    
    deque<state>dq;
    dq.push_back(st);
    dist[st.F][st.S]=0;
    
    while(!dq.empty()){
        auto cur=dq.front();
        dq.pop_front();
        
        if(vis[cur.F][cur.S]) continue;
        vis[cur.F][cur.S]=1;
        
        for(int dir=0;dir<4;dir++){
            int nx = cur.F+dx[dir];
            int ny = cur.S+dy[dir];
            
            if(isinside(nx,ny)){
                int edge = (arr[cur.F][cur.S] == dirs[dir] ? 0:1);
                if(dist[nx][ny] > dist[cur.F][cur.S]+edge){
                    dist[nx][ny] = dist[cur.F][cur.S]+edge;
                    parent[nx][ny]=cur;
                    
                    if(edge==0){
                        dq.push_front({nx,ny});
                    }
                    else{
                        dq.push_back({nx,ny});
                    }
                }
                
            }
        }
    }
}

int main(){
    cin>>n>>m;
    arr.resize(n,vector<char>(m));
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    st={0,0};
    bfs01(st);
    cout<<dist[n-1][m-1]<<endl;
    
    state cur={n-1,m-1};
    vector<state>path;
    while(cur!=state({-1,-1})){
        path.push_back(cur);
        cur=parent[cur.F][cur.S];
    }
    reverse(path.begin(),path.end());
    for(auto v:path){
        cout<<v.F<<" "<<v.S<<endl;
    }
    
}

