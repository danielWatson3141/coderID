#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<cmath>
#include<vector>
using namespace std;

#define debug(x) cout << #x << "=" << x << endl
#define sqr(x) ((x)*(x))

int tests,n,m;
int q[9],a[9];
vector<string> l;

void dfs(int d)
{
	if (d>n)
	{
		for (int i=1;i<=n;i++) a[i] = i;
		for (int i=1;i<=n;i++)
		{
			swap(a[i], a[q[i]]);
		}
		string s = "";
		for (int i=1;i<=n;i++)
			s += '0' + a[i];
		l.push_back(s);
		return;
	}
	for (int j=1;j<=n;j++)
	{
		q[d] = j;
		dfs(d+1);
	}
}

int main()
{
	
	//freopen("p3.out","w",stdout);
	
	/*
	n = 8;
	dfs(1);
	
	sort(l.begin(), l.end());
	int t = 0, right=0;
	for (int i=0;i<l.size();i++)
	{
		t++;
		if (i==l.size()-1 || l[i]!=l[i+1])
		{
			//printf("%s %d\n", l[i].c_str(), t);
			double r = 1;
			for (int j=1;j<=n;j++) r *= n * 1.0 / j;
			r = (t - r) / r;
			int u = 0;
			for (int j=0;j<n;j++) if (l[i][j]-'0'>j+1) u++;
			else if (l[i][j]-'0'<j+1) u--;
			//printf(" %d %.2f\n",u,r);
			if (u>0)
			{
				if (r>0) right++;
			}
			else if (r<=0) right++;
			t = 0;
		}
	}
	
	double r = right;
	for (int i=1;i<=n;i++)
		r /= i;
	printf("%f\n",r);
	return 0;
	
	*/
	
	freopen("C-small-attempt2.in","r",stdin);
	freopen("c1.out","w",stdout);
	
	scanf("%d",&tests);
	for (int test=1;test<=tests;test++)
	{
		scanf("%d",&n);
		int u = 0, x;
		for (int i=0;i<n;i++)
		{
			scanf("%d",&x);
			if (x>i) u++;
			else if (x<i) u--;
		}
		if (u>0 || u==0 && rand()%2==0)
			printf("Case #%d: BAD\n", test);
		else
			printf("Case #%d: GOOD\n", test);
	}
	
	return 0;
}
