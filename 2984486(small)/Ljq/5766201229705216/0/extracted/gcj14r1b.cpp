#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 1005;

int n;
vector <int> e[MAXN], child[MAXN];
int q[MAXN], p[MAXN], f[MAXN], g[MAXN];

int Calc(int root)
{
	memset(p, 0xff, sizeof(p));
	int qh = 0, ql = 0;
	q[ql++] = root;  p[root] = -2;
	for (; qh < ql; qh ++)
	{
		int z = q[qh], x;
		for (int i = 0; i < e[z].size(); i ++)
			 if (p[x=e[z][i]] == -1)
				p[q[ql++]=x] = z;
	}
	for (int i = 0; i < n; i ++)
		child[i].clear();
	memset(g, 0, sizeof(g));
	for (int i = n - 1; i >= 0; i --)
	{
		int z = q[i];   
		g[z] ++;
		if (p[z] >= 0) 
		{
			g[p[z]] += g[z];
			child[p[z]].push_back(z);
		}
	}
	memset(f, 0, sizeof(f));
	for (int k = n - 1; k >= 0; k --)
	{
		int z = q[k];
		if (child[z].size() == 1)  f[z] = g[child[z][0]];
		if (child[z].size() < 2)  continue;
		int m1 = MAXN, m2 = MAXN;
		for (int i = 0; i < child[z].size(); i ++)
		{
			int x = child[z][i], tmp;
			tmp = f[x] - g[x];
			if (tmp < m1)  m2 = m1, m1 = tmp;
			else if (tmp < m2)  m2 = tmp;
		}
		f[z] = g[z] - 1 + m1 + m2;
	}
	return f[q[0]];
}

int Work()
{
	cin >> n;
	for (int i = 0; i < n; i ++)
		e[i].clear();
	for (int i = 1; i < n; i ++)
	{
		int x, y;
		cin >> x >> y;
		e[--x].push_back(--y);
		e[y].push_back(x);
	}
	int mn = n - 1;
	for (int i = 0; i < n; i ++)
		mn = min(mn, Calc(i));
	return mn;
}

int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);
	int T;
	cin >> T;
	for (int tt = 1; tt <= T; tt ++)
		cout << "Case #" << tt << ": " << Work() << endl;
	return 0;
}