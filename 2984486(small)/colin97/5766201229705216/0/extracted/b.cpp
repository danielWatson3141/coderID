#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
#include<string>
#include<ctime>
#include<cmath>
#include<utility>
#include<set>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>
#define INF 1111111111
#define N 1111
#define eps 1e-9
using namespace std;
typedef long long LL;
int getint()
{
	char ch;
	do
	{
		ch=getchar();
	}while (ch!='-'&&(ch<'0'||ch>'9'));
	int ans=0,f=0;
	if (ch=='-') f=1; else ans=ch-'0';
	while (isdigit(ch=getchar())) ans=ans*10+ch-'0';
	if (f) ans*=-1;
	return ans;
}
struct edge
{
	int t,n;
}e[N*2];
int tmp[N],size[N],f[N],h[N];
int tote;
void adde(int f,int t)
{
	e[++tote].t=t;
	e[tote].n=h[f];
	h[f]=tote;
	return ;
}
void dp(int u,int fa)
{
	int cnt=0; size[u]=1; f[u]=0;
	for (int i=h[u];i;i=e[i].n)
	{
		int v=e[i].t;
		if (v==fa) continue;
		dp(v,u);
		size[u]+=size[v];
		f[u]+=size[v];
		cnt++;
	}
	if (cnt<2) return;
	tmp[0]=0;
	for (int i=h[u];i;i=e[i].n)
	{
		int v=e[i].t;
		if (v==fa) continue;
		tmp[++tmp[0]]=f[v]-size[v];
	}
	sort(&tmp[1],&tmp[cnt+1]);
	f[u]+=tmp[1]+tmp[2];
	return ;
}
void solve(int id)
{
	int n=getint(); tote=0;
	for (int i=1;i<=n;i++) h[i]=0;
	for (int i=1;i<n;i++)
	{
		int u=getint(),v=getint();
		adde(u,v); adde(v,u);
	}
	int ans=INF;
	for (int i=1;i<=n;i++)
	{
		memset(f,0,sizeof(f));
		memset(size,0,sizeof(size));
		dp(i,i);
		ans=min(ans,f[i]);
	}
	printf("Case #%d: %d\n",id,ans);
}
int main()
{
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
	int test=getint();
	for (int i=1;i<=test;i++) solve(i);
	return 0;
}

