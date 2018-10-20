#include <iostream>
#include <cstdio>
#include <deque>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
using namespace std; 

const int N=300;
const int INF = 100000000;
typedef long long LL;

int n, l;
LL a[N], b[N];
int ans;

int exp(LL x)
{
	int ret=0; 
	LL tx=x;
	while (tx!=0)
	{
		if (tx%2==1) ++ret;
		tx/=2;
	}
	return ret;
}

void init()
{
	scanf("%d%d", &n, &l);
	for (int i=1; i<=n; ++i)
	{
		char st[50];
		scanf("%s", &st);
		a[i]=0;
		for (int j=0; j<l; ++j)
			a[i]=a[i]*2ll+LL(st[j]-'0');
	}
	for (int i=1; i<=n; ++i)
	{
		char st[50];
		scanf("%s", &st);
		b[i]=0;
		for (int j=0; j<l; ++j)
			b[i]=b[i]*2ll+LL(st[j]-'0');
	}
}

multiset<LL> cset;
multiset<LL> dset;

bool check(LL x)
{
	cset.clear();
	for (int i=1; i<=n; ++i)
		cset.insert(a[i]^x);
	multiset<LL>::iterator itc, itd; 
	for (itc=cset.begin(), itd=dset.begin(); itc!=cset.end() && itd!=dset.end(); ++itc, ++itd)
		if ((*itc)!=(*itd)) return 0;
	return 1;
}

void cal()
{
	ans=INF;
	cset.clear();
	dset.clear();
	for (int i=1; i<=n; ++i)
		dset.insert(b[i]);
	for (int i=1; i<=n; ++i)
		for (int j=1; j<=n; ++j)
		{
			LL tmp=a[i]^b[j];
			int tt=exp(tmp);
			if (check(tmp) && ans > tt)
				ans =  tt;
		}
	if (ans >= INF) 
		printf("NOT POSSIBLE\n");
	else printf("%d\n", ans);
}

int main()
{
//	freopen("aa.in","r",stdin);
//	freopen("aa.out","w",stdout);
	int cas;
	scanf("%d", &cas);
	for (int k=1; k<=cas; ++k)
	{
		printf("Case #%d: ", k);
		init();
		cal();
	}
	return 0;
}
