#include <cmath>
#include <queue>
#include <vector>
#include <queue>
#include <map>
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <iomanip>   
#include <iostream>  
#include <sstream>  // istringstream buffer(myString);
#include <stack>
#include <set>
#include <algorithm>
#include <cstring>
#include <limits>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;

vector<string> A;
vector<string> B;
int N, L;
int best;

bool equal(int id) {
  for (int i = 0; i < N; i++) {
    if (A[i][id] != B[i][id]) { return  false;}
  }
  return true;
}

void flip(int id) {
  for (int i=0; i < N; i++) {
    if (A[i][id] == '0') { A[i][id] = '1';} else { A[i][id] = '0';}
  }
  sort(A.begin(), A.end());
}

int search(int id, int cnt) {
  //std::cout << "search" << id << std::endl;
  int rv = 1000;
  if (id == L) { best = min(best, cnt); return 0;}
  //  if (cnt > best) { return rv;}
  if (equal(id)) {
    //std::cout << "equal"<<id << std::endl;
    rv = min(rv, search(id+1, cnt));
  }
  flip(id);
  if (equal(id)) {
    //std::cout << "flipped equal" << std::endl;
    rv = min(rv, 1+search(id+1, cnt+1));
  }
  flip(id);
  //std::cout << "rv:"<<rv << std::endl;
  return rv;
}

int main() {
  int TC;
  cin >> TC;
  int C = 0;
  while(C++ < TC) {
    // backtracking with pruning
    scanf("%d %d\n", &N, &L);
    A.clear();
    B.clear();
    
    string a;
    for (int i = 0; i < N; i++) {
      cin >> a;
      A.push_back(a);
    }
    sort(A.begin(), A.end());
    
    for (int i = 0; i < N; i++) {
      cin >> a;
      B.push_back(a);
    }
    sort(B.begin(), B.end());

    // statistics
    int res = search(0, 0);
    if (res>999) {
      printf("Case #%d: NOT POSSIBLE\n", C);
    } else {
      printf("Case #%d: %d\n", C, res);
    }
  }

}
