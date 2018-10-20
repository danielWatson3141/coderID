#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <cmath>
#include <cstdio>
#include <string>
#include <complex>
#include <stack>
#include <iomanip>
#include <map>

using namespace std;
typedef long double ld;
typedef complex<ld> pt;
typedef vector<pt> pol;

int dp[1001];

int dfs(vector<int>*adj, int k, int prev) {
    if(dp[k] != -1) {
        return dp[k];
    }
    if(adj[k].size() < 3 && prev != -1 || adj[k].size() < 2 && prev == -1) {
        return 1;
    }
    int max1 = 0, max2 = 0;
    for(int j=0, _j = adj[k].size(); j<_j; j++) {
        if(adj[k][j] == prev) continue;
        int hmm = dfs(adj, adj[k][j], k);
        if(hmm > max1) {
            max2 = max1;
            max1 = hmm;
        } else if(hmm > max2) {
            max2 = hmm;
        }
    }
    dp[k] = max1 + max2 + 1;
    return dp[k];
}

int main() {
    int N;
    cin >> N;
    for (int kase = 1; kase<=N; kase++) {
        cout << "Case #" << kase << ": ";
        int n; cin >> n;
        vector<int> *adj = new vector<int>[n];
        for(int j=0; j<n-1; j++) {
            int x, y; cin >> x >> y;
            x--; y--;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        int xam = 0;
        for(int k=0; k<n; k++) {
            for(int i=0; i<n; i++) dp[i] = -1;
            int hmm = dfs(adj, k, -1);
            xam = max(xam, hmm);
            //cerr << k << " " << xam << endl;
        }
        cout << n-xam << endl;
    }
    return 0;    
}
