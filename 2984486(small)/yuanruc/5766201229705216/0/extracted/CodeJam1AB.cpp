#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<cstring>
using namespace std;

#define MAXN 1010

struct Edge{
	int y, next;
	};
	
int first[MAXN], tot, n;
Edge map[MAXN*2];
int T, tt = 0;
int f[MAXN], sum[MAXN];

int TreeDP(int x, int fa)
{
	if (f[x] != -1) return f[x];
	int t = first[x];
	int max1 = -1, max2 = -1;
	while (t >= 0)
	{
		int y = map[t].y;
		if (y != fa){
			int val = TreeDP(y, x);
			if (val > max1) { max2 = max1; max1 = val; }
			else if (val > max2) max2 = val;
			sum[x] += sum[y];
			}
		t = map[t].next;
		}
	sum[x]++;
	if (max2 == -1) f[x] = 1;
	else f[x] = max1 + max2 + 1;
	return f[x];
	}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	scanf("%d", &T);
	while (T--){
		scanf("%d", &n);
		tot = 0;
		memset(first, -1, sizeof(first));
		int x, y;
		for (int i = 1; i < n; ++i)
			{
				scanf("%d%d", &x, &y);
				map[tot].y = y; map[tot].next = first[x]; first[x] = tot; tot++;
				map[tot].y = x; map[tot].next = first[y]; first[y] = tot; tot++;
				}
		int ans = 0;
		for (int i = 0; i < n; ++i)
		{
			memset(f, -1, sizeof(f));
			memset(sum, 0, sizeof(sum));
			ans = max(ans, TreeDP(i, -1));
		}
		printf("Case #%d: %d\n", (++tt), n - ans);
		}
	return 0;
	}
