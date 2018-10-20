#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
const int Len = 150;
const int inf = (1<<30);
#define LL long long
#define ll1 ((LL)(1))
int device[Len+5], outlet[Len+5], tmpout[Len+5];
int n, l;
int ans;
void solve()
{
	ans = inf;
	sort(device, device+n);
	for (int i = 0; i < (ll1<<l); ++i)
	{
		for (int j = 0; j < n; ++j) tmpout[j] = outlet[j];
		for (int k = 0; k < l; ++k)
			if (i&(1<<k))
				for (int j = 0; j < n; ++j)
				{
					if (i&(1<<k)) tmpout[j] ^= (1<<k);
				}
		sort(tmpout, tmpout+n);
		bool flag = false;
		for (int j = 0; j < n; ++j)
			if (tmpout[j] != device[j])
			{
				flag = true;
				break;
			}
		if (!flag)
		{
			int tmp = 0;
			for (int j = 0; j < l; ++j)
				if (i&(1<<j)) ++tmp;
			ans = min(ans, tmp);
		}
	}
	if (ans == inf) puts("NOT POSSIBLE");
	else printf("%d\n", ans);
}
int main()
{
	//freopen("E:\\My Code\\GCJ\\R1A\\A-small-attempt0.in", "r", stdin);
	//freopen("E:\\My Code\\GCJ\\R1A\\A-small-attempt0.out", "w", stdout);
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