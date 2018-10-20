#include<cstdio>
#include<cstdlib>
#include<queue>
#include<cmath> 
#include<cstring> 
#include<map> 
#include<set>
#include<algorithm>

using namespace std;

long long a[256], b[256], ca[256];
int n, l;

long long trans(char s[64])
{
	long long ret = 0;
	int i;
	for(i = 0; i < l; i ++)
	{
		ret = ret*2 + s[i]- '0';
	}
	return ret;
}

int count(long long a)
{
	int ret = 0;
	while(a > 0)
	{
		if(a&1)ret ++;
		a /= 2;
	}
	return ret;
}

bool check(long long num)
{
	int i;
	for(i = 0; i < n; i ++)
	{
		ca[i] = a[i]^num;
	}
	sort(ca, ca+n);
	for(i = 0; i < n; i ++)
	{
		if(ca[i] != b[i])return false;
	}
	return true;
}

int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for(int cas = 1; cas <= T; cas ++)
	{
		scanf("%d%d", &n, &l);
		char s[64];
		int i, j;
		for(i = 0; i < n; i ++)
		{
			scanf("%s", s);
			a[i] = trans(s);
		}
		
		int ans = 64;
		
		for(i = 0; i < n; i ++)
		{
			scanf("%s", s);
			b[i] = trans(s);
		}
		
		sort(b, b+n);
		
		if(check(0))ans = 0;
		for(i = 0; i < n; i ++)
		{
			for(j = 0; j < n; j ++)
			{
				if(check(a[i]^b[j]))
				{
					ans <?= count(a[i]^b[j]);
				}
			}
		}
		if(ans < 64)
		{
			printf("Case #%d: %d\n", cas, ans);
		}
		else 
		{
			printf("Case #%d: NOT POSSIBLE\n", cas);
		}
	}
	return 0;
}
