#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define mp make_pair
#define pb push_back
#define sz(x) ((int)(x).size())
#define x first
#define y second
#define fi(n) fo(i,n)
#define fj(n) fo(j,n)
#define fk(n) fo(k,n)
#define fd(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define fo(i,n) fr(i,0,n)
#define fr(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define all(x) (x).begin(),(x).end()
#define sqr(x) ((x)*(x))
#define srt(x) sort(all(x))

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

const int INF = 1000*1000*1000+7;
const double EPS = 1e-9;
const double PI = acos(-1.0);
template<class T> int chmin(T &t, T f) { return (t>f) ? (t=f,1) : 0; }
template<class T> int chmax(T &t, T f) { return (t<f) ? (t=f,1) : 0; }

inline int getint() {
  int a;
  return scanf("%d",&a) ? a : (fprintf(stderr,"trying to read\n"),-1);
}

inline double getdouble() {
  double a;
  return scanf("%lf",&a) ? a : (fprintf(stderr,"trying to read\n"),-1);
}

// weight of subtree, number of nodes to delete below me
ii go(vvi& adj, int i, int p) {
  ii ret = ii(1,0);
  vi w, r;
  fj(sz(adj[i]))
    if (adj[i][j] != p) {
      ii a = go(adj,adj[i][j],i);
      w.pb(a.x);
      ret.x += a.x;
      r.pb(a.y);
    }
  ret.y = ret.x-1;
  if (sz(w) >= 2) {
    int s1 = 0, s2 = 0;
    fj(sz(w)) {
      int save = w[j] - r[j];
      if (save > s2) {
        s2 = save;
        if (s2 > s1)
          swap(s1,s2);
      }
    }
    ret.y -= s1 + s2;
  }
  return ret;
}

void myCode() {
  int ttt = getint();
  fo(tt,ttt) {
    int n = getint();
    vvi adj(n);
    fi(n-1) {
      int s = getint()-1, t = getint()-1;
      adj[s].pb(t);
      adj[t].pb(s);
    }
    int ret = INF;
    fi(n) {
      // i is the root
      chmin(ret,go(adj,i,-1).y);
    }
    printf("Case #%d: %d\n",tt+1,ret);
  }
}

int main () {
  srand(time(NULL));
  myCode();
  return 0;
}
