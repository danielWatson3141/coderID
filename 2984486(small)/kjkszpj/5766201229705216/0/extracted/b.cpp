#include <cstdio>
#include <cstring>
#include <algorithm>
#define REP(i, n) for (i = 0; i < (n); i++)
#define REP1(i, n) for (i = 1; i <= (n); i++)
using namespace std;

const int N = 1000;

bool edge[N][N];

int ans, n, nowtd, tdnum;

void ri()
{
	int i, x, y;

	ans = 0;
	memset(edge, 0, sizeof(edge));
	scanf("%d", &n);
	REP(i, n - 1)
	{
		scanf("%d%d", &x, &y);
		edge[x][y] = true;
		edge[y][x] = true;
	}
}

int ponderthis(int v1, int fa)
{
	int max1 = 0, max2 = 0, v2, result;

	REP1(v2, n)
		if (edge[v1][v2] && v2 != fa)
		{
			result = ponderthis(v2, v1);
			if (result > max1)
			{
				max2 = max1;
				max1 = result;
			}
			else if (result > max2) max2 = result;
		}
	if (max2 > 0) return 1 + max1 + max2; else return 1;
}

void solve()
{
	int i;

	REP1(i, n) ans = max(ans, ponderthis(i, 0));
}

void print() {printf("Case #%d: %d\n", nowtd, n - ans);}

int main()
{
	scanf("%d", &tdnum);
	REP1(nowtd, tdnum)
	{
		ri();
		solve();
		print();
	}
	return 0;
}
