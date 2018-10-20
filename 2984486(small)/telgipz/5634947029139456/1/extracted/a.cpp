#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <stack>
#include <cmath>
#include <queue>
using namespace std;

vector<string> a, b; 
int N, L;

int evaluate(int x, int y)
{
	string k;
	map<string, int> m;

	int out = 0;
	for (int i = 0; i < a[x].size(); ++i)
	{
		if (a[x][i] != b[y][i])
		{
			k.push_back('1');
			out++;
		}
		else k.push_back('0');
	}

	//printf("MATCH %d TO %d\nPATT IS", x, y);
	//cout << k;


	for (int i = 0; i < b.size(); ++i)
	{
		m[b[i]] += 1;
	}
	for (int i = 0; i < a.size(); ++i)
	{
		string r;
		for (int j = 0; j < a[i].size(); ++j)
		{
			if (k[j] == '1') 
			{
				if (a[i][j] == '1') r.push_back('0');
				else r.push_back('1');
			}
			else r.push_back(a[i][j]);
		}
		if (m[r] <= 0) return -1u/2;
		else m[r] -= 1;
	}
	return out;
}

void input()
{
	a.clear();
	b.clear();

	scanf("%d %d", &N, &L);
	string x;

	for (int i = 0; i < N; ++i)
	{
		cin >> x;
		a.push_back(x);
	}

	for (int i = 0; i < N; ++i)
	{
		cin >> x;
		b.push_back(x);
	}

	int m = -1u/2;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			m = min(m, evaluate(i, j));
		}
	}

	if (m == -1u/2) printf("NOT POSSIBLE\n");
	else printf("%d\n", m);
}

int main()
{
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	
	int T;
	scanf("%d", &T);

	for (int test = 1; test <= T; ++test)
	{
		printf("Case #%d: ", test);
		input();
		fflush(stdout);
	}

	return 0;
}