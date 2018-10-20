//Coder: Balajiganapathi
#define TRACE
#define DEBUG

#include <algorithm>
#include <bitset>
#include <deque>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<string> vs;

// Basic macros
#define st          first
#define se          second
#define all(x)      (x).begin(), (x).end()
#define ini(a, v)   memset(a, v, sizeof(a))
#define re(i,s,n)  	for(int i=s;i<(n);++i)
#define rep(i,s,n)  for(int i=s;i<=(n);++i)
#define fr(i,n)     re(i,0,n)
#define repv(i,f,t) for(int i = f; i >= t; --i)
#define rev(i,f,t)  repv(i,f - 1,t)
#define frv(i,n)    rev(i,n,0)
#define pu          push_back
#define mp          make_pair
#define sz(x)       (int)(x.size())

const int oo = 2000000009;
const double eps = 1e-9;

#ifdef TRACE
    #define trace1(x)                cerr << #x << ": " << x << endl;
    #define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
    #define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
    #define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
    #define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
    #define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

#else

    #define trace1(x)
    #define trace2(x, y)
    #define trace3(x, y, z)
    #define trace4(a, b, c, d)
    #define trace5(a, b, c, d, e)
    #define trace6(a, b, c, d, e, f)

#endif

const int mx = 1003;
int n;
vi child[mx];
int siz[mx];

int pre(int x, int p) {
    siz[x] = 0;
    fr(i, sz(child[x])) if(child[x][i] != p) siz[x] += pre(child[x][i], x);
    ++siz[x];

    return siz[x];
}
int solve(int x, int p) {
    int ret = 0;
    int ctot = 0, stot = 0;
    int cnt = 0;
    priority_queue<int> q;
    fr(i, sz(child[x])) if(child[x][i] != p) {
        int c = solve(child[x][i], x);
        int s = siz[child[x][i]];
        stot += s;
        ctot += c;
        q.push(s - c);
        if(sz(q) > 2) q.pop();
        ++cnt;
    }
    //trace3(x, p, sz(v));
    int ans;
    if(cnt == 0 || cnt == 2) ans = ctot;
    else if(cnt == 1) ans = stot;
    else {
        assert(sz(q) == 2);
        ans = stot;
        ans -= q.top(); q.pop();
        ans -= q.top(); q.pop();
    }
    //trace2(x, ans);

    return ans;
}

int main() {
    //freopen("sample.txt", "r", stdin);
    freopen("B-small-attempt0.in", "r", stdin);
    //freopen("B-large.in", "r", stdin);

    //freopen("output.txt", "w", stdout);
    freopen("small0.txt", "w", stdout);
    //freopen("large.txt", "w", stdout);
    
    int kases, kase;
    scanf("%d", &kases);
    for(kase = 1; kase <= kases; ++kase) {
        trace1(kase);
        scanf("%d", &n);
        fr(i, n - 1) {
            int x, y;
            scanf("%d %d", &x, &y);
            child[x].pu(y);
            child[y].pu(x);
        }

        int ans = oo;
        rep(root, 1, n) {
            //trace1(root);
            pre(root, -1);
            int cur = solve(root, -1);
            ans = min(ans, cur);
            //trace1(cur);
        }
        
        printf("Case #%d: ", kase);
        printf("%d\n", ans);

        rep(i, 1, n) child[i].clear();
        
    }
    
	return 0;
}
