#include<iostream>
#include<cstdio>
using namespace std;

const int maxn=150;
const int maxm=41;
int n,m,ca,num;
string str1[maxn],str2[maxn];
long long a[maxn],b[maxn],c[maxn],d[maxn];
long long get(string &st)
{
	long long ret=0;
	for (int i=m-1; i>=0; i--) ret=ret+1LL*((st[i]-'0')<<(m-1-i));
	return ret;
}
void solve()
{
	for (int i=0; i<n; i++) a[i]=get(str1[i]);
	for (int i=0; i<n; i++) b[i]=get(str2[i]);
	int ans=m+1;
	for (int i=0; i<n; i++)
	{
		bool pp=true;
		for (int j=0; j<n; j++)
		{
			c[j]=a[0]^b[i]^a[j];
			d[j]=b[j];
		}
		sort(c,c+n);
		sort(d,d+n);
		for (int j=0; j<n; j++)
			if (c[j]!=d[j]) pp=false;

		if (pp)
		{
			int ret=0;
			for (int j=0; j<m; j++)
				if (str1[0][j]!=str2[i][j]) ++ret;
			ans=min(ans,ret);
		}
	}
	printf("Case #%d: ",++ca);
	if (ans==m+1) printf("NOT POSSIBLE\n"); else printf("%d\n",ans);
}
void init()
{
	scanf("%d",&num);
	while (num--)
	{
		scanf("%d%d",&n,&m);
		for (int i=0; i<n; i++) cin>>str1[i];
		for (int i=0; i<n; i++) cin>>str2[i];
		solve();
	}
}
int main()
{
	init();
	return 0;
}
