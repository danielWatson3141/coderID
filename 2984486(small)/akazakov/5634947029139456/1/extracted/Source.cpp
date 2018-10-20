#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>

#include <algorithm>
#include <cmath>
#include <ctime>

#include <stack>
#include <deque>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

#define uLL unsigned long long
#define BIG 1000000000

using namespace std;

#define PROBLEM "A"

inline uLL strToBm(const string &s) {
    uLL res = 0;
    for (auto ch : s) {
        res <<= 1;
        res += ch == '1';
    }
    return res;
}

struct State {
    vector<uLL> sock, dev;
    int n;
    State(const vector<string> &sockets, const vector<string> &devices) :
        sock(sockets.size()), dev(devices.size()), n(int(devices.size()))
    {
        for (int i = 0; i < n; ++i) {
            sock[i] = strToBm(sockets[i]);
            dev[i] = strToBm(devices[i]);
        }
        sort(dev.begin(), dev.end());
    }
    inline int bitCount(uLL x) {
        int res = 0;
        while (x) {
            res += (x & 1);
            x >>= 1;
        }
        return res;
    }
    int checkSolution(uLL sol) {
        vector<uLL> newsock(n);
        for (int i = 0; i < n; ++i) {
            newsock[i] = sock[i] ^ sol;
        }
        sort(newsock.begin(), newsock.end());
        for (int i = 0; i < n; ++i) {
            if (newsock[i] != dev[i]) {
                return BIG;
            }
        }
        return bitCount(sol);
    }
};

void solveTestCase() {
    int n, l;
    cin >> n >> l;
    vector<string> sock_str(n), dev_str(n);
    for (int i = 0; i < n; ++i) {
        cin >> sock_str[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> dev_str[i];
    }
    State state(sock_str, dev_str);
    int best_bm_v = BIG;
    for (uLL i = 0; i < n; ++i) {
        int res = state.checkSolution(state.dev[0] ^ state.sock[i]);
        if (res < best_bm_v) {
            best_bm_v = res;
        }
    }
    if (best_bm_v >= BIG) {
        cout << "NOT POSSIBLE" << endl;
    } else {
        cout << best_bm_v << endl;
    }
}

int main() {
    freopen("input_" PROBLEM ".txt", "rt", stdin); //-V530
    freopen("output.txt", "wt", stdout); //-V530
    int num_tests;
    cin >> num_tests;
    for (int i = 1; i <= num_tests; ++i) {
        cerr << i << "\r" << flush;
        cout << "Case #" << i << ": ";
        solveTestCase();
    }
    return 0;
}