#include <cstdio>
#include <algorithm>
using namespace std;
int n, l;
long long a[2][150], b[150];
char s[41];
void solve() {
    scanf("%d%d", &n, &l);
    for (int i = 0 ; i < 2 ; ++i)
        for (int j = 0 ; j < n ; ++j) {
            scanf("%s", s);
            a[i][j] = 0;
            for (int k = 0 ; k < l ; ++k) {
                a[i][j] = (a[i][j] << 1) + s[k] - '0';
            }
        }
    int r = l + 1;
    sort(a[1], a[1] + n);
    for (int i = 0 ; i < n ; ++i)
        for (int j = i ; j < n ; ++j) {
            int v = 0;
            copy(a[0], a[0] + n, b);
            for (int k = 0 ; k < l ; ++k)
                if ((a[0][i] ^ a[1][j]) >> k & 1) {
                    ++v;
                    for (int x = 0 ; x < n ; ++x)
                        b[x] ^= (1ll << k);
                }
            sort(b, b + n);
            bool u = true;
            for (int k = 0 ; u && k < n ; ++k)
                if (b[k] != a[1][k])
                    u = false;
            if (u && v < r) r = v;
        }
    if (r > l) puts("NOT POSSIBLE");
    else printf("%d\n", r);
}
int main() {
    int t;
    freopen("1.txt", "r", stdin);
    freopen("2.txt", "w", stdout);
    scanf("%d", &t);
    for (int c = 0 ; c < t ; ++c) {
        printf("Case #%d: ", c + 1);
        solve();
    }
    return 0;
}
