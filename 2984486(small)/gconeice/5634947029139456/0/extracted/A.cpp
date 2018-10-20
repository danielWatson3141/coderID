#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>

using namespace std;

int T;
string s;
const int N=151;
long long a[N],aa[N];
long long b[N],bb[N];
int n,l;
int c[41];

int main()
{
  freopen("A.in","r",stdin);
  freopen("A.out","w",stdout);
  cin >>T;
  for (int ii=1;ii<=T;ii++)
    {
      cin >>n >>l;
      for (int i=1;i<=n;i++)
	{
	  cin >>s;
	  long long tmp=0;
	  for (int j=0;j<l;j++) tmp=tmp*2+(s[j]-'0');
	  a[i]=tmp;
	}
      for (int i=1;i<=n;i++)
	{
	  cin >>s;
	  long long tmp=0;
	  for (int j=0;j<l;j++) tmp=tmp*2+(s[j]-'0');
	  b[i]=tmp;
	}
      int ans=N;
      sort(a+1,a+n+1);
      for (int i=1;i<=n;i++)
	{
	  for (int j=1;j<=n;j++) bb[j]=b[j];
	  long long tmp=a[1]^b[i];
	  for (int j=1;j<=n;j++) bb[j]^=tmp;
	  sort(bb+1,bb+n+1);
	  bool check=1;
	  for (int j=1;j<=n;j++)
	    {
	      if (a[j]==bb[j]) continue;
	      check=0; break;
	    }
	  if (check==0) continue;
	  int tt=0;
	  while (tmp>0)
	    {
	      tt+=tmp%2;
	      tmp>>=1;
	    }
	  ans=min(ans,tt);
	}
      if (ans==N) printf("Case #%d: NOT POSSIBLE\n",ii);
      else printf("Case #%d: %d\n",ii,ans);
    }
  return 0;
}
