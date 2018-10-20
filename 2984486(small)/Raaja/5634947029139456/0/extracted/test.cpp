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

int main() {
    #ifdef raaja
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int zz, qq = 0;
    cin>>zz;
    int n, l;
    char o[150][40], r[150][40];
    VS o1(150), o2(150);
    while(qq++ < zz) {
        int ans = MOD;
        scanf("%d%d", &n, &l);
        REP(i, n) scanf("%s ", o[i]);
        REP(i, n) scanf("%s ", r[i]);
        REP(i, n) {
            o2[i] = "";
            REP(j, l) o2[i] += r[i][j];
        }
        sort(o2.begin(), o2.begin()+n);
        REP(i, 1) {
            REP(j, n) {
                bool f = 1;
                int m = 0;
                REP(k, n) o1[k] = "";
                REP(k, l) {
                    if(o[i][k] == r[j][k]) {
                        REP(kk, n) {
                            o1[kk] += o[kk][k];
                        }
                    } else {
                        m++;
                        REP(kk, n) {
                            o1[kk] += (o[kk][k]=='1'?'0':'1');
                        }
                    }
                }
                sort(o1.begin(), o1.begin()+n);
                REP(k, n) REP(kk, l)
                    if(o1[k][kk] != o2[k][kk]) kk=l, k = n, f = 0;
                if(f) {
                    ans = min(ans, m);
                }
            }
        }
        printf("Case #%d: ", qq);
        if(ans == MOD) printf("NOT POSSIBLE\n");
        else printf("%d\n", ans);
    }
}
