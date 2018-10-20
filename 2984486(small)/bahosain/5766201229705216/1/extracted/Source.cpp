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
int t, n, x, y;
vector<int>v[1001];
vector<int>cand;
bool vis[1001];
int big;
int can(int src,int par){
	if (v[src].size() == 1)
		return 1;
	vector<int>s;
	for (int i = 0; i < v[src].size();++i)
	if (v[src][i] != par){
		s.push_back(can(v[src][i],src));
	}
	sort(s.begin(), s.end());
	if (s.size() == 1)
		return 1;
	return s[s.size() - 1] + s[s.size() - 2] + 1;
}
int main(){
	freopen("B-large.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	scanf("%d", &t);
	for (int c = 1; c <= t; ++c){
		scanf("%d", &n);
		cand.clear();
		for (int i = 1; i <= n; ++i)
			v[i].clear();
		for (int i = 0; i < n - 1; ++i){
			scanf("%d%d", &x, &y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		int res = 0;
		for (int i = 1; i <= n; ++i){
			int get = can(i,i);
			res = max(res, get);
		}
		printf("Case #%d: %d\n", c, n-res);
	}
}