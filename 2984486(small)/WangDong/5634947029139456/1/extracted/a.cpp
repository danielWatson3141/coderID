#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

int n, l;
string a[200];
int b[200][200];
int c[200][200];
int ans;

void init() {
    cin >> n >> l;
    memset(b, 0, sizeof(b));
    memset(c, 0, sizeof(c));
    ans = 201;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        for (int j = 0; j < l; ++j)
            b[i][j] = a[i][j] - '0';
    }
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        for (int j = 0; j < l; ++j)
            c[i][j] = a[i][j] - '0';
    }
}

int cur[200];
int d[200][200];
int ch[200];

bool check() {
    memset(ch, 0, sizeof(ch));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (ch[j] == 0) {
                bool same = true;
                for (int t = 0; t < l; ++t)
                    if (d[i][t] != c[j][t])
                        same = false;
                if (same) {
                    ch[j] = 1;
                    break;
                }
            }
    for (int i = 0; i < n; ++i)
        if (ch[i] == 0)
            return false;
    return true;
}

void work() {
    for (int i = 0; i < n; ++i) {
        memset(d, 0, sizeof(d));
        memset(cur, 0, sizeof(cur));
        for (int t = 0; t < l; ++t)
            cur[t] = b[0][t]^c[i][t];
        for (int j = 0; j < n; ++j)
            for (int t = 0; t < l; ++t)
                d[j][t] = b[j][t]^cur[t];
        if (check()) {
            int curans = 0;
            for (int t = 0; t < l; ++ t)
                curans += cur[t];
            if (curans < ans)
                ans = curans;
        }
    }
}

void output(int k) {
    printf("Case #%d:", k);
    if (ans <= 200) {
        printf(" %d\n", ans);
    } else {
        printf(" NOT POSSIBLE\n");
    }
}

int main() {
    freopen("/Users/dong/Dropbox/Coding/Topcoder/Topcoder/A-large.in", "r", stdin);
    freopen("/Users/dong/Dropbox/Coding/Topcoder/Topcoder/out.txt", "w", stdout);
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        init();
        work();
        output(i + 1);
    }
    return 0;
}