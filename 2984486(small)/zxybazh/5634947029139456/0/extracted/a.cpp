#include <algorithm>
#include <iostream>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <utility>
#include <numeric>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <ctime>
#include <map>
#include <set>
using namespace std;
typedef pair<int, int> PII;
typedef vector<string> VS;
typedef map<int, int> MII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef set<int> SI;
typedef long double LD;
typedef long long LL;
#define PB push_back
#define MP make_pair
#define LB lower_bound
#define UP upper_bound
#define FI first
#define SE second
const int inf = 1073741823;
const int maxint = 0x7fffffff;
const LL  INF = 1152921504606846976ll;
const LD  eps = 1E-9;
const LD  pi = acos(-1);
template <class T> inline T _sqr(T a) {return (a*a);}
template <class T> inline T _abs(T a) {return (a>=0?a:-a);}
template <class T> inline T _lbt(T a) {return (a&(a^(a-1)));}
template <class T> inline T _max(T a, T b) {return (a>b?a:b);}
template <class T> inline T _min(T a, T b) {return (a<b?a:b);}
template <class T> inline T _smax(T a,T b,T c) {return _max(_max(a,b),c);}
template <class T> inline T _smin(T a,T b,T c) {return _min(_min(a,b),c);}
template <class T> inline T _sqrt(T a) {T b,c;for(b = sqrt(a),c=b-2;c<=b+2;c++)if(_sqr(c)<=a)b=c;return b;}
template <class T> inline T _pow(T a,T b,T c) {T d=1;for (a%=c;b;b>>=1,a=a*a%c)if(b&1)d=d*a%c;return d;}
#define rep(i, n) for (int i = 0; i < n; i++)
#define kep(i, n) for (int i = 1; i<= n; i++)
#define ifo(i, l, r) for (int i = l; i <= r; i++)
#define dfo(i, r, l) for (int i = r; i >= l; i--)
#define N 222
#define L 222

int T, n, l;
string a[N], b[N];
int ans;

void solve() {
	scanf("%d%d", &n, &l);
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];
	sort(b, b + n);
	ans = 0; bool flag;
	rep(j, l) {
		sort(a, a + n);
		flag = false;
		rep(i, n) {
			rep(t, j+1) if (a[i][t] != b[i][t]) {
				flag = true;
				break;
			}
			if (flag) break;
		}
		if (!flag) continue;
		flag = false;
		ans++;
		rep(i, n) if (a[i][j] == '1') a[i][j] = '0'; else a[i][j] = '1';
		sort(a, a + n);
		rep(i, n) {
			rep(t, j+1) if (a[i][t] != b[i][t]) {
				flag = true;
				break;
			}
			if (flag) break;
		}
		if (!flag) continue;
		puts("NOT POSSIBLE");
		return;
	}
	printf("%d\n", ans);
}

int main() {
    //freopen("a.in", "r", stdin);
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.ou", "w", stdout);
	scanf("%d", &T);
	kep(_, T) {
		printf("Case #%d: ", _);
		solve();
	}
}
