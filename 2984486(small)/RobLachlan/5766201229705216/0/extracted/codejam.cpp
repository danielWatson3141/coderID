#include <iostream>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <set>



using namespace std;







pair<int, int> cost_with_root(const map<int, vector<int>> & adjacent, int root, 
			      vector<bool> & visited) {
  const int N = adjacent.size();
  auto child_costs = vector<pair<int, int>>();
  auto & adj_v = adjacent.at(root);
  visited[root] = true;
  for (auto node: adj_v){
    if(!visited[node]){
      child_costs.push_back(cost_with_root(adjacent, node, visited));
    }
  }
  if (child_costs.empty()){
    return make_pair(0,1);
  }
  if (child_costs.size() == 1){
    return make_pair(child_costs[0].second, child_costs[0].second + 1);
  }
  int descendants = 0;
  for (auto & p: child_costs){
    descendants += p.second;
  }
  int min_subtree_cost = N;
  for(int n1 = 0; n1 < child_costs.size() - 1; ++n1){
    for(int n2 = n1 + 1; n2 < child_costs.size() ; ++n2){
      int this_cost = 0;
      for (int i=0; i<child_costs.size(); ++i){
	if (i == n1 || i == n2){
	  this_cost += child_costs[i].first;
	} else {
	  this_cost += child_costs[i].second;
	}
      }
      min_subtree_cost = min(min_subtree_cost, this_cost);
    }
  }
  return make_pair(min_subtree_cost, descendants + 1);
}




int cost(const map<int, vector<int>> & adjacent){
  const int N = adjacent.size();
  int min_cost = N;
  auto visited = vector<bool>(N + 1, false);
  for(int root=1; root<=adjacent.size(); ++root){
    min_cost = min(min_cost, cost_with_root(adjacent, root, visited).first);
    fill(visited.begin(), visited.end(), false);
  }
  return min_cost;
}




void do_case(int casenum) {
  auto adjacent = map<int, vector<int>>();
  int N;
  cin >> N;
  for(int i=0; i<N-1; ++i){
    int u, v;
    cin >> u >> v;
    adjacent[u].push_back(v);
    adjacent[v].push_back(u);
  }
  cout << "Case #" << casenum << ": " << cost(adjacent) << '\n';
}



int main() {
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  for (int i = 1; i<=T; ++i){
    do_case(i);
  }
  return 0;
}
