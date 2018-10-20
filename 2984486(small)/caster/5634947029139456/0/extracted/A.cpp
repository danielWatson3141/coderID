#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int MAXN = 155,MAXL = 45;

typedef unsigned int ull;
//typedef unsigned long long ull;

ull device[MAXN],outlet[MAXN];

ull readBin(int len)
{
  static char str[MAXL];
  scanf("%s",str);
  
  ull res = 0;
  for(int i = 0; i < len; i++)
    {
      res = (res << 1) | (str[i] - '0');
    }
  return res;
}

int main()
{
  int t;
  scanf("%d",&t);

  for(int case_num = 1; case_num <= t; case_num++)
    { 
      printf("Case #%d: ",case_num);

      int n,l;
      scanf("%d%d",&n,&l);  
      int ans = l + 1;
      for(int i = 0; i < n; i++) outlet[i] = readBin(l);
      for(int i = 0; i < n; i++) device[i] = readBin(l);
      sort(device,device + n);

      ull range = 1;
      range <<= l;

      for(ull m = 0,prem = 0; m < range; prem = m,m++)
	{
	  bool flag = true;

	  prem ^= m;
	  for(int i = 0; i < n; i++) outlet[i] ^= prem;

	  sort(outlet,outlet + n);
	  for(int i = 0; i < n; i++) 
	    if (outlet[i] != device[i]) 
	      {
		flag = false;
		break;
	      }

	  if (flag)
	    {
	      int c = 0;
	      for(int i = 0; i < l; i++)
		if ((m >> i) & 1) ++c;
	      //printf("%d %d\n",m,c);
	      ans = min(ans,c);
	    }
	}

      if (ans <= l) printf("%d\n",ans);
      else puts("NOT POSSIBLE");
    }
  return 0;
}
