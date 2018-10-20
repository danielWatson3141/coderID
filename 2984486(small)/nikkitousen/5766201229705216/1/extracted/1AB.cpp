#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <stack>

using namespace std;

#define FOR(i, A, B) for(int i=(A); i<(B); i++)
#define REP(i, N) for(int i=0; i<(N); i++)
#define SZ(v) ((int)(v).size())
#define ALL(v) (v).begin(), (v).end()
#define SORT(v) sort(ALL(v))
#define CLEAR(v) memset((v), 0, sizeof(v))
#define MP make_pair
#define PB push_back

int N;
vector<int> adj[1010];
int tsize[1010];

void calc(int root, int parent) {
    tsize[root] = 1;
    if(parent != -1 and SZ(adj[root]) == 1) return;
    if(parent == -1 and SZ(adj[root]) == 0) return;
    REP(i, SZ(adj[root])) {
        int v = adj[root][i];
        if(v != parent) calc(v, root), tsize[root] += tsize[v];
    }
}
        
        

int go(int root, int parent) {
    if(parent != -1 and SZ(adj[root]) == 1) return 0;
    if(parent != -1 and SZ(adj[root]) == 2) {
        REP(i, SZ(adj[root])) {
            int v = adj[root][i];
            if(v != parent) return tsize[v];
        }
    }
    if(parent == -1 and SZ(adj[root]) == 0) return 0;
    if(parent == -1 and SZ(adj[root]) == 1) {
        REP(i, SZ(adj[root])) {
            int v = adj[root][i];
            if(v != parent) return tsize[v];
        }
    }
    
    vector< pair<int, int> > res;
    REP(i, SZ(adj[root])) {
        int v = adj[root][i];
        if(v != parent) res.PB(MP(go(v, root), v));
    }
    
    int ret = 1001;
    int TOT = 0;
    REP(k, SZ(res)) TOT += tsize[res[k].second];
    REP(i, SZ(res)) {
        FOR(j, i+1, SZ(res)) {
            ret = min(ret, TOT-tsize[res[i].second]-tsize[res[j].second]+res[i].first+res[j].first);
        }
    }
    
    return ret;
}

int main()
{
    int T;
    cin >> T;
    FOR(caso, 1, T+1) {
        cin >> N;
        REP(i, N) adj[i].clear();
        
        REP(i, N-1) {
            int a, b;
            cin >> a >> b;
            adj[a-1].PB(b-1);
            adj[b-1].PB(a-1);
        }
        
        int best = 1001;
        REP(root, N) {
            // cout << "root " << root << endl;
            calc(root, -1);
            // REP(i, N) cout << tsize[i] << endl;
            best = min(best, go(root, -1));
        }
        cout << "Case #" << caso << ": " << best << endl;
    }
}
