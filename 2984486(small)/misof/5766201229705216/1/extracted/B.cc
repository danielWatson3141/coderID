// another fine solution by misof
// #includes {{{
#include <algorithm>
#include <numeric>

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cassert>

#include <cmath>
#include <complex>
using namespace std;
// }}}

/////////////////// PRE-WRITTEN CODE FOLLOWS, LOOK DOWN FOR THE SOLUTION ////////////////////////////////

// pre-written code {{{
#define SIZE(t) ((int)((t).size()))
// }}}

/////////////////// CODE WRITTEN DURING THE COMPETITION FOLLOWS ////////////////////////////////

int N;
vector< vector<int> > G;
vector<int> best;
vector<int> tsize;

void dfs(int kde, int parent) {
    tsize[kde] = 1;
    vector<int> deti;
    for (int x : G[kde]) if (x != parent) {
        dfs(x,kde);
        tsize[kde] += tsize[x];
        deti.push_back( best[x] );
    }
    if (SIZE(deti)<=1) { best[kde]=1; return; }
    sort( deti.begin(), deti.end() );
    reverse( deti.begin(), deti.end() );
    best[kde] = 1 + deti[0] + deti[1];
}

int solve(int root) {
    best.clear();
    best.resize(N,0);
    tsize.clear();
    tsize.resize(N,0);
    dfs(root,-1);
    return best[root];
}

int main() {
    int TT; cin >> TT;
    for (int tt=1; tt<=TT; ++tt) {
        cin >> N;
        G.clear();
        G.resize(N);
        for (int i=0; i<N-1; ++i) { int x,y; cin >> x >> y; --x; --y; G[x].push_back(y); G[y].push_back(x); }
        int answer = N-1;
        for (int n=0; n<N; ++n) answer = min( answer, N-solve(n) );
        cout << "Case #" << tt << ": " << answer << endl;
    }
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
