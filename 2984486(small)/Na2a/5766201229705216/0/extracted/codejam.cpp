#include <bits/stdc++.h>

#define llong long long

using namespace std;

const int INF = 1e9 + 7;
const int MXN = 1e5 + 7;

int t, n;
int d[25], a[25], b[25];
bool u[25];

int main()
{
    #define FNAME "file"
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout);

    scanf("%d", &t);
    for (int c = 1; c <= t; c++) {
        scanf("%d", &n);
        for (int i = 0; i < n - 1; i++) {
            scanf("%d%d", &a[i], &b[i]);
            --a[i]; --b[i];
        }
        int rrr = 0;
        int res = n - 1;
        for (int mask = 0; mask < (1 << n); mask++) {
            for (int i = 0; i < n; i++) d[i] = 0;
            for (int i = 0; i < n - 1; i++) {
                if ((mask & (1 << a[i])) && (mask & (1 << b[i]))) {
                    d[a[i]]++; d[b[i]]++;
                }
            }
            bool bintree = true;
            int rt, roots = 0;
            for (int i = 0; i < n; i++) {
                if (!(mask & (1 << i))) continue;
                if (d[i] == 2) rt = i, roots++;
                else if (d[i] != 3 && d[i] != 1) {
                    bintree = false;
                    break;
                }
            }
            if (roots != 1)
                bintree = false;
            else {
                memset(u, false, sizeof(u));

                u[rt] = true;
                for (int i = 0; i < n; i++) {
                    for (int e = 0; e < n - 1; e++) {
                        if ((mask & (1 << a[e])) && (mask & (1 << b[e]))) {
                            u[a[e]] |= u[b[e]];
                            u[b[e]] |= u[a[e]];
                        }
                    }
                }

                for (int i = 0; i < n; i++) {
                    if (!(mask & (1 << i))) continue;
                    if (!u[i]) bintree = false;
                }

                int cur = 0;
                for (int i = 0; i < n; i++)
                    if (mask & (1 << i)) cur++;

                if (bintree) {
                    if (n - cur < res) {
                        res = n - cur;
                        rrr = rt;
                    }
                }
            }

        }
        printf("Case #%d: ", c);
        printf("%d\n", res, rrr);
    }

    return 0;
}
