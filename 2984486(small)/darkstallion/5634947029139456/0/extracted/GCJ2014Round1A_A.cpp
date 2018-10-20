//darkstallion's template

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<map>
#include<list>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#include<cmath>
#include<string>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define popb pop_back
#define del erase
#define sz size
#define ins insert
#define FOR(a,b,c) for(int a = b; a < c; a++)
#define FORS(a,b,c) for(int a = b; a <= c; a++)
#define FORN(a,b) for(int a = 0; a < b; a++)
#define FORD(a,b,c) for (int a = b; a >= c; a--)
#define RES(a,b) memset(a,b,sizeof(a))
#define LL long long
#define PII pair<int,int>
#define PLL pair<long long,long long>
#define PDD pair<double,double>
#define PCC pair<char,char>
#define PSS pair<string,string>
#define PI acos(-1)
#define eps 1e-9
using namespace std;

int n,l,ans;
vector<string>out,dev;

bool dfs(int i, int flip)
{
  if (i == l)
  {
    ans = min(ans,flip);
    return true;
  }
  // not flipped
  bool sama = true;
  FORN(j,n)
    if (sama)
      FORN(k,i+1)
        if (out[j][k] != dev[j][k])
        {
          sama = false;
          break;
        }
  bool ret = false;
  if (sama)
    ret |= dfs(i+1,flip);
  // flipped
  sama = true;
  FORN(j,n)
    if (out[j][i] == '1')
      out[j][i] = '0';
    else
      out[j][i] = '1';
  sort(out.begin(),out.end());
  FORN(j,n)
    if (sama)
      FORN(k,i+1)
        if (out[j][k] != dev[j][k])
        {
          sama = false;
          break;
        }
  if (sama)
    ret |= dfs(i+1,flip+1);
  FORN(j,n)
    if (out[j][i] == '1')
      out[j][i] = '0';
    else
      out[j][i] = '1';
  sort(out.begin(),out.end());
  return ret;
}

int main()
{
  int t;
  scanf("%d",&t);
  FORN(i,t)
  {
    scanf("%d%d",&n,&l);
    out.clear();
    dev.clear();
    FORN(j,n)
    {
      string st;
      cin >> st;
      out.pb(st);
    }
    FORN(j,n)
    {
      string st;
      cin >> st;
      dev.pb(st);
    }
    sort(out.begin(),out.end());
    sort(dev.begin(),dev.end());
    ans = l;
    if (dfs(0,0))
      printf("Case #%d: %d\n",i+1,ans);
    else
      printf("Case #%d: NOT POSSIBLE\n",i+1);
  }
}