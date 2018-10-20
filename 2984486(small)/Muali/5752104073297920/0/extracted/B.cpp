#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;


double calc(vector<int>& p)
{
	double ret = 0;
	for (int i = 0; i < 1000; ++i)
	{
		int pos = p[i];
		int c = 0;
		while (pos != i)
		{
			pos = p[pos];
			++c;
		}
		ret += c;
	}
	return ret/1000;
}

void solve()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	double c = calc(v);
	if (fabs(c - 500) > 200)
		cout << "BAD";
	else
		cout << "GOOD";
}

void good()
{
	double res = 0;
	for (int k = 0; k < 10000; ++k)
	{
		vector<int> p;
		for (int i = 0; i < 1000; ++i)
			p.push_back(i + 1);
		for (int i = 0; i < 1000; ++i)
		{
			swap(p[i], p[i + (rand() % (1000 - i))]);
		}
		double tmp = fabs(500.0 - calc(p));
		res += tmp * tmp;
	}
	cout << res / 10000 << endl;
}
void bad()
{
	double res = 0;
	for (int k = 0; k < 10000; ++k)
	{
		vector<int> p;
		for (int i = 0; i < 1000; ++i)
			p.push_back(i + 1);
		for (int i = 0; i < 1000; ++i)
		{
			swap(p[i], p[rand() % 1000]);
		}
		double tmp = fabs(500.0 - calc(p));
		res += tmp * tmp;
	}
	cout << res / 10000;
}


void main()
{

	freopen("i.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
	{
		cout << "Case #" << i << ": ";
		solve();
		cout << endl;
	}
	
	/*
	freopen("input.txt", "r", stdin);
	int t;
	cin >> t;
	vector<int> ans(t);
	for (int i = 0; i < t; ++i)
	{
		ans[i] = stupid();
	}
	fclose(stdin);
	freopen("input.txt", "r", stdin);
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		if (ans[i] != solve())
			cout << "assadsasadasds";
	}
	*/
}