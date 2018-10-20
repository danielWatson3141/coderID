#include <bits/stdc++.h>

using namespace std;


void solve(int test) {
    cout << "Case #" << test << ": ";
    int n, l;
    cin >> n >> l;
    string s[n];
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    string need[n];
    for (int i = 0; i < n; ++i) {
        cin >> need[i];
    }

    long long a[n];
    long long b[n];
    for (int i = 0; i < n; ++i) {
        a[i] = b[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < l; ++j) {
            if (s[i][j] == '1') {
                a[i] |= (1ll << j);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < l; ++j) {
            if (need[i][j] == '1') {
                b[i] |= (1ll << j);
            }
        }
    }
    sort(b, b + n);
    map<vector<long long>, int> ss;

    int t = l / 2;
    int p = l - t;
    long long M = 1ll << t;
    long long cur = (M - 1) << p;
    for (long long i = 0; i < M; ++i) {
        vector<long long> tmp;
        for (int j = 0; j < n; ++j) {
            tmp.push_back(a[j] ^ (i << p));
        }
        sort(tmp.begin(),tmp.end());
        bool ok = true;
        for (int j = 0; j < n && ok; ++j){
            if ((tmp[j] & cur) != (b[j] & cur)) {
                ok = false;
            }
        }
        if (ok) {
            if (ss.count(tmp)) {
                int cur = ss[tmp];
                cur = min(cur, __builtin_popcount(i));
                ss[tmp] = cur;
            } else {
                ss[tmp] = __builtin_popcount(i);
            }
        }
    }

    int ans = l + 1;
    M = 1ll << p;
    for (long long i = 0; i < M; ++i) {
        vector<long long> tmp;
        for (int j = 0; j < n; ++j) {
            tmp.push_back(b[j] ^ i);
        }
        sort(tmp.begin(),tmp.end());
        int cnt = __builtin_popcount(i);
        if (ss.count(tmp)) {
            ans = min(ans, ss[tmp] + cnt);
        }
    }
    if (ans != l + 1) {
        cout << ans << endl;
    } else {
        cout << "NOT POSSIBLE" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    freopen("A-large.in", "r", stdin);
    freopen("out", "w", stdout);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cerr << i << endl;
        solve(i + 1);
    }
    return 0;
}
