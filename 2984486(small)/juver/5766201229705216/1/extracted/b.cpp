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

PII dfs(int v, VVI const& adj, int p) {
    vector<PII> childs;
    FOR (i, SIZE(adj[v])) {
        int const v1 = adj[v][i];
        if (v1 == p) continue;
        childs.PB(dfs(v1, adj, v));
    }

    if (childs.empty())
        return MP(0, 1);
    if (SIZE(childs) == 1)
        return MP(childs[0].second, childs[0].second + 1);

    int size = 1;
    FOR (i, SIZE(childs)) size += childs[i].second;

    sort(ALL(childs), [](PII const& s1, PII const& s2) {
        if (s1.second == s2.second)
            return s1.first > s2.first;
        return s1.second < s2.second;
    });

    int remove = 0;
    FOR (i, SIZE(childs) - 2) remove += childs[i].second;
    REP (i, SIZE(childs) - 2, SIZE(childs)) remove += childs[i].first;

    return MP(remove, size);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);

    int tests;
    cin >> tests;

    FOR (testId, tests) {
        int n;
        cin >> n;

        VVI adj(n);
        FOR (i, n - 1) {
            int x, y;
            cin >> x >> y;
            --x; --y;
            adj[x].PB(y);
            adj[y].PB(x);
        }

        int res = n;
        FOR (i, n) {
            res = min(res, dfs(i, adj, -1).first);
        }

        printf("Case #%d: %d\n", testId + 1, res);
    }

    return 0;
}
