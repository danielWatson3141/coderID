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
int bc(int n) { return n ? bc((n-1)&n)+1 : 0; }

int i, j, k, m, n, l, ans;
char ss[1000002];
vector<int> g[1005];
int x[1005], y[1005];

void solve(int i, int parent) {
    int sz = SZ(g[i]), j;

    vector<int> v;
    x[i] = 0;
    y[i] = 1;
    F0(j,sz) if (g[i][j] != parent) {
        int k = g[i][j];
        solve(k, i);
        x[i] += y[k];
        y[i] += y[k];
        v.push_back(x[k]-y[k]);
    }
    if (SZ(v) > 1) {
        sort(v.begin(), v.end());
        if (v[0] + v[1] < 0) x[i] += (v[0] + v[1]);
    }
}

int main() {
//	freopen("b.in", "r", stdin);

    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);

//	freopen("B-large.in", "r", stdin);
//	freopen("B-large.out", "w", stdout);

	int tt, tn; cin >> tn;
	F1(tt,tn) {
        //cerr << tt << endl;
        cin >> n;
        F1(i,n) g[i].clear();
        F0(k,n-1) {
            cin >> i >> j;
            g[i].push_back(j);
            g[j].push_back(i);
        }

        ans = n+5;
        F1(i,n) {
            solve(i, -1);
            ans = min(ans, x[i]);
        }

		printf("Case #%d: ", tt);

		cout << ans << endl;
	}

	return 0;
}
