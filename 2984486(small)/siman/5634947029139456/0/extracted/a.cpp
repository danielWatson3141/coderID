#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <limits.h>
#include <string>
#include <string.h>
#include <sstream>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <stack>
#include <queue>

using namespace std;

typedef long long ll;

ll string2int( string s ){
  ll res = 0;
  int size = s.size();

  for(int i = 0; i < size; i++){
    if( s[i] == '1' ){
      res += ( 1 << i );
    }
  }

  return res;
}

int solver(){
  vector<ll> outlets, tmp_outlets;
  vector<ll> requires;
  ll n, l, answer = 9999;
  cin >> n >> l;
  string num;

  for(int i = 0; i < n; i++){
    cin >> num;
    outlets.push_back(string2int(num));
  }

  sort( outlets.begin(), outlets.end() );

  for(int i = 0; i < n; i++){
    cin >> num;
    requires.push_back(string2int(num));
  }

  sort( requires.begin(), requires.end() );

  ll c, d, cnt;

  for(int i = 0; i < n; i++){
    c = requires[0];
    d = outlets[i];
    tmp_outlets = outlets;
    cnt = 0;

    for(int j = 0; j < l; j++){
      if( ((c >> j)&1) != ((d >> j)&1) ){
        for(int k = 0; k < n; k++){
          tmp_outlets[k] ^= ( 1 << j );
        }
        cnt++;
      }
    }

    sort( tmp_outlets.begin(), tmp_outlets.end() );

    bool flag = true;

    for(int i = 0; i < n && flag; i++){
      if( requires[i] != tmp_outlets[i] ) flag = false;
    }

    if(flag){
      answer = min( answer, cnt );
    }
  }

  return answer;
}

int main(){
  int test_case, ans;

  cin >> test_case;

  for(int i = 1; i <= test_case; i++){
    ans = solver();

    if( ans != 9999 ){
      printf("Case #%d: %d\n", i, ans );
    }else{
      printf("Case #%d: NOT POSSIBLE\n", i );
    }
  }

  return 0;
}
