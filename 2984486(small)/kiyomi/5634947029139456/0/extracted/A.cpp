#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cstdio>

#define INF 1 << 30

using namespace std;

int T, n, l;
string a[300], b[300], c[300], d[300];

bool solved(vector <int> &pos) {
    int m = (int) pos.size();
    for (int i = 0; i < n; i++) {
        c[i] = a[i];
        d[i] = b[i];
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (c[j][pos[i]] == '1')
                c[j][pos[i]] = '0';
            else
                c[j][pos[i]] = '1';
        }
    }
    sort(c, c + n);
    sort(d, d + n);
    for (int i = 0; i < n; i++)
        if (c[i] != d[i])
            return false;
    return true;
}

string f(int x) {
    string s = "";
    if (x == 0)
        return "0";
    while (x > 0) {
        s += (x % 10) + '0';
        x /= 10;
    }
    reverse(s.begin(), s.end());
    return s;
}

string solve() {
    int ret = INF;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            vector <int> pos;
            for (int k = 0; k < l; k++)
                if (a[i][k] != b[j][k])
                    pos.push_back(k);
            if (solved(pos))
                ret = min(ret, (int) pos.size());
        }
    }
    if (ret == INF)
        return "NOT POSSIBLE";
    else
        return f(ret);
}

int main() {

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    ios::sync_with_stdio(false);

    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> n >> l;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        cout << "Case #" << t << ": " << solve() << "\n";
    }

    return 0;

}
