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
#define N 1010
#define M 1000000

const int n = 1000;

int f1[N][N], f2[N][N];
int a[N], p, T;

void Good() {
	rep(i, n) a[i] = i;
	rep(k, n) {
		p = rand() % (n-k) + k;
		swap(a[k], a[p]);
	}
	rep(i, n) f1[i][a[i]]++;
}

void Bad() {
	rep(i, n) a[i] = i;
	rep(k, n) {
		p = rand() % n;
		swap(a[k], a[p]);
	}
	rep(i, n) f2[i][a[i]]++;
}

void solve() {
	scanf("%d", &p);
	double x1 = 0, x2 = 0;
	rep(i, n) {
		scanf("%d", &a[i]);
		x1 += (f1[i][a[i]] == 0?0:log(f1[i][a[i]]));
		x2 += (f2[i][a[i]] == 0?0:log(f2[i][a[i]]));
	}
	//printf("%.8lf:%.8lf::", x1, x2);
	if (x1 > x2) puts("GOOD"); else puts("BAD");
}

int main() {
	rep(i, M) {
		Good(); Bad();
	}
    freopen("C-small-attempt1.in", "r", stdin);
    freopen("C-small-attempt1.ou", "w", stdout);
	scanf("%d", &T);
	kep(_, T) {
		printf("Case #%d: ", _);
		solve();
	}
}
