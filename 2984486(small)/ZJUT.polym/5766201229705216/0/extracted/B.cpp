/*************************************************************************
Author: zjut_polym
Created Time:   2014/4/12 21:35:53
File Name: B.cpp
************************************************************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <climits>
#include <queue>
using namespace std;


//----------------------[ZJUT-polym for div2]-------------------------------------
#define ll long long
#define MOD 1000000007
#define PII pair<int, int>
#define ff first
#define ss second
#define sz(v) (int)v.size()
#define _mst(buf, val) memset(buf, val, sizeof(buf))
#define rep(i, l, r) for(i = (l); i <= (r); i++)
#define srep(i, l, r) for(i = (l); i >= (r); i--)
#define repi(it, c) for(typeof(c.begin())it = c.begin(); it != c.end(); it++)
#define inf 0x3f3f3f3f
#define N 10005
#define eps 1e-8
#define pi (2.0 * acos(0.0))
//--------------------------------------------------------------------------------

struct edge{
	int v, nxt;
}E[N];
int head[N], e;
void addedge(int u, int v){
	E[e].v = v; E[e].nxt = head[u]; head[u] = e++;
}
int dfs(int u, int pre){
	int sum[2];
	sum[0] = sum[1] = 0;
	for(int i = head[u]; i != -1; i = E[i].nxt){
		int v = E[i].v;
		if(pre == v) continue;
		int tmp = dfs(v, u);
		if(tmp > sum[1]) swap(sum[1], tmp);
		if(sum[1] > sum[0]) swap(sum[0], sum[1]);
	}
	if(sum[0] == 0 || sum[1] == 0) return 1;
	return sum[1] + sum[0] + 1;
}
int main() {
	int T, cas = 1, u, v;
	cin >> T;
	while(T--){
		printf("Case #%d: ", cas++);
		memset(head, -1, sizeof(head));
		e=0;
		int n;
		cin >> n;
		for(int i = 1; i < n; i++){
			cin >> u >> v;
			addedge(u, v); addedge(v, u);
		}
		int ans = 0;
		for(int i = 1; i <= n; i++){
			ans = max(ans, dfs(i, -1));
		}
		cout << n-ans << endl;
	}
    return 0;
}

