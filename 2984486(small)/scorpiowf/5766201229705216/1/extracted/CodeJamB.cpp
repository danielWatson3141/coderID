#include <iostream>
using namespace std;

int tabl[1010][1010];
int len[1010];
bool visit[1010];
int child[1010];
int n;
void insert(int x, int y)
{
	int s = len[x];
	tabl[x][s] = y;
	len[x]++;
	s = len[y];
	tabl[y][s] = x;
	len[y]++;
}
void input()
{
	int i, x, y;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		len[i] = 0;
	}
	for (i = 1; i < n; i++)
	{
		scanf("%d %d", &x, &y);
		x--;
		y--;
		insert(x, y);
	}
}
void init()
{
	int i;
	for (i = 0; i < n; i++)
	{
		visit[i] = false;
		child[i] = 0;
	}
}
int dfs(int node)
{
	visit[node] = true;
	int s = len[node];
	int i, k, c = 0;
	child[node] = 1;
	int m1 = 0, m2 = 0, sumrt = 0;
	for (i = 0; i < s; i++)
	{
		k = tabl[node][i];
		if (!visit[k])
		{
			c++;
			int rt = dfs(k);
			sumrt += rt;
			if (rt - child[k] <= m1)
			{
				m2 = m1;
				m1 = rt-child[k];
			}
			else if (rt - child[k] < m2)
			{
				m2 = rt - child[k];
			}
			child[node] += child[k];
		}
	}
	if (c == 0)
	{
		return 0;
	}else if (c == 1)
	{
		return child[node] - 1;
	}
	else if (c == 2)
	{
		return sumrt;
	}
	else
	{
		return child[node] + m1 + m2 - 1;
	}
}
void solveB(int tc)
{	
	int i;
	int ans = 1000000;
	for (i = 0; i < n; i++)
	{
		init();
		int rt = dfs(i);
		if (rt < ans)
		{
			ans = rt;
		}
	}
	printf("Case #%d: %d\n", tc, ans);
}
int main()
{
//	freopen("c:\\data\\r1\\B-large.in", "r", stdin);
//	freopen("c:\\data\\r1\\B-large.out", "w", stdout);
	
	int tc;
	scanf("%d", &tc);
	int i;
	for (i = 1; i <= tc; i++)
	{
		input();
		solveB(i);
	}
	return 0;
}