#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>

using namespace std;
//-----------------------------------------------------------
#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) int(a.size() - 1)
#define all(a) a.begin(), a.end()
#define seta(a,x) memset (a, x, sizeof (a))
#define I (int)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const ull inf64 = ((ull) 1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;

#define bit(i) ((ull)1 << i)
//-----------------------------------------------------------
//#define DBG
#define MAXN 1010

int N;
int ans;

struct NODE{
	int n;
	vector<int> v;
};

NODE v[MAXN];

void readfile(){
	int a, b;
	scanf("%d", &N);
	forn(i, N - 1){
		scanf("%d%d", &a, &b);
		v[a].v.pb(b);
		v[b].v.pb(a);
		v[a].n++;
		v[b].n++;
	}
}

int treeSize(int idx, int parent){
	int ret = 0;
	//printf("=> idx = %d, size = %d, parent = %d\n", idx, v[idx].v.size(), parent);
	forn(i, v[idx].v.size()) {
		if(v[idx].v[i] == parent) continue;
		ret += treeSize(v[idx].v[i], idx);
	}
	//printf("size idx = %d, ans = %d\n", idx, ret + 1);
	return ret + 1;
}

// min req for being binary tree
int trace(int idx, int parent, bool isroot) {
	int ret;

	if ((isroot && v[idx].v.size() == 0) ||
		(!isroot && v[idx].v.size() == 1))
	{
#ifdef DBG
		printf("1 Id = %d, ans = %d\n", idx, 0);
#endif
		return 0;
	}
	if ((isroot && v[idx].v.size() == 1) ||
		(!isroot && v[idx].v.size() == 2))
	{
		forn(i, v[idx].v.size()) {
			if(v[idx].v[i] == parent) continue;
			// must be deleted

			ret = treeSize(v[idx].v[i], idx);
#ifdef DBG
			printf("2 idx = %d, ans = %d\n", idx, ret);
#endif
			if(ret >= ans) return MAXN;
			return ret;
		}
	}

	int d[MAXN];
	int b[MAXN];
	int ch, ch1, ch2, chtmp, sol = INT_MAX, tmpsol;
	int btot = 0;
	memset(d, 0, sizeof(d));
	memset(b, 0, sizeof(b));

	forn(i, v[idx].v.size()) {
		ch = v[idx].v[i];
		if (ch == parent) continue;
		b[ch] = trace(ch, idx, false);
		btot += b[ch];
		if(b[ch] >= ans) return MAXN;
		//printf("child %d idx = %d, ans = %d\n", v[idx].v[i], idx, tmp);
	}
	if(btot >= ans) return MAXN;

	forn(i, v[idx].v.size()) {
		ch = v[idx].v[i];
		if (ch == parent) continue;
		d[ch] = treeSize(ch, idx);

		//printf("child %d idx = %d, ans = %d\n", v[idx].v[i], idx, tmp);
	}

	// select the smallest solution
	forn(i, v[idx].v.size()){
		ch1 = v[idx].v[i];
		if (ch1 == parent) continue;
		forn(j, v[idx].v.size()){
			ch2 = v[idx].v[j];
			if (ch2 == parent) continue;

			// select ch1 and ch2 to be the child
			tmpsol = 0;
			forn(k, v[idx].v.size()) {
				chtmp = v[idx].v[k];
				if (chtmp == parent) continue;
				if (chtmp == ch1) {
					tmpsol += b[ch1];
				}
				else if (chtmp == ch2) {
					tmpsol += b[ch2];
				}
				else {
					tmpsol += d[chtmp];
				}
			}
			sol = min(sol, tmpsol);
		}
	}
#ifdef DBG
	printf("3 idx = %d, ans = %d\n", idx, sol);
#endif
	return sol;
}

void solve() {
	int r = 0, tmp;
	// which node is being root
	forn(i, N)
	{
#ifdef DBG
		//printf("root = %d\n", i + 1);
#endif
		tmp = trace(i + 1, -1, true);
		if(ans > tmp) {
			ans = tmp;
			//r = i + 1;
		}
	}
#ifdef DBG
	printf("root = %d\n", r);
#endif
}

int main() {
	int cases;
	int casenum = 1;
	freopen("input", "r", stdin);
	//freopen("output", "w", stdout);

	scanf("%d", &cases);
	while (cases--) {
		ans = INT_MAX;
		memset(v, 0, sizeof(v));

		readfile();

		solve();

		printf("Case #%d: %d\n", casenum++, ans);
		fflush(stdout);


	}
	return 0;
}
