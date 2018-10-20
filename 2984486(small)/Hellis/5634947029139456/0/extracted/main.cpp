#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

typedef long long _int64 ;

char sa[205][55], sb[200][55];
map <_int64, int> M;
map <_int64, int>:: iterator it;

_int64 calc(char *s1, char *s2, int l)
{
	_int64 ans = 0;
	for (int i=0; i<l; i++)
	{
		ans <<= 1;
		ans |= (s1[i] != s2[i]);
	}
	return ans;
}

int main()
{
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
	int cas, T;
	
	for (cas=scanf("%d", &T); cas<=T; cas++)
	{
		int n, l;
		cin >> n >> l;
		for (int i=1; i<=n; i++) scanf("%s", sa[i]);
		for (int i=1; i<=n; i++) scanf("%s", sb[i]);
		
		M.clear();
		for (int i=1; i<=n; i++)
			for (int j=1; j<=n; j++)
			{
				_int64 tmp = calc(sa[i], sb[j], l);
				//cout << tmp <<endl;
				M[tmp] ++;
			}
		
		int ans = l + 1;
		for (it = M.begin(); it != M.end(); it++)
			if (it->second == n)
				ans = min(ans, __builtin_popcount(it->first));
		
		printf("Case #%d: ", cas);
		if (ans == l + 1) puts("NOT POSSIBLE");
		else printf("%d\n", ans);
	}
    return 0;
}
