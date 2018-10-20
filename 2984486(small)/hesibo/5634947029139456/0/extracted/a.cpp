#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    
    int T;
    cin >> T;
    for (int task = 1; task <= T; task++) {
        int n, l;
        char c;
        cin >> n >> l;
        int s[10], t[10], cnt[1024];
        for (int i = 0; i < n; i++) {
            string x;
            cin >> x;
            s[i] = 0;
            for (int j = 0; j < l; j++) {
                if (x[j] == '1') {
                    s[i] |= 1 << j;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            string x;
            cin >> x;
            t[i] = 0;
            for (int j = 0; j < l; j++) {
                if (x[j] == '1') {
                    t[i] |= 1 << j;
                }
            }
        }
        int ans = -1;
        for (int op = 0; op < (1 << l); op++) {
            bool c = true;
            memset(cnt, 0, sizeof(cnt));
            for (int i = 0; i < n; i++) {
                cnt[t[i]]++;
            }
            int a[10];
            for (int i = 0; i < n; i++) {
                a[i] = s[i];
                for (int j = 0; j < l; j++) {
                    if (op & (1 << j)) {
                        a[i] ^= (1 << j);
                    }
                }
                if (cnt[a[i]]) {
                    cnt[a[i]]--;
                } else {
                    c = false;
                    break;
                }
                
            }
            if (c) {
                int tot = 0;
                for (int j = 0; j < l; j++) {
                    if (op & (1 << j)) {
                        tot++;
                    }
                }
                if (ans == -1) {
                    ans = tot;
                } else {
                    ans = min(ans, tot);
                }
            }
        }
        if (ans == -1) {
            printf("Case #%d: NOT POSSIBLE\n", task);
        } else {
            printf("Case #%d: %d\n", task, ans);
        }
    }
    
    return 0;
}
