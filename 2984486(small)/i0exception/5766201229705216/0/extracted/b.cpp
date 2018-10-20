#include<iostream>
#include<string.h>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<deque>
#include<set>
#include<list>
#include<stack>
#include<sstream>
#include<fstream>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cassert>
#define CLRM(x) memset(x,-1,sizeof(x))
#define CLR(x) memset(x,0,sizeof(x))
#define ALL(x) x.begin(),x.end()
#define GI(x) scanf("%d", &x);
#define FORN(i, n) for(int i = 0; i < n; i++)
#define FOR(i, start, end) for(int i = start; i < end; i++)
#define PB push_back
#define MP make_pair
#define VI vector<int> 
#define VVI vector<vector<int> >
#define PII pair<int,int>
#define SZ(x) (int)x.size()
#define LL long long
#define MIN(a,b) (a)<(b)?(a):(b)
#define MAX(a,b) (a)>(b)?(a):(b)
#define LMAX 1000000000000000000LL
#define IMAX 1000000000

#define LIM 1100
using namespace std;
int N;
VVI adj;

int visited[LIM];
int children[LIM];

bool is_tree(int root, int avoid) {
  CLR(visited);
  CLR(children);
  queue<int> q;
  q.push(root);
  visited[root] = 1;
  while(!q.empty()) {
    int f = q.front();
    //cout << "node: " << f << endl;
    q.pop();
    FORN(i, SZ(adj[f])) {
      if (avoid & (1<<adj[f][i])) continue;
      if (!visited[adj[f][i]]) {
        visited[adj[f][i]]=1;
        children[f]++;
        q.push(adj[f][i]);
      }
    }
  }
  FORN(i, N) {
    if (children[i] == 0 || children[i] == 2)
      continue;
    //cout<<"nochild: "<<i<<endl;
    return false;
  }
  FORN(i, N) {
    if (avoid & (1<<i))
      continue;
    //cout<<"novisit: "<<i<<endl;
    if (visited[i] == 0)
      return false;
  }
  return true;
}

void solve() {
  int ret = 1e9;
  FORN(i, (1<<N)) {
    //cout << "avoid: " << i << endl;
    int cnt = __builtin_popcount(i);
    if (cnt >= ret) continue;
    FORN(j, N) {
      //cout << "root: " << j << endl;
      if (i & (1<<j)) continue;
      if (is_tree(j, i)) {
        ret = MIN(ret, cnt);
        break;
      }
      //cout<<endl;
    }
    //cout << "----------" << endl;
  }
  printf("%d\n", ret);
}

int main() {
  int tes;
  GI(tes);
  FORN(i, tes) {
    GI(N);
    adj.clear();
    adj.resize(N);
    FORN(j, N-1) {
      int x, y;
      GI(x); GI(y);
      x--;y--;
      adj[x].PB(y);
      adj[y].PB(x);
    }
    printf("Case #%d: ", i+1);
    solve();
  }
}
