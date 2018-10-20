#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
using namespace std;
#define SZ(v) ((int)(v).size())
#define SQR(x) ((x) * (x))
#define EPS 1e-9
const int maxint = -1u>>1;
const int maxn = 1000 + 4;

int n;
vector<int> v[maxn];

int calc(int now, int dad) {
    vector<int> rec;
    for (int i = 0; i < SZ(v[now]); ++i) {
        int x = v[now][i];
        if (x == dad) continue;
        rec.push_back(calc(x, now));
    }
    int ans = 1;
    if (SZ(rec) >= 2) {
        sort(rec.begin(), rec.end());
        reverse(rec.begin(), rec.end());
        ans = max(ans, rec[0] + rec[1] + 1);
    }
    return ans;
}

int main() {
    freopen("b.out", "w", stdout);
    int t, ca = 0;
    scanf("%d", &t);
    while (t--) {
        printf("Case #%d: ", ++ca);
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            v[i].clear();
        }
        for (int i = 0; i < n - 1; ++i) {
            int x1, x2;
            scanf("%d%d", &x1, &x2);
            --x1; --x2;
            v[x1].push_back(x2);
            v[x2].push_back(x1);
        }
        int ans = 1;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, calc(i, -1));
        }
        printf("%d\n", n - ans);
    }
    return 0;
}

