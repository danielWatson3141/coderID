#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
long long a[200],b[200];
int n,l,t,ans;
long long getnum()
{
	char ch[100];
	scanf("%s",ch);
	long long ret=0;
	for(int i=0;ch[i];++i)
		ret=ret<<1|(ch[i]-'0');
	return ret;
}


void init()
{
	scanf("%d%d",&n,&l);
	for(int i=0;i<n;++i) a[i]=getnum();
	for(int i=0;i<n;++i) b[i]=getnum();
}

int ct(long long op)
{
	int ret=0;
	for(int i=0;i<60;++i)
	{
		if((1LL<<i)&op) ++ret;
	}
	return ret;
}

int check(int op)
{
	map<long long ,int> mp;
	for(int i=0;i<n;++i)
	{
		mp[a[i]^op]++;
		mp[b[i]]--;
	}
	for(map<long long,int>::iterator it=mp.begin();it!=mp.end();++it) if(it->second!=0) return 1000;
	return ct(op);
}

int ca=1;
void solve()
{
	ans=10000;
	for(int i=0;i<n;++i) ans=min(ans,check(a[0]^b[i]));
	printf("Case #%d: ",ca++);
	if(ans==1000) puts("NOT POSSIBLE");
	else printf("%d\n",ans);
}
int main()
{
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		init();
		solve();
	}
}
