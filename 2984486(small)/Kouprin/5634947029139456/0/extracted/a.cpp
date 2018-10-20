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

lng give(string s) {
    lng now = 0, st = 1;
    for(int i = 0; i < sz(s); ++i) {
        if (s[i] == '1') now += st;
        st *= 2;
    }
    return now;
}

int T, n, l;
string s;
vector<lng> A, B;
set<lng> S;

int pa[222];
int u[222];

bool kuhn(int x, lng mask) {
    if (u[x]) return false;
    u[x] = 1;
    for(int i = 0; i < n; ++i) {
        if ((A[x] ^ B[i]) == mask) {
            if (pa[i] == -1 || kuhn(pa[i], mask)) {
                pa[i] = x;
                return true;
            }
        }
    }
    return false;
}

bool pairing(lng mask) {
    for(int i = 0; i < n; ++i) {
        pa[i] = -1;
    }
    for(int i = 0; i < n; ++i) {
        clr(u);
        if (!kuhn(i, mask)) return false;
    }
    return true;
}

int main() {
    cin >> T;
    for(int t = 0; t < T; ++t) {
        cout << "Case #" << t + 1 << ": ";
        lng ans = 100;
        cin >> n >> l;
        A.clear();
        B.clear();
        for(int i = 0; i < n; ++i) {
            cin >> s;
            lng z = give(s);
            A.pb(z);
        }
        for(int i = 0; i < n; ++i) {
            cin >> s;
            lng z = give(s);
            B.pb(z);
        }
        S.clear();
        for(int i = 0; i < n; ++i) {
            S.insert(A[0] ^ B[i]);
        }
        for(auto i = S.begin(); i != S.end(); ++i) {
            lng z = *i;
            if (pairing(z)) {
                ans = min(ans, lng(__builtin_popcount(z)));
            }
        }
        if (ans == 100) {
            cout << "NOT POSSIBLE" << endl;
        } else {
            cout << ans << endl;
        }
    }
    return 0;
};
