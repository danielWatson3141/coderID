#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define PB              push_back
#define SIZE(x)         (int)x.size()
#define clr(x,y)        memset(x,y,sizeof(x))
#define MP(x,y)         make_pair(x,y)
#define RS(n)           scanf ("%s", n)
#define ALL(t)          (t).begin(),(t).end()
#define FOR(i,n,m)      for (int i = n; i <= m; i ++)
#define ROF(i,n,m)      for (int i = n; i >= m; i --)
#define IT              iterator
#define FF              first
#define SS              second

typedef long long               ll;
typedef unsigned int            uint;
typedef unsigned long long      ull;
typedef vector<int>             vint;
typedef vector<string>          vstring;
typedef pair<int, int>          PII;

void RI (int& x){
        x = 0;
        char c = getchar ();
        while (!(c>='0' && c<='9' || c=='-'))     c = getchar ();
        bool flag = 1;
        if (c == '-'){
                flag = 0;
                c = getchar ();
        }
        while (c >= '0' && c <= '9'){
                x = x * 10 + c - '0';
                c = getchar ();
        }
        if (!flag)      x = -x;
}
void RII (int& x, int& y){RI (x), RI (y);}
void RIII (int& x, int& y, int& z){RI (x), RI (y), RI (z);}
void RC (char& c){
        c = getchar ();
        while (c == ' '||c == '\n')     c = getchar ();
}
char RC (){
        char c = getchar ();
        while (c == ' '||c == '\n')     c = getchar ();
        return c;
}

/**************************************END define***************************************/

const ll mod = 1e9+7;
const ll LINF = 1e18;
const int INF = 1e9;
const double EPS = 1e-8;

const int N = 1005;

vint g[N];
int n;

void init (){
        FOR (i, 1, 1000){
                g[i].clear ();
        }
}

int dp[1005];
int sum[1005];

int dfs (int u, int fa){
        dp[u] = 0;
        sum[u] = 1;
        vint vec;
        FOR (i, 0, SIZE (g[u])-1){
                int v = g[u][i];
                if (v == fa)    continue;
                dfs (v, u);
                sum[u] += sum[v];
                vec.PB (dp[v]);
        }
        sort (ALL (vec));
        if (SIZE (vec) < 2){
                dp[u] = 1;
        }else{
                int sz = SIZE (vec);
                dp[u] = 1 + vec[sz-1] + vec[sz-2];
        }
        return sum[u] - dp[u];
}

int main (){
        freopen ("1.txt", "r", stdin);
        freopen ("2.txt", "w", stdout);
        int T, cass = 1;
        cin >> T;
        while (T --){
                init ();
                cin >> n;
                FOR (i, 1, n-1){
                        int x, y;
                        cin >> x >> y;
                        g[x].PB (y);
                        g[y].PB (x);
                }
                int ans = INF;
                FOR (i, 1, n){
                        clr (dp, 0);
                        clr (sum, 0);
                        ans = min (ans, dfs (i, 0));
                        //cout << i << " VS " << dp[i] << endl;
                }
                printf("Case #%d: %d\n", cass ++, ans);
        }
}
