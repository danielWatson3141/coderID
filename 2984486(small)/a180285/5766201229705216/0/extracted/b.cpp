/*****************************************
NAME    : wei.huang
PROJECT : Full Binary Tree
LANG    : C++
2014    , reanren-inc
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
const int N = 1 << 10               ;
const int M = 1               ;
const ll P = 10000000097ll    ;

void read() {

}

void print() {

}

vector<int> edge[N];
int move_[N];
int count_[N];

void dfs(const int far, const int u) {
  int child = 0;
  count_[u] = 1;
  Foreach (it, edge[u]) {
    int v = *it;
    if (far == v) {
      continue;
    }
    dfs(u, v);
    child++;
    count_[u] += count_[v];
  }
  switch (child) {
  case 0:
    move_[u] = 0;
    break;
  case 1:
    move_[u] = count_[u] - 1;
    break;
  default: // more
    int mx1 = -oo;
    int mx2 = -oo;
    Foreach (it, edge[u]) {
      int v = *it;
      if (v == far) {
        continue;
      }
      int left = count_[v] - move_[v];
      if (left > mx1) {
        mx2 = mx1;
        mx1 = left;
      } else if (left > mx2) {
        mx2 = left;
      }
    }
    move_[u] = count_[u] - (mx1 + mx2 + 1);
    break;
  }
}

int doit() {

  for (int i = 0; i < N; i++) {
    edge[i].clear();
  }

  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    edge[x].push_back(y);
    edge[y].push_back(x);
  }

  int ans = +oo;

  for (int i = 1; i <= n; i++) {
    MEM(move_);
    MEM(count_);
    dfs(0, i);
    // printf("root:%d move:%d count:%d\n", i, move_[i], count_[i]);
    checkmin(ans, move_[i]);
  }
  return ans;
}

int main(int argc, char const *argv[]) {

  int T;

  cin >> T;

  for (int i = 1; i <= T; i++) {
    read();
    int ans = doit();
    print();
    printf("Case #%d: %d\n", i, ans);
  }

  return 0;
}

/**



**/


