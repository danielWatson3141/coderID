#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>

using namespace std;

const int N=1010;
int size[N];
int n,T;
struct Point
{
  int next;
  void init() {next=-1;}
}P[N];
struct Edge
{
  int to,next;
}E[N*2];
int Enum;
bool check[N];
int f[N];

void Ins(int from,int to)
{
  Enum++;
  E[Enum].to=to; E[Enum].next=P[from].next; P[from].next=Enum;
}

void dfs(int now)
{
  check[now]=1;
  f[now]=0;
  size[now]=1;
  int tt[N],tnum=0;
  for (int p=P[now].next;p!=-1;p=E[p].next)
    {
      if (check[E[p].to]) continue;
      dfs(E[p].to);
      size[now]+=size[E[p].to];
      tt[++tnum]=E[p].to;
    }
  int aa; aa=size[now]-1;
  if (tnum==0)
    {
      check[now]=0;
      return;
    }
  for (int i=1;i<=tnum;i++)
    for (int j=i+1;j<=tnum;j++)
      {
	int tmp=f[tt[i]]+f[tt[j]];
	for (int k=1;k<=tnum;k++)
	  {
	    if (k==i||k==j) continue;
	    tmp+=size[tt[k]];
	  }
	aa=min(aa,tmp);
      }
  f[now]=aa;
  check[now]=0;
}

int main()
{
  freopen("B.in","r",stdin);
  freopen("B.out","w",stdout);
  scanf("%d",&T);
  for (int ii=1;ii<=T;ii++)
    {
      scanf("%d",&n);
      for (int i=1;i<=n;i++) P[i].init();
      Enum=-1;
      for (int i=1;i<n;i++)
	{
	  int x,y;
	  scanf("%d%d",&x,&y);
	  Ins(x,y); Ins(y,x);
	}
      int ans=N;
      for (int i=1;i<=n;i++) //root
	{
	  
	  dfs(i);
	  ans=min(ans,f[i]);
	}
      printf("Case #%d: %d\n",ii,ans);
    }
  return 0;
}
