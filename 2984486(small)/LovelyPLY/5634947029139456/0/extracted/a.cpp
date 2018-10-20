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

ll s[200];
ll t[200];
ll a[200][200];

int cal (string a, string b){
        int ans = 0;
        FOR (i, 0, SIZE (a)-1){
                if (a[i] != b[i]){
                        ans ++;
                }
        }
        //cout << a << " " << b << " " << ans << endl;
        return ans;
}

ll change (string a){
        ll ans = 0;
        FOR (i, 0, SIZE (a) - 1){
                ans = ans * 2 + a[i] - '0';
        }
        //cout << a << " " << ans << endl;
        return ans;
}

const int N = 210;
vint g[N];
int cx[N], cy[N], cnt;
bool vis[N];

void init (){
        FOR (i, 1, 400)         g[i].clear ();
}

bool findpath (int u){
        FOR (i, 0, SIZE (g[u])-1){
                int v = g[u][i];
                if (!vis[v]){
                        vis[v] = 1;
                        if (cy[v] == -1 || findpath (cy[v])){
                                cx[u] = v;
                                cy[v] = u;
                                return true;
                        }
                }
        }
        return false;
}

int maxmatch (){
        int ans = 0;
        clr (cx, -1), clr (cy, -1);
        FOR (i, 1, cnt){
                if (cx[i] == -1){
                        clr (vis, 0);
                        ans += findpath (i);
                }
        }
        return ans;
}

int solve (int n, set<ll> sset){
        int num = INF;
        for (set<ll>::IT it = sset.begin (); it != sset.end (); it ++){
                //cout << i << endl;
                ll i = *it;
                //cout << i << endl;
                init ();
                FOR (j, 1, n){
                        FOR (k, 1, n){
                                if (a[j][k] == i){
                                        //if (i == 1){
                                        //        cout << j << " " << k << endl;
                                        //}
                                        g[j].PB (k);
                                }
                        }
                }
                if (maxmatch () == n){
                        int ans = 0;
                        FOR (j, 0, 60){
                                if ((1LL<<j) & i){
                                        ans ++;
                                }
                        }
                        //cout << i << " VS " << ans << endl;
                        num = min (num, ans);
                }
        }
        return num;
}

int main (){
freopen ("1.txt", "r", stdin);
      freopen ("3.txt", "w", stdout);
        int T, cass = 1;
        cin >> T;
        while (T --){
                int n, l;
                cin >> n >> l;
                cnt = n;
                FOR (i, 1, n){
                        string a;
                        cin >> a;
                        s[i] = change (a);
                }
                FOR (i, 1, n){
                        string a;
                        cin >> a;
                        t[i] = change (a);
                }
                set<ll> sset;
                FOR (i, 1, n){
                        FOR (j, 1, n){
                                a[i][j] = s[i] ^ t[j];
                                //cout << i << " " << j << " " << a[i][j] << endl;
                                sset.insert (a[i][j]);
                        }
                }
                int num = solve (n, sset);
                printf("Case #%d: ", cass ++);
                if (num == INF) puts ("NOT POSSIBLE");
                else            printf("%d\n", num);
        } 
}
