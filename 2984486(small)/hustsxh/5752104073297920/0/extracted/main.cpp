#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct Case {
    int id;
    int perm[1000];
    double value;
    bool ans;
    static bool byID(const Case &a, const Case &b) {
        return a.id < b.id;
    }
    static bool byValue(const Case &a, const Case &b) {
        return a.value < b.value;
    }
}c[121];

int perm[1000];
double rate[1000];

void solve() {
    int n = 1000;
    for (int k = 0; k < 120; ++k) {
        
        for (int i = 0; i < n; ++i) {
            perm[i] = i;
        }
        for (int i = 0; i < n; ++i) {
            int r = 0, temp;
            for (int j = i; j < n; ++j) {
                if (perm[j] == c[k].perm[i]) {
                    r = j;
                }
            }
            temp = perm[i], perm[i] = perm[r], perm[r] = temp;
            rate[i] = 1.0 * (r - i) / (n - i);
        }
        sort(rate, rate + n);
        c[k].value = 0;
        for (int i = 0; i < n; ++i) {
            double e = 1.0 * i / n - rate[i];
            c[k].value += e * e;
        }
    }
    sort(c, c + 120, Case::byValue);
    for (int i = 0; i < 60; ++i) {
        c[i].ans = true;
    }
    for (int i = 60; i < 120; ++i) {
        c[i].ans = false;
    }
    sort(c, c + 120, Case::byID);
}

int main() {
    int testcase;
    freopen("/Users/xhSong/Downloads/C-small-attempt2.in", "r", stdin);
    freopen("/Users/xhSong/gcj/out.txt", "w", stdout);
    cin >> testcase;
    for (int k = 0; k < testcase; ++k) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> c[k].perm[i];
        }
        c[k].id = k;
    }
    solve();
    for (int i = 1; i <= testcase; ++i) {
        cout << "Case #" << i << ": " << (c[i - 1].ans?"GOOD":"BAD") << endl;
    }
    return 0;
}
