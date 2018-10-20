
#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

vector<bool> diff(const string &a, const string &b)
{
	int length = a.length();
	vector<bool> d(length);
	for (int i = 0; i < length; i++)
	{
		d[i] = a[i] != b[i];
	}
	return d;
}

string change(const string &o, const vector<bool> &d)
{
	string k = o;
	int len = k.length();
	for (int i = 0; i < len; i++)
	{
		if (d[i])
		{
			if (k[i] == '0')
			{
				k[i] = '1';
			}
			else
			{
				k[i] = '0';
			}
		}
	}
	return k;
}

void testCase()
{
	int n, l;
	scanf("%d%d", &n, &l);

	vector<string> a, b;
	for (int i = 0; i < n; i++)
	{
		string input;
		cin >> input;
		a.push_back(input);
	}
	for (int i = 0; i < n; i++)
	{
		string input;
		cin >> input;
		b.push_back(input);
	}

	int answer = INT_MAX;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			vector<bool> d = diff(a[i], b[j]);
			vector<bool> check(n);

			for (int p = 0; p < n; p++)
			{
				string t = change(a[p], d);
				for (int q = 0; q < n; q++)
				{
					if (b[q] == t)
					{
						check[q] = true;
						break;
					}
				}
			}

			int p;
			for (p = 0; p < n; p++)
			{
				if (!check[p])
				{
					break;
				}
			}
			if (p < n == false)
			{
				int current = 0;
				for (int q = 0; q < l; q++)
				{
					current += d[q];
				}
				answer = min(answer, current);
			}
		}
	}
	if (answer == INT_MAX)
	{
		printf("NOT POSSIBLE");
	}
	else
	{
		printf("%d", answer);
	}
}

int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		printf("Case #%d: ", i);
		testCase();
		printf("\n");
	}
	return 0;
}