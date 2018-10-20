#include<bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);

#define D(x) cout << #x << " = " << x << endl;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repd(i,a,b) for(int i=b-1;i>=a;i--)
#define REP(i,n) rep(i,0,n)
#define REPD(i,n) repd(i,0,n)
#define pb push_back
#define mp make_pair

typedef long long int lld;
typedef vector<int> vi;
typedef vector<lld> vlld;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

int main(){ IO;
  freopen("A.in","r",stdin);
  freopen("A.out","w",stdout);

  int t;
  cin >> t;

  rep(ncase,1,t+1){
    cout << "Case #" << ncase << ": ";

    int n, l;
    cin >> n >> l;

    vs outlet(n), device(n);
    REP(i,n) cin >> outlet[i];
    REP(i,n) cin >> device[i];

    set<string> devices;
    REP(i,n) devices.insert(device[i]);

    int ans = INT_MAX;
    REP(mask,1<<l){
      bool good = true;
      REP(i,n){
	string s = outlet[i];
	REP(j,l){
	  int m = 1 << j;
	  if(mask & m) s[j] = (s[j] == '1') ? '0' : '1';
	}
	if(devices.find(s) == devices.end()){
	  good = false;
	  break;
	}
      }
      if(good) ans = min(ans, __builtin_popcount(mask));
    }

    if(ans != INT_MAX) cout << ans << endl;
    else cout << "NOT POSSIBLE" << endl;
  }

  return 0;
}
