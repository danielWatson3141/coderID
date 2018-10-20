#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
using namespace std;

const int mx = 200;
int n, l;
string ori[mx], tar[mx];

int f()
{
	int ret = 10000;
	set<string> tars;
	for (int i = 0; i < n; i++)	tars.insert(tar[i]);
	for (int i = 0; i < n; i++)
	{
		string cur[mx], t = tar[0];
		for (int j = 0; j < n; j++)	cur[j] = ori[j];
		int cnt = 0;
		for (int j = 0; j < l; j++)
		{
			if (t[j] != cur[i][j])
			{
				cnt++;
				for (int k = 0; k < n; k++)
				{
					cur[k][j] = (cur[k][j] == '0') ? '1' : '0';
				}
			}
		}
		set<string> curs;
		for (int j  = 0 ; j < n; j++)	curs.insert(cur[j]);
		if (curs == tars)	{ret = min(ret, cnt);}
	}
	return ret;
}


int main ()
{
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
	int TC; scanf("%d", &TC);
	for (int tc = 1; tc <= TC; tc++)
	{
		scanf("%d%d", &n, &l);
		char tem[mx];
		for (int i = 0; i < n; i++)	{scanf("%s", tem); ori[i] = string(tem);}
		for (int i = 0; i < n; i++)	{scanf("%s", tem); tar[i] = string(tem);}
		int ans = f();
		if (ans == 10000)		printf("Case #%d: NOT POSSIBLE\n", tc);
		else printf("Case #%d: %d\n", tc, ans);
	}

}