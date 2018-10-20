/*****************************************
NAME    : wei.huang
PROJECT : Proper Shuffle
LANG    : C++
2014    , renren-inc
*****************************************/

# include <math.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <algorithm>
# include <iostream>
# include <string>
# include <queue>
# include <stack>
# include <map>
# include <set>
# include <vector>
# include <cstring>
# include <list>
# include <ctime>
# include <sstream>

# define For(i,a)   for((i)=0;i<(a);(i)++)
# define MAX(x,y)   ((x)>(y)? (x):(y))
# define MIN(x,y)   ((x)<(y)? (x):(y))
# define sz(a)      (sizeof(a))
# define MEM(a)     (memset((a),0,sizeof(a)))
# define MEME(a)    (memset((a),-1,sizeof(a)))
# define MEMX(a)    (memset((a),0x7f,sizeof(a)))
# define pb(a)      push_back(a)

# define Foreach(it, v)     for(__typeof((v).begin()) it = (v).begin(); (v).end() != it; ++it)

using namespace std;

typedef long long           ll      ;
typedef unsigned long long  ull     ;
typedef unsigned int        uint    ;
typedef unsigned char       uchar   ;


template<class T> inline void checkmin(T &a, T b) {
  if (b < a) a = b;
}
template<class T> inline void checkmax(T &a, T b) {
  if (a < b) a = b;
}

const int oo = 1 << 30          ;
const double eps = 1e-7       ;
const int N = 1               ;
const int M = 1               ;
const ll P = 10000000097ll    ;

void read() {

}

void print() {

}

bool checkWithHalf(const vector<int> & v) {
  int n = v.size();
  int half = n / 2;
  int last = (v[0] > half);
  int count = 0;
  for (int i = 1; i < n; i++) {
    int now = (v[i] > half);
    count += (now ^ last);
    last = now;
  }
  // printf("%d %d\n", count, half);
  return count >= half;
}

int doit() {
  int n;
  vector<int> v;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    v.push_back(x);
  }

  return checkWithHalf(v);
}

int main(int argc, char const *argv[]) {

  int T;

  cin >> T;

  char ans[2][10] = {"BAD", "GOOD"};

  for (int i = 1; i <= T; i++) {
    read();
    int good = doit();
    print();
    printf("Case #%d: %s\n", i, ans[good]);
  }

  return 0;
}

/**



**/


