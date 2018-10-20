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

const int N = 500;
typedef long long LL;

LL fromcode[N], tocode[N];

LL code2num(char s[], int l) {
    LL num = 0;
    for (int i = 0; i < l; ++i) {
        num = (num << 1) | (s[i] - '0');
    }
    return num;
}

void solve() {
    int n, l;
    char code[50];
    cin >> n >> l;
    for (int i = 0; i < n; ++i) {
        cin >> code;
        fromcode[i] = code2num(code, l);
    }
    for (int i = 0; i < n; ++i) {
        cin >> code;
        tocode[i] = code2num(code, l);
    }
    vector<LL> c;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            c.push_back(fromcode[i] ^ tocode[j]);
        }
    }
    sort(c.begin(), c.end());
    c.push_back(-1);
    // for (int i = 0; i < c.size(); ++i) cout << c[i] << " ";
    // cout << endl;
    int cnt = 1, anschange = l + 1;
    for (int i = 1; i < c.size(); ++i) {
        if (c[i] == c[i - 1]) {
            ++ cnt;
        } else {
            if (cnt >= n) {
                LL temp = c[i - 1];
                int cntbits = 0;
                while (temp) {
                    cntbits += ((temp & 1)? 1: 0);
                    temp /= 2;
                }
                if (cntbits < anschange) {
                    anschange = cntbits;
                }
            }
            cnt = 1;
        }
    }
    if (anschange == l + 1) {
        cout << " NOT POSSIBLE" << endl;
    } else {
        cout << " " << anschange << endl;
    }
}

int main() {
    int testcase;
    freopen("/Users/xhSong/Downloads/A-large.in", "r", stdin);
    freopen("/Users/xhSong/gcj/out.txt", "w", stdout);
    cin >> testcase;
    for (int test = 1; test <= testcase; ++test) {
        cout << "Case #" << test << ":";
        solve();
    }
    return 0;
}
