#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
using namespace std;

int main() {
    freopen("A-large.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    
    int T;
    cin >> T;
    for (int task = 1; task <= T; task++) {
        int n, l;
        char c;
        cin >> n >> l;
        long long s[200], t[200];
        for (int i = 0; i < n; i++) {
            string x;
            cin >> x;
            s[i] = 0;
            for (int j = 0; j < l; j++) {
                if (x[j] == '1') {
                    s[i] |= 1LL << j;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            string x;
            cin >> x;
            t[i] = 0;
            for (int j = 0; j < l; j++) {
                if (x[j] == '1') {
                    t[i] |= 1LL << j;
                }
            }
        }
        int ans = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                set<long long> cnt;
                long long op = s[i] ^ t[j];
                int tot = 0;
                bool c = true;
                for (int j = 0; j < l; j++) {
                    if (op & (1LL << j)) {
                        tot++;
                    }
                }
                if (ans == -1 || tot < ans) {
                    for (int i = 0; i < n; i++) {
                        cnt.insert(t[i]);
                    }
                    for (int i = 0; i < n; i++) {
                        if (cnt.find(s[i] ^ op) == cnt.end()) {
                            c = false;
                            break;
                        }
                    }
                    if (c) {
                        ans = tot;
                    }
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
