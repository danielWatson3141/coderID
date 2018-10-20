#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

typedef long long ll;

char dev[200][100];
char outl[200][100];
ll bdev[200];
ll bout[200];
char msk[200];

int bitcnt(ll n)
{
	int res=0;
	while(n)
	{
		res+=n&1;
		n>>=1;
	}
	return res;
}

int main()
{
	freopen("/home/knightl/A-large.in","r",stdin);
	int T;
	scanf("%d",&T);
	for(int test=1;test<=T;test++)
	{
		int n,l;
		scanf("%d%d",&n,&l);
		int res=1000000;
		for(int i=0;i<n;i++)
		{
			scanf("%s",outl[i]);
			bout[i]=0;
			for(int j=0;j<l;j++)
				if(outl[i][j]=='1')
					bout[i]|=1LL<<j;
		}
		for(int i=0;i<n;i++)
		{
			scanf("%s",&dev[i]);
			bdev[i]=0;
			for(int j=0;j<l;j++)
				if(dev[i][j]=='1')
					bdev[i]|=1LL<<j;
		}
		set<ll> dev_set;
		for(int i=0;i<n;i++)
			dev_set.insert(bdev[i]);
		for(int i=0;i<n;i++)
		{
			bool ok=true;
			ll msk=bdev[0]^bout[i];
			for(int j=0;j<n;j++)
				ok &= dev_set.count(bout[j]^msk);
			if(ok)
				res=min(res,bitcnt(msk));
		}
		if(res==1000000)
			printf("Case #%d: NOT POSSIBLE\n",test);
		else
			printf("Case #%d: %d\n",test,res);
	}
	return 0;
}
