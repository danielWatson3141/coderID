#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#include<set>
#include<complex>
#include<map>
#include<list>
#include<deque>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;

ll bin(string s){
  ll res = 0;
  rep(i,s.size()){
    if(s[i]=='1')res |= 1LL<<i;
  }
  return res;
}

int main(){
  int testcase;
  int ans;

  cin >> testcase;
  for(int casenum=1;casenum<=testcase;casenum++){
    ans = 1e8;
    int n,l;
    cin >> n >> l;
    string o[200],d[200];
    set<ll> s;
    rep(i,n)cin >> o[i];
    rep(i,n){
      cin >> d[i];
      s.insert(bin(d[i]));
    }

    rep(i,n)rep(j,n){
      string swc;
      int num = 0;
      rep(x,l){
	if(o[i][x] != d[j][x])swc += '1', num++;
	else swc += '0';
      }

      if(num>=ans)continue;

      bool f = true;
      rep(k,n){
	ll bin = 0;
	rep(x,l){
	  if(o[k][x] != swc[x])bin |= 1LL<<x;
	}
	if(s.find(bin)==s.end()){
	  f = false;
	  break;
	}
      }
      if(f)ans = num;
    }

    cout << "Case #" << casenum << ": ";
    if(ans<1e8)cout << ans << endl;
    else cout << "NOT POSSIBLE" << endl;
  }
}
