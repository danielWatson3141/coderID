#include <stdio.h>
#include <set>
#include <string.h>
#include <stdlib.h>
using namespace std;

int n, l;
long long a[160];
long long b[160];

long long count(long long x)
{
	long long retv = 0;
	while(x != 0)
	{
		retv += x&1LL;
		x >>= 1LL;
	}
	return retv;
}

int
main(void)
{
	int T, t = 0;
	scanf("%d", &T);
	while(T--)
	{
		char s[50];
		scanf(" %d %d", &n, &l);
		for(int i = 0; i < n; i++)
		{
			scanf(" %s", s);
			a[i] = strtoll(s, NULL, 2);
		}
		for(int i = 0; i < n; i++)
		{
			scanf(" %s", s);
			b[i] = strtoll(s, NULL, 2);
		}
	
		long long ans = 0x3f3f3f3f;
	
		for(int i = 0; i < n; i++)
		{
			long long change = b[i] ^ a[0];
			bool pos = true;
			multiset<long long> ex;
			ex.clear();
			for(int j = 1; j < n; j++)
				ex.insert(a[j]);
			for(int j = 0; j < n && pos; j++)
				if(j != i)
				{
					if(ex.find(b[j] ^ change) != ex.end())
						ex.erase(ex.find(b[j] ^ change));
					else
						pos = false;
				}
			if(pos)
				ans = min(ans, count(change));
		}
		printf("Case #%d: ", ++t);
		if(ans != 0x3f3f3f3f)
			printf("%lld\n", ans);
		else
			printf("NOT POSSIBLE\n");
	}
}












