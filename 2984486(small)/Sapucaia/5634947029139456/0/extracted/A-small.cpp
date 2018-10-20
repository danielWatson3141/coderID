#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f

#define rep0(i,n) for(int i = 0;i < (int)n;i++)
#define rep1(i,n) for(int i = 1;i <= (int)n;i++)
#define per0(i,n) for(int i = (int)n-1;i >= 0;i--)
#define per1(i,n) for(int i = (int)n ;i >= 1;i--)

#define pb push_back
#define fill(d,v) memset(d,v,sizeof(d))

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<pii> vii;
#define MAX_N 11
string outlets[MAX_N];
string devices[MAX_N];

int main()
{
  int T;
  scanf(" %d",&T);
  int N,L;
  for(int t = 1; t <= T;t++)
    {
      cin >> N >> L;
      for(int i = 0; i < N;i++)
	cin >> outlets[i];
      for(int i = 0; i < N;i++)
	cin >> devices[i];
      
      int ans = L+1;
      //masks
      for(int m = 0; m < (1<<L);m++)
	{
	  //outlets
	  bool ok = true;
	  for(int i = 0; i < N && ok;i++)
	    {
	      //devices
	      bool match = true;
	      for(int j = 0; j < N;j++)
		{
		  match = true;
		  for(int k = 0,p = 1; k < L && match; k++,p <<= 1)
		    {
		      if( ((m&p) == 0 && (outlets[i][k] != devices[j][k])) || ((m&p) != 0 && (outlets[i][k] == devices[j][k])))
			{
			  match = false;
			}
		      
		    }
		  if(match)
		    break;
		}
	      if(!match)
		ok = false;
	    }
	  if(ok)
	    {
	      int curAns = 0;
	      for(int k = 0,p = 1; k < L; k++,p <<= 1)
		if((m&p)!=0)
		  curAns++;
	      ans = min(ans,curAns);
	    }
	}
      printf("Case #%d: ",t);
      if(ans == L+1)
	printf("NOT POSSIBLE\n");
      else
	printf("%d\n",ans);
    }

  return 0;
}
