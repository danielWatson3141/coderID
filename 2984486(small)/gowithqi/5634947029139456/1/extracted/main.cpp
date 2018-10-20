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

int n, l;
FILE* fin = fopen("/Users/zhangzhiqi/code/xcode/competition/competition/data.txt", "r");
FILE* fout = fopen("/Users/zhangzhiqi/code/xcode/competition/competition/output.txt", "w");

int count1(ll t) {
    int ret = 0;
    while (t) {
        ++ret;
        t = t&(t-1);
    }
    return ret;
}

int solve(int n, int l) {
    int ret = 100;
    VL a, b;
    rep(i, 0, n) {
        char t1[40];
        fscanf(fin, "%s", t1);
        a.push_back(strtol(t1, NULL, 2));
    }
    rep(i, 0, n) {
        char t1[40];
        fscanf(fin, "%s", t1);
        b.push_back(strtol(t1, NULL, 2));
    }
    
    sort(all(a));
    sort(all(b));
    
    rep(i, 0, n) {
        ll c = a[0] ^ b[i];
        VL aa;
        rep(j, 0, n) {
            aa.push_back(a[j] ^ c);
        }
        sort(all(aa));
        
        bool flag = true;
        rep(j, 0, n) {
            if (aa[j] != b[j]) {flag = false; break;}
        }
        if (flag) {
            int t = count1(c);
            if (t < ret) ret = t;
        }
    }
    
    if (ret == 100) ret = -1;
    return ret;
}
int main(int argc, const char * argv[])
{
    //fin = stdin;
    //fout = stdout;
    int _, __ = 0;
    fscanf(fin, "%d", &_);
    for (; _; _--) {
        fscanf(fin, "%d%d", &n, &l);
        int ret = solve(n, l);
        if (ret  < 0) fprintf(fout, "Case #%d: NOT POSSIBLE\n", ++__);
        else fprintf(fout, "Case #%d: %d\n", ++__, ret);
    }
    
    return 0;
}

