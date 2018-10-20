#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;

typedef vector<double> vd;

vd operator + (const vd &a, const vd &b)
{
	int n = a.size();
	vd res(n);
	for (int i = 0; i < n; i++) res[i] = a[i] + b[i];
	return res;
}

vd operator * (const vd &a, double k)
{
	int n = a.size();
	vd res(n);
	for (int i = 0; i < n; i++) res[i] = a[i] * k;
	return res;
}

vector<vd> a, b;


int test(int n)
{
	a.resize(n);
	b.resize(n);
	for (int i = 0; i < n; i++)
	{
		a[i] = vd(n);
		a[i][i] = 1.0;
	}
	for (int i = 0; i < n; i++)
	{
		vd sum = a[0];
		for (int j = 1; j < n; j++) sum = sum + a[j];
		for (int j = 0; j < n; j++)
			if (i != j)
				b[j] = a[j] * (1.0 * (n-1) / n) + a[i] * (1.0 / n);
			else
				b[j] = sum * (1.0 / n);
		a.swap(b);
	}
	/*
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) printf("%3lf ", a[i][j]);
		printf("\n");
	}
	*/
}


int solvecase()
{
	return 0;
}

bool res[1005];

int main()
{
	int t, n, q;
	scanf("%d", &t);
	vector<pair<double, int> > x;
	for (int i = 0; i < t; i++)
	{
		scanf("%d", &n);
		if (i == 0) test(n);
		double p = 1.0;
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &q);
			p *= a[j][q] * n;
		}
		x.push_back(make_pair(p, i));
	}
	sort(x.begin(), x.end());
	for (int i = 0; i < t / 2; i++)
		res[x[i].second] = true;
	for (int i = 0; i < t; i++)
		printf("Case #%d: %s\n", i+1, res[i] ? "GOOD" : "BAD");
	return 0;
}
