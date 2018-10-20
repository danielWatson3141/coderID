#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <cstring>

using namespace std;

int T, n, l, ans;
bool found;
string x[152], y[152];
int f[42], s[2][42][2], xx[152], yy[152], tx[152], ty[152], haha;

bool check() {
    for (int j = 1; j <= l; j++) {
        for (int i = 1; i <= n; i++) {
            s[0][j][(xx[i] >> (l - j) & 1)]++;
            s[1][j][(yy[i] >> (l - j) & 1)]++;
        }
        if (s[1][j][0] == s[1][j][1] && s[0][j][0] == s[0][j][1] && s[0][j][0] == s[1][j][0]) {
            f[j] = 2;
            haha++;
        } else if (s[0][j][0] == s[1][j][0] && s[0][j][1] == s[1][j][1]) {
            f[j] = 0;
        } else if (s[0][j][0] == s[1][j][1] && s[0][j][1] == s[1][j][0]) {
            f[j] = 1;
        } else {
            return false;
        }
    }
    return true;
}

bool checkk(int k) {
    int px[152], py[152];
    for (int i = 1; i <= n; i++) {
        px[i] = (xx[i] >> (l - k)), py[i] = (yy[i] >> (l - k));
        // cout << k << " " << px[i] << " " << py[i] << endl;
    }
    sort(px + 1, px + n + 1);
    sort(py + 1, py + n + 1);
    for (int i = 1; i <= n; i++)
        if (px[i] != py[i])
            return false;
    return true;
}

int dfs(int k, int ti) {
    if (found)
        return 0;
    if (k == l + 1) {
        for (int i = 1; i <= n; i++)
            tx[i] = xx[i], ty[i] = yy[i];
        sort(tx + 1, tx + n + 1);
        sort(ty + 1, ty + n + 1);
        for (int i = 1; i <= n; i++)
            if (tx[i] != ty[i])
                return 1;
        found = true;
        cout << "Case " << "#" << ti << ": " << ans << endl;
        return 0;
    }
    bool tb = checkk(k - 1);
    if (!tb)
        return 1;
    if (f[k] == 2) {
        dfs(k + 1, ti);
        ans++;
        for (int i = 1; i <= n; i++)
            xx[i] ^= (1 << (l - k));
        dfs(k + 1, ti);
        for (int i = 1; i <= n; i++)
            xx[i] ^= (1 << (l - k));
        ans--;
    } else
        dfs(k + 1, ti);
}

int solve(int ti) {
    cin >> n >> l;
    // cout << n << "#" << l << endl;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        xx[i] = strtol(x[i].c_str(), NULL, 2);
    }
    for (int i = 1; i <= n; i++) {
        cin >> y[i];
        yy[i] = strtol(y[i].c_str(), NULL, 2);
    }

    haha = 0;
    for (int i = 1; i <= l; i++) {
        // cout << i << endl;
        s[0][i][0] = 0, s[0][i][1] = 0, s[1][i][0] = 0, s[1][i][1] = 0;
    }
    ans = 0;
    found = false;

    if (!check()) {
        cout << "Case " << "#" << ti << ": NOT POSSIBLE" << endl;
        return 1;
    }

    // cout << haha << endl;
    for (int j = 1; j <= l; j++)
        if (f[j] == 1) {
            for (int i = 1; i <= n; i++)
                xx[i] ^= (1 << (l - j));
            ans++;
        }
    found = false;
    dfs(1, ti);
    if (!found) {
        cout << "Case " << "#" << ti << ": NOT POSSIBLE" << endl;
    }
}

int main() {
    freopen("A-small-attempt2.in", "r", stdin);
    freopen("A-small-attempt2.out", "w", stdout);
    cin >> T;
    for (int ti = 1; ti <= T; ti++) {
        solve(ti);
    }
    return 0;
}
