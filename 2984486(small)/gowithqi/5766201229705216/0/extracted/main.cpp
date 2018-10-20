#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#include <cassert>
#include <complex>
#include <time.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<(int)n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define ACCU accumulate
#define TWO(x) (1<<(x))
#define TWOL(x) (1ll<<(x))
#define clr(a) memset(a,0,sizeof(a))
#define POSIN(x,y) (0<=(x)&&(x)<n&&0<=(y)&&(y)<m)
#define PRINTC(x) printf("Case #%d: %d\n",++__,x)
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long ll;
typedef long double LD;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<ll> VL;
typedef vector<PII> VPII;
typedef complex<double> CD;
const int inf=0x20202020;
const ll mod=1000002013;
const double eps=1e-9;
const double pi=3.1415926535897932384626;
const int DX[]={1,0,-1,0},DY[]={0,1,0,-1};
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll powmod(ll a,ll b,ll mod) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

//typedef pair<list<SS>::iterator, list<SS>::iterator> PTT;

int n;
int m = 1000;
int ed[1000][1000];
int edd[1000][1000];
int node[1000];
FILE* fin = fopen("/Users/zhangzhiqi/code/xcode/competition/competition/data.txt", "r");
FILE* fout = fopen("/Users/zhangzhiqi/code/xcode/competition/competition/output.txt", "w");

bool check() {
    bool ret = true;
    bool flag2 = false;
    rep(i, 0, n) {
        if (node[i] == 2) {
            if (!flag2) flag2 = true;
            else return false;
        } else if (node[i]!=3 && node[i] != 1 && node[i] != 0) {
            return false;
        } else {}
    }
    return ret;
}

void dfs(int d) {
//    if (check()) {
//        if (d < m) m = d;
//        return;
//    } else {
//        if (d >= m) return;
//    }

    if (d >= m) return;
    rep(i, 0, n) {
        if (node[i] == 1) {
            node[i] = 0;
            VPII r;
            rep(j, 0, n) {
                if (ed[i][j]) {
                    node[j]--;
                    ed[i][j] = 0;
                    ed[j][i] = 0;
                    PII t; t.first = i; t.second = j;
                    r.push_back(t);
                }
            }
            
            if (check()) m = d+1;
            else {
                dfs(d+1);
                node[i] = 1;
                rep(i, 0, r.size()) {
                    PII t = r[i];
                    node[t.second]++;
                    ed[t.first][t.second] = 1;
                    ed[t.second][t.first] = 1;
                }
            }
        }
    }
    return;
}

int solve(int n) {
    rep(i, 0, n-1) {
        int s, e;
        fscanf(fin, "%d%d", &s, &e);
        ed[s][e] = 1; edd[s][e] = 1;
        ed[e][s] = 1; edd[e][s] = 1;
        node[s]++;node[e]++;
    }
    
    if (check()) m = 0;
    else dfs(0);
    
    return m;
}
int main(int argc, const char * argv[])
{
    //fin = stdin;
    //fout = stdout;
    int _, __ = 0;
    fscanf(fin, "%d", &_);
    for (; _; _--) {
        clr(ed);
        clr(node);
        m = 1000;
        fscanf(fin, "%d", &n);
        int ret = solve(n);
        fprintf(fout, "Case #%d: %d\n", ++__, ret);
    }
    
    return 0;
}

