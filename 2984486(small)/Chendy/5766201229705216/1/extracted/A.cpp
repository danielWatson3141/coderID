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
struct edge
{
	int x,y;
}e[2010];
int pos[1010],next[2010],fa[1010],sum[1010],ch[1010][1010];
struct pp
{
	int v,p;
}dp[1010][1010];
bool cmp(pp x,pp y)
{
	return x.v<y.v;
}
void add(int x,int y)
{
	next[++cnt]=pos[x];pos[x]=cnt;
	e[cnt].x=x;e[cnt].y=y;
}
void dfs(int x)
{
	sum[x]=1;
	for (int i=pos[x];i;i=next[i])
	if (e[i].y!=fa[x])
	{
		fa[e[i].y]=x;
		dfs(e[i].y);
		sum[x]+=sum[e[i].y];
	}
}
int calc(int x)
{
	int cnt=0;
	for (int i=pos[x];i;i=next[i])
	if (e[i].y!=fa[x])
	{
		cnt++;
		ch[x][cnt]=e[i].y;	
	}
	if (cnt==1) return sum[ch[x][1]];
	else if (cnt==2) return calc(ch[x][1])+calc(ch[x][2]);
	else if (cnt>2) 
	{
		int total=0;
		for (int i=1;i<=cnt;i++) total+=sum[ch[x][i]],dp[x][i].v=calc(ch[x][i])-sum[ch[x][i]],dp[x][i].p=i;
		sort(dp[x]+1,dp[x]+cnt+1,cmp);
		return total+dp[x][1].v+dp[x][2].v;
	}
	return 0;
}
void work(int lab)
{
	printf("Case #%d: ",lab);
	memset(pos,0,sizeof(pos));
	memset(next,0,sizeof(next));
	cnt=0;
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	int ans=n+1;
	for (int rt=1;rt<=n;rt++)
	{
		memset(fa,0,sizeof(fa));
		memset(sum,0,sizeof(sum));
		dfs(rt);
		ans=min(ans,calc(rt));
	}
	printf("%d\n",ans);
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
