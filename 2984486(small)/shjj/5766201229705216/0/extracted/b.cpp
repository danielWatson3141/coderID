//shjj-B

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

const int N=1000;
int go[N*2+3],t[N*2+3],last[N+3],q[N+3],s[N+3],f[N+3],fa[N+3],n,en,ans;
void add(int u,int v){go[++en]=v;t[en]=last[u];last[u]=en;}
void Bfs(int w)
{
memset(f,130,sizeof(f));
memset(fa,0,sizeof(fa));
q[1]=w;fa[w]=-1;
for (int l=0,r=1;l<r;)
  for (int i=last[q[++l]];i;i=t[i])
    if (!fa[go[i]]) q[++r]=go[i],fa[go[i]]=q[l];
for (int i=n;i>=1;i--)
  {
  int x=q[i],Max1=0,Max2=0;s[x]=1;
  for (int j=last[x];j;j=t[j])
    if (fa[go[j]]==x)
	  {
	  int to=go[j];
	  s[x]+=s[to];
	  if (f[to]>Max1) Max2=Max1,Max1=f[to];
		else if (f[to]>Max2) Max2=f[to];
	  }
  if (!Max2) f[x]=1;
    else f[x]=Max1+Max2+1;
  }
ans=max(ans,f[w]);
}

int main()
{
freopen("B.in","r",stdin);
freopen("B.out","w",stdout);
int Test,tt=0;scanf("%d",&Test);
for (;Test--;)
  {
  scanf("%d",&n);
  memset(last,0,sizeof(last));en=0;
  for (int i=1;i<n;i++)
    {
	int u,v;scanf("%d%d",&u,&v);
	add(u,v);add(v,u);
	}
  ans=0;
  for (int i=1;i<=n;i++) Bfs(i);
  printf("Case #%d: %d\n",++tt,n-ans);
  }
}