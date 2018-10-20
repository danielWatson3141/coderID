
//by allenlyh
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <list>
#include <complex>

using namespace std;

typedef long long LL;

#define X first
#define Y second
#define MP make_pair
#define PB push_back
#define sqr(x) (x)*(x)
#define sign(x) (((x)<-eps)?-1:(x)>eps)
#define foreach(ite,s) for (__typeof(s.begin()) ite=s.begin();ite!=s.end();ite++)
#define lowbit(x) ((x) & (-(x)))
const double eps=1e-9;
const int INF=0x3f3f3f3f;

const int maxn=1000+10;
int n;
vector<int> edge[maxn];

int dfs(int r, int fa) {
	if (edge[r].size() > 2 || fa == -1) {
		int t1 = -1, t2 = -1;
		for (int i=0;i<edge[r].size();i++) {
			if (edge[r][i] == fa) continue;
			int tmp = dfs(edge[r][i], r);
			if (tmp > t1) {
				t2 = t1;
				t1 = tmp;
			} else if (tmp > t2) {
				t2 = tmp;
			}
		}
		return t1+t2+1;
	} else return 1;
}

void work() {
	scanf("%d", &n);
	for (int i=0;i<n;i++) edge[i].clear();
	for (int i=0;i<n-1;i++) {
		int x,y;
		scanf("%d%d", &x, &y);
		x--;y--;
		edge[x].PB(y);
		edge[y].PB(x);
	}
	int ans = INF;
	for (int i=0;i<n;i++) {
		ans = min(n - dfs(i, -1), ans);
	}
	printf("%d\n", ans);
}

int main() {
	int T;
	int cas=0;
	scanf("%d", &T);
	while (T--) {
		printf("Case #%d: ", ++cas);
		work();
	}
	return 0;
}
