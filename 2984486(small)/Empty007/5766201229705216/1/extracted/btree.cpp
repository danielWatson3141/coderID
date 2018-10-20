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
#include <cstring>

using namespace std;

#define pb push_back
#define mp make_pair

#define ALL(x) (x).begin(),(x).end()
#define CLR(a,b) memset(a,b,sizeof(a))
#define REPN(x,a,b) for (int x=a; x<b;++x)
#define REP(x,b) REPN(x, 0, b)

#define dbg(x) cout << #x << " = " << x << endl;
#define dbg2(x, y) cout << #x << " = " << x << "  " << #y << " = " << y << endl;
#define dbg3(x, y, z) cout << #x << " = " << x << "  " << #y << " = " << y << "  " << #z << " = " << z << endl;
#define dbg4(x, y, z, w) cout << #x << " = " << x << "  " << #y << " = " << y << "  " << #z << " = " << z << "  " << #w << " = " << w <<  endl;

vector <int> G[1005];

int go(int u, int par) {
    vector <int> S;
    REP(i, G[u].size()) {
        int v = G[u][i];
        if (v == par) continue;
        S.pb(go(v, u));
    }

    sort(ALL(S));
    int n = int(S.size());
    if (n < 2) return 1;
    return S[n-1]+S[n-2]+1;
}

int main() { 
    int N, T;

    cin >> T;
    
    REP(tc, T) {
        cin >> N;
        REPN(i, 1, N+1) G[i].clear();
        int x, y;
        REP(i, N-1) {
            cin >> x >> y;
            G[x].pb(y);
            G[y].pb(x);
        }

        int res = 0;

        REPN(i, 1, N+1) {
            int have = go(i, -1);
            res = max(have, res);
        }

        printf("Case #%d: %d\n", tc+1, N - res);
    }
	
	return 0;
}
