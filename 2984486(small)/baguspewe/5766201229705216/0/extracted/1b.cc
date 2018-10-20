#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <list>
#include <stdint.h>

using namespace std;

typedef struct {
  int a;
  int b;
} node;
 
class Solver {
 public:
  Solver() {
  }

  ostringstream convert;

  bool is_bin_tree(list<node> A) {
    int count[N];
    for (int n=0; n<N; n++) {
      count[n] = 0;
    }

    list<node>::iterator i;

    for (i=A.begin(); i!=A.end(); i++) {
      if (++count[(*i).a-1] > 2) return false;
      if (++count[(*i).b-1] > 2) return false;
    }

    bool head_found = false;
    for (int n=0; n<N; n++) {
      if (!head_found && count[n] == 2) {
        head_found = true;
        continue;
      }

      if (count[n] != 1 && count[n] != 3)
        return false;
    }

    return true;
  }

  int min;
  void try_remove(int pos, bool rem, int rem_cnt, list<node> the_node) {
    list<node>::iterator i;
    if (min <= rem_cnt)
      return;

    if (rem) {
      int offset = 0;
      rem_cnt++;

      i = the_node.begin();
      int n = pos;
      while(n--) {
        i++;
      }

      the_node.erase(i);

      if (is_bin_tree(the_node)) {
        if (min > rem_cnt) min = rem_cnt;
        return;
      }
    }
    else {
      pos++;
    }

    if (pos < the_node.size()) {
      try_remove(pos, true, rem_cnt, the_node);
      try_remove(pos, false, rem_cnt, the_node);
    }
  }

  string solve() {
    if (is_bin_tree(nodes)) {
      return "0";
    }
    else {
      min = N;
      try_remove(0, true, 0, nodes);
      try_remove(0, false, 0, nodes);
      convert << min;
      return convert.str();
    }
  }

  int N;
  list<node> nodes;
};
 
int main (void) {
  int n, T;
  string val;

  cin >> T;

  for (n=1; n<=T; n++) {  
    Solver *solver = new Solver();
    cin >> solver->N;

    for (int m=0; m<solver->N-1; m++) {
      int a, b;
      cin >> a >> b;
      if (a > b) {
        int temp = a;
        a=b;
        b=temp;
      }

      node k;
      k.a = a;
      k.b = b;

      solver->nodes.push_back(k);
    }

    cout << "Case #" << n << ": " << solver->solve() << endl;
  }

  return 0;
}
