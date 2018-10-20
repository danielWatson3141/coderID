#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <iterator>
using namespace std;
const int Len = 150;
const int inf = (1<<30);
#define LL long long
#define ll1 ((LL)(1))
LL device[Len+5], outlet[Len+5];
int n, l;
int ans;
map<LL, int> M;
int getBits(LL num)
{
	int sum = 0;
	for (int i = 0; i < l; ++i)
		if (num&(1<<i)) ++sum;
	return sum;
}
void solve()
{
	ans = inf;
	M.clear();
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		{
			LL cur = (device[i]^outlet[j]);
			if (M.find(cur) == M.end()) M[cur] = 1;
			else ++M[cur];
		}
	for (map<LL, int>::iterator it = M.begin(); it != M.end(); it++)
		if (it->second >= n)
		{
			int tmpans = getBits(it->first);
			ans = min(ans, tmpans);
		}
	if (ans == inf) puts("NOT POSSIBLE");
	else printf("%d\n", ans);
}
int main()
{
	//freopen("E:\\My Code\\GCJ\\R1A\\A-large.in", "r", stdin);
	//freopen("E:\\My Code\\GCJ\\R1A\\A-large.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int C = 1; C <= T; ++C)
	{
		scanf("%d%d", &n, &l);
		for (int i = 0; i < n; ++i)
		{
			string tmpstr;
			cin >> tmpstr;
			LL tmp = 0;
			for (int j = 0; j < l; ++j)
				if (tmpstr[j] == '1')
					tmp += (ll1<<(l-j-1));
			outlet[i] = tmp;
		}
		for (int i = 0; i < n; ++i)
		{
			string tmpstr;
			cin >> tmpstr;
			LL tmp = 0;
			for (int j = 0; j < l; ++j)
				if (tmpstr[j] == '1')
					tmp += (ll1<<(l-j-1));
			device[i] = tmp;
		}
		printf("Case #%d: ", C);
		solve();
	}
	return 0;
}