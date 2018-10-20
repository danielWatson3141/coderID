#include<cstdio>
#include<cstdlib>
#include<vector>
#include<map>
#include<set>
using namespace std;
int T, N;
vector<int> tree[1010];
int sz[1010];
int fix(int current, int prev) {
    int sons = 0;
    for (int i=0; i<tree[current].size(); i++) {
        // printf("tree[current][i] = %d, prev = %d\n", tree[current][i], prev);
        if (tree[current][i] != prev) sons++;

    }
    // printf("Sons de %d = %d\n", current, sons);
    if (sons == 0) return 0;
    if (sons == 1) {
        int sum = 0;
        for (int i=0; i<tree[current].size(); i++) {
            if (tree[current][i] != prev) {
                sum += sz[tree[current][i]];
            }
        }
        return sum;
    }
    vector<pair<int, int> > costs;
    int totalSize = 0;
    for (int i=0; i<tree[current].size(); i++) {
        if (tree[current][i] != prev) {
            totalSize += sz[tree[current][i]];
            costs.push_back(make_pair(fix(tree[current][i], current), tree[current][i]));
        }
    }
    int ans = 0x3f3f3f3f;
    for (int i=0; i<costs.size(); i++) {
        for (int j=i+1; j<costs.size(); j++){
            ans = min(ans, costs[i].first +
                      costs[j].first +
                      totalSize -
                      sz[costs[j].second] -
                      sz[costs[i].second]);
        }
    }
    return ans;
}

void getSizes(int current, int prev) {
    sz[current] = 1;
    for (int i=0; i<tree[current].size(); i++) {
        if (tree[current][i] != prev) {
            getSizes(tree[current][i], current);
            sz[current] += sz[tree[current][i]];
        }
    }
}

int main() {
    scanf("%d",&T);
    for (int t=1; t<=T; t++) {
        scanf("%d",&N);
        for (int i=0; i<N; i++) tree[i].clear();
        for (int i=0; i<N-1; i++) {
            int a, b;
            scanf("%d%d",&a, &b);
            a--, b--;
            tree[a].push_back(b);
            tree[b].push_back(a);
        }
        int ans = 0x3f3f3f3f;
        for (int i=0; i<N; i++) {
            memset(sz, 0, sizeof sz);
            getSizes(i, -1);
            int res = fix(i, -1);
            // printf("res = %d\n", res);
            ans = min(ans, res);
        }
        printf("Case #%d: %d\n", t, ans);
    }
    return 0;
}
