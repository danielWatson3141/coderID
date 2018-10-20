#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <bitset>
#include <string>
#include <numeric>
#include <functional>
#include <iterator>
#include <typeinfo>
#include <utility>
#include <memory>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstddef>
#include <complex>
#include <ctime>
#include <cassert>
using namespace std;

typedef long long int64;
const int inf = 2000000000;
static inline int Rint()
{
	struct X{ int dig[256]; X(){
	for(int i = '0'; i <= '9'; ++i) dig[i] = 1; dig['-'] = 1;
	}};
	static 	X fuck;int s = 1, v = 0, c;
	for (;!fuck.dig[c = getchar()];);
	if (c == '-') s = 0; else if (fuck.dig[c]) v = c ^ 48;
	for (;fuck.dig[c = getchar()]; v = v * 10 + (c ^ 48));
	return s ? v : -v;
}
typedef vector<int> vi;
typedef vi::iterator ivi;
typedef map<int, int> mii;
typedef mii::iterator imii;
typedef set<int> si;
typedef si::iterator isi;

#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define rep(i, s, e) for (int i = (s); i < (e); ++i)
#define foreach(itr, c) for(__typeof((c).begin()) itr = (c).begin(); itr != (c).end(); ++itr)
template<typename T> static inline void cmax(T& a, const T& b){if(b>a)a=b;}
template<typename T> static inline void cmin(T& a, const T& b){if(b<a)a=b;}

vi adj[1024];
int dp[1024];
int cut[1024];
int total[1024];

static inline int bt_nodes(int height)
{
	return (1 << (height+1)) - 1;
}

static inline int selected_cost(int height, int costed, int dest)
{
	if (height == dest) return costed;
	return costed + bt_nodes(height)- bt_nodes(dest);
}
// 结点now，构成的最高的二叉树的高度，以及对应的删除的结点数。
void dfs(int now, int prev)
{
	vi& cld = adj[now];
	const int cnt = sz(cld);
	int removed = 0;
	total[now] = 1;
	vi info;
	rep(i, 0, cnt)
	{
		int to = cld[i];
		if (to == prev) continue;
		dfs(to, now);
		info.pb(to);
		total[now] += total[to];
	}
	if (sz(info) <= 1)
	{
		const int n = sz(info);
		for (int i = 0; i < n; ++i)
		{
			removed += total[info[i]];
		}
		cut[now] = removed;
		return;
	}
	const int n = sz(info);
	int ldp[2][3];
	int* from = ldp[0];
	int* to = ldp[1];
	{
		from[0] = 0;
		from[1] = 100000000;
		from[2] = 100000000;
		for (int i = 0; i < n; ++i)
		{
			to[0]=to[1]=to[2]=100000000;
			int c_add = cut[info[i]];
			cmin(to[1], from[0]+c_add);
			cmin(to[2], from[1]+c_add);
			int c_no_add = total[info[i]];
			cmin(to[0], from[0] + c_no_add);
			cmin(to[1], from[1] + c_no_add);
			cmin(to[2], from[2] + c_no_add);
			swap(from, to);
		}
	}
	cut[now] = from[2];
}

int main()
{
	int T = Rint();
	for (int id = 1; id <= T; ++id)
	{
		int n = Rint();
		for (int i = 1; i <= n; ++i)
		adj[i].clear();
		for (int i = 1; i < n; ++i)
		{
			int s = Rint(), t = Rint();
			adj[s].pb(t), adj[t].pb(s);
		}
		int ans = 1000000000;
		for (int root = 1; root <= n; ++root)
		{
			dfs(root, -1);
			cmin(ans, cut[root]);
		}
		printf("Case #%d: %d\n", id, ans);
	}
	return 0;
}
