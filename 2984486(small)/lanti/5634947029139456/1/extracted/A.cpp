// template.cpp
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

char doflip(char ch)
{
    if (ch == '0') return '1';
    else return '0';
}

void solve(int tcase)
{
    cout << "Case #" << tcase << ": ";
    int N, L; cin >> N >> L;
    vector<string> src(N), target(N);
    for (int i = 0; i < N; ++i) cin >> src[i];
    for (int i = 0; i < N; ++i) cin >> target[i];
    sort(target.begin(), target.end());
    // src[0] must match one of target[j], this determines flip of all columns

    int ans = L + 10;
    for (int j = 0; j < N; ++j) {
        int flip[50] = {0};
        for (int pos = 0; pos < L; ++pos) {
            if (src[0][pos] == target[j][pos]) flip[pos] = 0;
            else flip[pos] = 1;
        }
        // now check the rest
        vector<string> src2 = src;
        for (int x = 0; x < N; ++x)
        for (int pos = 0; pos < L; ++pos) {
            if (flip[pos]) {
                char ch = src2[x][pos];
                src2[x][pos] = doflip(ch);
            }
        }
        sort(src2.begin(), src2.end());
        int cost = 0;
        for (int pos = 0; pos < L; ++pos) cost += flip[pos];
        if (src2 == target) ans = min(ans, cost);
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
