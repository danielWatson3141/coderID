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

const int N = 1e4+10, E = 2e4+10;
int to[E], nxt[E];
int head[N];
int ec;
int dp[E], cnt[E];
void add(int u, int v) {
    to[ec] = v;
    nxt[ec] = head[u];
    head[u] = ec++;
}

void dfs(int e) {
    if (dp[e] != -1) return;
    int u = to[e];
    int &s = cnt[e];
    vector<int> v;
    for (int i = head[u]; i != -1; i = nxt[i]) {
        if ((i^1)==e) continue;
        dfs(i);
        s += cnt[i];
    }

    dp[e] = s;
    for (int i = head[u]; i != -1; i = nxt[i]) {
        if ((i^1)==e) continue;
        for (int j = nxt[i]; j != -1; j = nxt[j]) {
            if ((j^1)==e) continue;
            checkmin(dp[e], s - cnt[i] + dp[i] - cnt[j] + dp[j]);
        }
    }
    s++;
}

int n, m;
int main() {
    int T;
    cin >> T;
    rep(cas, T) {
        mem(head, -1);
        ec = 0;
        mem(cnt, 0);
        mem(dp, -1);
        scanf("%d", &n);
        rep(i, n-1) {
            int u, v;
            scanf("%d%d", &u, &v);
            add(u, v);
            add(v, u);
        }
        rep(i, ec) dfs(i);
        /*
        show(dp, ec);
        show(cnt, ec);
        show(to, ec);
        */
        int ans = 1e9;
        for(int u = 1; u<=n; u++) {
            int s = 0;
            for (int i = head[u]; i != -1; i = nxt[i]) {
                s += cnt[i];
            }

            checkmin(ans, s);
            for (int i = head[u]; i != -1; i = nxt[i]) {
                for (int j = nxt[i]; j != -1; j = nxt[j]) {
                    checkmin(ans, s - cnt[i] + dp[i] - cnt[j] + dp[j]);
                }
            }
        }
        printf("Case #%d: %d\n", cas+1, ans);
    }
    return 0;
}
