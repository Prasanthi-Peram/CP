#include <bits/stdc++.h>
using namespace std;

int gcd_all(const vector<int>& a) {
    int g = a[0];
    for (int i = 1; i < a.size(); ++i)
        g = __gcd(g, a[i]);
    return g;
}

int min_operations(vector<int> a) {
    int n = a.size();
    int G = gcd_all(a);
    queue<int> q;
    vector<bool> isG(n, false);

    // First, try to create one G
    int ops = 0;
    bool createdG = false;
    for (int i = 0; i < n && !createdG; ++i) {
        for (int j = 0; j < n && !createdG; ++j) {
            if (i == j) continue;
            int g = __gcd(a[i], a[j]);
            ++ops;
            if (g == G) {
                a[i] = G;
                isG[i] = true;
                createdG = true;
            }
        }
    }

    // Now that we have at least one G, we can use it to convert others
    while (true) {
        bool done = true;
        for (int i = 0; i < n; ++i) {
            if (a[i] != G) {
                done = false;
                // use any known G to convert this
                for (int j = 0; j < n; ++j) {
                    if (i != j && a[j] == G) {
                        a[i] = __gcd(a[i], a[j]);
                        ++ops;
                        if (a[i] == G) isG[i] = true;
                        break;
                    }
                }
            }
        }
        if (done) break;
    }

    return ops;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int& x : a) cin >> x;

        cout << min_operations(a) << '\n';
    }

    return 0;
}
