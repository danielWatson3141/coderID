#include <cstdio>
#include <cmath>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <iterator>

#define MOD 1000000007
#define INF 1000000000000000000
#define PI acos(-1)

using namespace std;

int deg[20],deleted[20],u[20],v[20];

int find (int n) {
	int c;
	c = 0;
	while (n % 2 == 0) {
		c++;
		n = n / 2;
	}
	if (n == 1) {
		return c;
	} else {
		return -1;
	}
}

int solve (int idx,int n) {
	int one,two,three;
	int i,x,val,prev;
	if (idx == n + 1) {
		two = 0;
		one = 0;
		three = 0;
		for (i = 1; i <= n; i++) {
			if (deleted[i] == 1) {
				continue;
			}
			if (deg[i] == 1) {
				one++;
			} else if (deg[i] == 2) {
				two++;
			} else if (deg[i] == 3) {
				three++;
			}
		}
		if (two != 1) {
			return -1;
		}
		x = find(one);
		if (x == -1) {
			return -1;
		}
		if (three != pow(2,x) - 2) {
			return -1;
		}
		return 0;
	}
	val = solve(idx + 1,n);
	if (val >= 0) {
		return val;
	}
	for (i = 0; i < n - 1; i++) {
		if (u[i] == idx) {
			if (deleted[v[i]] == 0) {
				deg[v[i]]--;
			}
		} else if (v[i] == idx) {
			if (deleted[u[i]] == 0) {
				deg[u[i]]--;
			}
		}
	}
	prev = deg[idx];
	deg[idx] = 0;
	deleted[idx] = 1;
	val = solve(idx + 1,n);
	if (val >= 0) {
		return (val + 1);
	}
	for (i = 0; i < n - 1; i++) {
		if (u[i] == idx) {
			if (deleted[v[i]] == 0) {
				deg[v[i]]++;
			}
		} else if (v[i] == idx) {
			if (deleted[u[i]] == 0) {
				deg[u[i]]++;
			}
		}
	}
	deg[idx] = prev;
	deleted[idx] = 0;
	return -1;
}

int main()
{
//	freopen("input.in","r",stdin);
//	freopen("output.in","w",stdout);
	int t,y;
	scanf("%d",&t);
	y = 1;
	while (t --) {
		int n,i,ans;
		scanf("%d",&n);
		memset(deg,0,sizeof(deg));
		memset(deleted,0,sizeof(deleted));
		for (i = 0; i < n - 1; i++) {
			scanf("%d%d",&u[i],&v[i]);
			deg[u[i]]++;
			deg[v[i]]++;
		}
		ans = solve(1,n);
		if (ans == -1) {
			ans = n - 1;
		}
		printf("Case #%d: %d\n",y,ans);
		y++;
	}
	return 0;
}
