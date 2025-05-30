#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;

    vector<long long int> a(n),b(m);
    for(auto &x:a) cin>>x;
    for(auto &x:b) cin>>x;

    long long int dp[1001][1001];
    for(int i=n;i>=0;i--){
        for(int j=m;j>=0;j--){
            if(i==n || j== m) dp[i][j]=0;
            else{
                if(a[i]!=b[j]) dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
                else {
                    dp[i][j]=max(dp[i][j],1+dp[i+1][j+1]);
                }
            }
        }
    }
    cout<<dp[0][0]<<endl;
    int i,j;
    i=j=0;
    vector<long long> lcs;
    while(i<n && j<m){
        if(a[i]==b[j]){
            lcs.push_back(a[i]);
            i++;
            j++;
        }
        else if(dp[i+1][j]>dp[i][j+1]) i++;
        else j++;
    }

    for(auto u: lcs) cout<<u<<" ";
    cout<<endl;
    return 0;
}