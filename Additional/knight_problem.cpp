/*Given an n*m board whats the shortest path a knight can take from coordinates (x,y)->(a,b) */

//A possible extension to this would be to print the path
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000007
#define F first
#define S second

int n,m,x,y,a,b;
vector<string> board;
using state= pair<int,int>;

vector<int> dx={-2,-2,2,2,-1,-1,1,1};
vector<int> dy= {1,-1,1,-1,2,-2,2,-2};
vector<vector<int>> dist;


bool in(int a,int b){
    return (a>=0 && a<n && b>=0 && b<m && board[a][b]!='#');
}
vector<state> neigh(state curr){
    vector<state> el;
    
    for(int i=0;i<8;i++){
        int nx= curr.F+dx[i];
        int ny= curr.S+dy[i];

        if(in(nx,ny)) el.push_back({nx,ny});
    }

    return el;
}
void bfs(state st){

    queue<state> q;
    q.push(st);
    dist[st.F][st.S]=0;

    while(!q.empty()){

        state curr= q.front();
        q.pop();
        for(auto u: neigh(curr)){
            if(dist[u.F][u.S]>dist[curr.F][curr.S]+1){
                dist[u.F][u.S]=dist[curr.F][curr.S]+1;
                q.push(u);
            }
        }
    }
}

int main(){
    
    cin>>n>>m>>x>>y>>a>>b;
    board.resize(n);
    dist.assign(n,vector<int>(m,INF));

    for(int i=0;i<n;i++){
        cin>>board[i];
    }

    state st,en;
    st=make_pair(x-1,y-1);
    en=make_pair(a-1,b-1);

    bfs(st);
    cout<<dist[en.F][en.S]<<endl;

    /*for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cout<<dist[i][j]<<" ";
        cout<<endl;
    }*/

    

}