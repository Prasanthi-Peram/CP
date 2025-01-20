int n;
vector<vector<int>> adj;
vector<int> side(n,-1);
bool is_bipartite = true;

//This for loop is necessary to handle any disconnected components if necessary

for(int st=0;st<n;st++){
  if(side[st]==-1){
     q.push(st);
     side[st]=0;
     
     while(!q.empty()){
        int v= q.front();
        q.pop();
        
        for(auto u: adj[v]){
           if(side[u]==-1){
              side[u]=side[v]^1 //Toggle between 0 & 1
              q.push(u);
           }else{
             is_bipartite &= side[u] !=side[v];
           }
        }
     }
  }
}

cout<< (is_bipartite ? "YES" : "NO")<<endl;