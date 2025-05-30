#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define INF 1000000009

int main(){
    int n,x;
    cin>>n>>x;
    
    vector<int> a(n);
    for(auto &x: a) cin>>x;
    int dp[x+1];

   for(int i=0;i<=x;i++){
        if(i==0){
            dp[i]=1;
            continue;
        }

        dp[i]=0;
        for(auto u: a){
           // cout<<u<<endl;
            if(i>=u) dp[i]= (dp[i]+dp[i-u])%MOD;
        }
    }

    if(dp[x]==INF) cout<<"-1"<<endl;
    else cout<<dp[x]<<endl;
    
    return 0;
}