//This is a greedy algorithm and uses a priority queue
//To find the shortest path from a single source node to all other nodes in a weighted graph (with non-negative weights on edges).

distances.resize(n, INT_MAX);
for(int i=1;i<=n;i++) distance[i]=INF;
distance[x]=0;
q.push({0,x});

while(!q.empty()){
  int a = q.top().second(); q.pop();
  if(processed[a]) continue;
  processed[a]=true;
  
  for(auto u: adj[a]){
    int b = u.first, w=u.second;
    if(distance[a]+w< distance[b]){
      distance[b]= distance[a]+w;
      q.push({-distance[b],b});
   } 
  }
}
