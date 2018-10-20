#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <stack>
#include <map>
#include <math.h>
#include <time.h>
using namespace std;
typedef long long LL;
const int N = 155;
const int M = 45;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> PII;

int n, l;

char a[N][M], b[N][M];
map<int, int> NUM;

LL Get(char *s1, char *s2) {
    LL cnt = 0;
    for (int i = 0; i < l; i++) {
        cnt *= 2;
        if (s1[i] != s2[i]) {
            cnt |= 1;
        }
    }
    return cnt;
}

int main () {
    //freopen("1.in", "r", stdin);
    //freopen("1.out", "w", stdout);
    int cases;
    scanf ("%d", &cases);
    for (int cas = 1; cas <= cases; cas++) {
        scanf ("%d %d", &n, &l);
        NUM.clear();
        for (int i = 0; i < n; i++) {
            scanf("%s", a[i]);
        }
        for (int i = 0; i < n; i++) {
            scanf("%s", b[i]);
        }
        for(int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                LL cnt = Get(a[i], b[j]);
                NUM[cnt]++;
            }
        }
        printf("Case #%d: ", cas);

//      LL ans = INF;
        int ans = INF;
        map<int, int>::iterator iter;
        for (iter = NUM.begin(); iter != NUM.end(); iter++) {
            if (iter -> second == n) {
                ans = min(ans, __builtin_popcount(iter -> first));
            }
        }
        if(ans == INF) {
            puts("NOT POSSIBLE");
        }
        else {
            cout<<ans<<endl;
        }

    }






    return 0;
}
