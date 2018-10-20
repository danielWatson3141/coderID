// Jason Lau
#include <cstdio>
#include <algorithm>

using namespace std;

void process(void);

int main(void) {
    process();
    return 0;
}

int processOne(void);

void process(void) {
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        int ans = processOne();
        if (ans == -1) {
            printf("Case #%d: NOT POSSIBLE\n", i);
        } else {
            printf("Case #%d: %d\n", i, ans);
        }
    }
}

const int MAXN = 150;
long long src[MAXN+1], dest[MAXN+1];

int n, l;
long long getVal(int l);

void dfs(int at);

int ans = 0x7FFFFFFF;

int processOne(void) {
    scanf("%d%d", &n, &l);
    for (int i = 1; i <= n; i++) {
        src[i] = getVal(l);
    }
    for (int i = 1; i <= n; i++) {
        dest[i] = getVal(l);
    }
    sort(src+1, src+n+1);
    sort(dest+1, dest+n+1);
    ans = 0x7FFFFFFF;
    dfs(l-1);
    return ans < 0x6FFFFFFF ? ans : -1;
}

int changed = 0;

void dfs(int at) {
    if (changed >= ans) return;
    if (at == -1) ans = changed;
    // not changing
    long long mask = ((1LL << (l-at)) - 1) << at;
    bool flag = true;
    for (int i = 1; i <= n; i++) {
        if ((src[i] & mask) != (dest[i] & mask)) {
            flag = false; break;
        }
    }
    if (flag) dfs(at - 1);
    // changing
    for (int i = 1; i <= n; i++) {
        src[i] ^= (1LL << at);
    }
    changed++;
    sort(src+1, src+n+1);
    flag = true;
    for (int i = 1; i <= n; i++) {
        if ((src[i] & mask) != (dest[i] & mask)) {
            flag = false; break;
        }
    }
    if (flag) dfs(at - 1);
    for (int i = 1; i <= n; i++) {
        src[i] ^= (1LL << at);
    }
    changed--;
    sort(src+1, src+n+1);
}

long long getVal(int l) {
    long long ret = 0;
    for (int i = 1; i <= l; i++) {
        int get; scanf("%1d", &get);
        ret = (ret << 1LL) + get;
    }
    return ret;
}
