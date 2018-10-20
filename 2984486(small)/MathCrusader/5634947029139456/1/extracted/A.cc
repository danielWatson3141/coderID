#include <iostream>
#include <string>
#include <set>
using namespace std;

#define ll long long

const int MAX_N = 200;
long long A[MAX_N],B[MAX_N];

void do_case(){
  int N,L;
  char c;
  cin >> N >> L;
  for(int i=0;i<N;i++){
    A[i] = 0;
    for(int j=0;j<L;j++){
      A[i] *= 2;
      cin >> c;
      if(c == '1') A[i]++;
    }
  }
  for(int i=0;i<N;i++){
    B[i] = 0;
    for(int j=0;j<L;j++){
      B[i] *= 2;
      cin >> c;
      if(c == '1') B[i]++;
    }
  }
  
  set<ll> ans;
  for(int i=0;i<N;i++)
    ans.insert(B[i]);
  
  int best = -1;
  for(int i=0;i<N;i++){
    // I want A[0] to match B[i]
    ll XOR = A[0] ^ B[i];
    set<ll> S;
    for(int j=0;j<N;j++)
      S.insert(A[j] ^ XOR);
    
    if(S == ans){
      int pc = __builtin_popcountll(XOR);
      if(best == -1) best = pc;
      if(pc < best) best = pc;
    }
    
  }
  if(best == -1){
    cout << "NOT POSSIBLE" << endl;
  } else {
    cout << best << endl;
  }  
}

int main(){
  int T,C=1;
  cin >> T;
  while(T--){
    cout << "Case #" << C++ << ": ";
    do_case();
  }
  
  return 0;
}
