//By Lin
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<map>
#include<queue>
#include<cctype>
#include<cmath>

#define eps 1e-9
#define sqr(x) ((x)*(x))
#define Rep(i,n) for(int i = 0; i<n; i++)
#define foreach(i,n) for( __typeof(n.begin()) i = n.begin(); i!=n.end(); i++)
#define X first
#define Y second
#define mp(x,y) make_pair(x,y)

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

#define N 100010

int ecnt;
struct Edge {
	int to;
	Edge *next;
}*mat[N], edges[N*2];
void link(int x, int to) {
	edges[ecnt] = (Edge){to, mat[x]};
	mat[x] = &edges[ecnt++];
}
int n;
int ma[N];

int solve(int i, int father) {
	vector<int> tmp;
	for (Edge *p = mat[i]; p; p=p->next) {
		int to = p->to;
		if (to == father) continue;
		tmp.push_back(solve(to, i));
	}
	if (tmp.size() >= 2) {
		sort(tmp.begin(), tmp.end());
		reverse(tmp.begin(), tmp.end());
		return 1 + tmp[0] + tmp[1];
	}
	return 1;
}

int		main(){
	int cas, tt = 0;
	scanf("%d", &cas);
	while (cas --) {
		ecnt = 0;
		memset(mat, 0, sizeof(mat));
		scanf("%d", &n);
		Rep(i, n - 1) {
			int x, y;
			scanf("%d%d", &x, &y);
			x--, y--;
			link(x, y);
			link(y, x);
		}
		int ans = 1;
		Rep(i, n) ans = max(ans, solve(i, -1));
		printf("Case #%d: %d\n", ++tt, n - ans);
	}
	return 0;
}
