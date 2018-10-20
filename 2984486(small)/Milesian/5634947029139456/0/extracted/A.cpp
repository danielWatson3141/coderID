#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <ctime>
#include <cmath>
#define rep(i,n) for(int i=1;i<=n;++i)
#define ll long long
using namespace std;
int a[202][52],b[202][52];
int l;
int f[51][2];
ll sa[202],sb[202];
bool match[202];
int T,n,ans;
int check(int x)
{
	memset(match,0,sizeof(match));
	rep(i,l)
	{
		if(a[1][i]==b[x][i])
		{
			f[i][1]=1;
			f[i][0]=0;
		}else
		{
			f[i][1]=0;
			f[i][0]=1;
		} 
		//f[i][a[1][i]^1]=b[x][i]^1;
	}
	rep(i,n)
	{
		sa[i]=0;
		rep(j,l)
		{
			sa[i]*=2;
			sa[i]+=f[j][a[i][j]];
		}
	}
//	printf("%lld %lld %d %d \n",sa[1],sb[1],f[2][0],f[2][1]);
	rep(i,n)
	{
		bool flag=false;
		rep(j,n)
		{
			if(sa[i]==sb[j]&&(!match[j]))
			{
				match[j]=1;
				flag=true;
				break;
			}
		}
		if(!flag)return l+1;
	}
	int y=0;
	rep(i,l)if(f[i][0]!=0)++y;
	return y;
}
int get()
{
	char t=getchar();
	while(t<'0'||t>'9')t=getchar();
	int x=0;
	while(t>='0'&&t<='9')
	{
		x*=10;
		x+=t-'0';
		t=getchar();
	}
	return x; 
}
int main()
{
//	freopen("A.in","r",stdin);
//	freopen("A.out","w",stdout);
	
	scanf("%d",&T);
	rep(ii,T) 
	{
	//	scanf("%d%d",&n,&l);
		n=get();
		l=get();
	//	printf("%d %d\n",n,l);
		rep(i,n)rep(j,l)
		{
			char t=getchar();
			while(t<'0'||t>'1')t=getchar();
			if(t=='0')a[i][j]=0;else a[i][j]=1;
		//	printf("%d",a[i][j]);
		//	if(j==l)printf("\n");
		}
		rep(i,n)rep(j,l)
		{
			char t=getchar();
			while(t<'0'||t>'1')t=getchar();
			if(t=='0')b[i][j]=0;else b[i][j]=1;
		//	printf("%d",b[i][j]);
		//	if(j==l)printf("\n");
		}	
		rep(i,n)
		{
			sb[i]=0;
			rep(j,l)
			{
				sb[i]*=2; 
				sb[i]+=b[i][j];
			}
		}
		ans=l+1;
		rep(i,n)ans=min(ans,check(i));
		if(ans>l)printf("Case #%d: NOT POSSIBLE\n",ii);else printf("Case #%d: %d\n",ii,ans);
	}
	return 0;
}			