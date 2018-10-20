#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <deque>
#include <limits>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cctype>

using namespace std;

inline void readData(int& n,vector< vector<int > >& graph,istream& cin) {
    cin >> n;
    graph.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
}

int go(int v, const int& parent, vector< vector<int> >& graph,vector<int>& bst,vector<int>& weight) {
    if (bst[v] != -1) return bst[v];
    for (auto& w : graph[v]) {
        if (w != parent) {
            go(w, v, graph, bst, weight);
            weight[v] += weight[w];
        }
    }
    
    bst[v] = weight[v];
  
    for (int i = 0; i < (int)graph[v].size(); i++) {
        if (graph[v][i] == parent) continue;
        for (int j = i + 1; j < (int)graph[v].size(); j++) {
           if (graph[v][j] != parent) {
                bst[v] = min(bst[v], weight[v] - weight[graph[v][i]] - weight[graph[v][j]] + bst[graph[v][i]] + bst[graph[v][j]]);
           }
        }
    }
    weight[v]++;
    return bst[v];
}

int solve(istream& cin) {
    int n; 
    vector< vector<int> > graph;
    readData(n, graph, cin);
    int ret = n - 1; 
    for (int root = 0; root < n; root++) {
        vector<int> bst(n,-1);
        vector<int> weight(n);
        ret = min(ret, go(root, -1, graph, bst, weight));
    }
    return ret;
}

int main() {
    ifstream cin("test.in");
    ofstream cout("test.out");
    int testCount;
    cin >> testCount;
    for (int testCase = 1; testCase <= testCount; testCase++) {
        cout << "Case #" << testCase << ": "; 
        cout << solve(cin) << "\n"; 
    }   
    return 0;
}
