#include <iostream>
#include <map>
#include <set>
#include <stdexcept>
#include <vector>

using namespace std;

int getsize(int nodeid, int parent, multimap<int, int>& edges) {
  set<int> childset;
  pair<multimap<int, int>::iterator, multimap<int, int>::iterator> range;
  range = edges.equal_range(nodeid);
  
  for (multimap<int, int>::iterator it = range.first; it != range.second; ++it) {
    if (it->second != parent) {
      childset.insert(it->second);
    }
  }
  vector<int> children(childset.begin(), childset.end());
  int sum = 0;
  for (int i = 0; i < children.size(); ++i) {
    sum += getsize(*(children.begin() + i), nodeid, edges);
  }
  return 1 + sum;
}

int compute(int nodeid, int parent, multimap<int, int>& edges) {
  set<int> childset;
  pair<multimap<int, int>::iterator, multimap<int, int>::iterator> range;
  range = edges.equal_range(nodeid);
  //cout << "children of " << nodeid << ":";
  for (multimap<int, int>::iterator it = range.first; it != range.second; ++it) {
    if (it->second != parent) {
      childset.insert(it->second);
      //cout << " " << children.back();
    }
  }
  vector<int> children(childset.begin(), childset.end());
  //cout << endl;
  if (0 == children.size()) {
    return 0;
  }
  if (1 == children.size()) {
    return getsize(*(children.begin()), nodeid, edges);
  }
  if (2 == children.size()) {
    return compute(*(children.begin()), nodeid, edges) + 
               compute(*(children.begin() + 1), nodeid, edges);
  }
  if (children.size() > 2) {
    int best = 10000000;
    for (int l = 0; l < children.size(); ++l) {
      for (int r = l + 1; r < children.size(); ++r) {
        int curr = compute(children.at(l), nodeid, edges) +
                     compute(children.at(r), nodeid, edges);
        for (int del = 0; del < children.size(); ++del) {
          if (del != l && del != r) {
            curr += getsize(children.at(del), nodeid, edges);
          }
        }
        if (curr < best) {
          best = curr;
        } 
      }
    }
    return best;
  }
  throw logic_error("not possible");
}

int main() {
  int ncases;
  cin >> ncases;
  
  for (int c = 0; c < ncases; ++c) {
    cout << "Case #" << c + 1 << ": ";
    int numNodes;
    cin >> numNodes;
    multimap<int, int> edges;
    set<int> nodes;
    
    int mindel = numNodes;
    
    for (int e = 0; e + 1 < numNodes; ++e) {
      int e1, e2;
      cin >> e1 >> e2;
      nodes.insert(e1);
      nodes.insert(e2);
      edges.insert(make_pair(e1, e2));
      edges.insert(make_pair(e2, e1));
    }
      for (set<int>::iterator nodeit = nodes.begin(); 
           nodeit != nodes.end(); ++nodeit) {
           int currdel = compute(*nodeit, -1, edges);
           //cout << "node=" << *nodeit << " mindel=" << mindel << endl;
           if (currdel < mindel) {
             mindel = currdel;
           }
      }
    cout << mindel << endl;
  }
  return 0;
}

