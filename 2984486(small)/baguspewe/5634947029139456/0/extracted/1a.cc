#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <list>
#include <stdint.h>

using namespace std;

uint64_t str2uint(string input) {
  uint64_t val = 0;

  for (int n=0; n<input.length(); n++)
    val += input[n] == '1' ? 1 << n : 0;

  return val;
}
 
class Solver {
 public:
  Solver() {
  }

  ostringstream convert;

  bool does_it_work(list<uint64_t> a, list<uint64_t> b) {
    list<uint64_t>::iterator i,j;
    a.sort();
    b.sort();

    for (i=a.begin(),j=b.begin(); i!=a.end(); i++, j++) {
      if (*i != *j)
        return false;
    }
    return true;
  }

  void try_switch(int pos, bool sw, int sw_cnt, list<uint64_t> a, list<uint64_t> b) {
    list<uint64_t>::iterator i,j;
    if (min <= sw_cnt)
      return;

    if (sw) {
      sw_cnt++;
      for (i=a.begin(),j=b.begin(); i!=a.end(); i++, j++) {
        *i = *i ^ 1<<pos;
      }

      if (does_it_work(a, b)) {
        if (min > sw_cnt) min = sw_cnt;
        return;
      }
    }

    if (pos < L-1) {
      try_switch(pos+1, false, sw_cnt, a, b);
      try_switch(pos+1, true, sw_cnt, a, b);
    }
  }

  string solve() {
    if (does_it_work(outlets, devices)) {
      convert << 0;
      return convert.str();
    }

    min = L+1;

    int res;
    try_switch(0, true, 0, outlets, devices);
    try_switch(0, false, 0, outlets, devices);

    if (min > L) {
      return "NOT POSSIBLE";
    }
    else {
      convert << min;
      return convert.str();
    }
  }

  int N, L;
  list<uint64_t> outlets;
  list<uint64_t> devices;
  int min;
};
 
int main (void) {
  int n, T;
  string val;

  cin >> T;

  for (n=1; n<=T; n++) {  
    Solver *solver = new Solver();
    cin >> solver->N >> solver->L;

    for (int m=0; m<solver->N; m++) {
      cin >> val;
      solver->outlets.push_back(str2uint(val));
    }
    for (int m=0; m<solver->N; m++) {
      cin >> val;
      solver->devices.push_back(str2uint(val));
    }

    cout << "Case #" << n << ": " << solver->solve() << endl;
  }

  return 0;
}
