#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>

using namespace std;

typedef long long i64;
typedef vector<int> VI;
typedef vector<string> VS;
#define REP(i,n) for(int _n=n, i=0;i<_n;i++)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;i++)
#define ALL(x)   (x).begin(),(x).end()
#define SORT(x) sort(ALL(x))
#define PB push_back

string X[200], Y[200];
int ret;
int N, L;

void play(string M) {
  int ll = M.length();
  // cout<<M<<endl;
  if(M.length() > L) {
    int cc=0;
    REP(i, L) {
      if(M[i]=='1') cc++;
    }
    if (cc<ret) ret=cc;
    return;
  }

  VS v1, v2;
  REP(i, N) {
    string tt=X[i].substr(0,ll);
    REP(j, ll) {
      if(M[j]=='1') tt[j]=(tt[j]=='1')?'0':'1';
    }
    v1.PB(tt);
    v2.PB(Y[i].substr(0,ll));
  }
  SORT(v1); SORT(v2);
  if (v1 == v2) {
    play(M+"0");
    play(M+"1");
  }
}

int main() {
  int Ts;
  cin>>Ts;
  FOR(cs, 1, Ts) {
    cin >> N >> L;
    REP(i, N) cin>>X[i];
    REP(i, N) cin>>Y[i];
    ret=L+100;
    play("");
    cout << "Case #" << cs << ": ";
    if (ret<L+10) {
      cout<<ret;
    } else cout<<"NOT POSSIBLE";
    cout<<endl;
  }

  return 0;
}
