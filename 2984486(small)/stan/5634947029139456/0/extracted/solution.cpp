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

string solve(vector<string> s, vector<string> t)
{
    sort(all(t));
    int n = t.size();
    int l = t[0].size();
    int ans = l + 1;
    forn(mask, 1 << l) {
        auto ss = s;
        int cnt = 0;
        forn(i, l) {
            if (mask & (1 << i)) {
                ++cnt;
                forn(j, n) {
                    ss[j][i] = '1' - ss[j][i] + '0';
                }
            }
        }
        sort(all(ss));
        if (ss == t) {
            ans = min(ans, cnt);
        }
    }
    if (ans == l + 1) return "NOT POSSIBLE";
    ostringstream os;
    os << ans;
    return os.str();
}

void solve()
{
    int tc;
    cin >> tc;
    forn(it, tc) {
        int n, l;
        cin >> n >> l;
        vector<string> t(n), s(n);
        forn(i, n) cin >> t[i];
        forn(i, n) cin >> s[i];
        cout << "Case #" << it + 1 << ": " << solve(s, t) << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
