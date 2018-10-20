#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>

using namespace std;

template <typename t>
inline void upd_min(t &dest,t src){if(dest>src)dest=src;return ;}

int T,N,L;
char s[100];
long long is[200],ds[200];
long long f[200][200];
map<long long ,int>hash;

long long calc(char* s)
{
  long long ret=0ll;
  long long tt=1ll;
  for(int i=0;i<L;i++)
  {
    if(s[i]-'1'==0)
      ret+=tt;
    tt<<=1;
  }
//  cout<<ret<<endl;
  return ret;
}

int check(long long n)
{
  int ret=0;
  while(n)
  {
    if(n&1ll)
      ret++;
    n>>=1;
  }
  return ret;
}

int ans=0;

int main()
{
  freopen("A.in","r",stdin);
  freopen("A.out","w",stdout);

  scanf("%d",&T);
  for(int ca=1;ca<=T;ca++)
  {
    scanf("%d%d",&N,&L);
    ans=L+3;
    for(int i=1;i<=N;i++)
    {
      scanf("%s",s);
      is[i]=calc(s);
    }
    for(int i=1;i<=N;i++)
    {
      scanf("%s",s);
      ds[i]=calc(s);
    }
    hash.clear();
    for(int i=1;i<=N;i++)
      for(int j=1;j<=N;j++)
        f[i][j]=is[i]^ds[j];
    for(int i=1;i<=N;i++)
      for(int j=1;j<=N;j++)
        if(++hash[f[i][j]]==N)
          upd_min(ans,check(f[i][j]));
    if(ans!=L+3)
      printf("Case #%d: %d\n",ca,ans);
    else
      printf("Case #%d: NOT POSSIBLE\n",ca);
  }
  return 0;
}


