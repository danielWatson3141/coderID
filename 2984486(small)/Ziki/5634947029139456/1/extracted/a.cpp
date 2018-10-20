/*==================================================*\
 | Author: ziki
 | Created Time: 
 | File Name: 
 | Description: 
\*==================================================*/
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <string.h>
 
using namespace std;
using namespace rel_ops;
 
typedef long long int64;
typedef long long ll;
typedef unsigned long long uint64;
typedef unsigned long long ull;
const double pi=acos(-1.0);
const double eps=1e-11;
const int inf=0x7FFFFFFF;
template<class T> inline bool checkmin(T &a,T b){return b<a?a=b,1:0;}
template<class T> inline bool checkmax(T &a,T b){return b>a?a=b,1:0;}
template<class T> inline T sqr(T x){return x*x;}
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VII;
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)
#define mem(a,b) memset(a, b, sizeof(a))
#define clr(a) memset(a, 0, sizeof(a))
#define rep(i,n) for(int i=0; i<int(n); i++)
#define repit(i,v) for(typeof(v.begin()) i=v.begin(); i!=v.end(); i++)
#define iter(v) typeof(v.begin())
#define ff first
#define ss second
#define sz(x) int(x.size())
#ifdef LOCAL
#define dbg(args...) printf(args); //##__VA_ARGS__
#define dout cout
#define out(x) (cout<<#x<<": "<<x<<endl)
template<class T>void show(T a, int n){for(int i=0; i<n; ++i) cout<<a[i]<<' '; cout<<endl;}
template<class T>void show(T a, int r, int l){for(int i=0; i<r; ++i)show(a[i],l);cout<<endl;}
#else
#define dbg(...)
#define dout if(true);else cout
#define out(...)
#define show(...)
#endif
int n, L;
string outlet[1101], dev[1101];
ll a[1001], b[1001];

bool check(ll mask, ll len) {
    ll tot = (1ll << len) - 1;
    rep(i, n) {
        ll m1 = a[i] & tot;
        int c1 = 0, c2 = 0;
        rep (j, n) if((a[j]&tot) == m1) c1++;
        rep (j, n) if(((b[j]&tot)^mask) == m1) c2++;
        if (c1 != c2) return false;
    }
    return true;
}

int bfs() {
    queue<pair<ll,int> > q;
    int ans = 1e9;
    q.push(MP(0ll, 0));
    while (!q.empty()) {
        ll mask = q.front().ff, len = q.front().second;
        q.pop();
        if (len == L) {
            int t = 0;
            while(mask>0) {
                t += mask & 1;
                mask >>= 1;
            }
            checkmin(ans, t);
        }
        else {
            if (check(mask|(1ll<<len), len+1)) 
                q.push(MP(mask|(1ll<<len), len+1));
            if (check(mask, len+1)) 
                q.push(MP(mask, len+1));
        }
    }
    return ans;
}

int main() {
    int T;
    cin >> T;
    rep (cas, T) {
        scanf("%d%d", &n, &L);
        clr(a); clr(b);
        rep (i, n) cin >> outlet[i];
        rep (i, n) {
            rep (j, L) 
                a[i] = (a[i]<<1) + (outlet[i][j] == '1');
        }
        rep (i, n) cin >> dev[i];
        rep (i, n) {
            rep (j, L) 
                b[i] = (b[i]<<1) + (dev[i][j] == '1');
        }
        int ans = bfs();
        printf("Case #%d: ", cas+1);
        if (ans == 1e9) puts("NOT POSSIBLE");
        else printf("%d\n", ans);

    }

    return 0;
}
