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

#define ull unsigned long long int 

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

int main() {
  int t;
  cin >> t;
  REP(rep,t){
    ull d[160][160];
    int n,l;
    cin >> n >> l;
    vector<string> v;
    vector<string> r;
    REP(i,n){
      string s; cin >> s;
      v.push_back(s);
    }
    REP(i,n){
      string s; cin >> s;
      r.push_back(s);
    }
    REP(i,n){
      REP(j,n){
	d[i][j] = 0ULL;
	REP(k,l){
	  d[i][j] <<= 1;
	  d[i][j] += ((v[i][k] == r[j][k]) ? 0 : 1);
	}
      }
    }
    int mn = 10000;
    REP(i,n){
      int re = 0;
      ull hoge = d[i][0];
      REP(j,l){
	if((hoge&1ULL)==1ULL){
	  re++;
	}
	hoge >>= 1;
      }
      int flg = 1;
      for(int j=1;j<n;j++){
	int f = 0;
	REP(k,n){
	  if(d[k][j] == d[i][0]){
	    f = 1;
	    break;
	  }
	}
	if(f==0){
	  flg = 0;
	  break;
	}
      }
      if(flg == 1){
	mn = min(mn,re);
      }
    }
    cout << "Case #" <<rep+1 << ": " << (mn>1000?"NOT POSSIBLE" : to_string(mn))<<endl;
    

  }



  return 0;
}
