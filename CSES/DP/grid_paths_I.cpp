#include <bits/stdc++.h>
using namespace std;
vector<string> grid;
#define MOD 1000000007

int main(){
    int n;
    cin>>n;
    grid.resize(n);
    for(int i=0;i<n;i++) cin>>grid[i];
    int dp[n][n];

    //dp[i][j]=dp[i-1][j]+dp[i][j-1];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==0 && j==0 && grid[i][j]!='*') {
                dp[i][j]=1;
                continue;
            }
            //else if(i==0 || j==0) dp[i][j]=0;

            int ans=0;
            if(grid[i][j]!='*'){
                if(i) ans+=dp[i-1][j];
                if(j) ans+=dp[i][j-1];
            }
            dp[i][j]=ans%MOD;
        }
    }
    cout<<dp[n-1][n-1]<<endl;
    return 0;
}