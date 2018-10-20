#include <iostream>
#include <algorithm>

using namespace std;

long long a[150];
long long b[150];
int N, L;

long long toInt(string str){
  long long res = 0;
  
  reverse(str.begin(), str.end());
  
  for(int i = 0; i < (int)str.size(); ++i){
    if ( str[i] == '1' ){
      res |= ( 1LL << i);
    }
  }
  
  return res;
}

void scan(){
  cin >> N >> L;
  
  for(int i = 0; i < N; ++i){
    string str;
    cin >> str;
    
    a[i] = toInt(str);
  }
  
  for(int i = 0; i < N; ++i){
    string str;
    cin >> str;
    b[i] = toInt(str);
  }
}


long long canFind(long long x){
  for(int i = 0; i < N; ++i)
    if(a[i] == x)
      return 1;
    
  return 0;
}
int ok(){
  for(int i = 0; i < N; ++i)
    if(canFind(b[i]) == 0)
      return 0;
    
  return 1;
}


void solve(int test){
  int res = 1e9;
  for(int i = 0; i < (1LL << L); ++i){
    for(int j = 0; j < L; ++j)
      if( (1 << j) & i){
	for(int k = 0; k < N; ++k)
	  a[k] ^= (1LL << j);
      }
    if(ok()){
      res = min(res, __builtin_popcountll(i));
    }
    
    for(int j = 0; j < L; ++j)
      if( (1 << j) & i){
	for(int k = 0; k < N; ++k)
	  a[k] ^= (1LL << j);
      }
  }
  
  cout << "Case #" << test << ": ";
  if(res == 1e9){
    cout << "NOT POSSIBLE\n";
    return;
  }
  
  cout << res << endl;
}

int main(){
  int tests;
  
  cin >> tests;
  
  for(int i = 1; i <= tests; ++i){
    scan();
    solve(i);
  }
}
