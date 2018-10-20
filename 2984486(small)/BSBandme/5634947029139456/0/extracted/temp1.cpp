/*
 * temp.cpp
 *
 *  Created on: 2012-7-18
 *      Author: BSBandme
 */
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cassert>
#include <list>
#include <iomanip>
#include <math.h>
#include <deque>
#include <utility>
#include <map>
#include <set>
#include <bitset>
#include <numeric>
#include <climits>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <sstream>

using namespace std;

#define mpr make_pair
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <double, double> pdd;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <double> vd;
typedef vector <string> vs;
typedef map <string, int> mpsi;
typedef map <double, int> mpdi;
typedef map <int, int> mpii;

const double pi = acos(0.0) * 2.0;
const double eps = 1e-12;
const int step[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

template <class T> inline T abs1(T a) {return a < 0 ? -a : a;}

template <class T> inline T max1(T a, T b) { return a > b ? a : b; }
template <class T> inline T max1(T a, T b, T c) { return max1(max1(a, b), c); }
template <class T> inline T max1(T a, T b, T c, T d) { return max1(max1(a, b, c), d); }
template <class T> inline T max1(T a, T b, T c, T d, T e) { return max1(max1(a, b, c, d), e); }
template <class T> inline T min1(T a, T b) { return a < b ? a : b; }
template <class T> inline T min1(T a, T b, T c) { return min1(min1(a, b), c); }
template <class T> inline T min1(T a, T b, T c, T d) { return min1(min1(a, b, c), d); }
template <class T> inline T min1(T a, T b, T c, T d, T e) { return min1(min1(a, b, c, d), e); }

inline int jud(double a, double b){
	if(abs(a) < eps && abs(b) < eps) return 0;
	else if(abs1(a - b) / abs1(a) < eps) return 0;
	if(a < b) return -1;
	return 1;
}
template <typename t> inline int jud(t a, t b){
	if(a < b) return -1;
	if(a == b) return 0;
	return 1;
}

// f_lb == 1代表返回相同的一串的左边界，f_small == 1代表返回如果没有寻找的值返回小的数
template <typename it, typename t1>
inline int find(t1 val, it a, int na, bool f_small = 1, bool f_lb = 1){
	int be = 0, en = na - 1;
	if(*a <= *(a + na - 1)){
		if(f_lb == 0) while(be < en){
			int mid = (be + en + 1) / 2;
			if(jud(*(a + mid), val) != 1) be = mid;
			else en = mid - 1;
		}else while(be < en){
			int mid = (be + en) / 2;
			if(jud(*(a + mid), val) != -1) en = mid;
			else be = mid + 1;
		}
		if(f_small && jud(*(a + be), val) == 1) be--;
		if(!f_small && jud(*(a + be), val) == -1) be++;
	} else {
		if(f_lb) while(be < en){
			int mid = (be + en + 1) / 2;
			if(jud(*(a + mid), val) != -1) be = mid;
			else en = mid - 1;
		}else while(be < en){
			int mid = (be + en) / 2;
			if(jud(*(a + mid), val) != 1) en = mid;
			else be = mid + 1;
		}
		if(!f_small && jud(*(a + be), val) == -1) be--;
		if(f_small && jud(*(a + be), val) == 1) be++;
	}
	return be;
}

template <class T> inline T lowb(T num) {return num & (-num); }
inline int bitnum(ui nValue) { return __builtin_popcount(nValue); }
inline int bitnum(int nValue) { return __builtin_popcount(nValue); }
inline int bitnum(ull nValue) { return __builtin_popcount(nValue) + __builtin_popcount(nValue >> 32); }
inline int bitnum(ll nValue) { return __builtin_popcount(nValue) + __builtin_popcount(nValue >> 32); }
inline int bitmaxl(ui a) { if(a == 0) return 0; return 32 - __builtin_clz(a); }
inline int bitmaxl(int a) { if(a == 0) return 0; return 32 - __builtin_clz(a); }
inline int bitmaxl(ull a) { int temp = a >> 32; if(temp) return 32 - __builtin_clz(temp) + 32; return bitmaxl(int(a)); }
inline int bitmaxl(ll a) { int temp = a >> 32; if(temp) return 32 - __builtin_clz(temp) + 32; return bitmaxl(int(a)); }

long long pow(long long n, long long m, long long mod = 0){
	if(m < 0) return 0;
	long long ans = 1;
	long long k = n;
	while(m){
		if(m & 1) {
			ans *= k;
			if(mod) ans %= mod;
		}
		k *= k;
		if(mod) k %= mod;
		m >>= 1;
	}
	return ans;
}

#define debug
//.........................mi.......feng......xian.......xia.......jin.......zhi.......hack...............................................

/*
 *  call ::
 *  pre(n, source, terminal);
 *  for(int i = 0; i < m; i++) {
 *  	addedge(from, to, capcity);
 *  }
 *  SAP();
 *
 *  返回maxflow;
 */
#define MAXM 10000
#define MAXN 300
#define Clr(x) memset(x,0,sizeof(x))
#define INF 0x5fffffff

struct sap {
	struct edge {
		int to, cap, next;
	} e[MAXM * 2];

	int p, head[MAXN], h[MAXN], vh[MAXN];
	int n, m, s, t, maxFlow;

	inline int min(int a, int b) {
		return a < b ? a : b;
	}
	inline void addedge(int a, int b, int c) {
		e[p].to = b, e[p].cap = c, e[p].next = head[a], head[a] = p++;
		e[p].to = a, e[p].cap = 0, e[p].next = head[b], head[b] = p++;
	}
	int dfs(int u, int pre) {
		if (u == t)
			return pre;
		int now, aug, mh = n + 10, to, tmp = pre;
		for (now = head[u]; now; now = e[now].next) {
			to = e[now].to;
			if (e[now].cap) {
				if (pre && h[u] == h[to] + 1) {
					aug = dfs(to, min(pre, e[now].cap));
					pre -= aug;
					e[now].cap -= aug;
					e[now ^ 1].cap += aug;
					if (h[s] >= n)
						return tmp - pre;
				}
				mh = min(mh, h[to]);
			}
		}
		if (tmp - pre > 0)
			return tmp - pre;
		--vh[h[u]];
		if (!vh[h[u]]) {
			h[s] = n;
			return 0;
		}
		++vh[h[u] = mh + 1];
		return 0;
	}

	void init() {
		maxFlow = 0;
		Clr(h);
		Clr(vh);
		vh[0] = n;
	}
	void SAP() {
		init();
		while (h[s] < n)
			maxFlow += dfs(s, INF);
	}
	void pre(int nn, int ss = -1, int tt = -1) {
		p = 2;
		Clr(head);
		n = nn;
		if(ss == -1) s = 0;
		else s = ss;
		if (tt == -1) t = n - 1;
		else t = tt;
	}
} g;

const int maxn = 200;
int ncase;
int n, l;
char str1[maxn][maxn], str2[maxn][maxn];

ll getnum(char *a, char *b) {
	ll ans = 0;
	for(int i = 0; i < l; i++) {
		ans *= 2;
		ans += (a[i] != b[i]);
	}
	return ans;
}
int main(){
    ios_base::sync_with_stdio(0);
	#ifdef debug //......................................................................................................
	freopen("input.txt", "r", stdin);
	#endif //...........................................................................................................
	scanf("%d", &ncase);
	for(int i1 = 0; i1 < ncase; i1++) {
		scanf("%d%d", &n, &l);
		for(int i = 0; i < n; i++)
			scanf("%s", str1[i]);
		for(int j = 0; j < n; j++)
			scanf("%s", str2[j]);
		int ans = 1000000000;
		for(int i = 0; i < n; i++) {
			g.pre(n * 2 + 2, n * 2, n * 2 + 1);
			ll num = getnum(str1[0], str2[i]);
			for(int j = 0; j < n; j++) for(int k 	= 0; k < n; k++)
				if(getnum(str1[j], str2[k]) == num)
					g.addedge(j, k + n, 1);
			for(int j = 0; j < n; j++) {
				g.addedge(n * 2, j, 1);
				g.addedge(j + n, n * 2 + 1, 1);
			}
			g.SAP();
			if(g.maxFlow == n)
				ans = min(ans, bitnum(num));
		}
		printf("Case #%d: ", i1 + 1);
		if(ans > l) puts("NOT POSSIBLE");
		else printf("%d\n", ans);
	}

    return 0;
}



