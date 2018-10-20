#include <vector>
#include <list>
#include <map>
#include <set>
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

#define FOR(i,a,b) for(int i=a;i<b;++i)
#define REP(i,n) FOR(i,0,n)
#define RFOR(i,a,b) for(int i=a;i>=b;i--)
#define RREP(i,n) RFOR(i,n-1,0)
#define ECH(it, v) for(auto it=v.begin();it!=v.end();++it)
#define ALL(x) (x).begin(),(x).end()
#define CLR(x) memset(x,0,sizeof(x))
#define SET(x) memset(x,-1,sizeof(x))
#define MOD 1000000007
typedef long long LL;
typedef unsigned int UI;
typedef unsigned long long UL;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;

int n;
bool g[1000][1000];

int findNC(int in, int r) {
    int ret = 0;
    REP(i, n) {
        if(g[in][i] && i!=r) ret += 1+findNC(i, in);
    }
    return ret;
}

int solve(int in, int root) {
    int ret = 0, deg = 0;
    REP(i, n) if(g[in][i] && i!=root) deg++;
    if(deg == 1) return findNC(in, root);
    if(deg >= 3) {
        VI mn(deg);
        VI nc(deg);
        int ii = 0;
        REP(i, n) if(g[in][i] && i!=root) mn[ii] = solve(i, in), nc[ii] = 1+findNC(i, in), ii += 1;
        /*
        cout<<"MN:\n";
        REP(i, 3) cout<<mn[i]<<endl;
        cout<<"NC:\n";
        REP(i, 3) cout<<nc[i]<<endl;
        */
        ret = MOD;
        int tt = 0;
        REP(i, deg) tt += nc[i];
        REP(i, deg) FOR(j, i+1, deg) ret = min(ret, tt-nc[i]-nc[j]+mn[i]+mn[j]);
    } else if(deg == 2) REP(i, n) if(g[in][i] && i!=root) ret += solve(i, in);
    return ret;
}

int main() {
    #ifdef raaja
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int zz, qq = 0;
    cin>>zz;
    int x, y;
    while(qq++ < zz) {
        scanf("%d", &n);
        CLR(g);
        REP(i, n-1) {
            scanf("%d%d", &x, &y);
            x--, y--;
            g[x][y] = g[y][x] = 1;
        }
        int ans = n-1;
        //REP(i, n) cout<<solve(i, -1)<<endl;
        REP(i, n) ans = min(ans, solve(i, -1));
        printf("Case #%d: %d\n", qq, ans);
    }
}
