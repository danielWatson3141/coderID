#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <climits>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int maxn = 1200;

int T, n, u, v, l;
int a[maxn], b[maxn], c[maxn];
char buf[maxn];

int cnt_bit(int x) {
    int ans = 0;
    while (x) x -= x & -x, ++ans;
    return ans;
}

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int cs = 0;
    cin>>T;
    while (T--) {
        cin>>n>>l;
        for (int i = 0; i < n; i++) {
            a[i] = 0;
            scanf("%s", buf);
            for (int j = 0; j < l; j++) a[i] = a[i] * 2 + buf[j] - '0';
        }
        for (int i = 0; i < n; i++) {
            b[i] = 0;
            scanf("%s", buf);
            for (int j = 0; j < l; j++) b[i] = b[i] * 2 + buf[j] - '0';
        }
        sort(a, a + n);
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            int x = a[0] ^ b[i];
            vector<int> v;
            for (int i = 0; i < n; i++) v.push_back(b[i] ^ x);
            sort(v.begin(), v.end());
            int flag = 1;
            for (int i = 0; i < n; i++)
                flag &= a[i] == v[i];
            if (flag) ans = min(ans, cnt_bit(x));
        }
        printf("Case #%d: ", ++cs);
        if (ans == INT_MAX) printf("NOT POSSIBLE\n");
        else printf("%d\n", ans);
    }
    return 0;
}
