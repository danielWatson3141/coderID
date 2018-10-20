#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <cassert>
#include <complex>
#include <unordered_map>
#include <unordered_set>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii;
typedef long long ll; typedef vector<long long> vl; typedef pair<long long,long long> pll; typedef vector<pair<long long,long long> > vpll;
typedef vector<string> vs; typedef long double ld;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

vector<vi> g;
vector<int> parent;
vector<vi> stateidx;
vi t_ord;
int nstates = 0;

void tree_getstateindices(int root) {
	int n = g.size();
	parent.assign(n, -1);
	stateidx.assign(n, vi());
	t_ord.clear();
	nstates = 0;

	vector<int> stk; stk.push_back(root);
	while(!stk.empty()) {
		int i = stk.back(); stk.pop_back();
		t_ord.push_back(i);
		stateidx[i].assign(g[i].size() + 1, -1);
		rep(j, g[i].size()) {
			int c = g[i][j];
			if(parent[c] == -1 && c != root) {
				stk.push_back(c);
				stateidx[i][j] = nstates ++;
			}else {
				stateidx[i][j] = -1;
				parent[i] = c;
			}
		}
		stateidx[i][g[i].size()] = nstates ++;
	}
}

vector<int> subtreesize;
int memo[1000*2][3];

int rec(int i, int j, int n) {
	int s = stateidx[i][j];
	if(s == -1) return rec(i, j+1, n);
	int &r = memo[s][n];
	if(j == g[i].size())
		return r = n == 0 ? 0 : INF;
	r = INF;
	//この子を使う
	if(n > 0) {
		amin(r, rec(g[i][j], 0, 2) + rec(i, j+1, n-1));
		amin(r, rec(g[i][j], 0, 0) + rec(i, j+1, n-1));
	}
	//この子を使わない
	amin(r, subtreesize[g[i][j]] + rec(i, j+1, n));
	return r;
}

int main() {
	int T;
	scanf("%d", &T);
	rep(ii, T) {
		int N;
		scanf("%d", &N);
		g.assign(N, vi());
		rep(i, N-1) {
			int x, y;
			scanf("%d%d", &x, &y), x --, y --;
			g[x].pb(y); g[y].pb(x);
		}
		int ans = INF;
		rep(root, N) {
			tree_getstateindices(root);
			subtreesize.assign(N, 1);
			for(int ix = N-1; ix >= 0; ix --) {
				int i = t_ord[ix];
				if(parent[i] != -1)
					subtreesize[parent[i]] += subtreesize[i];
			}
			mset(memo, -1);
			int x = INF;
			amin(x, rec(root, 0, 2));
			amin(x, rec(root, 0, 0));
//			cerr << root << ": " << x << endl;
			amin(ans, x);
		}
		printf("Case #%d: %d\n", ii+1, ans);
	}
	return 0;
}
