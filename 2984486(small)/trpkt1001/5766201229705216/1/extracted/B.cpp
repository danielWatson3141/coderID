#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
using namespace std;

inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

int e[1010][1010];
int d[1010];
int n;
int a[1010];

int chk(int p){
  a[p] = 1;
  int cnt = 0;
  int c = 0;
  d[p] = 1;
  int mx1,mx2;
  int sum  =0;
  mx1 = mx2 = -100000;
  for(int i=1;i<=n;i++){
    if(e[p][i] == 1 && a[i] == 0){
      int hoge = chk(i);
      cnt+=hoge;
      if(d[i] - hoge > mx1){
	mx2 = mx1;
	mx1 = d[i] - hoge;
      }else if(d[i] - hoge > mx2){
	mx2 = d[i] - hoge;
      }
      sum += d[i] - hoge;
      d[p] += d[i];
      c++;
    }
  }
  if(c == 0 || c == 2){
    return cnt;
  }else{
    
    if(c == 1 )return cnt + sum;
    return cnt + sum - mx1 - mx2;
  }
}

int main() {
  int t;
  cin >> t;
  REP(rep,t){
    REP(i,1010)REP(j,1010)e[i][j] = 0;
    REP(i,1010)d[i] = 0;
    cin >> n;
    int v[1010][2];
    REP(i,n-1){
      cin >> v[i][0] >> v[i][1];
      e[v[i][0]][v[i][1]] = e[v[i][1]][v[i][0]] = 1;
    }
    int mn = 10000;
    for(int i = 1;i <= n ; i++){
      REP(i,1010)a[i] = 0;
      mn = min(mn,chk(i));
    }
    cout << "Case #" << rep+1 << ": " << mn << endl;

  }


    return 0;
}
