// Asmall.cpp
//

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
using namespace std;

char flip(char ch)
{
    if (ch == '0') return '1';
    else return '0';
}

int count_bit(int mask)
{
    int ans = 0;
    while (mask) {
        ans++;
        mask &= mask-1;
    }
    return ans;
}

bool match(string s1, string s2)
{
    if (s1 == s2) return true;
    return false;
}

bool match(const vector<string> &v1, const vector<string> &v2)
{
    int N = v1.size();
    int used[20] = {0};
    for (int i = 0; i < N; ++i) {
        bool found = false;
        for (int j = 0; j < N; ++j) {
            if (!used[j] && match(v1[i], v2[j])) {
                used[j] = 1; found = true; break;
            }
        }
        if (!found) { return false; }
    }
    return true;
}

void solve(int tcase)
{
    cout << "Case #" << tcase << ": ";
    int N, L; cin >> N >> L;
    vector<string> src(N), target(N);
    for (int i = 0; i < N; ++i) cin >> src[i];
    for (int i = 0; i < N; ++i) cin >> target[i];
    int ans = L + 10;
    for (int mask = 0; mask < (1<<L); ++mask) {
        vector<string> src2 = src;
        for (int pos = 0; pos < L; ++pos) if (1<<pos & mask)
        for (int i = 0; i < N; ++i) {
            char ch = src2[i][pos];
            src2[i][pos] = flip(ch);
        }
        //cout << endl << "mask " << mask << endl;
        //for (int i = 0; i < N; ++i) cout << src2[i] << endl;

        if (match(src2, target)) ans = min(ans, count_bit(mask));
    }
    if (ans > L) cout << "NOT POSSIBLE" << endl;
    else cout << ans << endl;
}

int main()
{
    int T; cin >> T;
    for (int t = 1; t <= T; ++t)
        solve(t);
}
