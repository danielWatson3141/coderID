#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <float.h>

using namespace std;

#define REP(i, from, to) for (int i = (from); i < (to); ++i)
#define FOR(i, n) REP(i, 0, (n))
#define ALL(x) x.begin(), x.end()
#define SIZE(x) (int)x.size()
#define PB push_back
#define MP make_pair

typedef long long i64;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef vector<VS> VVS;
typedef pair<int, int> PII;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);

    int tests;
    cin >> tests;

    FOR (testId, tests) {
        int n, l;
        cin >> n >> l;

        VS a(n);
        FOR (i, n) cin >> a[i];

        VS b(n);
        FOR (i, n) cin >> b[i];

        sort(ALL(b));
        int res = -1;
        FOR (mask, 1 << l) {
            VS c = a;
            int flips = 0;
            FOR (i, l) if (mask & (1 << i)) {
                FOR (j, n)
                    c[j][i] = ('1' - c[j][i]) + '0';
                ++flips;
            }

            sort(ALL(c));
            if (c == b) {
                if (res == -1 || res > flips)
                    res = flips;
            }
        }

        printf("Case #%d: ", testId + 1);
        if (res != -1)
            printf("%d\n", res);
        else
            printf("NOT POSSIBLE\n");
    }

    return 0;
}
