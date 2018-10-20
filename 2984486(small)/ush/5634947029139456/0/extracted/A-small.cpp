
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cctype>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <bitset>
#include <algorithm>
#include <limits>
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, c) for(__typeof((c).begin()) i=(c).begin(); i != (c).end(); ++i)
using namespace std;
typedef long long ll;

int main(void) {
  int nCase;
  cin >> nCase;
  REP(iCase, nCase){
    printf("Case #%d: ", iCase+1);
    
    int N, L;
    cin >> N >> L;
    vector<ll> initial, target;
    REP(i, N){
      string s;
      cin >> s;
      ll v = 0;
      REP(j, L){
	if(s[j] == '1')
	  v |= 1LL << j;
      }
      initial.push_back(v);
    }
    REP(i, N){
      string s;
      cin >> s;
      ll v = 0;
      REP(j, L){
	if(s[j] == '1')
	  v |= 1LL << j;
      }
      target.push_back(v);
    }
    sort(initial.begin(), initial.end());
    sort(target.begin(), target.end());
    
    int mini = 10*L;
    REP(i, N){
      int cnt = 0;
      vector<ll> cur;
      vector<bool> bs(L, false);
      REP(k, L){
	if((target[0] & (1LL << k)) != (initial[i] & (1LL << k))){
	  bs[k] = true;
	  cnt++;
	}
      }
      if(cnt > mini)
	continue;
      REP(j, N){
	ll v = initial[j];
	REP(k, L){
	  if(bs[k])
	    v ^= 1LL << k;
	}
	cur.push_back(v);
      }
      sort(cur.begin(), cur.end());
      if(cur == target){
	mini = cnt;
      }
    }
    
    if(mini <= L){
      printf("%d\n", mini);
    }else{
      puts("NOT POSSIBLE");
    }
    
    
    
  }
  return 0;
}
