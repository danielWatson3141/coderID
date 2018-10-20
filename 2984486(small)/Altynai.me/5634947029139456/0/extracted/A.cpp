#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <string>
#include <map>
#include <ctime>
#include <cmath>
#include <cassert>
#include <numeric>
#include <algorithm>
using namespace std;

#define N 480
#define M 80000
#define ll long long
#define inf 0X3f3f3f3f
#define lson (id<<1)
#define rson (id<<1|1)

#define mod 1000000007
#define eps 1e-6
#define pii pair<int,int>
#define pdd pair<double,int>
#define MP(i,j) make_pair(i,j)

int a[N], b[N], c[N], n, m;

int a2i(char *s, int len) {
    int result = 0, x = 1;
    for (int i = len - 1; i >= 0; i--) {
        if (s[i] == '1')
            result += x;
        x <<= 1;
    }
    return result;
}

void read() {
    char s[N];
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        a[i] = a2i(s, m);
    }
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        c[i] = a2i(s, m);
    }
}

int madan() {
    int result = 0X3f3f3f3f;
    sort(c, c + n);
    for (int i = 0, k; i < (1 << m); i++) {
        // init
        for (int j = 0; j < n; j++)
            b[j] = a[j];
        int bit = 0;
        for (int j = 0; j < m; j++) {
            if (!(i & (1 << j)))
                continue;
            bit++;
            for (k = 0; k < n; k++)
                b[k] ^= (1 << j);
        }
        sort(b, b + n);
        for (k = 0; k < n; k++) {
            if (b[k] != c[k])
                break;
        }
        if (k == n)
            result = min(result, bit);
    }
    return result;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int cas, pcas = 1;
    scanf("%d", &cas);
    while (cas--) {
        scanf("%d%d", &n, &m);
        read();
        int result = madan();
        if (result == 0X3f3f3f3f)
            printf("Case #%d: NOT POSSIBLE\n", pcas++);
        else
            printf("Case #%d: %d\n", pcas++, result);
    }
    return 0;
}
