#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<map>
#include<set>

using namespace std;

int de[200];
int ot[200];
char des[200][50]; 
char ots[200][50];
bool use[200];
bool jd[200];
int n, m, ct,res;
bool suc;

void dfs(int i,int r)
{
	if (suc) return;
	if (jd[i]) {
		dfs(i + 1,r); 
		return;
	}
	int j;
	if (i >= m)
	{
		memset(use, 0, sizeof(use));
		int k;
		for (j = 0; j < n; j++)
		{
			for (k = 0; k < n; k++)
			{
				if (!use[k])
				{
					if (strcmp(des[j], ots[k]) == 0)
					{
						use[k] = true;
						break;
					}
				}
			}
			if (k == n) break;
		}
		if (j == n)
		{
			suc = true;
			res = min(res, r);
		}
		return;
	}
	
	dfs(i + 1,r);
	if (!suc)
	{
		for (j = 0; j < n; j++)
		{
			if (ots[j][i] == '0') ots[j][i] = '1';
			else ots[j][i] = '0';
		}
		dfs(i + 1, r + 1);
		for (j = 0; j < n; j++)
		{
			if (ots[j][i] == '0') ots[j][i] = '1';
			else ots[j][i] = '0';
		}
	}
}

int main()
{
	int t, ca;
	scanf("%d", &t);
	int i, j;
	
	for (ca = 1; ca <= t; ca++)
	{
		memset(de, 0, sizeof(de));
		memset(ot, 0, sizeof(ot));
		memset(jd, 0, sizeof(jd));
		scanf("%d%d", &n, &m);
		for (i = 0; i < n; i++)
		{
			scanf("%s", des[i]);
		}
		for (i = 0; i < n; i++)
		{
			scanf("%s", ots[i]);
		}
		ct = 0;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				if (des[i][j] == '0')
					de[j]++;
			}
			for (j = 0; j < m; j++)
			{
				if (ots[i][j] == '0')
					ot[j]++;
			}
		}
		for (i = 0; i < m; i++)
		{
			if (de[i] != ot[i])
			{
				if (de[i] == (n - ot[i]))
				{
					ot[i] = n - ot[i];
					for (j = 0; j < n; j++)
					{
						if (ots[j][i] == '0') ots[j][i] = '1';
						else ots[j][i] = '0';
					}
					jd[i] = true;
					ct++;
				}
				else break;
			}
		}
		suc = false;

		if (i == m)
		{
			res = m + 1;
			dfs(0, ct);
		}
		else i = 0;
		printf("Case #%d: ", ca);
		if (suc)
		{
			printf("%d\n", res);
		}
		else
		{
			printf("NOT POSSIBLE\n");
		}
	}
	return 0;
}