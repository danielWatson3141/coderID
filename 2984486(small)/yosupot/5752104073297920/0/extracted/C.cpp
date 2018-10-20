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
typedef pair<ll, int> P;
typedef tuple<int, int, int> T;

int main() {
    int T;
    cin >> T;
    bool used[1010] = {};
    for (int t = 0; t < T; t++) {
        int n;
        cin >> n;
        int d[1010];
        ll r = 0;
        for (int i = 0; i < n; i++) {
            cin >> d[i];
            r += (d[i] <= i) ? 1 : 0;
        }
        if (r < 490) used[t] = true;
    }
    for (int i = 1; i <= T; i++) {
        printf("Case #%d: %s\n", i, used[i-1] ? "BAD" : "GOOD");
    }
    return 0;
}
