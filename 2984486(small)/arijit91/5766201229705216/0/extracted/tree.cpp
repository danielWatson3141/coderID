#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <climits>
#include <limits>
using namespace std;
//Macros
#define SIZE(A) ((int)(A.size()))
#define SET(A,x) memset(A,x,sizeof(A));                 //NOTE: Works only for x = 0 and -1. Only for integers.
#define FILL(A,x) fill(A.begin(),A.end(),x)
#define REP(i,N) for(int i=0;i<(int)(N);i++)
#define FOR(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define REV(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define TR(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ALL(x)  x.begin(),x.end()
#define INF (INT_MAX/2)
#define LLINF (LONG_LONG_MAX/2LL)
#define EPS 1e-11
#define GI ({int t;scanf("%d",&t);t;})                  //NOTE: Don't comma separate two inputs.
#define GL ({long long t;scanf("%lld",&t);t;})          //NOTE: Don't comma separate two inputs.
#define GF ({double t;scanf("%lf",&t);t;})              //NOTE: Don't comma separate two inputs.
#define MP make_pair
#define PB push_back
#define gcd(a,b) __gcd(a,b)                             //NOTE: Both the arguments should be of the same type.
#define nbits(n) __builtin_popcount(n)                  //NOTE: Works only for int. Write your own function for long long :-/
#define MOD 1000000007
#define MAXN 1000005
#define FIX(a) (((a)%MOD+MOD)%MOD)
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> pii;
#define SUBMIT false                                    //NOTE: Set this to true before submitting
#define   debug(x)              if(!SUBMIT){ cout<<"-> "<<#x<<" = "<<x<<"\n";}
#define   debugv(x)             if(!SUBMIT){ cout<<"-> "<<#x<<" =\n";REP(i,SIZE(x))cout<<x[i]<<" ";cout<<"\n";}
#define   debugvv(x)            if(!SUBMIT){ cout<<"-> "<<#x<<" =\n";REP(i,SIZE(x)){REP(j,SIZE(x[i])){cout<<x[i][j]<<" ";}cout<<"\n";}}
#define   debug1(A,N)           if(!SUBMIT){ cout<<"-> "<<#A<<" =\n";REP(i,N)cout<<A[i]<<" ";cout<<"\n";}
#define   debug2(A,R,C)         if(!SUBMIT){ cout<<"-> "<<#A<<" =\n";REP(i,R){REP(j,C){cout<<A[i][j]<<" ";}cout<<"\n";}}

vector<vector<int> > adj, child;
int f[1005];
int g[1005];
int h[1005];
int vis[1005];

int sol_f (int);
int sol_h (int);

int sol_g (int v) {
  int &ret = g[v];
  if (ret != -1) return ret;
  ret = 0;
  REP (i, child[v].size ()) {
    ret = max (ret, sol_f (child[v][i]));
  }
  return ret;
}

int sol_h (int v) {
  int &ret = h[v];
  if (ret != -1) return ret;
  ret = 1;
  REP (i, child[v].size()) {
    REP (j, i) {
      ret = max (ret, 1 + sol_h (child[v][i]) + sol_h (child[v][j]));
    }
  }
  return ret;
}

int sol_f (int v) {
  int &ret = f[v];
  if (ret != -1) return ret;
  ret = 1;
  ret = max (ret, sol_g (v));
  ret = max (ret, sol_h (v));
  //REP (i, child[v].size()) {
  //  REP (j, i) {
  //    ret = max (ret, 1 + sol_f (child[v][i]) + sol_f (child[v][j]));
  //  }
  //}
  return ret;
}

void dfs (int v) {
  vis[v] = 1;
  REP (i, adj[v].size ()) {
    int y = adj[v][i];
    if (!vis[y]) {
      child[v].push_back (y);
      dfs (y);
    }
  }
}

//Main code starts here
int main()
{
  int t = GI;
  FOR (cas, 1, t) {
    int ans = 0;
    int n = GI;
    adj.clear (); adj.resize (n);
    REP (i, n-1) {
      int a, b;
      a = GI; b = GI;
      adj[a-1].push_back (b-1);
      adj[b-1].push_back (a-1);
    }
    int max_comp = 0;
    FOR (i, 1, n) {
      memset (f, -1, sizeof(f));
      memset (g, -1, sizeof(g));
      memset (h, -1, sizeof(h));
      memset (vis, 0, sizeof(vis));
      child.clear (); child.resize (n);
      dfs (i - 1);
      //REP (j, n) cout<<child[j].size()<<endl;
      max_comp = max (max_comp, sol_f (i - 1));
    }
    assert (1 <= max_comp && max_comp <= n);
    printf("Case #%d: %d\n", cas, n - max_comp);
  }
	return 0;
}
