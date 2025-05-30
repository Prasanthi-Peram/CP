#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000

int main(){
    int a,b;
    cin>>a>>b;

    int dp[a+1][b+1];
    for(int x=1;x<=a;x++){
        for(int y=1;y<=b;y++){
            if(x==y) dp[x][y]=0;
            else{
                dp[x][y]=INF;
                for(int a=1;a<=x-1;a++) dp[x][y]=min(dp[x][y],dp[a][y]+dp[x-a][y]+1);
                for(int b=1;b<=y-1;b++) dp[x][y]=min(dp[x][y],dp[x][b]+dp[x][y-b]+1);
                
            }
        }
    }
    cout<<dp[a][b]<<endl;
    return 0;
}