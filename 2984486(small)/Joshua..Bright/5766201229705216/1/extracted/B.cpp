#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
const int oo=1073741819;
using namespace std;
int f[200000],g[200000];
int tail[500000],next[500000],sora[500000];
int n,ss,st[500000];
void dfs(int x,int y)
{
	f[x]=oo,g[x]=1;
	for (int i=x,ne;next[i];) {
		i=next[i],ne=sora[i];
		if (ne!=y) dfs(ne,x),g[x]+=g[ne];
	}
	int r=0,sum=0;
	for (int i=x,ne;next[i];) {
		i=next[i],ne=sora[i];
		if (ne!=y) st[++r]=ne,sum+=g[ne];
	}
	if (r==1) {
		f[x]=sum;
		return ;
	}
	else if (r==0) {
		f[x]=0;
		return ;
	}
	int Min1=oo,Min2=oo;
	for (int i=1;i<=r;i++)
		if (f[st[i]]-g[st[i]]<=Min1) Min2=Min1,Min1=f[st[i]]-g[st[i]];
		else if (f[st[i]]-g[st[i]]<Min2) Min2=f[st[i]]-g[st[i]];
	f[x]=sum+Min1+Min2;
}
void origin()
{
	ss=n;
	for (int i=1;i<=n;i++) tail[i]=i,next[i]=0;
}
void link(int x,int y)
{
	++ss,next[tail[x]]=ss,tail[x]=ss,sora[ss]=y,next[ss]=0;
	++ss,next[tail[y]]=ss,tail[y]=ss,sora[ss]=x,next[ss]=0;
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	cin>>T;
	for (int Case=1;T;T--,Case++) {
		printf("Case #%d: ",Case);
		scanf("%d",&n);
		origin();
		for (int i=1;i<=n-1;i++) {
			int x,y;
			scanf("%d%d",&x,&y);
			link(x,y);
		}
		int ans=oo;
		for (int i=1;i<=n;i++) {
			dfs(i,0);
			ans=min(ans,f[i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}
