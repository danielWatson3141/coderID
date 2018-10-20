#include <iostream>
#include <vector>
using namespace std;

#define pb push_back

int dfs(int node, int parent, vector< vector<int> > &graph, vector<int> &children, const vector< vector<int> > &orig) {
  int under = 1;
  for (int x=0; x < (int)orig[node].size(); x++) {
    int v = orig[node][x];
    if (v != parent) {
      graph[node].pb( v );
      under += dfs(v, node, graph, children, orig);
    }
  }
  children[node] = under;
  return under;
}

int solve(int node, const vector< vector<int> > &graph, const vector<int> &desc) {
  int numChild = graph[node].size();
  if (numChild == 0) {
    return 0;
  } else if (numChild == 1) {
    return desc[node] - 1;
  } else {
    vector<int> costs;
    int X = graph[node].size();
    int descSum = 0;
    for (int i=0; i < X; i++) {
      int v = graph[node][i];
      descSum += desc[ v ];
      costs.push_back( solve(v, graph, desc) );
    }
    int result = (int)2e9;
    for (int i=0; i < X; i++)
    for (int j=i+1; j < X; j++) {
      int totalCost = costs[i] + costs[j] + descSum - desc[ graph[node][i] ] - desc[ graph[node][j] ] ;
      result = min(result, totalCost);
    }
    return result;
  }
}

int main() {
  int T; cin>>T;
  for (int t=1; t <= T; t++) {
    cout << "Case #" << t << ": ";
    int N; cin>>N;
    vector< vector<int> > adj(N);
    for (int i=1; i < N; i++) {
      int x, y; cin>>x>>y; --x; --y;
      adj[x].pb(y);
      adj[y].pb(x);
    }
    int ans = (int)2e9;
    for (int root=0; root < N; root++) {
      vector< vector<int> > adj2(N);
      vector< int > under ( N );
      dfs(root, root, adj2, under, adj);
      ans = min(ans, solve(root, adj2, under));
    }
    cout << ans << endl;
  }
}
