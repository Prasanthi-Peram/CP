//Remember that if it's Form 1 then order would also have mattered and there's also a restriction of no. of levels..This problem is not form 1

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define INF 1000000009

int main(){
    int n;
    cin>>n;
    

    vector<int> dp(n+1,INF);
    for(int i=0;i<=n;i++){
        if(i==0){
            dp[i]=0;
            continue;
        }

        int num=i;
        while(num>0){
            int rem=num%10;
            dp[i]=min(dp[i],1+dp[i-rem]);
            num/=10;
        }

    }


    cout<<dp[n]<<endl;
    return 0;
}