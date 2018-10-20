#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <functional>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <stdio.h>
#include <string.h>
using namespace std;

#define FOR(i,a,b)  for(int i=(a),_##i=(b);i<_##i;++i)
#define F(i,a)      FOR(i,0,a)
#define ALL(x)      x.begin(),x.end()
#define PB          push_back
#define S           size()
#define MP          make_pair
typedef long long   LL;

int N;
vector<vector<int> > G;

int memo[1002][1002];

int createTree(int dad, int x) {
    if(memo[dad][x] == -1) {
        int maxi = 0, aux1, aux2;
        F(i, G[x].S) {
            if(dad == G[x][i]) continue;
            aux1 = createTree(x, G[x][i]);
            FOR(j, i+1,  G[x].S) {
                if(dad == G[x][j]) continue;
                aux2 = createTree(x, G[x][j]);
                maxi = max(maxi, aux1 + aux2);
            }
        }
        memo[dad][x] = maxi + 1;
    }
    return memo[dad][x];
}

void read() {
    int A, B;
    cin >> N;
    G = vector<vector<int> > (N+1, vector<int> ());
    F(i, N-1) {
        cin >> A >> B;
        G[A].PB(B);
        G[B].PB(A);
    }
}

void solve() {
    read();
    int mini = 1000000;
    memset(memo, -1, sizeof(memo));
    FOR(i, 1, N+1) {
        int res = createTree(0, i);
        mini = min(N - res, mini);
    }
    cout << mini << endl;
}

int main(){
    // freopen("in.txt", "r", stdin);
    freopen("B-large.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int Te;
    scanf("%d", &Te);
    for(int cas=1; cas<=Te ;cas++) {
        printf("Case #%d: ", cas);
        solve();
    }
}
