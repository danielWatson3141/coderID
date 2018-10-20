#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
const int N = 200;
const int M = 100;
int t, n, m, ans = -1;
int a[N][M], b[N][M];
int pa[N], pb[N], f[N];

bool cmpa(int x, int y) {
    rep(i, m) {
        if ((a[x][i] ^ f[i]) < (a[y][i] ^ f[i])) return true;
        if ((a[x][i] ^ f[i]) > (a[y][i] ^ f[i])) return false;
    }
    return true;
}

bool cmpb(int x, int y) {
    rep(i, m) {
        if (b[x][i] < b[y][i]) return true;
        if (b[x][i] > b[y][i]) return false;
    }
    return true;
}

bool right() {
    rep(i, n) pa[i] = i;
    sort(pa, pa+n, cmpa);
    rep(i, n) {
        rep(j, m) {
            if ((a[pa[i]][j] ^ f[j]) != b[pb[i]][j]) return false;
        }
    }
    return true;
}

void solve() {
    ans = -1;
    sort(pb, pb+n, cmpb);
    memset(f, 0, sizeof f);
    rep(i, n) {
        rep(j, n) {
            int cnt = 0;
            rep(k, m) {
                if (a[i][k] != b[j][k]) {
                    f[k] = 1;
                }
                else f[k] = 0;

                cnt += f[k];
            }

            if ((cnt<ans || ans==-1) && right()) ans = cnt;
        }
    }

    if (ans==-1) cout << "NOT POSSIBLE" << endl;
    else cout << ans << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    //freopen("test.in", "r", stdin);
    //freopen("tmp.out", "w", stdout);
    scanf("%d", &t);
    rep(i, t) {
        scanf("%d%d", &n, &m);
        char c;
        rep(j, n) {
            pa[j] = j;
            rep(k, m) {
                while ((c=getchar()) && c!='0' && c!='1');
                a[j][k] = c-'0';
            }
        }
        rep(j, n) {
            pb[j] = j;
            rep(k, m) {
                while ((c=getchar()) && c!='0' && c!='1');
                b[j][k] = c-'0';
            }
        }
        cout << "Case #" << i+1 << ": ";
        solve();
    }
    return 0;
}
