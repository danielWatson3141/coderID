#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <deque>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;

typedef double dbl;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<dbl,dbl> pdd;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<dbl> vd;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<pii> vp;

#define eps 1e-9
#define inf 1000000000
#define infll 1000000000000000000LL
#define infdbl 1e15
#define sqr(x) ((x)*(x))
#define pb push_back
#define mp make_pair
#define px first
#define py second
#define sz(x) ((int)(x).size())
#define intclz(x) __builtin_clz(x)
#define intctz(x) __builtin_ctz(x)
#define intln(x) (32-intclz(x))
#define intbc(x) __builtin_popcount(x)
#define llclz(x) __builtin_clzll(x)
#define llctz(x) __builtin_ctzll(x)
#define llln(x) (64-llclz(x))
#define llbc(x) __builtin_popcountll(x)
#define atbit(x,i) (((x)>>(i))&1)
#define tof(x) __typeof(x)
#define FORab(i,a,b) for (int i=(a); i<=(b); ++i)
#define RFORab(i,a,b) for (int i=(a); i>=(b); --i)
#define FOR1(i,n) FORab(i,1,(n))
#define RFOR1(i,n) RFORab(i,(n),1)
#define FOR(i,n) FORab(i,0,(n)-1)
#define RFOR(i,n) RFORab(i,(n)-1,0)
#define allstl(i,x,t) for (t::iterator i = (x).begin(); i!=(x).end(); ++i)
#define rallstl(i,x,t) for (t::reverse_iterator i = (x).rbegin(); i!=(x).rend(); ++i)
#define begend(x) (x).begin(),(x).end()
#define rbegend(x) (x).rbegin(),(x).rend()
#define ms(a,v) memset(a,v,sizeof(a))
#define msn(a,v,n) memset(a,v,n*sizeof(a[0]))
#define mcp(d,s,n) memcpy(d,s,n*sizeof(s[0]))
#define clamp(x,a,b) min(max(x,a),b)

int n, l;

string init[200];
string conv[200];
string targ[200];

int main() {
    freopen("A-small-attempt0.in", "rt", stdin);
    freopen("A-small-attempt0.out", "wt", stdout);

    int T;
    cin>>T;
    FOR1(cas,T) {
        cin>>n>>l;
        FOR(i,n) cin>>init[i];
        FOR(i,n) cin>>targ[i];

        sort(targ, targ+n);

        int cost = l+1;
        FOR(bm,(1<<l)) {
            if (intbc(bm) >= cost) continue;

            FOR(i,n) {
                conv[i] = init[i];
                FOR(j,l) if (bm&(1<<j)) {
                    conv[i][j] = (conv[i][j] == '0' ? '1' : '0');
                }
            }
            sort(conv, conv+n);

            bool same = true;
            FOR(i,n) if (conv[i] != targ[i]) {
                same = false;
                break;
            }

            if (same) cost = min(cost, intbc(bm));
        }

        cout<<"Case #"<<cas<<": ";
        if (cost == l+1) cout<<"NOT POSSIBLE"<<endl;
        else cout<<cost<<endl;
    }

    return 0;
}
