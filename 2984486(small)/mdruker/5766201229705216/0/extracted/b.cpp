#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

ifstream in("data.in");
ofstream out("data.out");

int N;
vector< vector<int> > edges;

vector<int> SubtreeSize;
vector<bool> visited;

int calcSubtrees(int curnode) {
  visited[curnode] = true;
  SubtreeSize[curnode] = 1;
  for (int i=0; i<edges[curnode].size(); i++) {
    if (!visited[edges[curnode][i]]) {
      SubtreeSize[curnode] += calcSubtrees(edges[curnode][i]);
    }
  }
  return SubtreeSize[curnode];
}

int numToDelete(int curnode) { 
  visited[curnode] = true;

  int numtodelete = 0;
  vector<int> v;

  for (int i=0; i<edges[curnode].size(); i++) {
    if (!visited[edges[curnode][i]]) {
      numtodelete += SubtreeSize[edges[curnode][i]];
      v.push_back(SubtreeSize[edges[curnode][i]] - numToDelete(edges[curnode][i]));
    }
  }

  sort(v.begin(), v.end());
  if (v.size() > 1) {
    numtodelete -= v[v.size()-1];
    numtodelete -= v[v.size()-2];
  }
  
  return numtodelete;
}

int main() {
  int T;
  in >> T;
  for (int curcase = 1; curcase <= T; curcase++) {
    in >> N;
    edges.clear();
    edges.resize(N+1);
    
    int x,y;
    for (int i=0; i<N-1; i++) {
      in >> x >> y;
      edges[x].push_back(y);
      edges[y].push_back(x);
    }

    int MinToDelete = N-1, CurToDelete;
    for (int r=1; r<=N; r++) {
      visited.clear();
      visited.resize(N+1,0);
      SubtreeSize.clear();
      SubtreeSize.resize(N+1,0);
      calcSubtrees(r);
      
      visited.clear();
      visited.resize(N+1,0);

      CurToDelete = numToDelete(r);
      MinToDelete = min(MinToDelete, CurToDelete);
    }

    out << "Case #" << curcase << ": " << MinToDelete << endl;
  }
}
