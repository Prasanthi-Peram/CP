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

        bitset<100001> temp;
        temp[0]=1;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;

            temp|=temp<<x;
        }

        vector<int> ans;
        for(int i=1;i<100001;i++){
            if(temp[i]) ans.push_back(i);
        }
        cout<<ans.size()<<endl;
        for(auto v: ans) cout<<v<<" ";
        cout<<endl;

    return 0;
}