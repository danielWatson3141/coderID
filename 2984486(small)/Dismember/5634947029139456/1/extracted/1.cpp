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

const int MAXN = 333;

int N, L;
LL A[MAXN], B[MAXN];
int G[MAXN][MAXN];
int linkY[MAXN];

int countBit(LL x) {
	if (x == 0) return 0;
	if (x & 1) return countBit(x >> 1) + 1;
	return countBit(x >> 1);
}

bool vis[MAXN];

bool Find(int x) {
	if (vis[x]) return false;
	vis[x] = true;
	Rep(y, 1, N) if (G[x][y])
		if (linkY[y] == -1 || Find(linkY[y])) {
			linkY[y] = x;
			return true;
	}
	return false;
}

bool check(LL Xor) {
	Rep(i, 1, N) {
		LL v = A[i] ^ Xor;
		Rep(j, 1, N)
			if (B[j] == v)
				G[i][j] = 1;
	}
	
	int ans = 0;
	memset(linkY, -1, sizeof(linkY));
	Rep(x, 1, N) {
		memset(vis, 0, sizeof(vis));
		if (Find(x)) ++ans;
	}
	return ans == N;
}

void solve(int Case) {
	static char buf[10033];
	scanf("%d %d", &N, &L);
	Rep(i, 1, N) {
		scanf("%s", buf);
		LL &res = A[i] = 0;
		Foru(bit, 0, L)
			if (buf[bit] == '1')
				res += 1LL << bit;
	}
	Rep(i, 1, N) {
		scanf("%s", buf);
		LL &res = B[i] = 0;
		Foru(bit, 0, L)
			if (buf[bit] == '1')
				res += 1LL << bit;
	}
//	Rep(i, 1, N) cout << A[i] << ' '; cout << endl;
//	Rep(i, 1, N) cout << B[i] << ' '; cout << endl;
	
	map<LL, int> cnt;
	Rep(i, 1, N) Rep(j, 1, N)
		++cnt[A[i] ^ B[j]];
	int ans = INF;
	for (map<LL, int>::iterator itr(cnt.begin()); itr != cnt.end(); ++itr) {
//		cout << "cnt: " << itr->first << ' ' << itr->second << endl;
		if (itr->second >= N)
			if (check(itr->first)) {
				Down(ans, countBit(itr->first));
				
			}
	}
	if (ans >= INF)
		printf("Case #%d: NOT POSSIBLE\n", Case);
	else
		printf("Case #%d: %d\n", Case, ans);
}

int main() {
	int T;
	scanf("%d", &T);
	Rep(Case, 1, T) solve(Case);
	return 0;
}
