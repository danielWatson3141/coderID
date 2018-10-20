#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <utility>
#include <vector>

#define FOR(I,A,B)   for(int I= (A); I<(B); ++I)
#define REP(I,N)     FOR(I,0,N)
#define ALL(A)       (A).begin(), (A).end()
#define SZ(A)        int((A).size())
#define PB           push_back
#define FST(A)       (A).first
#define SEC(A)       (A).second
#define DEBUG        0

typedef unsigned long long int ulld;

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<bool> vb;

int sizeTree(vector<vector<int>> &G, int node, vector<bool> &visited) {
  visited[node] = true;
  vector<int> res;
  REP(v, SZ(G[node])) {
    if (!visited[G[node][v]]) {
      int temp = sizeTree(G, G[node][v], visited);
      res.push_back(temp);
    }
  }
  int size = SZ(res);
  if (size == 0 || size == 1)
    return 1;
  else {
    sort(res.begin(), res.end());
    reverse(res.begin(), res.end());
    return 1 + res[0] + res[1];
  }
}

int main ()
{
  int T;
  cin >> T;
  REP(t, T) {
    int N;
    cin >> N;
    int a, b;
    vector< vector<int> > G(N);
    REP(i, N-1) {
      cin >> a >> b;
      a--;
      b--;
      G[a].push_back(b);
      G[b].push_back(a);
    }
    int minn = 1000000000;
    // Assume root node
    REP(i, N) {
      // determine how many nodes have to be deleted
      vector<bool> visited(N, false);
      int ret = sizeTree(G, i, visited);
      minn = min(minn, N-ret);
    }
    cout << "Case #" << t+1 << ": " << minn << endl;
  }
}
