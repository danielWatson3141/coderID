#include <stdio.h>
#include <vector>
#include <string>
#include <stack>
#include <map>
#include <iostream>
using namespace std;

const int MAXN = 151;
const int MAXL = 41;
char pre[MAXN][MAXL];
char after[MAXN][MAXL];
int n, l;
int switchstatus[MAXN][MAXN][MAXL];
int ans;
void Dfs(int curbit, int *curstatus)
{
	int i, j, k;
	char a;
	bool get[MAXN];
	int cur;
	for (i = 0; i < n; ++ i)
	{
		get[i] = false;
	}
	if (curbit == l)
	{
		for (i = 0; i < n; ++ i)
		{
			for (j = 0; j < n; ++ j)
			{
				for (k = 0; k < l; ++ k)
				{
					if (curstatus[k] == 1)
					{
						a = '1' - pre[i][k] + '0';
					}
					else
					{
						a = pre[i][k];
					}
					if (after[j][k] != a)
					{
						break;
					}
				}
				if (k >= l)
				{
					get[j] = true;
					break;
				}
			}
		}
		for (i = 0; i < n; ++ i)
		{
			if (!get[i])
			{
				break;
			}
		}
		if (i >= n)
		{
			cur = 0;
			for (k = 0; k < l; ++ k)
			{
				if (curstatus[k] == 1)
				{
					cur++;
				}
			}
			if (cur < ans)
			{
				ans = cur;
			}
		}
		return;
	}
	for (i = 0; i < 2; ++ i)
	{
		curstatus[curbit] = i;
		Dfs(curbit+1, curstatus);
	}
}

int main()
{
	//freopen("A-small-attempt0.in", "r", stdin);
	//freopen("A-small-attempt0.out", "w", stdout);


	int nCase;
	int t;
	int i, j, k;
	scanf("%d", &nCase);
	for (t = 1; t <= nCase; ++ t)
	{
		scanf("%d%d", &n, &l);
		for (i = 0; i < n; ++ i)
		{
			for (j = 0; j < l; ++ j)
			{
				scanf(" %c", &pre[i][j]);
			}
		}
		for (i = 0; i < n; ++ i)
		{
			for (j = 0; j < l; ++ j)
			{
				scanf(" %c", &after[i][j]);
			}
		}
		//
		//for (i = 0; i < n; ++ i)
		//{
		//	for (j = 0; j < n; ++ j)
		//	{
		//		for (k = 0; k < l; ++ k)
		//		{
		//			if (pre[i][k] != after[j][k])
		//			{
		//				switchstatus[i][j][k] = 1;
		//			}
		//			else
		//			{
		//				switchstatus[i][j][k] = 0;
		//			}
		//		}
		//	}
		//}
		
		ans = l+1;
		int curstatus[MAXL];
		Dfs(0, curstatus);
				
		
		printf("Case #%d: ", t);
		if (ans > l)
		{
			printf("NOT POSSIBLE");
		}
		else
		{
			printf("%d", ans);
		}
		
		if (t < nCase)
		{
			printf("\n");
		}
	}

	//system("pause");
	return 0;
}

