/*
#ifdef ONLINE_JUDGE
#pragma comment(linker, "/STACK:16777216")
#endif
*/
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <time.h>
#include <vector>
// #include <sys/time.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define sz(x) ((int)(x).size())
#define x first
#define y second
#define fi(n) fo(i, n)
#define fj(n) fo(j, n)
#define fk(n) fo(k, n)
#define fd(i,n) for(int i=(int)(n)-1;i>=0;--i)
#define fo(i,n) fr(i,0,n)
#define fr(i,a,b) for(int i=(int)(a); i<(int)(b); i++)
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define srt(x) sort(all(x))
//#define lgLowestBit(x) __builtin_ctz(x)
//#define bitCount(x) __builtin_popcount(x)
//#define foreach(it, a) for(__typeof((a).begin()) it=(a).begin(); it != (a).end(); it++)
//#define me (*this)
//#define PQ(t) priority_queue< t, vector< t >, greater< t > >
//#define CLR(a, v) memset(a, v, sizeof(a))
//#define UNIQUE(a) srt(a), a.resize(unique(all(a))-a.begin())
//#define RAND (((double)rand()/RAND_MAX) + ((double)rand()/RAND_MAX/RAND_MAX))
//#define assert(cond,msg) if(!(cond)){ fprintf(stderr, "assert failed at line %d: %s\n", __LINE__, msg); exit(1); }
/*
char systemBuffer[1<<10];
#define execute(...) {\
  sprintf(systemBuffer, __VA_ARGS__); \
  system(systemBuffer); \
}

#ifdef LOCAL
  #define debug(msg, ...) fprintf(stderr, msg, __VA_ARGS__)
#else
  #define debug(msg, ...)
#endif
*/
typedef long long ll;
typedef pair<int, int> ii;
typedef vector< ii > vii;
typedef vector< vii > vvii;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef vector< string > vs;
typedef vector< double > vd;
typedef vector< vd > vvd;
typedef vector< ll > vll;
typedef vector< bool > vb;

const int INF = 1000*1000*1000+7;
const double EPS = 1e-9;
const double PI = acos(-1.0);
template<class T> int chmin(T &t, T f){ return (t>f) ? (t=f, 1) : 0; }
template<class T> int chmax(T &t, T f){ return (t<f) ? (t=f, 1) : 0; }

/* 
struct timeval startTime, finishTime;
double timeElapsed(){
  gettimeofday(&finishTime, NULL);
  int top = finishTime.tv_sec-startTime.tv_sec-(startTime.tv_usec > finishTime.tv_usec);
  int bot = finishTime.tv_usec-startTime.tv_usec;
  if(bot < 0)
    bot += 1e6;
  return top+bot/1e6;
}
*/
inline int getint() {
  int a;
  return scanf("%d", &a) ? a : (fprintf(stderr, "trying to read\n"),-1);
}

inline double getdouble() {
  double a;
  return scanf("%lf", &a) ? a : (fprintf(stderr, "trying to read\n"),-1);
}

int bit_count(int x){ return x ? 1+bit_count(x&(x-1)) : 0; }



int n;

int binRoot(const vvi &a, int i, int p){
  int nchild = 0;
  fj(sz(a[i]))
    if(a[i][j] != p){
      ++nchild;
      if(!binRoot(a, a[i][j], i))
        nchild = 3;
    }
  return nchild == 0 || nchild == 2;
}

int dfs(const vvi &a, int i, int p){
  int ret = 1;
  fj(sz(a[i]))
    if(a[i][j] != p)
      ret += dfs(a, a[i][j], i);
  return ret;
}
int conn(const vvi &a){
  return dfs(a, 0, -1) == sz(a);
}

int binary(const vvi &a){
  if(!conn(a))
    return 0;
  fi(sz(a))
    if(binRoot(a, i, -1))
      return 1;
  return 0;
}

vvi del(vvi a, int del){
  vi map(sz(a));
  int upto = 0;
  fi(n){
    map[i] = upto;
    if(!(del&(1<<i)))
      ++upto;
  }
  vvi ret(upto);
  fi(n)
    if(!(del&(1<<i)))
      fj(sz(a[i]))
        if(!(del&(1<<a[i][j])))
          ret[map[i]].pb(map[a[i][j]]);
  return ret;
}

void myCode() {

  int ttt=getint();
  fo(tt,ttt){

    n=getint();
    vvi a(n);
    fi(n-1){
      int x=getint()-1, y=getint()-1;
      a[x].pb(y);
      a[y].pb(x);
    }

    int ret = n;
    fi((1<<n)-1){
      vvi b = del(a, i);
      if(binary(b))
        chmin(ret, bit_count(i));
    }

    printf("Case #%d: %d\n", tt+1, ret);

  }

}

int main() {
/*
  // seed the random number generator with microseconds
  gettimeofday(&startTime, NULL);
  srand(startTime.tv_usec);
*/
  myCode();
  return 0;
}










