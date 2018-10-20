#pragma comment(linker, "/STACK:65000000")
#include <algorithm>
#include <cmath>
#include <cstdio> 
#include <cstring> 
#include <iostream> 
#include <map> 
#include <queue> 
#include <set> 
#include <sstream> 
#include <string> 
#include <vector> 

using namespace std; 

template<class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }

typedef long long lng;
typedef long double ld;
typedef stringstream istr;

#define TynKogep TOPCODER
#define bublic public:
#define pb push_back
#define sz(x) ((int)(x).size())
#define mp make_pair
#define first fi
#define second se
#define clr(a) memset((a),0,sizeof(a))

vector<int> v[1100];
int t, n;

int u[1100];

int dfs(int x) {
    u[x] = 1;
    vector<int> w;
    for(int i = 0; i < v[x].size(); ++i) {
        if (!u[v[x][i]])
            w.pb(dfs(v[x][i]));
    }
    if (!w.size()) return 1;
    if (w.size() == 1) return 1;
    sort(w.begin(), w.end());
    return 1 + w.back() + w[w.size() - 2];
}

int go(int x) {
    clr(u);
    return dfs(x);
}

int main() {
    cin >> t;
    for(int T = 0; T < t; ++T) {
        cin >> n;
        for(int i = 0; i < 1010; ++i) {
            v[i].clear();
        }
        for(int i = 0; i < n - 1; ++i) {
            int x, y;
            cin >> x >> y;
            --x;
            --y;
            v[x].pb(y);
            v[y].pb(x);
        }
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            ans = max(ans, go(i));
        }
        cout << "Case #" << T + 1 << ": ";
        cout << n - ans << endl;
    }
    return 0;
};
