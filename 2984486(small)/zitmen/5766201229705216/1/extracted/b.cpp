#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

set<int> nodes[1000];

int build_full_tree(int root, int parent) {
    int n, best_n;
    if ((parent < 0) && nodes[root].size() == 2) { // 2 children
        best_n = 1 + build_full_tree(*(nodes[root].begin()), root) + build_full_tree(*(++(nodes[root].begin())), root);
    } else if (nodes[root].size() <= 2) {  // (0) single root with no children, (1) leaf or a (2) node with only one child!
        best_n = 1;
    } else {   // full-sized inner node
        best_n = 1;
        for (set<int>::iterator it = nodes[root].begin(); it != nodes[root].end(); ++it) {
            if (*it == parent) continue;
            for (set<int>::iterator jt = it; jt != nodes[root].end(); ++jt) {
                if (jt == it) continue;
                if (*jt == parent) continue;
                n = 1 + build_full_tree(*it, root) + build_full_tree(*jt, root);
                if (n > best_n) {
                    best_n = n;
                }
            }
        }
    }
    return best_n;
}

int main() {
    int T, N, X, Y, tree_size, max_tree_size;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            nodes[i].clear();
        }
        for (int i = 1; i < N; i++) {
            cin >> X >> Y;
            nodes[X - 1].insert(Y - 1);
            nodes[Y - 1].insert(X - 1);
        }
        max_tree_size = 1;
        for (int i = 0; i < N; i++) {
            if (nodes[i].size() != 1) { // !leaf
                tree_size = build_full_tree(i, -1);
                if (tree_size > max_tree_size) {
                    max_tree_size = tree_size;
                }
            }
        }
        cout << "Case #" << t << ": " << (N - max_tree_size) << '\n';
    }
    cout << flush;
    return 0;
}