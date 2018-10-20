#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;

vector<string> powerset(int n){
  if(n==0){
    vector<string> w;
    w.push_back("");
    return w;
  }
  vector<string> x = powerset(n-1);
  vector<string> w;
  for(int i=0; i<x.size(); i++){
    w.push_back(x[i] + "0");
    w.push_back(x[i] + "1");
  }
  return w;
}

char other(char a){
  if(a == '0') return '1';
  if(a == '1') return '0';
  return 'X';
}

void doproblem(int testcase){
  int n, l;
  cin >> n >> l;
  vector<string> v1 (n);
  vector<string> v2 (n);
  for(int i=0; i<n; i++) cin >> v1[i];
  for(int i=0; i<n; i++) {
    cin >> v2[i];
  }
  int minswitch = l+1;
  sort(v2.begin(), v2.end());
  vector<string> x = powerset(l);
  for(int i=0; i<x.size(); i++){
    vector<string> w = v1;
    for(int j=0; j<l; j++){
      if(x[i][j] == '1'){
        for(int k=0; k<n; k++){
          w[k][j] = other(w[k][j]);
        }
      }
    }
    sort(w.begin(), w.end());
    if(w == v2){
      int thisswitch = 0;
      for(int j=0; j<l; j++){
        if(x[i][j] == '1') thisswitch++;
      }
      if(thisswitch < minswitch)
        minswitch = thisswitch;
    }
  }
  if(minswitch == l + 1){
    printf("Case #%d: NOT POSSIBLE\n", testcase);
    return ;
  }
  printf("Case #%d: %d\n", testcase, minswitch);
  return ;
}

int main(){
  int T;
  cin >> T;
  for(int i=0; i<T; i++){
    doproblem(i+1);
  }
}
