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

vector<vector<int> > v(1010);
int a, b, N;
int m[1010][1010];
int mx[1010][1010];

int sizex(int node, int from)
{
	if (m[node][from] != -1) return m[node][from];

	int ret = 1;
	for (int i = 0; i < v[node].size(); ++i)
	{
		if (v[node][i] != from) ret += sizex(v[node][i], node);
	}

	return m[node][from] = ret;
}



int evaluate(int node, int from)
{
	if (mx[node][from] != -1) return mx[node][from];
	vector<int> list;
	int sum = 0;

	for (int i = 0; i < v[node].size(); ++i)
	{
		if (v[node][i] != from) list.push_back(sizex(v[node][i], node));
		else list.push_back(0);
	}

	for (int i = 0; i < list.size(); ++i)
	{
		sum += list[i];
		//if (node == 4 && from == 2) printf("list %d: %d\n", i, list[i]);
		//else
	}

	int ret = sum;

	for (int i = 0; i < v[node].size(); ++i)
	{
		for (int j = i + 1; j < v[node].size(); ++j)
		{
			if (v[node][i] != from && v[node][j] != from)
			{
				//if (node == 4 && from == 2) printf("%d %d\n", i, j);
				ret = min(ret, sum + evaluate(v[node][i], node) + evaluate(v[node][j], node) - list[i] - list[j]);
			}
		}
	}
	
	return mx[node][from] = ret;

}

void input()
{
	scanf("%d", &N);

	for (int i = 1; i <= N; ++i)
	{
		v[i].clear();
	}
	for (int i = 0; i < 1010; ++i)
	{
		for (int j = 0; j < 1010; ++j)
		{
			m[i][j] = -1;
			mx[i][j] = -1;
		}
	}

	for (int i = 1; i < N; ++i)
	{
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}

	int m = -1u/2;
	for (int i = 1; i <= N; ++i)
	{
		m = min(m, evaluate(i, -1));

	}

	printf("%d\n", m);
}

int main()
{
	freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	
	int T;
	scanf("%d", &T);

	for (int test = 1; test <= T; ++test)
	{
		printf("Case #%d: ", test);
		input();
	}

	return 0;
}