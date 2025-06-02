#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 998244353;
const int MAXN = 100000;
ll pow2[MAXN * 4 + 5];  // Make sure it's big enough

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Precompute powers of 2 modulo MOD
    pow2[0] = 1;
    for (int i = 1; i <= MAXN * 4; i++) {
        pow2[i] = (pow2[i - 1] * 2) % MOD;
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n), q(n);
        for (int i = 0; i < n; i++) cin >> p[i];
        for (int i = 0; i < n; i++) cin >> q[i];

        vector<int> PA(n), PB(n), idxA(n), idxB(n);
        PA[0] = p[0];
        PB[0] = q[0];
        idxA[0] = 0;
        idxB[0] = 0;

        for (int i = 1; i < n; i++) {
            if (p[i] > PA[i - 1]) {
                PA[i] = p[i];
                idxA[i] = i;
            } else {
                PA[i] = PA[i - 1];
                idxA[i] = idxA[i - 1];
            }

            if (q[i] > PB[i - 1]) {
                PB[i] = q[i];
                idxB[i] = i;
            } else {
                PB[i] = PB[i - 1];
                idxB[i] = idxB[i - 1];
            }
        }

        vector<ll> r(n);
        for (int i = 0; i < n; i++) {
            int maxA = PA[i], idA = idxA[i];
            int maxB = PB[i], idB = idxB[i];
            int M = max(maxA, maxB);
            int best_other = 0;

            if (maxA == M) {
                int other1 = max(0, q[i] - idA);
                best_other = max(best_other, other1);
            }

            if (maxB == M) {
                int other2 = max(0, p[i] - idB);
                best_other = max(best_other, other2);
            }

            ll val = (pow2[M] + pow2[best_other]) % MOD;
            r[i] = val;
        }

        for (int i = 0; i < n; i++) {
            cout << r[i] << (i + 1 < n ? ' ' : '\n');
        }
    }

    return 0;
}