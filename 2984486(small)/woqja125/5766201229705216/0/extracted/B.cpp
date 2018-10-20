#include<stdio.h>
#include<vector>
#include<queue>
std::vector<int> map[1001];
int d[1001];
int c[1001];
void getC(int x, int p)
{
	int i;
	for(i=0; i<map[x].size(); i++)
	{
		if(map[x][i] == p) continue;
		getC(map[x][i], x);
		c[x] += c[map[x][i]];
	}
	c[x]++;
}
void getD(int x, int p)
{
	int i, ans = 10000, sum=0;
	sum = 0;
	for(i=0; i<map[x].size(); i++)
	{
		if(map[x][i] == p) continue;
		getD(map[x][i], x);
		sum += d[map[x][i]];
	}
	if((map[x].size() ==2 && p==-1) || (map[x].size()==3 && p!=-1))
	{
		d[x] = sum;
		return;
	}
	else if((map[x].size() == 1 && p==-1) || (map[x].size() == 2 && p!=-1))
	{
		sum = 0;
		for(i=0; i<map[x].size(); i++)
		{
			if(map[x][i] == p) continue;
			sum += c[map[x][i]];
		}
		d[x] = sum;
		return;
	}
	else if((map[x].size() == 0 && p==-1) || (map[x].size() == 1 && p!=-1))
	{
		d[x] = 0;
		return;
	}
	else
	{
		sum = 0;
		std::priority_queue<int> t;
		for(i=0; i<map[x].size(); i++)
		{
			if(map[x][i] == p) continue;
			sum += c[map[x][i]];
			t.push(c[map[x][i]] - d[map[x][i]]);
		}
		sum -= t.top();
		t.pop();
		sum -= t.top();
		d[x] = sum;
	}
}
int main()
{
	int T, k;
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	scanf("%d", &T);
	for(k=1; k<=T; k++)
	{
		int n, i, j, a, b, ans=10000, t;
		scanf("%d", &n);
		for(i=1; i<=n; i++) map[i].clear();
		for(i=1; i<n; i++)
		{
			scanf("%d%d", &a, &b);
			map[a].push_back(b);
			map[b].push_back(a);
		}
		for(i=1; i<=n; i++)
		{
			// root is i
			for(j=1; j<=n; j++)
			{
				c[j] = d[j] = 0;
			}
			getC(i, -1);
			getD(i, -1);
			for(j=1; j<=n; j++)
			{
				t = n - c[j] + d[j];
				if(ans > t) ans = t;
			}
		}
		printf("Case #%d: %d\n", k, ans);
	}
	return 0;
}