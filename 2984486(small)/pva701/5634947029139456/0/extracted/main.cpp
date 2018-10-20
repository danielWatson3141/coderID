#include <iostream>
#include <cstdio>
using namespace std;
const int N = 160;
bool check(string a[], string b[], int n) {
    for (int i = 0; i < n; ++i) {
        bool found = false;
        for (int j = 0; j < n && !found; ++j)
            if (a[i] == b[j])
                found = true;
        if (!found)
            return false;
    }
    return true;
}

void solve() {
    int n, l, res = N;
    string a[N], b[N], aa[N], bb[N];
    cin >> n >> l;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    for (int i = 0; i < n; ++i) {
        for (int k = 0; k < n; ++k) aa[k] = a[k];
        for (int k = 0; k < n; ++k) bb[k] = b[k];

        int cnt = 0;
        for (int j = 0; j < l; ++j)
            if (aa[0][j] != bb[i][j]) {
                ++cnt;
                for (int t = 0; t < n; ++t)
                    if (aa[t][j] == '1') aa[t][j] = '0';
                    else aa[t][j] = '1';
            }
        if (check(aa, bb, n))
            res = min(res, cnt);
    }
    if (res == N)
        cout << "NOT POSSIBLE\n";
    else
        cout << res << "\n";
}

int main(int argc, char *argv[])
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
