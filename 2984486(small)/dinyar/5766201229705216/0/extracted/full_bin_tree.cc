#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <utility>
#include <iomanip> 
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <set>

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::map;
using std::set;

int count_children(int root, 
                          map<int, vector<int> > graph, 
                          set<int> frontier)
{
  int children = 0;

  vector<int> neighbour_cands = graph[root];
  //  cout << "candidates: " << neighbour_cands.size() << endl;

  for(vector<int>::iterator neighbour = neighbour_cands.begin();
      neighbour != neighbour_cands.end();
      ++neighbour) {
    if(frontier.find(*neighbour) == frontier.end()) {
      ++children;
    }
  }
  return children;
}

vector<int> get_children(int root, 
                          map<int, vector<int> > graph, 
                          set<int> frontier)
{
  vector<int> children;
  vector<int> neighbour_cands = graph[root];
  for(vector<int>::iterator neighbour = neighbour_cands.begin();
      neighbour != neighbour_cands.end();
      ++neighbour) {
    if(frontier.find(*neighbour) == frontier.end()) {
      children.push_back(*neighbour);
    }
  }
  return children;
}

int find_largest_bin_tree(int root, 
                          map<int, vector<int> > graph, 
                          set<int> frontier)
{

  //  cout << "at root " << root << endl;

  int num_children = count_children(root, graph, frontier);
  if (num_children < 2) {
    //cout << "have less than 2 children" << endl;
    return 1;
  } else {
    //cout << "have more children" << endl;
    vector<int> tree_sizes;
    vector<int> children = get_children(root, graph, frontier);
    for(vector<int>::iterator child = children.begin();
        child != children.end();
        ++child) {
      set<int> new_frontier = frontier;
      new_frontier.insert(root);
      int tmp = 0;
      tmp = find_largest_bin_tree(*child, graph, new_frontier);
      tree_sizes.push_back(tmp);
    }
    std::sort(tree_sizes.begin(), tree_sizes.end());
    return 1 + tree_sizes.at(tree_sizes.size()-1) + tree_sizes.at(tree_sizes.size()-2);
  }
  cout << "ERROR: We shouldn't land here!" << endl;
}

int find_result(map<int, vector<int> > graph)
{
  int result = 0;
  for (map<int, vector<int> >::iterator root = graph.begin();
       root != graph.end();
       ++root) {
    set<int> frontier;
    int prelim_result = find_largest_bin_tree(root->first, graph, frontier);
    if(prelim_result > result) {
      result = prelim_result;
    }
  }
  return result;
}

int main()
{
  std::string filename = "testFile_small.in";
  std::ifstream file(filename.c_str());
  int numCases;

  file >> numCases;

  for(int i = 0; i < numCases; ++i) {
    int N;
    file >> N;

    map<int, vector<int> > graph;
    for (int j = 0; j < N-1; ++j) {
      int x, y;
      file >> x >> y;
      vector<int> x_vec, y_vec;
      x_vec = graph[x];
      y_vec = graph[y];
      x_vec.push_back(y);
      y_vec.push_back(x);
      graph[x] = x_vec;
      graph[y] = y_vec;
    }

    int result;
    result = find_result(graph);

    // WARN: Result is largest bin tree. Need to subtract this from number od nodes.
    std::cout << "Case #" << i+1 << ": " << N-result << std::endl;
  }
}
