#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
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
#include <cstring>

using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
typedef pair<int, int>     ii;
typedef vector<ii>         vii;
typedef set<int>           si;
typedef map<string, int>   msi;

//#define for(i, a, b) \
//  for(int i = int(a); i <= int(b); i++)
//#define Rvi(c, it) \
//  for(vi::iterator it = (c).begin(); it != (c).end(); it++)
//#define Rvii(c, it) \
//  for(vii::iterator it = (c).begin(); it != (c).end(); it++)
//#define Rmsi(c, it) \
//  for(msi::iterator it = (c).begin(); it != (c).end(); it++)

vector<vi> G;
int c = 0;
bool B[1001];
bool sw = false;

void dfs(int r) {
  B[r] = true;
  if(sw)
    c++;

  if(G[r].size() != 3 && G[r].size() != 1) {
    sw = true;
  }

  for(int i=0; i<G[r].size(); i++) {
    if(!B[G[r][i]])
      dfs(G[r][i]);
  }

  sw = false;
}

int main() {
  int t, tc = 0;
  scanf("%d", &t);

  while(t--) {
    tc++;
    int n;
    scanf("%d", &n);

    G.assign(n+1, vi());

    int a, b;
    for(int i=0; i<n-1; i++) {
      scanf("%d %d", &a, &b);
      G[a].push_back(b);
      G[b].push_back(a);
    }

    int mn = n - 1;
    for(int i=1; i<=n; i++) {
      memset(B, false, sizeof(B));
      c = 0;
      sw = false;

      if(G[i].size() == 2) {
	B[i] = true;
	dfs(G[i][0]);
	dfs(G[i][1]);
	mn = min(mn, c);
      }
    }

    printf("Case #%d: %d\n", tc, mn);
  }

  return 0;
}
