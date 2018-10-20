/*
ID: ahri1
PROG: A
LANG: C++
*/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;
#define sz(X) ((int)(X).size())
#define foreach(i,c) for(__typeof((c).begin()) i=((c).begin());i!=(c).end();++i)
template<class T> vector<T> tokenize_to(const string &str) { vector<T> r; T x; istringstream is(str); while (is >> x) r.push_back(x); return r; }
#define junik(X) {sort( (X).begin(), (X).end() ); (X).erase( unique( (X).begin(), (X).end() ), (X).end() ); }

template<typename T> string v_2_s(vector<T> &a) { stringstream sb; __typeof(a.begin()) i = a.begin(); if (i!=a.end()) { sb << *i; ++i; } for (; i!=a.end();++i) { sb << " " << *i; } return sb.str(); }


string FAIL = "NOT POSSIBLE";

void tilt(vector<string> &A, int i) {
  int N=sz(A);
  for(int j=0;j<N;++j){
    if (A[j][i]=='1') A[j][i]='0';
    else A[j][i]='1';
  }
}

bool compare(vector<string> &A, vector<string> &B) {
  int N=sz(A);
  sort(A.begin(), A.end());
  for(int i=0;i<N;++i){
    if (A[i]!=B[i]) {
      return false;
    }
  }
  return true;
}

int rek(vector<string> &A, vector<string> &B, vector<int> M, int d) {
  if (d==sz(M)) {
    if (compare(A, B)) return 0;
    else return sz(A[0])+1;
  }
  int ret1, ret2;
  ret1 = rek(A, B, M, d+1);  
  tilt(A, M[d]);
  ret2 = rek(A, B, M, d+1) + 1;
  tilt(A, M[d]);
  return min(ret1, ret2);
}

void solve(){
  int N, L;
  cin >> N >> L;
  vector<string> A(N), B(N);
  for(int i=0;i<N;++i){
    cin >> A[i];
  }
  for(int i=0;i<N;++i){
    cin >> B[i];
  }
  
  int ret = 0;
  // sort(A.begin(), A.end());
  // sort(B.begin(), B.end());
  // cout << endl;
  // cout << v_2_s(A) << endl;
  // cout << v_2_s(B) << endl;
  // cout << endl;

  sort(B.begin(), B.end());
  
  vector<int> M;
  
  for(int i=0;i<L;++i){
    int countA = 0, countB=0;
    for(int j=0;j<N;++j){
      if (A[j][i]=='1') countA++;
    }
    for(int j=0;j<N;++j){
      if (B[j][i]=='1') countB++;
    }
    if (countA!=countB) { 
      tilt(A, i);
      ret++;
    }
    if (countA==countB && countA*2==N) {
      M.push_back(i);
    }
    // cout << v_2_s(A) << endl;
  }
  // cout << endl <<  "M::" << v_2_s(M) << endl;
  
  vector<string> A_t=A;
  
  // sort(A.begin(), A.end());
  // cout << ret << endl;
  ret+=rek(A, B, M, 0);
  // cout << ret << endl;
  
  
  if (ret>L) {
    cout << FAIL << endl;
  } else {
    cout << ret << endl;
  }
  
}

int main() {

  cin.sync_with_stdio(0);
  int T;
  cin >> T;
  // T=1;
  for (int i=0;i<T;i++) {
    cout << "Case #" << i+1 << ": ";
    solve();
  }
  
  return 0;
}
