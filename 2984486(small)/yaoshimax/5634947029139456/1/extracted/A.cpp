#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <cstring>


using namespace std;
long long b2i(string str){
  int size = str.size();
  long long ans = 0;
  for( int i = 0 ; i  <size;i++){
    ans *= 2;
    ans += str[i]-'0';
  }
  return ans;
}
int bitcount(long long num){
  int ans = 0;
  while( num != 0 ){
    ans++;
    num = num&(num-1);
  }
  return ans;
}

int main(){
  int n_case;
  cin >> n_case;
  for( int loop = 0 ; loop < n_case ; loop++ ){
    int N,L;
    cin>>N>>L;
    long long devices[N];
    long long outlets[N];
    for( int i = 0 ; i < N ; i++ ){
      string tmp;
      cin >> tmp;
      devices[i] = b2i(tmp);
    }
    for( int i = 0 ; i < N ; i++ ){
      string tmp;
      cin >> tmp;
      outlets[i] = b2i(tmp);
    }
    sort(devices,devices+N);
    sort(outlets,outlets+N);
    int ans = INT_MAX;
    for( int i = 0 ; i < N ; i++ ){
      long long shifted[N];
      long long dif = outlets[i]^devices[0];
      int b_count = bitcount(dif);
      cout << "try"<<i<<"..."<<dif<<"("<<b_count<<")"<<endl;
      for( int j = 0 ; j < N ; j++ ){
        shifted[j] = dif^devices[j];
      }
      sort( shifted,shifted+N);
      bool ok= true;
      for( int j = 0 ; j <N; j++){
        if( shifted[j]!=outlets[j]){
          ok = false;
          break;
        }
      }
      if(ok) ans = min(ans,b_count);
    }
    if(ans!=INT_MAX){
      cout << "Case #" << loop+1 << ": " <<ans<< endl;
    }
    else{
      cout << "Case #" << loop+1 << ": " <<"NOT POSSIBLE"<< endl;
    }
  }
  return 0;
}
