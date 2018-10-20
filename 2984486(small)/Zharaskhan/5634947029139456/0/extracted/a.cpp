#include <bits/stdc++.h>
using namespace std;
int T, n, l;
char ch;
bool test[110][1500];
vector <int> v;
int getone(int x) {
    int q = 0;
    while (x > 0) {
        q += x % 2;
        x >>= 1;
    }
    return q;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> T;
    for (int k = 1; k <= T; k++) {
        int res = 2000;
        cin >> n >> l;
        getchar();
        v.clear();
        for (int i = 1; i <= n; i++) {
            int ans = 0;
            for (int j = 0, jj = l - 1; j < l ; j++, jj--) {
                ch = getchar();
                ans += (ch - '0') * (1 << jj);
            }
            ch = getchar();
            test[k][ans] = true;
        }

        for (int i = 1; i <= n; i++) {
            int ans = 0;
            for (int j = 0, jj = l - 1; j < l ; j++, jj--) {
                ch = getchar();
                ans += (ch - '0') * (1 << jj);
            }
            ch = getchar();
            v.push_back(ans);
        }
        for (int i = 0; i < (1 << l); i++) {
            bool good = true;
            for (int j = 0; j < v.size(); j++) {
                if (!test[k][(i ^ v[j])]) {
                    good = false;
                    break;
                }
            }
            if (good) {
                res = min(getone(i), res);
            }
        }
        printf("Case #%d: ", k);
        if (res == 2000) {
            printf("NOT POSSIBLE\n");
        } else {
            printf("%d\n", res);
        }

    }
    return 0;
}
