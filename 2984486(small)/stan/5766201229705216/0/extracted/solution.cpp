#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <utility>
#include <cassert>
#include <numeric>
#include <sstream>
#include <limits>
using namespace std;

#define REQUIRE(cond, message) \
    do { \
        if (!(cond)) { \
            std::cerr << message << std::endl; \
            assert(false); \
        } \
    } while (false)

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define for1(i, n) for (int i = 1; i <= int(n); ++i)
#define forv(i, v) forn(i, (v).size())
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef vector<string> vs;
typedef long double ld;

template<typename T>
inline int popcount(T t) {
    if (std::numeric_limits<T>::digits <=
                            std::numeric_limits<unsigned int>::digits) {
        return __builtin_popcount(t);
    } else {
        return __builtin_popcountll(t);
    }
}

const ld EPS = 1e-8;
const ld PI = acosl(0.0) * 2;

template <class G>
void dfs(int v, const G& g, vector<bool>& us)
{
    us[v] = true;
    forv(i, g[v]) {
        int u = g[v][i];
        if (!us[u]) {
            dfs(u, g, us);
        }
    }
}

template <class G>
int solve(G g)
{
    int n = g.size();
    int ans = n - 1;
    forn(mask, 1 << n) {
        vector<bool> us(n);
        int cnt = 0;
        forn(i, n) {
            if (mask & (1 << i)) us[i] = true, ++cnt;
        }
        forn(i, n) {
            if (!us[i]) {
                dfs(i, g, us);
                break;
            }
        }
        bool ok = true;
        forn(i, n) if (!us[i]) ok = false;
        if (!ok) continue;
        vi deg(4);
        forn(v, n) {
            if (mask & (1 << v)) continue;
            int d = 0;
            forv(i, g[v]) {
                int u = g[v][i];
                if (mask & (1 << u)) continue;
                ++d;
            }
            if (d > 3) {
                ok = false;
                break;
            }
            ++deg[d];
        }
        if (!ok) continue;
        if (deg[2] == 0 && deg[3] == 0 && deg[1] == 0 && deg[0] == 1)
            ans = min(ans, cnt);
        if (deg[2] == 1)
            ans = min(ans, cnt);
    }
    return ans;
}

void solve()
{
    int tc;
    cin >> tc;
    forn(it, tc) {
        int n;
        cin >> n;
        vector<vi> g(n);
        forn(i, n - 1) {
            int u, v;
            cin >> u >> v;
            g[u - 1].pb(v - 1);
            g[v - 1].pb(u - 1);
        }
        cout << "Case #" << it + 1 << ": " << solve(g) << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
