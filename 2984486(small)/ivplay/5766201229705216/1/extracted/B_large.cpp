#include<algorithm>
#include<bitset>
#include<cctype>
#include<cmath>
#include<complex>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<functional>
#include<iostream>
#include<istream>
#include<iterator>
#include<list>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<strstream>
#include<string>
#include<utility>
#include<vector>
#include<iomanip>
#include<ctime>
using namespace std;
/***************************************************************************************************************************************/
typedef long long int LLI;
typedef unsigned long long int ULLI;
#define IMAX ((unsigned)1<<31)-1
#define eps 1e-11
#define LIMAX (1LL<<63)-1
#define ULIMAX (1LL<<64)-1
#define UIMAX ((LLI)1<<32)-1
#define MP(X,Y) make_pair(X,Y)

#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b,c) for(int i=a;i<=b;i+=c)

#define fill(a,v) memset(a,v,sizeof(a))
#define DEBUG(x) cout << #x << ": " << x << endl;
#define SZ(X) ((int)X.size())
#define all(x) (x).begin(),(x).end()
#define SORT(x) sort(all(x))
#define VI vector<int>
#define VS vector<string>
#define PB push_back
#define REV(a) reverse(all(a))
typedef pair<int, int>PII;
typedef pair<LLI, LLI>PLL;
typedef pair<char, int>PCI;
typedef pair<int, char>PIC;
typedef pair<double, double>PDD;
#define MSI map<string,int>
#define MSLI map<string,LLI>
#define MCI map<char,int>
template<class T> inline T MIN_3(T a, T b, T c)
{
    return min(min(a, b), c);
}
template<class T> inline T MAX_3(T a, T b, T c)
{
    return max(max(a, b), c);
}
#define ACM(x) accumulate(all(x),0);
#define CAP(x,y,z) set_intersection (all(x), all(y), z.begin())
#define CUP(x,y,z) set_union(all(x),all(y),z.begin())
#define DIF(x,y,z) set_difference (all(x),all(y),z.begin());
#define BRPS(n,bit) bitset<bit>(n)
#define DSORT(X)  sort(X.rbegin(), X.rend());
#define read(x) freopen(#x".txt","r",stdin)
#define write(x) freopen(#x".txt","w",stdout)
#define LB(A, x) (lower_bound(all(A), x) - A.begin())//exactly where it starts
#define UB(A, x) (upper_bound(all(A), x) - A.begin())
#define UNQ(x) SORT(x),(x).erase(unique(all(x)),x.end())

template<class T> inline T BIGMOD(T n, T m, T mod)
{
    LLI ans = 1;
    LLI k = n;
    while(m)
    {
        if(m & 1)
        {
            ans *= k;
            if(ans>mod) ans %= mod;
        }
        k *= k;
        if(k>mod) k %= mod;
        m >>= 1;
    }
    return ans;
}

inline int DBLCMP(double a, double b)
{
    if(fabs(a - b) <= eps) return 0;
    if(a < b) return -1;
    return 1;
}
template<class T> inline T sqr(T x)
{
    return x*x;
}
template<class T> inline int countbit(T n)
{
    return (n == 0) ? 0 : (1 + countbit(n&(n - 1)));
}
template<class T> inline T euclide(T a, T b, T &x, T &y)
{
    if (a < 0)
    {
        T d = euclide(-a, b, x, y);
        x = -x;
        return d;
    }
    if (b < 0)
    {
        T d = euclide(a, -b, x, y);
        y = -y;
        return d;
    }
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    else
    {
        T d = euclide(b, a % b, x, y);
        T t = x;
        x = y;
        y = t - (a / b) * y;
        return d;
    }
}
template<class T> string toString(T n)
{
    ostringstream ost;
    ost << n;
    ost.flush();
    return ost.str();
}
template<class T> string toBinary(T n)
{
    string ret="";
    while(n)
    {
        if(n%2==1)ret+='1';
        else ret+='0';
        n>>=1;
    }
    reverse(ret.begin(),ret.end());
    return ret;
}
void combination(int n,vector< vector<int> > &ret)
{
    ret.resize(n+1, vector<int>(n+1, 0));
    for(int i=1; i<=n; i++)
    {
        ret[i][0]=ret[i][i]=1;
        for(int j=1; j<i; j++)
        {
            ret[i][j]=ret[i-1][j]+ret[i-1][j-1];
        }
    }
}
int toInt(string s)
{
    int r = 0;
    istringstream sin(s);
    sin >> r;
    return r;
}
LLI toLInt(string s)
{
    LLI r = 0;
    istringstream sin(s);
    sin >> r;
    return r;
}
double toDouble(string s)
{
    double r = 0;
    istringstream sin(s);
    sin >> r;
    return r;
}
vector<string> parse(string temp)
{
    vector<string> ans;
    ans.clear();
    string s;
    istringstream iss(temp);
    while (iss >> s)ans.PB(s);
    return ans;
}
template<class T> inline T gcd(T a, T b)
{
    if (a < 0)return gcd(-a, b);
    if (b < 0)return gcd(a, -b);
    return (b == 0) ? a : gcd(b, a % b);
}
template<class T> inline T lcm(T a, T b)
{
    if (a < 0)return lcm(-a, b);
    if (b < 0)return lcm(a, -b);
    return a*(b / gcd(a, b));
}
template<class T> inline T power(T b, T p)
{
    if (p < 0)return -1;
    if (b <= 0)return -2;
    if (!p)return 1;
    return b*power(b, p - 1);
}
#define fst first
#define snd second
//istringstream(temp) >> data >> value >> stamp;
//mod1 = 1000000007, mod2 = 1000000009;
//.016-.040-.900-2.48
// insidegrid
/***************************************************************************************************************************************/
vector<int>adj[2009];
int mem[2009];
bool vis[2009];
int node;
int rec(int cn)
{
    vis[cn]=true;
    int ret=1;
    for(int i=0; i<adj[cn].size(); i++)
    {
        int now=adj[cn][i];
        if(!vis[now])ret+=rec(now);
    }
    mem[cn]=ret;
    return ret;
}

int dfs(int cn,int par)
{
    //getchar();
    //cout << cn << " :: " << par << endl;
    int x=0;
    int sz=adj[cn].size();
    //if(sz==1)return mem[cn]-1;
    //if(sz==0)return 0;
    for(int i=0;i<sz;i++)
    {
        int nowa=adj[cn][i];
        if(nowa!=par)x++;
    }
    //cout << x << endl;
    if(x==1)return mem[cn]-1;
    else if(x==0)return 0;
    int ret=mem[cn];
    //cout << cn << " " << mem[cn] << endl;
    int sum=0;
    for(int i=0;i<sz;i++)
    {
        int nowa=adj[cn][i];
        for(int j=i+1;j<sz;j++)
        {
            int nowb=adj[cn][j];
            if(nowa!=par && nowb!=par)ret=min(ret,dfs(nowa,cn)+dfs(nowb,cn)+mem[cn]-1-mem[nowa]-mem[nowb]);
        }
    }
    return ret;
}
int main()
{
    //read();
    //write();
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    int kase,ks=0,a,b;
    scanf("%d",&kase);
    while(kase--)
    {
        scanf("%d",&node);
        for(int i=0; i<=node+1; i++)adj[i].clear();
        REP(i,node-1)
        {
            scanf("%d %d",&a,&b);
            adj[a].PB(b);
            adj[b].PB(a);
        }
        int res=node;
        for(int i=1; i<=node; i++)
        {
            fill(vis,0);
            fill(mem,0);
            mem[i]=rec(i);
            //cout << i << " -> " << dfs(i,-1) << endl;
            res=min(res,dfs(i,-1));
        }
        printf("Case #%d: %d\n",++ks,res);
    }
}






