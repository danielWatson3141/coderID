#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <queue>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)
const int maxn = 100;
const int inf = 1e9;

char a[maxn][maxn];
char b[maxn][maxn];
char c[maxn][maxn];
bool use[maxn];


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
     freopen("out", "w", stdout);
#endif
    int T, l, n;
    scanf("%d", &T);
    for (int tt = 0; tt < T; tt++) {
        scanf("%d %d", &n, &l);
        for (int i = 0; i < n; i++)
            scanf("%s", a[i]);
        for (int i = 0; i < n; i++)
            scanf("%s", b[i]);
        int ans = l + 1;
        for (int mask = 0; mask < (1 << l); mask++) {
            for (int i = 0; i < n; i++)
                for (int j = 0; j < l; j++)
                    c[i][j] = (((mask >> j) & 1) ^ (a[i][j] - '0')) + '0';
            memset(use, 0, sizeof(use));
            bool bigFlag = 1;
            for (int i = 0; i < n; i++) {
                bool flag1 = 0;

                for (int j = 0; j < n; j++) 
                    if (!use[j]) {
                        bool flag = 1;
                        for (int k = 0; k < l; k++) {
                            if (c[i][k] != b[j][k])
                                flag = 0;
                        }
                        if (flag) {
                            use[j] = 1;
                            flag1 = 1;
                            break;
                        }
                    }
                if (flag1 == 0)
                    bigFlag = 0;
            }
            if (bigFlag)
                ans = min(ans, __builtin_popcount(mask));
        }
        printf("Case #%d: ", tt + 1);
        if (ans == l + 1)
            printf("NOT POSSIBLE\n");
        else
            printf("%d\n", ans);
    }


    return 0;
}

