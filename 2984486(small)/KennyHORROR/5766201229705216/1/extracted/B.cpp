#ifdef DEBUG
//#define _GLIBCXX_DEBUG
#endif
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <string>
#include <cstring>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <cassert>
#include <functional>
#include <complex>

using namespace std;
typedef long double LD;
typedef long long LL;

const int kInf = 1 << 30;

struct Arc {
    int f, s, prev;
} arr[5005];

int beg[5005], kol;

void Init() {
    memset(beg, -1, sizeof beg);
    kol = 0;
}

void AddArc(int f, int s) {
    arr[kol].f = f;
    arr[kol].s = s;
    arr[kol].prev = beg[f];
    beg[f] = kol++;

    arr[kol].f = s;
    arr[kol].s = f;
    arr[kol].prev = beg[s];
    beg[s] = kol++;
}

int dp[1005], sz[1005];

int DFS1(int cur, int p = -1) {
    int ret = 1;
    for (int i = beg[cur]; i != -1; i = arr[i].prev) {
        if (arr[i].s != p) {
            ret += DFS1(arr[i].s, cur);
        }
    }
    return sz[cur] = ret;
}

int DFS2(int cur, int p = -1) {
    int ret = 0;
    for (int i = beg[cur]; i != -1; i = arr[i].prev) {
        if (arr[i].s != p) {
            DFS2(arr[i].s, cur);
        }
    }
    int mn1 = kInf, mn2 = kInf;
    for (int i = beg[cur]; i != -1; i = arr[i].prev) {
        if (arr[i].s != p) {
            ret += sz[arr[i].s];
            int save = dp[arr[i].s] - sz[arr[i].s];
            if (save < mn1) {
                mn2 = mn1;
                mn1 = save;
            } else if (save < mn2) {
                mn2 = save;
            }
        }
    }
    if (mn1 != kInf && mn2 != kInf) {
        ret += mn1 + mn2;
    }
    return dp[cur] = ret;
}

int main() {
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    int T;
    cin >> T;
    for (int I = 0; I < T; ++I) {
        printf("Case #%d: ", I + 1);
        Init();
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n - 1; ++i) {
            int f, s;
            scanf("%d%d", &f, &s);
            --f;
            --s;
            AddArc(f, s);
        }
        int ret = kInf;
        for (int i = 0; i < n; ++i) {
            DFS1(i);
            ret = min(ret, DFS2(i));
        }
        printf("%d\n", ret);
    }
    return 0;
}
