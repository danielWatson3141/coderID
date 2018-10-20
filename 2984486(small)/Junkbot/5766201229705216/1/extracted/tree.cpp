#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

#undef DEBUG
#ifdef DEBUG
#define D(x...) fprintf(stderr,x)
#else
#define D(x...)
#endif

typedef pair<int,int> pii;

const int MAX_N = 1005;

int N;
vector<int> edges[MAX_N];
bool seen[MAX_N];

void reset(void);
void markUnseen(void);
pair<int,int> solve(int u);
bool comp(pii a, pii b) {
    return (a.first - a.second) < (b.first - b.second);
}

int main() {
    int T;
    scanf("%d",&T);

    for(int z=1;z<=T;z++) {
        reset();

        scanf("%d",&N);

        for(int i=0;i<N-1;i++) {
            int a, b;
            scanf("%d %d",&a,&b);
            a--;
            b--;
            edges[a].push_back(b);
            edges[b].push_back(a);
        }

        int best = N-1;
        for(int i=0;i<N;i++) {
            D("* root = %d\n",i);
            markUnseen();
            seen[i] = true;
            pii s = solve(i);
            best = min(best, s.first);
        }

        printf("Case #%d: %d\n",z,best);
    }

    return 0;
}

void reset(void) {
    for(int i=0;i<MAX_N;i++) {
        edges[i].clear();
    }

    markUnseen();
}

void markUnseen(void) {
    for(int i=0;i<MAX_N;i++) {
        seen[i] = false;
    }
}

// < min cost, total nodes in subtree >
pair<int,int> solve(int u) {
    int totChildren = 0;
    vector<pii> results;

    for(int i=0;i<edges[u].size();i++) {
        int v = edges[u][i];
        if(!seen[v]) {
            seen[v] = true;
            results.push_back(solve(v));
            totChildren += results.back().second;
        }
    }

    pii ans;
    if(results.size() == 0) {
        // 0 cost, 1 node
        ans = make_pair(0, 1);
    } else if(results.size() == 1) {
        // have to delete all the kids
        ans = make_pair(totChildren, totChildren+1);
    } else {
        sort(results.begin(), results.end(), comp);
        ans = make_pair(totChildren + (results[0].first - results[0].second) + (results[1].first - results[1].second), totChildren+1);
    }

    D("** solve(%d): ans = %d, subtreeSize = %d\n",u,ans.first,ans.second);

    return ans;
}
