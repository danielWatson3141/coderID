#include <cstdio>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;
typedef long long i64;

typedef int nkr_int;

typedef vector<nkr_int> vi;
typedef vector<vi> vvi;
#define pb push_back
#define iter(T) T::iterator
#define sz(a) int((a).size())
#define all(c) (c).begin(), (c).end()
#define tr(c, i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define present(c, x) ((c).find(x) != (c).end())
#define cpresent(c, x) (find(all(c), x) != (c).end())
#define REP(s, e, n)  for(n = (s); n < (e); ++n)

class Solver {
public:
  Solver() {}
  ~Solver() {}

  void solve();
};

typedef pair<int, int> pi;

void Solver::solve() {
  int N, i, j;
  cin >> N;
  vvi G(N);
  REP(0, N - 1, i) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    G[a].pb(b);
    G[b].pb(a);
  }

  int min_nodes = N;
  int root;
  REP(0, N, root) {
    int del_nodes = 0;
    vi visited(N, 0);
    set<int> queue;

    vi order(N, -1), parents(N, -1);
    int ord = 0;

    queue.insert(root);
    while(!queue.empty()) {
      int c = *queue.begin();
      queue.erase(queue.begin());
      visited[c] = 1;

      order[ord] = c;

      ord++;

      REP(0, sz(G[c]), j) {
	if(visited[G[c][j]] == 0) {
	  queue.insert(G[c][j]);
	  parents[G[c][j]] = c;
	}
      }
    }

    int LNUM = N * 2;
    vvi costs(N, vi(2, LNUM));
    vi num_children(N, 0);
    REP(0, N, i) {
      int node = order[N - 1 - i];
      int parent = parents[node];
      if(parent == -1)
	continue;

      if(costs[node][0] == LNUM) {
	// 0 children
	costs[parent].pb(-1);
	sort(all(costs[parent]));
	costs[parent].resize(2);
	num_children[parent] += 1;
      }
      else if(costs[node][1] == LNUM) {
	costs[parent].pb(-1);
	sort(all(costs[parent]));
	costs[parent].resize(2);
	num_children[parent] += num_children[node] + 1;
      }
      else {
	int nodes_alive = - costs[node][0] - costs[node][1];
	costs[parent].pb(- nodes_alive - 1);
	sort(all(costs[parent]));
	costs[parent].resize(2);
	num_children[parent] += num_children[node] + 1;
      }
    }

    if(costs[root][0] == LNUM) {
      // 0 children
      del_nodes = 0;
    }
    else if(costs[root][1] == LNUM) {
      del_nodes = N - 1;
    }
    else {
      del_nodes = num_children[root] + costs[root][0] + costs[root][1];
    }

    min_nodes = min(min_nodes, del_nodes);
  }
  cout << min_nodes << endl;

}

int main(int argc, char *argv[]){

  i64 N;
  cin >> N;
  i64 n;

  Solver s;

  REP(0, N, n) {
    cout << "Case #" << n + 1 << ": ";

    s.solve();
  }

  return 0;
}

