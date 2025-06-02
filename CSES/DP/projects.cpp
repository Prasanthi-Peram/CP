#include <bits/stdc++.h>
using namespace std;
#define MP make_pair
#define INF 1000000000

void solve(){
    int n;
    cin>>n;

    pair<long long,pair<long long,long long>> arr[n];
    for(int i=0;i<n;i++){
        int l,r,p;
        cin>>l>>r>>p;
        arr[i]=MP(l,MP(r,p)); 
    }

    sort(arr,arr+n);
    long long dp[n+1];
    for(int i=n;i>=0;i--){
        if(i==n) dp[i]=0;
        else{

            //don't take
            dp[i]=dp[i+1];

            //take;
            long long nextVal=arr[i].second.first;
            //lower bound use -1e9
            auto it= upper_bound(arr,arr+n,MP(nextVal,MP(1LL*INF,1LL*INF)))-arr;
            dp[i]=max(dp[i],arr[i].second.second+dp[it]);
        }
    }
    cout<<dp[0]<<endl;
}
int main(){
    solve();
    return 0;
}