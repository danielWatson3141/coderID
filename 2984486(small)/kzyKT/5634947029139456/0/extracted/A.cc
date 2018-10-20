#include <bits/stdc++.h>
using namespace std;
#define all(c) (c).begin(),(c).end()
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define iter(c) __typeof((c).begin())
#define tr(it,c) for(iter(c) it=(c).begin(); it!=(c).end(); it++)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define pr(a) cout << (a) << endl
typedef long long ll;
typedef pair<int,int> P;
const int MAX=1000000000;
int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};

int cnt;
int n,l;
vector<int> v;
int m;
void solve(int k,int x,vector<string> s, vector<string> a) {
  bool ck=true;
  sort(all(s));
  rep(i,n) {
    if(s[i]!=a[i]) {
      ck=false;
      break;
    }
  }
  if(ck) {
    m=min(m,x);
  } else {
    if(k==v.size()) return;
    solve(k+1,x,s,a);
    rep(i,n) {
      if(s[i][v[k]]=='1') s[i][v[k]]='0';
      else s[i][v[k]]='1';
    }
    solve(k+1,x+1,s,a);
  }
}

int main() {
  int T;
  cin >> T;
  for(int t=1; t<=T; t++) {
    cin >> n >> l;
    vector<string> s(n),a(n);
    rep(i,n) cin >> s[i];
    rep(i,n) cin >> a[i];
    bool ck=true;
    cnt=0;
    m=MAX;
    sort(all(s));
    sort(all(a));
    v.clear();
    rep(i,l) {
      int cnts=0,cnta=0;
      rep(j,n) {
	if(s[j][i]=='1') cnts++;
	if(a[j][i]=='1') cnta++;
      }
      if(cnts!=cnta) {
	if(cnts==n-cnta) {
	  cnt++;
	  rep(j,n) {
	    if(s[j][i]=='1') s[j][i]='0';
	    else s[j][i]='1';
	  }
	} else ck=false;
      }
      if(cnts==n-cnts) v.pb(i);
    }
    solve(0,0,s,a);
    cout << "Case #" << t << ": ";
    if(m==MAX || !ck) cout << "NOT POSSIBLE" << endl;
    else cout << cnt+m << endl;
  }
  return 0;
}
