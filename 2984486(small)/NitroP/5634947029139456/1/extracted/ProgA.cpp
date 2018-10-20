#include <cstdio>
#include <algorithm>
using namespace std;
int n, l;
long long bitR[2][150], b[150];
char s[41];

int main() {
    int t;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    for (int c = 0 ; c < t ; ++c) {
        printf("Case #%d: ", c + 1);
            scanf("%d%d", &n, &l);
            for (int i = 0 ; i < 2 ; ++i)
        for (int j = 0 ; j < n ; ++j) {
            scanf("%s", s);
            bitR[i][j] = 0;
            for (int k = 0 ; k < l ; ++k) {
                bitR[i][j] = (bitR[i][j] << 1) + s[k] - '0';
            }
        }
        int r = l + 1;
        sort(bitR[1], bitR[1] + n);
        for (int i = 0 ; i < n ; ++i)
            for (int j = i ; j < n ; ++j) {
                int v = 0;
                copy(bitR[0], bitR[0] + n, b);
                for (int k = 0 ; k < l ; ++k)
                    if ((bitR[0][i] ^ bitR[1][j]) >> k & 1) {
                        ++v;
                        for (int x = 0 ; x < n ; ++x)
                            b[x] ^= (1ll << k);
                    }
                sort(b, b + n);
                bool u = true;
                for (int k = 0 ; u && k < n ; ++k)
                    if (b[k] != bitR[1][k])
                        u = false;
                if (u && v < r) r = v;
        }
    if (r > l) puts("NOT POSSIBLE");
    else printf("%d\n", r);
    }
    return 0;
}
