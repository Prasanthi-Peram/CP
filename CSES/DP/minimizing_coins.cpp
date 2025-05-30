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
            dp[i]=0;
            continue;
        }

        dp[i]=INF;
        for(auto u: a){
           // cout<<u<<endl;
            if(i>=u) dp[i]=min(dp[i],1+dp[i-u]);
        }
    }

    if(dp[x]==INF) cout<<"-1"<<endl;
    else cout<<dp[x]<<endl;
    

   /* int dp[n+1][x+1];
    for(int i=n;i>=0;i--){
        for(int s=0;s<=x;s++){
            if(s<0) dp[i][s]=INF;
            if(i==n){
                if(s==0) dp[i][s]=0;
                else dp[i][s]=INF;
                continue;
            }

            int ans=dp[i+1][s];
                if(s>=a[i])
                {
                  //  cout<<i<<endl;
                //cout<<dp[i+1][s]<<" "<<dp[i][s-a[i]]<<endl;
                ans=min(ans,1+dp[i][s-a[i]]);
                }
            dp[i][s]=ans;
        }
    }
    if(dp[0][x]==INF) cout<<"-1"<<endl;
    else cout<<dp[0][x]<<endl;
    */


    return 0;
}