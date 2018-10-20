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

  vector<int> outlet(n);
  vector<int> device(n);

  REP(k,2){
    vector<int> &v = k == 0 ? outlet : device;

    REP(i,n){
      char buff[256];
      scanf("%s", buff);

      REP(j,l){
	if(buff[j] == '1') v[i] |= 1 << j;
      }
    }
  }

  sort(device.begin(), device.end());

  int ans = 1000;

  REP(i,1<<l){
    REP(j,n) outlet[j] ^= i;

    sort(outlet.begin(), outlet.end());

    bool ok = true;
    REP(j,n) if(outlet[j] != device[j]) ok = false;
    if(ok) ans = min(ans, __builtin_popcount(i));

    REP(j,n) outlet[j] ^= i;
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
