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

int getVal(int l);
int getCnt(int a);

int processOne(void) {
    int n, l; scanf("%d%d", &n, &l);
    int src[MAXN+1], dest[MAXN+1];
    for (int i = 1; i <= n; i++) {
        src[i] = getVal(l);
    }
    for (int i = 1; i <= n; i++) {
        dest[i] = getVal(l);
    }
    sort(dest+1, dest+n+1);
    int ans = 0x7FFFFFFF;
    for (int s = (1 << l) - 1; s >= 0; s--) {
        int got[MAXN+1];
        for (int i = 1; i <= n; i++) {
            got[i] = src[i] ^ s;
        }
        sort(got+1, got+n+1);
        int isOK = true;
        for (int i = 1; i <= n; i++) {
            if (got[i] != dest[i]) {
                isOK = false;
                break;
            }
        }
        if (isOK) ans = min(ans, getCnt(s));
    }
    return ans < 0x6FFFFFFF ? ans : -1;
}

int getVal(int l) {
    int ret = 0;
    for (int i = 1; i <= l; i++) {
        int get; scanf("%1d", &get);
        ret = (ret << 1) + get;
    }
    return ret;
}

int getCnt(int a) {
    int cnt = 0;
    while (a) {
        if (a & 1) cnt++;
        a >>= 1;
    }
    return cnt;
}
