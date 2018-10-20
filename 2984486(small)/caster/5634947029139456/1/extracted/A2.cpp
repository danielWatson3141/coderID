#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int MAXN = 155,MAXL = 45;

typedef unsigned long long ull;

ull device[MAXN],outlet[MAXN],tmp[MAXN];

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

int ans,N,L;

bool match(int k)
{
  sort(device,device + N);
  for(int i = 0; i < N; i++)
    if ((device[i] ^ outlet[i]) >> k) 
      return false;
  return true;
}

void search(int k,int c)
{
  if (k == -1)
    {
      ans = min(ans,c);
    }
  else if (c < ans)
    {
      if (match(k))
	search(k - 1,c);

      for(int i = 0; i < N; i++) device[i] ^= (ull(1) << k);
      if (match(k))
	search(k - 1,c + 1);
      for(int i = 0; i < N; i++) device[i] ^= (ull(1) << k);
    }
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
      
      for(int i = 0; i < n; i++) outlet[i] = readBin(l);
      for(int i = 0; i < n; i++) device[i] = readBin(l);
      sort(device,device + n);
      sort(outlet,outlet + n);
      
      ans = l + 1;
      N = n,L = l;
      search(l - 1,0);

      if (ans <= l) printf("%d\n",ans);
      else puts("NOT POSSIBLE");
    }
  return 0;
}
