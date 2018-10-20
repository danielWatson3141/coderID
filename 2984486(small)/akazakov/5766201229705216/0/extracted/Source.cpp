#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>

#include <algorithm>
#include <cmath>
#include <ctime>

#include <stack>
#include <deque>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

#define uLL unsigned long long
#define BIG 1000000000

using namespace std;

#define PROBLEM "B"

struct Node {
    int size;
    vector<int> neighbours;
};

int dfs_calc_sizes(vector<Node> &nodes, int cur_idx, int from_idx) {
    nodes[cur_idx].size = 1;
    auto &nb = nodes[cur_idx].neighbours;
    for (size_t i = 0; i < nb.size(); ++i) {
        if (nb[i] == from_idx) {
            continue;
        }
        nodes[cur_idx].size += dfs_calc_sizes(nodes, nb[i], cur_idx);
    }
    return nodes[cur_idx].size;
}

int dfs_get_answer(vector<Node> &nodes, int cur_idx, int from_idx) {
    int res = 0;
    bool is_root = from_idx < 0;
    auto &nb = nodes[cur_idx].neighbours;
    if (nb.size() == (is_root ? 1 : 2)) {
        for (size_t i = 0; i < nb.size(); ++i) {
            if (nb[i] == from_idx) {
                continue;
            }
            res += nodes[nb[i]].size;
        }
    } else {
        sort(nb.begin(), nb.end(), [=](int a, int b){
            return nodes[a].size < nodes[b].size;
        });
        int todel = int(nb.size()) - (is_root ? 2 : 3);
        int deleted = 0;
        for (size_t i = 0; i < nb.size(); ++i) {
            if (nb[i] == from_idx) {
                continue;
            }
            if (deleted < todel) {
                res += nodes[nb[i]].size;
                ++deleted;
            } else {
                res += dfs_get_answer(nodes, nb[i], cur_idx);
            }
        }
    }
    return res;
}

void solveTestCase() {
    int n;
    cin >> n;
    std::vector<Node> tree(n);
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        tree[x].neighbours.push_back(y);
        tree[y].neighbours.push_back(x);
    }
    int best_res = BIG;
    for (int root = 0; root < n; ++root) {
        dfs_calc_sizes(tree, root, -1);
        int res = dfs_get_answer(tree, root, -1);
        best_res = min(res, best_res);
    }
    cout << best_res << endl;
}

int main() {
    freopen("input_" PROBLEM ".txt", "rt", stdin); //-V530
    freopen("output.txt", "wt", stdout); //-V530
    int num_tests;
    cin >> num_tests;
    for (int i = 1; i <= num_tests; ++i) {
        cerr << i << "\r" << flush;
        cout << "Case #" << i << ": ";
        solveTestCase();
    }
    return 0;
}