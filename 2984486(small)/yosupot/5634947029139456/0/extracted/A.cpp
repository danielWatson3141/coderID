#include <vector>
#include <iostream>
#include <set>
#include <cstdio>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cmath>
#include <complex>
#include <algorithm>
#include <tuple>
#include <algorithm>
#include <limits>
#include <map>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int n, l;
        cin >> n >> l;
        string x[200], y[200];
        for (int i = 0; i < n; i++) {
            cin >> x[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> y[i];
        }
        int res = 10000;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                set<string> s;
                bool c[100] = {};
                int r = 0;
                for (int k = 0; k < l; k++) {
                    if (x[i][k] != y[j][k]) {
                        r++;
                        c[k] = true;
                    }
                }
                for (int k = 0; k < n; k++) {
                    string s1 = x[k];
                    for (int u = 0; u < l; u++) {
                        if (c[u]) {
                            s1[u] = (s1[u] == '0') ? '1' : '0';
                        }
                    }
                    s.insert(s1);
                }
                bool f = true;
                for (int k = 0; k < n; k++) {
                    if (!s.count(y[k])) {
                        f = false;
                        break;
                    }
                }
                if (f) {
                    res = min(res, r);
                }
            }
        }
        if (res == 10000) {
            printf("Case #%d: NOT POSSIBLE\n", t);
        } else {
            printf("Case #%d: %d\n", t, res);
        }
    }
    return 0;
}
