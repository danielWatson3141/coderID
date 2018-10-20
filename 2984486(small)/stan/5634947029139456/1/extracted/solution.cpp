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
int ans;

struct Cmp
{
    Cmp(int shift): shift_(shift) { }
    bool operator()(ll x, ll y) const
    {
        return (x >> shift_) < (y >> shift_);
    }
    int shift_;
};

bool eq(const vector<ll>& a, const vector<ll>& b, int shift)
{
    forv(i, a) {
        if ((a[i] >> shift) != (b[i] >> shift)) return false;
    }
    return true;
}

void calc(int idx, int l, const vector<ll>& tv, vector<ll> sv, int nsw)
{
    if (idx == l) {
        ans = min(ans, nsw);
        return;
    }
    int shift = l - idx - 1;
    sort(all(sv), Cmp(shift));
    if (eq(sv, tv, shift)) {
        calc(idx + 1, l, tv, sv, nsw);
    }
    for (ll& x : sv) {
        x ^= 1 << shift;
    }
    sort(all(sv), Cmp(shift));
    if (eq(sv, tv, shift)) {
        calc(idx + 1, l, tv, sv, nsw + 1);
    }
}

string solve(vector<string> s, vector<string> t)
{
    vector<ll> sv(s.size()), tv(t.size());
    forv(i, sv) {
        sv[i] = 0;
        tv[i] = 0;
        forv(j, s[i]) {
            sv[i] <<= 1;
            sv[i] += '1' - s[i][j];
            tv[i] <<= 1;
            tv[i] += '1' - t[i][j];
        }
    }
    sort(all(tv));
    int l = t[0].size();
    ans = l + 1;

    calc(0, l, tv, sv, 0);

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
        cerr << it << endl;
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
