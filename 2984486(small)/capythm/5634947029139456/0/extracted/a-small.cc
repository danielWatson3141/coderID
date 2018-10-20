#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
ll inputVal( string s ){
  ll ret = 0;
  for( int j=0; j<s.size(); j++ ){
    ret = (ret<<1) | (s[j]-'0');
  }
  return ret;
} 
int main( void )
{
  int T,N,L;
  string s;
  ll d[150],e[150];
  cin >> T;
  for( int testcase=1; testcase<=T; testcase++ ){
    cin >> N >> L;
    for( int i=0; i<N; i++ ){
      cin >> s; d[i] = inputVal(s);
    }
    for( int i=0; i<N; i++ ){
      cin >> s; e[i] = inputVal(s);
    }
    sort( e, e+N );
    int ret = L+1;
    do {
      int r=0;
      ll x = d[0] ^ e[0];
      int f=0;
      for( int i=1; i<N; i++ ){
        if( (d[i]^e[i]) != x ){ f=1; break; }
      }
      if( f ) continue;
      while( x > 0 ){
        r += x&1;
        x >>= 1;
      }
      ret = min( ret, r );
    } while( next_permutation( e, e+N ) );
    if( ret > L ){
      cout << "Case #" << testcase << ": NOT POSSIBLE" << endl;
    } else {
      cout << "Case #" << testcase << ": " << ret << endl;
    }
  }
  return 0;
}
