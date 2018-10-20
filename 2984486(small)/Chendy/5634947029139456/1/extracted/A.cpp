#include<iostream>
#include<fstream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<iomanip>
#include<ctime>
#include<cstring>
#include<climits>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<algorithm>
#include<stack>
#include<deque>
#include<list>
#include<vector>
#define LL long long
using namespace std;
int cnt,snt,n,L,times;
char s[110];
LL a[210],b[210],c[210],d[210];
int change[210];
void work(int lab)
{
	printf("Case #%d: ",lab);
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	scanf("%d%d",&n,&L);
	for (int i=1;i<=n;i++)
	{
		scanf("%s",s);
		a[i]=0;
		for (int j=L-1;j>=0;j--) 
		{
			a[i]=a[i]*2ll+(LL)(s[j]-'0');
			a[n+1]^=a[i];
		}
	}
	for (int i=1;i<=n;i++)
	{
		scanf("%s",s);
		b[i]=0;
		for (int j=L-1;j>=0;j--) 
		{
			b[i]=b[i]*2ll+(LL)(s[j]-'0');
			b[n+1]^=b[i];
		}
	}
	if (((n&1)==0)&&b[n+1]!=a[n+1])
	{
		printf("NOT POSSIBLE\n");return;
	}
	if (n&1)
	{
		LL convert=0;
		LL ans=0;
		for (int i=0;i<L;i++)
		{
			int cnt=0;
			for (int j=1;j<=n;j++) if ((a[j]>>i)&1) cnt++;
			int snt=0;
			for (int j=1;j<=n;j++) if ((b[j]>>i)&1) snt++;
			if (snt!=cnt) convert^=1ll<<i,ans++;
		}
		for (int i=1;i<=n;i++) a[i]^=convert;
		sort(a+1,a+n+1);
		sort(b+1,b+n+1);
		for (int i=1;i<=n;i++) if (a[i]!=b[i])
		{
			printf("NOT POSSIBLE\n");return;
		}
		cout<<ans<<"\n";
	}
	else
	{
		memcpy(c,a,sizeof(a));
		memcpy(d,b,sizeof(b));
		LL ans=L+1;
		bool cd;
		for (int i=1;i<=n;i++)
		{
			cd=true;
			memcpy(a,c,sizeof(a));
			memcpy(b,d,sizeof(b));
			memset(change,0,sizeof(change));
			swap(a[i],a[1]);
			LL tans=0;
			LL convert=0;
			convert=a[1]^b[1];
			for (int j=0;j<L;j++) if (((a[1]>>j)&1)!=((b[1]>>j)&1)) tans++,change[j]++;
			for (int j=1;j<=n;j++) a[j]^=convert;
			LL tconvert=0;
			for (int k=0;k<L;k++)
			{
				int cnt=0;
				for (int j=2;j<=n;j++) if ((a[j]>>k)&1) cnt++;
				int snt=0;
				for (int j=2;j<=n;j++) if ((b[j]>>k)&1) snt++;
				if (snt!=cnt) tconvert^=1ll<<k,tans++,change[k]++;
			}
			for (int j=1;j<=n;j++) a[j]^=tconvert;
			sort(a+1,a+n+1);
			sort(b+1,b+n+1);
			for (int j=1;j<=n;j++)
			if (a[j]!=b[j])
			{
				cd=false;break;
			}
			if (cd)
			ans=min(ans,tans);
		}
		if (ans==L+1)
		printf("NOT POSSIBLE\n");
		else cout<<ans<<"\n";
	}
}
int main()
{
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	scanf("%d",&times);
	for (int i=1;i<=times;i++)
	work(i);
	return 0;
}
