#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

vector< vector<int> > adjoin;

bool cmp(const pair<int, int> &lhs, const pair<int, int> &rhs) {
    return lhs.second - lhs.first > rhs.second - rhs.first;
}

int DFS(int root, int parent, int &tot) {
    tot = 1;
    vector<pair<int, int> > w;
    for (int j = 0; j < adjoin[root].size(); j++) {
        int child = adjoin[root][j];
        if (child == parent) continue;
        int child_size = 0;
        int child_cut = DFS(child, root, child_size);
        tot += child_size;
        w.push_back(make_pair(child_cut, child_size));
    }
    if (w.size() == 1) return tot - 1;
    sort(w.begin(), w.end(), cmp);
    int ret = 0;
    for (int i = 0; i < w.size(); i++) {
        if (i < 2) ret += w[i].first;
        else ret += w[i].second;
    }
    return ret;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        int n;
        scanf("%d", &n);
        adjoin.clear();
        adjoin.resize(n);
        //adjoin.assign(n, vector(int>());
        for (int i = 0; i < n - 1; i++) {
            int xi, yi;
            scanf("%d%d", &xi, &yi);
            xi--,yi--;
            adjoin[xi].push_back(yi);
            adjoin[yi].push_back(xi);
        }
        int best = n;
        for (int root = 0; root < n; root++) {

            int tot = 0;
            int cur = DFS(root, -1, tot);
            if (cur < best) best = cur;
           // printf("%d:%d\n", root, cur);
        }
        printf("Case #%d: %d\n", cas, best);
    }
    return 0;
}
