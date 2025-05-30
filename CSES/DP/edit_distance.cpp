#include <bits/stdc++.h>
using namespace std;
#define INF 1000000009

int n,m;
string a,b;
int main(){

    cin>>a>>b;
    n=a.length();
    m=b.length();

    int dp[n+1][m+1];
    for(int i=n;i>=0;i--){
        for(int j=m;j>=0;j--){

            if(i==n || j==m) dp[i][j]=(n-i)+(m-j);
            else{
                dp[i][j]=min({1+dp[i+1][j],1+dp[i][j+1],dp[i+1][j+1]+(a[i]!=b[j])});
            }
        }
    }

    cout<<dp[0][0]<<endl;
    return 0;
}