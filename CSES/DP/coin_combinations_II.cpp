//In this problem multiple combinations aren't allowed we must return unique ways: count in some order(lexicographical)/sorted

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define INF 1000000009

int main(){
    int n,x;
    cin>>n>>x;
    
    vector<int> a(n);
    for(auto &x: a) cin>>x;
    int dp[n+1][x+1];

   for(int i=n;i>=0;i--){
     for(int j=0;j<=x;j++){
        if(i==n){
            if(j==0) dp[i][j]=1;
            else dp[i][j]=0;
            continue;
        }

        int ans=0;
    
            if(j>=a[i]) ans=(dp[i+1][j]+dp[i][j-a[i]])%MOD;
            else ans=dp[i+1][j]%MOD;

        dp[i][j]=ans;
     }
   }

    cout<<dp[0][x]<<endl;
    
    return 0;
}