#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <sstream>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define SZ(x) (int)(x.size())
#define F0(i,n) for(i=0;i<n;i++)
#define F1(i,n) for(i=1;i<=n;i++)
#define CL(a,x) memset(x, a, sizeof(x))
const int inf = 1000000009;
const double pi = atan(1.0)*4.0;
const double eps = 1e-8;
ll gcd(ll x, ll y) { return y ? gcd(y, x%y) : x; }
int bc(ll n) { return n ? bc((n-1)&n)+1 : 0; }

int i, j, k, m, n, l, ans;
char ss[1000002];

ll conv(string s) {
    ll ret = 0;
    int i;
    F0(i,SZ(s)) ret = ret * 2 + (s[i] - '0');
    return ret;
}

int main() {
//	freopen("a.in", "r", stdin);

    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);

//	freopen("A-large.in", "r", stdin);
//	freopen("A-large.out", "w", stdout);

	int tt, tn; cin >> tn;
	F1(tt,tn) {
        //cerr << tt << endl;
        vector<ll> v1, v2;
        string s;
        cin >> n >> m;
        F0(i,n) {
            cin >> s;
            v1.push_back(conv(s));
        }
        F0(i,n) {
            cin >> s;
            v2.push_back(conv(s));
        }
        sort(v2.begin(), v2.end());
        ans = m + 5;
        F0(j,n) {
            ll x = v1[0] ^ v2[j];
            vector<ll> v3;
            F0(i,n) v3.push_back(v1[i] ^ x);
            sort(v3.begin(), v3.end());
            if (v2 == v3) {
                ans = min(ans, bc(x));
            }
        }

		printf("Case #%d: ", tt);
        if (ans > m) cout << "NOT POSSIBLE" << endl;
        else cout << ans << endl;
	}
	
	return 0;
}
