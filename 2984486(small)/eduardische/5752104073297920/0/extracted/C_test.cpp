#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <utility>
#include <iostream>
#define MAXN 45000

using namespace std;

int N;
static pair<int, pair<int, string> > cnt[MAXN];
static int a[10];
int ac;

static int data[MAXN];

void DFS (int point)
{
	if (point == N)
	{
		int inv = 0;
		int i, j;
		string perm = "";
		for (i = 0; i < N; i++)
		{
			for (j = i+1; j < N; j++)
			{
				if (a[i] > a[j]) inv++;
			}
			char d = a[i] + '0';
			perm += d;
		}
		pair<int, string> cur = make_pair(inv, perm);
		i = 0;
		while ((i < ac) && (cnt[i].second != cur)) i++;
		if (i == ac)
		{
			cnt[ac].second = cur;
			cnt[ac].first = 1;
			ac++;
		}
		else
		{
			cnt[i].first++;
		}
	}
	else
	{
		int i, j;
		for (i = 0; i < N; i++)
		{
			j = a[point]; a[point] = a[i]; a[i] = j;
			DFS(point+1);
			j = a[point]; a[point] = a[i]; a[i] = j;
		}
	}
}

int main ()
{
	N = 7;
	int i;
	for (i = 0; i < N; i++) a[i] = i;
	ac = 0;
	DFS(0);
	sort(cnt,cnt+ac);
	
	int T, iT;
	scanf("%d",&T);
	for (iT = 0; iT < T; iT++)
	{
		scanf("%d",&N);
		for (i = 0; i < N; i++)
		{
			scanf("%d",&(data[i]));
		}
		pair<int, int> c[7];
		for (i = 0; i < 7; i++)
		{
			c[i] = make_pair(data[i], i);
		}
		sort(c, c+7);
		for (i = 0; i < 7; i++)
		{
			c[i].first = c[i].second;
			c[i].second = i;
		}
		sort(c, c+7);
		string s = "";
		for (i = 0; i < 7; i++)
		{
			char ch = c[i].second + '0';
			s += ch;
		}
		i = 0;
		while (cnt[i].second.second != s) i++;

		printf("Case #%d: ",iT+1);
		if (i < 2800) printf("GOOD\n");
		else printf("BAD\n");
	}

	return 0;
}
