#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<math.h>
#include<queue>
#include<stack>
#include<stdio.h>
#include<map>
#include<set>
#include<memory.h>
#include<algorithm>
#include<vector>
#include<stdlib.h>
#include<sstream>
using namespace std;
typedef long long ll;
ll ABS(ll x){
	if (x<0)return -x;
	return x;
}
ll gcd(ll a, ll b){
	if (!b)
		return a;
	return gcd(b, a%b);
}
ll lcm(ll a, ll b){
	return b / gcd(a, b)*a;
}
#define FOR(I,N) for(int(i)=0;i<int(N);++i)
#define FORK(I,N,K) for(int(i)=0;i<int(N);i+=int(K))
int n, t, l, oo = (1 << 30);
char x[100][100], y[100][100];
bool vis[11];
bool match(int &a, int &b, int &c){
	for (int i = 0; i < l;++i)
	if ((((c >> i) & 1) && x[a][i] != y[b][i]) || (!((c >> i) & 1) && x[a][i] == y[b][i]))
		continue;
	else return 0;
	return 1;
}
int main(){
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	scanf("%d", &t);
	for (int c = 1; c <= t; ++c){
		scanf("%d%d", &n, &l);
		for (int i = 0; i < n; ++i)
			scanf("%s", x[i]);
		for (int i = 0; i < n; ++i)
			scanf("%s", y[i]);
		int res = oo;
		for (int i = 0; i < (1 << l); ++i){
			memset(vis, 0, sizeof(vis));
			int done = 0;
			for (int j = 0; j < n; ++j){
				bool F = 0;
				for (int k = 0; k < n; ++k){
					if (!vis[k] && match(j, k, i)){
						vis[k] = 1;
						F = 1;
						break;
					}
				}
				if (!F)
					break;
				else ++done;
			}
			if (done == n){
				int s = 0;
				for (int j = 0; j < 15;++j)
				if ((i >> j) & 1)
					++s;
				res = min(res, s);
			}
		}
		if (res == oo)
			printf("Case #%d: NOT POSSIBLE\n", c);
		else printf("Case #%d: %d\n", c, res);
	}
}