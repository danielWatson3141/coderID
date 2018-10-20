#ifdef DEBUG
//#define _GLIBCXX_DEBUG
#endif
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <string>
#include <cstring>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <cassert>
#include <functional>
#include <complex>

using namespace std;
typedef long double LD;
typedef long long LL;

const int kInf = 1 << 30;

char cur[155][55];
char goal[155][55];
char tmp[55];
char flip[55];

int Solve(int pos, int n, int l) {
    int ret = 0;
    memset(flip, 0, sizeof flip);
    for (int i = 0; i < l; ++i) {
        if (goal[pos][i] != cur[0][i]) {
            flip[i] = 1;
            ++ret;
        } else {
            flip[i] = 0;
        }
    }
    vector<string> v1, v2;
    for (int i = 0; i < n; ++i) {
        v1.push_back(goal[i]);
    }
    for (int i = 0; i < n; ++i) {
        string tmp = cur[i];
        for (int j = 0; j < l; ++j) {
            if (flip[j]) {
                tmp[j] ^= 1;
            }
        }
        v2.push_back(tmp);
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    for (int i = 0; i < n; ++i) {
        if (v1[i] != v2[i]) {
            return kInf;
        }
    }
    return ret;
}

int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    int T;
    cin >> T;
    for (int I = 0; I < T; ++I) {
        printf("Case #%d: ", I + 1);
        int n, l;
        scanf("%d%d", &n, &l);
        for (int i = 0; i < n; ++i) {
            scanf("%s", cur[i]);
        }
        for (int i = 0; i < n; ++i) {
            scanf("%s", goal[i]);
        }
        int ret = kInf;
        for (int i = 0; i < n; ++i) {
            int val = Solve(i, n, l);
            if (val < ret) {
                ret = val;
            }
        }
        if (ret == kInf) {
            puts("NOT POSSIBLE");
        } else {
            printf("%d\n", ret);
        }
    }
    return 0;
}
