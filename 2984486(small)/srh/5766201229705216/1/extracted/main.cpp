#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

typedef uint64_t ul;
typedef size_t sz;

struct data {
    std::vector<std::vector<int> > a;
    std::vector<int> depth;
    std::vector<int> treesize;

    void fill_data(int k, int d) {
        depth[k] = d;
        for (int neigh : a[k]) {
            if (depth[neigh] == -1) {
                fill_data(neigh, d + 1);
            }
        }

        int sz = 1;
        for (int neigh : a[k]){
            if (depth[neigh] > d) {
                sz += treesize[neigh];
            }
        }
        treesize[k] = sz;
    }

    int trim_cost(int k) {
        int ncount = 0;
        std::vector<int> nsizes;
        std::vector<int> trimcosts;
        std::vector<int> diffs;
        int sizesum = 0;
        for (int neigh : a[k]) {
            if (depth[neigh] > depth[k]) {
                ncount ++;
                nsizes.push_back(treesize[neigh]);
                sizesum += treesize[neigh];
                int tc = trim_cost(neigh);
                trimcosts.push_back(tc);
                diffs.push_back(treesize[neigh] - tc);
            }
        }

        if (ncount == 0) {
            return 0;
        }

        if (ncount == 1) {
            return nsizes[0];
        }

        // cost = sum(treesize[neigh]) - treesize[i] - treesize[j] + trimcost[i] + trimcost[j]

        std::sort(diffs.begin(), diffs.end());
        std::reverse(diffs.begin(), diffs.end());
        // maximum subtraction.
        return sizesum - diffs[0] - diffs[1];
    }

// cost if N was root.
int compute_root_cost(int N, int I, std::vector<std::pair<int, int> > e) {
    a.resize(N);
    depth.resize(N, -1);
    treesize.resize(N, -1);
    for (auto p : e) {
        a[p.first].push_back(p.second);
        a[p.second].push_back(p.first);
    }

    fill_data(I, 0);

    int cost = trim_cost(I);
    return cost;
}

};



int main() {
    int T;
    std::cin >> T;
    for (int casenum = 1; casenum <= T; ++casenum) {
        int N;
        std::cin >> N;
        std::vector<std::pair<int, int> > e;
        for (int i = 0; i < N - 1; ++i) {
            int xi, yi;
            std::cin >> xi >> yi;
            --xi;
            --yi;
            e.push_back(std::make_pair(std::min(xi, yi),
                                       std::max(xi, yi)));
        }

        std::sort(e.begin(), e.end());

        // one node has 2 neighbors
        // the rest have 3 neighbors or 1 neighbor.

        int min_cost = N + 5;
        for (int i = 0; i < N; ++i) {
            data d;
            int cost = d.compute_root_cost(N, i, e);
            min_cost = std::min(cost, min_cost);
        }

        std::cout << "Case #" << casenum << ": " << min_cost << std::endl;
    }
}
