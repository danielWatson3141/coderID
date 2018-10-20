#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<string>
using namespace std;
int len[1001];
int node[1001][1001];
int func(int root, int father, int &total)
{
	//printf("%d %d\n", root, father);
	int ct;
	total = 1;
	int son = 0;
	for(int i = 0; i < len[root]; i++)
	{
		if(node[root][i] != father) son++;
	}
	if(son == 0)
	{
		return 0;
	}
	if(son == 1)
	{
		for(int i = 0; i < len[root]; i++)
		{
			if(node[root][i] != father)
			{
				func(node[root][i], root, ct);
				total += ct;
				return ct;
			}
		}
	}
	if(son== 2)
	{
		int ans = 0;
		for(int i = 0; i < len[root]; i++)
		{
			if(node[root][i] != father)
			{
				ans += func(node[root][i], root, ct);
				total = total + ct;
			}
		}
		return ans;
	}
	int Max = -1;
	int Second = -1;
	int ans = 0;
	int left[1001];
	for(int i = 0; i < len[root]; i++)
	{
		if(node[root][i] == father) continue;
		int temp = func(node[root][i], root, ct);
		left[i] = ct - temp;
		total = total + ct;
	}
	for(int i = 0; i < len[root]; i++)
	{
		if(node[root][i] == father) continue;
		if(left[i] > Max)
		{
			Second =Max;
			Max = left[i];
		}
		else if(left[i] > Second)
		{
			Second = left[i];
		}
	}
	ans = total - 1 - Max - Second;
	return ans;
}
		

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("B-small-attempt0.in", "r", stdin);
	//freopen("B-small-attempt1.in", "r", stdin);
	//freopen("B-small-attempt2.in", "r", stdin);
	freopen("B-large.in", "r", stdin);
	freopen("B.out", "w", stdout);

	int T;
	scanf("%d", &T);
	int N, x, y;
	for(int Case = 1; Case <= T; Case++)
	{
		scanf("%d", &N);
		for(int i = 1; i <= N; i++)
		{
			len[i] = 0;
		}
		for(int i = 0; i < N - 1; i++)
		{
			scanf("%d%d", &x, &y);
			node[x][len[x]] = y;
			len[x]++;
			node[y][len[y]] = x;
			len[y]++;
		}
		int Min = 1000000;
		int idx;
		for(int i = 1; i <= N; i++)
		{
			int total;
			int temp = func(i, -1, total);
			//printf("%d ", total);
			if(temp < Min)
			{
				Min = temp;
				idx = i;
			}
		}
		printf("Case #%d: %d\n", Case, Min);
	}
	return 0;
}
