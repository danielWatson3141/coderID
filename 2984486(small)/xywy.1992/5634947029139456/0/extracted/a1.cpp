#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>
#include <cstdio>

int T, n, l;
std::string s[10], t[10];

bool equal(std::vector <int> & x, std::vector <int> & y) {
    std::sort(x.begin(), x.end());
    std::sort(y.begin(), y.end());
    for(int i = 0; i < n; ++i) {
        if(x[i] != y[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    std::cin >> T;
    for(int test = 1; test <= T; ++test) {
        std::cin >> n >> l;
        for(int i = 0; i < n; ++i) {
            std::cin >> s[i];
        }
        for(int i = 0; i < n; ++i) {
            std::cin >> t[i];
        }
        int ans = INT_MAX;
        for(int i = 0; i < (1 << l); ++i) {
            std::vector<int> x, y;
            for(int j = 0; j < n; ++j) {
                int u = 0, v = 0;
                for(int k = 0; k < l; ++k) {
                    if((i >> k) & 1) {
                        u = u << 1 | (s[j][k] == '0');
                    } else {
                        u = u << 1 | (s[j][k] == '1');
                    }
                    v = v << 1 | (t[j][k] == '1');
                }
                x.push_back(u), y.push_back(v);
            }
            if(equal(x, y)) {
                int tmp = 0;
                for(int j = 0; j < l; ++j) {
                    if(i & (1 << j)) {
                        tmp++;
                    }
                }
                ans = std::min(ans, tmp);
            }
        }
        if(ans == INT_MAX) {
            std::cout << "Case #" << test << ": NOT POSSIBLE" << std::endl;
            continue;
        }
        std::cout << "Case #" << test << ": " << ans << std::endl;
    }
    return 0;
}
