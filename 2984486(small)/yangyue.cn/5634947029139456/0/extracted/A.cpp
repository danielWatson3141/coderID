// File Name: A.cpp
// Author: YangYue
// Created Time: Sat Apr 26 10:47:50 2014
//headers 
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <ctime>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
typedef pair<LL, LL>PLL;
typedef pair<LL,int>PLI;

#define lch(n) ((n<<1))
#define rch(n) ((n<<1)+1)
#define lowbit(i) (i&-i)
#define sqr(x) ((x)*(x))
#define fi first
#define se second
#define MP make_pair
#define PB push_back

const int MaxN = 1000005;
const double eps = 1e-8;
const double DINF = 1e100;
const int INF = 1000000006;
const LL LINF = 1000000000000000005ll;

LL a[155], b[155];
char s[44];

int main()
{
	freopen("in","r",stdin);

	int n, L;
	int cases; scanf("%d", &cases);
	for (int cas = 1; cas <= cases; ++cas) {
		scanf("%d %d", &n, &L);
		int ans = -1;
		for (int i = 0; i < n; ++i) {
			LL x = 0;
			scanf("%s", s);
			for (int j = 0; j < L; ++j) x = x * 2 + s[j] - '0';
			a[i] = x;
		}
		set<LL> SET;
		for (int i = 0; i < n; ++i) {
			LL x = 0;
			scanf("%s", s);
			for (int j = 0; j < L; ++j) x = x * 2 + s[j] - '0';
			b[i] = x;
			SET.insert(x);
		}
		for (int target = 0; target < n; ++target) {
			LL oper = b[target] ^ a[0];
			bool can = 1;
			for (int i = 0; i < n; ++i) {
				LL tmp = a[i] ^ oper;
				if (!SET.count(tmp)) {
					can = 0;
					break;
				}
			}
			if (!can) continue;
			int tmp = __builtin_popcountll(oper);
			if (ans == -1) ans = tmp;
			else ans = min(ans, tmp);
		}
		printf("Case #%d: ", cas);
		if (ans == -1) puts("NOT POSSIBLE");
		else printf("%d\n", ans);
	}
	
	return 0;
}

// hehe ~


