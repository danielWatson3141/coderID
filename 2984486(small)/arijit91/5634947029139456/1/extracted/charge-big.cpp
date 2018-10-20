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

//Main code starts here
string a[155], b[155], c[155];
int n, l;

string join (char ch) {
  vector<string> v;
  REP (i, n) {
    if (ch == 'a') {
      v.push_back (a[i]);
    }
    if (ch == 'b') {
      v.push_back (b[i]);
    }
    if (ch == 'c') {
      v.push_back (c[i]);
    }
  }
  sort (ALL(v));
  string ret = "";
  REP (i, n) {
    ret += v[i];
  }
  return ret;
}

int main()
{
  int t = GI;
  FOR (cas, 1, t) {
    n = GI; l = GI;
    int ans = 1000;
    string S, T;
    REP (i, n) { cin>>a[i]; }
    REP (i, n) { cin>>b[i]; }
    bool flag = false;
    S = join ('b');

    REP (i, n) {
      vector<int> flips;
      REP (j, l) {
        if (a[0][j] != b[i][j]) {
          flips.push_back (j);
        }
      }
      REP (j, n) c[j] = a[j];
      int num_flips = flips.size ();
      REP (j, num_flips) {
        int col = flips[j];
        REP (k, n) {
          c[k][col] = (48 + 49 - c[k][col]);
        }
      }
      T = join ('c');
      if (S == T) {
        flag = true;
        ans = min (ans, num_flips);
      }
    }

    printf("Case #%d: ", cas);
    if (flag) {
      cout<<ans<<endl;
    }
    else {
      cout<<"NOT POSSIBLE\n";
    }
  }
	return 0;
}
