#include <iostream>
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
string x[152], y[152], tx[152], ty[152];
int f[42], s[2][42][2];

bool check() {
    for (int j = 0; j < l; j++) {
        for (int i = 1; i <= n; i++) {
            if (x[i][j] == '1')
                s[0][j][1]++;
            if (x[i][j] == '0')
                s[0][j][0]++;
            if (y[i][j] == '1')
                s[1][j][1]++;
            if (y[i][j] == '0')
                s[1][j][0]++;
        }
        if (s[1][j][0] == s[1][j][1] && s[0][j][0] == s[0][j][1] && s[0][j][0] == s[1][j][0]) {
            f[j] = 2;
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

int dfs(int k, int ti) {
    if (found)
        return 0;
    if (k == l) {
        for (int i = 1; i <= n; i++)
            tx[i] = x[i], ty[i] = y[i];
        sort(tx + 1, tx + n + 1);
        sort(ty + 1, ty + n + 1);
        for (int i = 1; i <= n; i++)
            if (tx[i] != ty[i])
                return 1;
        found = true;
        printf("Case #%i: %i\n", ti, ans);
        return 0;
    }
    if (f[k] == 2) {
        dfs(k + 1, ti);
        ans++;
        for (int i = 1; i <= n; i++)
            x[i][k] = '0' + '1' - x[i][k];
        dfs(k + 1, ti);
        for (int i = 1; i <= n; i++)
            x[i][k] = '0' + '1' - x[i][k];
        ans--;
    } else
        dfs(k + 1, ti);
}

int solve(int ti) {
    cin >> n >> l;
    for (int i = 1; i <= n; i++)
        cin >> x[i];
    for (int i = 1; i <= n; i++)
        cin >> y[i];

    for (int i = 0; i < l; i++)
        s[0][i][0] = 0, s[0][i][1] = 0, s[1][i][0] = 0, s[1][i][1] = 0;
    ans = 0;
    found = false;

    if (!check()) {
        printf("Case #%i: NOT POSSIBLE\n", ti);
        return 1;
    }
    for (int j = 0; j < l; j++)
        if (f[j] == 1) {
            for (int i = 1; i <= n; i++)
                x[i][j] = '0' + '1' - x[i][j];
            ans++;
        }
    found = false;
    dfs(0, ti);
    if (!found) {
        printf("Case #%i: NOT POSSIBLE\n", ti);
    }
}

int main() {
    cin >> T;
    for (int ti = 1; ti <= T; ti++) {

        solve(ti);
    }
    return 0;
}
