#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
struct node {
  vector<node *> neighbors;
  node *parent;
  vector <node *> children;
  long long numDescend;
};

long long calcDesc(node *root) {
  if (root->children.size() == 0) return (root->numDescend = 0);
  else {
    for (node *child : root->children) {
      root->numDescend += 1 + calcDesc(child);
    }
    return root->numDescend;
  }
}

// root at k
void root(node *tree, long long k, long long N) {
  vector <node *> used = {};
  vector <node *> layer = {tree + k};
  tree[k].parent = tree+k;
  while (used.size() != N) {
    vector <node *> newLayer;
    for (long long ii = 0; ii < layer.size(); ii++) {
      used.push_back(layer[ii]);
      for (node *n : layer[ii]->neighbors) {
        if (!n->parent) {
          n->parent = layer[ii];
          newLayer.push_back(n);
          layer[ii]->children.push_back(n);
        }
      }
    }
    layer = newLayer;
  }
  calcDesc(tree+k);
}

void unroot(node *tree, long long N) {
  for (long long ii = 0; ii < N; ii++) {
    tree[ii].parent = nullptr;
    tree[ii].children.clear();
    tree[ii].numDescend = 0;
  }
}

long long nodesReq(node *root) {
  long long numChildren = root->children.size();
  if (numChildren == 0) return 0;
  else if (numChildren == 1) return root->numDescend;
  else if (numChildren == 2) return nodesReq(root->children[0]) + nodesReq(root->children[1]);
  else {
    long long c, sum = 0;
    vector<long long> val;
    for (node *child : root->children) {
      val.push_back(child->numDescend - nodesReq(child));
      sum += child->numDescend;
    }
    sort(val.begin(), val.end());
    sum -= val[numChildren-1] + val[numChildren-2];
    return sum + numChildren - 2;
  }
}

int main() {
  long long T;
  cin >> T;
  for (long long ii = 1; ii <= T; ii++) {
    long long N, X, Y;
    cout << "Case #" << ii << ": ";
    cin >> N;
    node tree[N];
    for (long long jj = 1; jj < N; jj++) {
      cin >> X >> Y;
      tree[X-1].neighbors.push_back(tree+(Y-1));
      tree[Y-1].neighbors.push_back(tree+(X-1));
    }

    long long best = N, n;
    for (long long jj = 0; jj < N; jj++) {
      unroot(tree, N);      
      root(tree, jj, N);      
      n = nodesReq(tree+jj);
      if (n < best) {
        best = n;
      }
    }
    cout << best << endl;
  }
}
