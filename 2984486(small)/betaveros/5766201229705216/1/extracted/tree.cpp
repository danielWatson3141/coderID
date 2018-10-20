// @betaveros :: vim:set fdm=marker:
// #define NDEBUG
// #includes, using namespace std {{{
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cmath>
// #include <cinttypes> // C++11?
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <functional>
#include <new>
#include <algorithm>
#include <iostream>
using namespace std;
// }}}
// #defines, typedefs, constants {{{
#define fori(i,s,e) for(int i = s; i < ((int)e); i++)
#define forui(i,s,e) for(unsigned int i = s; i < ((unsigned int)e); i++)
#define foruin(i,c) for(unsigned int i = 0; i < ((unsigned int)(c).size()); i++)
#define _conc(x,y) x ## y
#define _conc2(x,y) _conc(x,y)
#define repeat(n) fori(_conc2(_,__LINE__),0,n)
#define allof(s) (s).begin(), (s).end()
#define scan_d(x) scanf("%d",&(x))
#define scan_dd(x,y) scanf("%d%d",&(x),&(y))
#define scan_ddd(x,y,z) scanf("%d%d%d",&(x),&(y),&(z))
#define scan_dddd(x,y,z,w) scanf("%d%d%d%d",&(x),&(y),&(z),&(w))
#define pushb push_back
#define popb push_back

#ifdef NDEBUG
#define debug(code)
#define debugf(...) ((void)0)
#else
#define debug(code) code
#define debugf(...) fprintf(stderr, __VA_ARGS__)
#endif
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef vector<int> Vint;
typedef vector<int>::iterator Vit;

// const int OO  = 1000 << 10;
// const int OO2 = 2000 << 10;
// const int       M7  = 1000000007;
// const int       M9  = 1000000009;
// const long long M7L = 1000000007L;
// }}}
// dump, min/maxify {{{
template <class T> void dumpBetween(const T & a, const T & b) {
	for (T it = a; it != b; it++) cout << *it << " ";
	cout << endl;
}
template <class T> void dumpAll(const T & a) { dumpBetween(allof(a)); }
template <class T> void minify(T & a, const T & b) { if (a > b) a = b; }
template <class T> void maxify(T & a, const T & b) { if (a < b) a = b; }
// }}}

int n;
vector<int> graph[1008];

void readInput() {
	fori (i, 0, 1008) graph[i].clear();
	scan_d(n);
	repeat(n-1) {
		int a, b;
		scan_dd(a, b);
		graph[a].pushb(b);
		graph[b].pushb(a);
	}
}
int best;
void checkNode(int v, int p, int & size, int & save) {
	size = 1;
	int sv1 = 0, sv2 = 0;
	int nChildren = 0;
	foruin (i, graph[v]) {
		int w = graph[v][i];
		if (w == p) continue;
		nChildren++;
		int csize, csave;
		checkNode(w, v, csize, csave);
		size += csize;

		if (csave >= sv1) { sv2 = sv1; sv1 = csave; }
		else if (csave >= sv2) { sv2 = csave; }
	}
	if (nChildren < 2) {
		save = 1;
	} else {
		save = 1 + sv1 + sv2;
	}
}
void checkRoot(int r) {
	int sz, sv;
	checkNode(r, -1, sz, sv);
	assert(sz == n);
	maxify(best, sv);
}

void tc(int tci) {
	readInput();
	best = 0;
	fori (i, 1, n+1) checkRoot(i);

	printf("Case #%d: %d\n", tci, n - best);
}

int main() {
	int tcn;
	scanf("%d", &tcn);
	fori (i, 0, tcn) tc(i+1);
}
