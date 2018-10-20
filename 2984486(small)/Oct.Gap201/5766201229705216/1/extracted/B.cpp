#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <bitset>

typedef long long LL;
#define pb push_back
#define MPII make_pair<int, int>
#define PII pair<int, int>
#define sz(x) (int)x.size()

using namespace std;

template<class T> T abs(T x){if (x < 0) return -x; else return x;}

const int maxn = 10000;

struct Edge{
	int x, next;
}gragh[maxn];

int f[maxn], s[maxn], q[maxn], head[maxn], d[maxn], fa[maxn];
bool visit[maxn];
int n, ans, num;

void Add_edge(int x, int y){
	gragh[++num].x = y;
	gragh[num].next = head[x];
	head[x] = num;
}

void dfs(int u){
	visit[u] = true;
	for (int i = head[u]; i; i = gragh[i].next)
		if (!visit[gragh[i].x]){
			fa[gragh[i].x] = u;
			++d[u];
			dfs(gragh[i].x);
		}
}

void dp(int u){
	memset(f, 0, sizeof(f));
	memset(s, 0, sizeof(s));
	int l = 1, r = 0;
	for (int i = 1; i <= n; ++i)
		f[i] = n - 1;
	for (int i = 1; i <= n; ++i)
		if (d[i] == 0){
			q[++r] = i;
		}

	while (l <= r){
		int now = q[l], tot = 0;
		s[now] = 1;
		for (int i = head[now]; i; i = gragh[i].next){
			if (gragh[i].x == fa[now]) continue;
			++tot;
			s[now] += s[gragh[i].x];
		}

		if (tot == 0) f[now] = 0; else 
			if (tot == 1){
				f[now] = s[now] - 1;
			} else {
				for (int i = head[now]; i; i = gragh[i].next)
					for (int j = gragh[i].next; j; j = gragh[j].next){
						if (gragh[i].x == fa[now] || gragh[j].x == fa[now]) continue;
						f[now] = min(f[now], s[now] - s[gragh[i].x] - s[gragh[j].x] + f[gragh[i].x] + f[gragh[j].x] - 1);
					}
			}
		--d[fa[now]];
		if (!d[fa[now]]) q[++r] = fa[now];
		++l;
	}
}

int main(){
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
	int Cases;
	scanf("%d", &Cases);
	for (int C = 1; C <= Cases; ++C){
		printf("Case #%d: ", C);
		scanf("%d", &n);
		memset(head, 0, sizeof(head));
		num = 0;
		for (int i = 0; i < n - 1; ++i){
			int x, y;
			scanf("%d%d", &x, &y);
			Add_edge(x, y);
			Add_edge(y, x);
		}
		ans = n - 1;
		for (int i = 1; i <= n; ++i){
			memset(visit, false, sizeof(visit));
			memset(d, 0, sizeof(d));
			memset(fa, 0, sizeof(fa));
			dfs(i);
			dp(i);
			ans = min(ans, f[i]);
		}
		printf("%d\n", ans);
	}
	return 0;
}

