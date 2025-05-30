#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

long long int dp[1000100][2];
void solve(){
    for(int i=1;i<=1000000;i++){
        if(i==1){
            dp[i][0]=1;
            dp[i][1]=1;
            continue;
        }
        dp[i][0]=(2LL*dp[i-1][0]+dp[i-1][1])%MOD;
        dp[i][1]=(dp[i-1][0]+4LL*dp[i-1][1])%MOD;
    }
}
int main(){
    int t;
    cin>>t;
    solve();
    while(t--){
        int n;
        cin>>n;

        cout<<(dp[n][0]+dp[n][1])%MOD<<endl;
    }
    return 0;
}