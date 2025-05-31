#include <bits/stdc++.h>
using namespace std;
vector<string> g;
int main(){
    int n;
    cin>>n;

    g.resize(n);
    for(int i=0;i<n;i++) cin>>g[i];
    
    //int dp[n][n];
    vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            //dp[i][j]=INT_MAX;
            if(i==0 && j==0) dp[i][j]=g[i][j]-'A'+1;
            if(i) dp[i][j]=min(dp[i][j],(g[i][j]-'A'+1)+dp[i-1][j]);
            if(j) dp[i][j]=min(dp[i][j],(g[i][j]-'A'+1)+dp[i][j-1]);
         }
    }

    string s;
    /*for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<dp[i][j]<<" ";
        }cout<<endl;
    }*/

        int i=0,j=0;
        s+=g[0][0];
        while(i<n-1 || j<n-1){
            if(i == n - 1) j++; 
            else if(j == n - 1) i++;
            else if(dp[i+1][j]<dp[i][j+1]) {
                i++;
            }
            else {
                j++;
            }
            s+=g[i][j];
        }
    //cout<<dp[n-1][n-1]<<endl;
    cout<<s<<endl;
    
    
    return 0;
}