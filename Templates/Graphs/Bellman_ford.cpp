//Shortest distance from starting node to all nodes in a graph, provided it has no negative weights, can be used to detect negative weights.

for(int i=1;i<=n;i++) distance[i]=INF
distance[x]=0;

for(int i=1;i<=n-1;i++){
  for(auto e: edges){
    int a,b,w;
    tie(a,b,w)=e;
    distance[b]=min(distance[b],distance[a]+w);
  }//O(nm).Efficeint: Stop the algorithm if no distance can be reduced during the round
}//Size of distance vector is n+1
//A negative cycle can be detected: When Bellman-ford runs n-times and the distance reduces on the nth round then there exists a negative edge in the graph.