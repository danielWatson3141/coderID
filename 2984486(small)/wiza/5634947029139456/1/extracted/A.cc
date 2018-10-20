#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;
using std::sort;
typedef vector<string> VS;

int N, L;

void flip(VS &out, int i) {
    for (auto &str: out) {
        str[i] = str[i] == '0' ? '1' : '0';
    }
}

bool check(const VS &out, const VS &dev, int n) {
    for (int i = 0; i < N; i++) {
        if (strncmp(out[i].c_str(), dev[i].c_str(), n))
            return false;
    }
    return true;
}

VS out, dev;

int solve(int i) {
    if (i == L) return 0;
    int out_0 = 0, dev_0 = 0;
    for (auto &str: out) {
        if (str[i] == '0') out_0++;
    }
    for (auto &str: dev) {
        if (str[i] == '0') dev_0++;
    }
    int ret0 = -1, ret1 = -1;
    if (out_0 == dev_0) {
        if (check(out, dev, i+1)) {
            ret0 = solve(i+1);
        }
    }
    if (out_0 == N - dev_0) {
        flip(out, i);
        sort(out.begin(), out.end());
        if (check(out, dev, i+1)) {
            ret1 = solve(i+1);
        }
        flip(out, i);
        sort(out.begin(), out.end());
    }
    if (ret0 == -1 && ret1 == -1) return -1;
    if (ret0 == -1) return ret1 + 1;
    if (ret1 == -1) return ret0;
    if (ret0 < ret1 + 1) return ret0;
    return ret1 + 1;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int test = 1; test <= T; test++) {
        int i;
        char str[40];
        out.clear();
        dev.clear();

        printf("Case #%d: ", test);
        scanf("%d %d", &N, &L);

        for (i = 0; i < N; i++) {
            scanf("%s", str);
            out.push_back(str);
        }
        for (i = 0; i < N; i++) {
            scanf("%s", str);
            dev.push_back(str);
        }
        sort(out.begin(), out.end());
        sort(dev.begin(), dev.end());

        int ans = solve(0);
        if (ans == -1) {
            puts("NOT POSSIBLE");
        } else {
            printf("%d\n", ans);
        }
    }
    return 0;
}
