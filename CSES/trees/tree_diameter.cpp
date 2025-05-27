#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> tree;

int main(){
    cin>>n;
    tree.resize(n+1);

    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;

        tree[a].push_back(b);
        tree[b].push_back(a);

        //This algorithm and intution has been provided in the CSES handbook
        int b= dfs(1);
        int c= dfs(b);

        
    }
    return 0;
}