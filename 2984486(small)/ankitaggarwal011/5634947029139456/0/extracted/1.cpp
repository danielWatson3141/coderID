#include<iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>


using namespace std;


int temp(int l){
  int s;
  cin >> s;
  int h = 0;
  for (int i = 0; i < l; i++){
    if (s % 10)
      h = h | (1 << i);
    s /= 10;
  }
  return h;
}

int main() {
  int n, l, list1[155], list2[155];
  int test;
  cin >> test;
  
  for (int cases = 1; cases <= test;cases++){
    map<int, int> i1, i2;
    map<int, int> *ia, *ib, *tempo;
    
    cin >> n >> l;
    for (int i = 0; i < n; i++)
      list1[i] = temp(l);
    for (int i = 0; i < n; i++)
      list2[i] = temp(l);
    ia = &i1, ib = &i2;
    for (int j = 0; j < n; j++){
      int xtra = list1[0] ^ list2[j];
      int &peta = (*ia)[xtra];
      peta=1;
    }
    for (int i = 1; i < n; i++){
      tempo = ia, ia = ib, ib = tempo;

      for (int j = 0; j < n; j++){
        int xtra = list1[i] ^ list2[j];
        int &papeta = (*ib)[xtra];
        if (papeta){
          int &peta = (*ia)[xtra];
          peta=1;
        }
      }
      ib->clear();
    }
    int mini = 1<<30;
    for (map<int, int>::iterator eta = ia->begin(); eta != ia->end(); eta++){
      int n = eta->first;
      int q = 0;
      for (int i = 0; i < l;i++)
      if ((n&(1 << i)) != 0) q++;
      mini = min(mini, q);
    }
    cout << "Case #" << cases << ": ";
    if (mini == (1 << 30)) cout << "NOT POSSIBLE"<<endl;
    else cout << mini << endl;
  }
  return 0;
}
