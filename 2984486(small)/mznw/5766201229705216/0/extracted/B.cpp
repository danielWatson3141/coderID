#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxN=1000+13;
const int maxE=3000+13;

struct Arc
{
  int dest;
  Arc *next;
  Arc(){};
  Arc(int dest,Arc* next):dest(dest),next(next){};
}Npool[maxE],*Nptr(Npool);

Arc *adj[maxN];
int s[maxN],d[maxN];
int f[maxN],g[maxN];
int c[maxN];
bool v[maxN];
int T,N;

template <typename t>
inline void upd_min(t &dest,t src){if(dest>src)dest=src;return ;}

inline void add_edge(int s,int t)
{
  adj[s]=new (Nptr++) Arc(t,adj[s]);
  adj[t]=new (Nptr++) Arc(s,adj[t]);
}

void reset()
{
  Nptr=Npool;
  for(int i=1;i<=1000;i++)
    adj[i]=NULL;
  memset(s,0,sizeof(s));
  memset(d,0,sizeof(d));
}

void dfs(int id)
{
  v[id]=1;
  int tt=1;
  for(Arc *p=adj[id];p;p=p->next)
  {
    if(!v[p->dest])
    {
      d[p->dest]=d[id]+1;
      dfs(p->dest);
      tt+=c[p->dest];
    }
  }
  c[id]=tt;
  return;
}

void dp(int id)
{
  f[id]=c[id]-1;
  int tc[maxN],ind=0;
  for(Arc *p=adj[id];p;p=p->next)
  {
    if(d[p->dest]-d[id]==1)
    {
      ind++;
      tc[ind]=p->dest;
    }
  }
  if(ind<=1)
    return ;
  for(Arc *p=adj[id];p;p=p->next)
    if(d[p->dest]-d[id]==1)
      dp(p->dest);
  if(ind==2)
  {
    f[id]=0;
    for(Arc *p=adj[id];p;p=p->next)
      if(d[p->dest]-d[id]==1)
        f[id]+=f[p->dest];
    return ;
  }
  for(int i=2;i<=ind;i++)
  {
    for(int j=1;j<i;j++)
    {
      int tt=0;
      int ti=tc[i],tj=tc[j];
      tt=f[ti]+f[tj];
      for(int k=1;k<=ind;k++)
        if(tc[k]!=ti && tc[k]!=tj)
          tt+=c[tc[k]];
      upd_min(f[id],tt);
    }
  }
  return ;
}

int treeDP(int rn)
{
  memset(v,0,sizeof(v));
  memset(f,0,sizeof(f));
  memset(c,0,sizeof(c));
  d[rn]=1;
  dfs(rn);

  dp(rn);
//  cout<<rn<<endl;
//  for(int i=1;i<=N;i++)
//    cout<<i<<' '<<d[i]<<' '<<c[i]<<' '<<f[i]<<endl;
  return f[rn];
}


int main()
{
  freopen("B.in","r",stdin);
  freopen("B.out","w",stdout);
  scanf("%d",&T);
  for(int ca=1;ca<=T;ca++)
  {
    scanf("%d",&N);
    reset();
    for(int i=1;i<N;i++)
    {
      int ts,td;
      scanf("%d%d",&ts,&td);
      add_edge(ts,td);
      s[ts]++;s[td]++;
    }
    int ans=N-1;
    for(int i=1;i<=N;i++)
      upd_min(ans,treeDP(i));
    printf("Case #%d: %d\n",ca,ans);
  }
  return 0;
}

