typedef long long ll;

#include <algorithm>
#include <queue>
#define REP(i,n) for(int i=0; i<(int)(n); i++)

#include <cstdio>
inline int getInt(){ int s; scanf("%d", &s); return s; }

#include <set>
using namespace std;

int solve(int c){
  const int n = getInt();
  const int l = getInt();

  vector<ll> outlet(n);
  vector<ll> device(n);

  REP(k,2){
    vector<ll> &v = k == 0 ? outlet : device;

    REP(i,n){
      char buff[256];
      scanf("%s", buff);

      REP(j,l){
	if(buff[j] == '1') v[i] |= 1ll << j;
      }
    }
  }

  int ans = 1000;

  sort(device.begin(), device.end());
  REP(i,n){
    const ll diff = outlet[0] ^ device[i];
    REP(j,n) outlet[j] ^= diff;
    sort(outlet.begin(), outlet.end());

    bool ok = true;
    REP(j,n) if(outlet[j] != device[j]) ok = false;
    if(ok){
      int cnt = 0;
      REP(j,l) if(diff & (1ll << j)) cnt++;
      ans = min(ans, cnt);
    }

    REP(j,n) outlet[j] ^= diff;
  }

  printf("Case #%d: ", c);
  if(ans == 1000){
    printf("NOT POSSIBLE\n");
  }else{
    printf("%d\n", ans);
  }
}

int main(){
  const int c = getInt();
  REP(i,c) solve(i + 1);
  return 0;
}




