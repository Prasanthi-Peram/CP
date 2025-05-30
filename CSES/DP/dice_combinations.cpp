#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main(){
    int n;
    cin>>n;
    

    //Game DP
    vector<int> dp(n+1,0);
    dp[0]=1;
    for(int s=1;s<=n;s++){
        for(int x=1;x<=6;x++){
            if(s>=x) dp[s]=(dp[s]+dp[s-x])%MOD;
        }
    }

    cout<<dp[n]<<endl;
    return 0;
}