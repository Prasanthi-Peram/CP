#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;


//This ones a subset sum problem
int main() {

    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    
        int n;
        cin>>n;

        vector<long long int> a(n);
        for(auto &x:a) cin>>x;

        /*vector<int> dp(n,1);
        for(int i=0;i<n;i++){
            for(int j=i;j>=0;j--){
                if(a[j]<a[i]) dp[i]=max(dp[i],dp[j]+1);
            }
        }
        
        //for(auto u: dp) cout<<u<<" ";
        //cout<<endl;
        //cout<<dp[n-1]<<endl;
        int u=*max_element(dp.begin(),dp.end());
        cout<<u<<endl; This code is giving TLE try for O(nlogn)*/

        

    return 0;
}