#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;


int T, n, m;
int size[1008];
vector<int> e[1008];
int f[1008];
int cnt[1008];
/*void DFS1(int x, int fa)
{
    size[x] = 1;
    int y;
    for (int i = 0; i < e[x].size(); i++) {
        y = e[x][i];
        if (y != fa) {
            DFS1(y, x);
            size[x] += size[y];
        }
    }
}*/


void DFS(int x, int fa)
{
	size[x] = 1;cnt[x] = 0;
	int y, t1 = 0, t2 = 0;
	for (int i = 0; i < e[x].size(); i++) {
		y = e[x][i];
		if (y != fa) {
			DFS(y, x);
			size[x] += size[y];
			cnt[x]++;
			int v = size[y] - f[y];
			if (v > t2) {
				t2 = t1;
				t1 = v;
			} else if (v > t2) {
				t2 = v;
			}
		}
	}
		f[x] = size[x] - 1;
	if (cnt[x] >= 2) f[x] -= t1 + t2;
}
void work()
{
	int a, b, ans = ~0u>>1;
    scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		e[i].clear();
	}
    for (int i = 1; i <= n - 1; i++) {
        scanf("%d%d", &a, &b);
        e[a].push_back(b);
        e[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
			DFS(i, 0);
			ans = min(ans, f[i]);
		}
	printf("%d\n", ans);
}
int main()
{
		freopen("B.in", "r", stdin);
			freopen("B.out", "w", stdout);
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		printf("Case #%d: ", i);
		work();
	}
}
