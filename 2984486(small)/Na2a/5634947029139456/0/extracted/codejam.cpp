#include <bits/stdc++.h>

#define llong long long

using namespace std;

const int INF = 1e9 + 7;
const int MXN = 1e5 + 7;

int n, len, t;
string s[MXN], aim[MXN];

char flipchar(char x)
{
    if (x == '0') return '1';
    else return 48;
}

int main()
{
    #define FNAME "file"
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout);

    scanf("%d", &t);
    cerr << t << endl;
    for (int te = 1; te <= t; te++) {
        scanf("%d%d", &n, &len);
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> aim[i];
        }
        cerr << t << "\n";
        sort(aim, aim + n);
        int res = INF;
        do {
            bool globalfail = false;

            int ans = 0;
            for (int i = 0; i < len; i++) {
                bool ok = true;
                for (int x = 0; x < n; x++) {
                    if (s[x][i] != aim[x][i]) {
                        ok = false;
                        break;
                    }
                }

                if (ok) continue;

                ok = true;
                for (int x = 0; x < n; x++) {
                    if (flipchar(s[x][i]) != aim[x][i]) {
                        ok = false;
                        break;
                    }
                }

                if (ok) {
                    ans++;
                    continue;
                }
                globalfail = true;
                break;
            }
            if (!globalfail) {
                res = min(res, ans);
                if (ans == 0) break;
            }
        }
        while (next_permutation(aim, aim + n));

        printf("Case #%d: ", te);
        if (res == INF) puts("NOT POSSIBLE");
        else printf("%d\n", res);
    }

    return 0;
}
