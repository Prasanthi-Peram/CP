#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main(){
    int n,m;
    cin>>n>>m;

    vector<int> a(n);
    for(auto &x: a) cin>>x;

    int dp[n+1][m+1];

    //dp[level][prev]= dp[level+1][prev-1]+dp[level+1][prev+1]
    for(int i=n;i>=1;i--){
        for(int last=1;last<=m;last++){

            //cout<<i<<" "<<last<<endl;
            if(i==n) {
                dp[i][last]=1;
                continue;
            }

            //dp[i][last]=0;
            int ans=0;
            if(a[i]==0){
                    //cout<<a[i]<<endl;
                    for(int d=-1;d<=1;d++){
                        int c=last+d;
                        if(c<=m && c>=1) ans= (ans+dp[i+1][c])%MOD;
                    }
            }else{
                if(abs(a[i]-last)<=1) ans=dp[i+1][a[i]];//I'm filling last at this point

            }

            dp[i][last]=ans%MOD;
            //cout<<dp[i][last]<<endl;
        }
    }
    int ans=0;
    if(a[0]==0){
        for(int i=1;i<=m;i++){
            ans= (ans+dp[1][i])%MOD;
        }
    }else{
        ans= (ans+dp[1][a[0]])%MOD;
    }
    cout<<ans<<endl;
    return 0;
}