#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
int main(){
    
    int n,x;
    cin>>n>>x;
    
    vector<int> h(n);
    vector<int> s(n);

    for(auto &x: h) cin>>x;
    for(auto &x:s) cin>>x;

    int dp[n+1][x+1];
    for(int i=n;i>=0;i--){
        for(int j=0;j<=x;j++){
            if(i==n || j==0){
                dp[i][j]=0;
                continue;
            }

            int ans=dp[i+1][j];
            if(j>=h[i]) ans=max(ans,s[i]+dp[i+1][j-h[i]]);

            dp[i][j]=ans;
            //cout<<i<<" "<<j<<" "<<ans<<endl;
        }
    }
    cout<<dp[0][x]<<endl;
    return 0;
}