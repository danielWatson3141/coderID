#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

ll readLLbinary()
{
	char buf[66];
	scanf("%s",buf);
	int len = strlen(buf);

	ll ans = 0;
	for(int i = 0;i < len;i++)
	{
		ans <<= 1;
		ans |= buf[i] - '0';
	}
	return ans;
}

int main(void)
{
	int T = 0;
	int TK = 0;
	scanf("%d",&T);
	while(T--)
	{
		printf("Case #%d: ",++TK);
		int N = 0;
		int L = 0;
		scanf("%d %d",&N,&L);
		ll flow[222] = {0};
		ll device[222] = {0};
		for(int i = 0;i < N;i++) flow[i] = readLLbinary();
		for(int i = 0;i < N;i++) device[i] = readLLbinary();
		sort(device,device+N);
		
		ll tflow[222] = {0};
		int ans = ~0U>>1;
		for(int i = 0;i < N;i++)
		{
			for(int j = 0;j < N;j++)
			{
				ll mask = flow[i] ^ device[j];
				for(int k = 0;k < N;k++) tflow[k] = flow[k] ^ mask;
				sort(tflow,tflow+N);
				if(equal(tflow,tflow+N,device)) ans = min(ans, __builtin_popcountll(mask));
			}
		}
		if(ans > 0x3F000000) puts("NOT POSSIBLE");
		else printf("%d\n",ans);
	}
	return 0;
}
