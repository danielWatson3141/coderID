/*
 * 1.cpp
 *
 *  Created on: 
 *      Author: 
 */

#include <ctime>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <climits>
#include <cassert>

#include <iostream>
#include <sstream>

#include <string>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <bitset>

#include <utility>
#include <numeric>
#include <functional>
#include <algorithm>

using namespace std;

#define INF 1000000000
#define LL_INF 4000000000000000000ll
#define EPS (1e-9)

#define Lc(x) ((x) << 1)
#define Rc(x) (Lc(x) + 1)
#define Pow2(x) (1 << (x))
#define Contain(a, x) (((a) >> (x)) & 1)

#define Rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define Til(i, a, b) for(int i = (a); i >= (b); --i)
#define Foru(i, a, b) for(int i = (a); i < (b); ++i)
#define Ford(i, a, b) for(int i = (a); i > (b); --i)

#define It iterator
#define For(i, x) for(__typeof(x.begin()) i = x.begin(); i != x.end(); ++i)

#define Debug(x) (cerr << #x << " = " << (x) << endl)
#define Debug2(x, y) (cerr << #x << " = " << (x) << ", " << #y << " = " << (y) << endl)

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int, int> pii;
typedef vector<int> VI;
typedef vector<string> VS;

//inline int rand(int a, int b) { return rand() % (b - a + 1) + a; }

template <class T> inline bool Up(T &a, const T &b) { if(a < b) {a = b; return true;} return false; }
template <class T> inline bool Down(T &a, const T &b) { if(a > b) {a = b; return true;} return false; }

inline int getus() { int tmp, c; while(tmp = fgetc(stdin), tmp < '0' || tmp > '9'); tmp -= '0'; while(c = fgetc(stdin), '0' <= c && c <= '9') tmp = tmp * 10 + c - '0'; return tmp; }
inline int getint() { int tmp, c, flag; while(flag = fgetc(stdin), flag != '-' && (flag < '0' || flag > '9')); if(flag == '-') tmp = 0; else tmp = flag - '0'; while(c = fgetc(stdin), '0' <= c && c <= '9') tmp = tmp * 10 + c - '0'; return flag == '-' ? -tmp : tmp; }

const int MAXN = 1033;

struct enode {
	int to;
	enode *next;
} ebase[MAXN * 2 + 1], *etop = ebase, *fir[MAXN];
typedef enode *edge;

inline void addEdge(int a, int b) {
	etop->to = b;
	etop->next = fir[a];
	fir[a] = etop++;
}

int N, root, size[MAXN], maxSize[MAXN];

void DFS(int x, int fa) {
	int &s = size[x] = 1, y;
	for (edge e(fir[x]); e; e = e->next)
		if ((y = e->to) != fa) {
			DFS(y, x);
			s += size[y];
		}
	int &res = maxSize[x] = 1;
	int max1 = -INF, max2 = -INF;
	for (edge e(fir[x]); e; e = e->next)
		if ((y = e->to) != fa) {
			if (maxSize[y] > max1) {
				max2 = max1;
				max1 = maxSize[y];
			}
			else if (maxSize[y] > max2) {
				max2 = maxSize[y];
			}
		}
	Up(res, 1 + max1 + max2);
}

void solve(int Case) {
	memset(fir, 0, sizeof(fir));
	etop = ebase;
	
	scanf("%d", &N);
	Rep(i, 2, N) {
		int a, b;
		scanf("%d %d", &a, &b);
		addEdge(a, b);
		addEdge(b, a);
	}
	
	int ans = 1;
	for (root = 1; root <= N; ++root) {
		DFS(root, -1);
		Up(ans, maxSize[root]);
	}
	printf("Case #%d: %d\n", Case, N - ans);
	
}

int main() {
	int T;
	scanf("%d", &T);
	Rep(Case, 1, T) solve(Case);
	return 0;
}
