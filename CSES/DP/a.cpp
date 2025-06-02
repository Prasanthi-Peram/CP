#include <iostream>
using namespace std;

int main() {

    int t;
    cin>>t;
    while (t--) {

        long long a,b,c,d;
        cin>>a>>b>>c>>d;

        long long g_time =min(b,d);
        long long fl_time =min(a,c);

        cout<<(g_time <= fl_time ? "Gellyfish" : "Flower")<<'\n';
    }
    return 0;
}
