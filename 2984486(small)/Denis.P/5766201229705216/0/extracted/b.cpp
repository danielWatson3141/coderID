#include <iostream>
#include <vector>
#include <string>
#include <vector>
using namespace std;

int N;
vector<vector<int> > adj;
vector<int> sizes;
vector<int> curRes;

void computeSizes(int node, int parent) {
  sizes[node] = 1;
  for(int i = 0; i < adj[node].size(); i++) {
    int next = adj[node][i];
    if(next != parent) {
      computeSizes(next, node);
      sizes[node] += sizes[next];
    }
  }
}

void go(int node, int parent) {
  for(int i = 0; i < adj[node].size(); i++) {
    int next = adj[node][i];
    if(next != parent) {
      go(next, node);
    }
  }
  // now find out the best way;
  int result = 0;
  // either remove all of the children
  for(int i = 0; i < adj[node].size(); i++) {
    if(adj[node][i] != parent) {
      result += sizes[adj[node][i]];
    }
  }

  // or remove all but two
  for(int i = 0; i < adj[node].size(); i++) {
    if(adj[node][i] == parent) continue;    
    for(int j = i+1; j < adj[node].size(); j++) {
      if(adj[node][j] == parent) continue;
      int one = adj[node][i];
      int two = adj[node][j];
      int localRes = curRes[one] + curRes[two];
      for(int k = 0; k < adj[node].size(); k++) {
	if(k == i || k == j || adj[node][k] == parent) continue;
	localRes += sizes[adj[node][k]];
      }
      if(localRes < result) {
	result = localRes;
      }
    }
  }

  curRes[node] = result;
}

int main() {
  int T;
  cin >> T;

  for(int caseno = 1; caseno <= T; caseno++) {
    cin >> N;
    adj.clear();
    sizes.clear();
    curRes.clear();
    for(int i = 0; i < N; i++) {
      adj.push_back(vector<int>());
      sizes.push_back(-1);
      curRes.push_back(-1);
    }

    for(int i = 0; i < N-1; i++) {
      int x,y;
      cin >> x >> y;
      x--;
      y--;
      adj[x].push_back(y);
      adj[y].push_back(x);
    }

    int result = -1;
    for(int root = 0; root < N; root++) {
      computeSizes(root, root);
      go(root, root);
      if(result == -1 || result > curRes[root]) {
	result = curRes[root];
      }
    }


    cout << "Case #" << caseno << ": " << result << endl;
  }

  return 0;
}
