#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<queue>
#include<fstream>
#include<sstream>
#include<stack>
#include<list>
#include<deque>
#include<bitset>
#include<utility>
#include<climits>
#include<iomanip>
#include<ctime>
#include<complex>
#include<set>

using namespace std;


#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)

#define inf INT_MAX/3
#define INF INT_MAX/3
#define PB push_back
#define pb push_back
#define MP make_pair
#define mp make_pair
#define ALL(a) (a).begin(),(a).end()
#define all(a) (a).begin(),(a).end()
#define SET(a,c) memset(a,c,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define PII pair<int,int>
#define pcc pair<char,char>
#define pic pair<int,char>
#define pci pair<char,int>
#define VS vector<string>
#define VI vector<int>
#define debug(x) cout<<#x<<": "<<x<<endl
#define MIN(a,b) (a>b?b:a)
#define MAX(a,b) (a>b?a:b)
#define pi 2*acos(0.0)
#define INFILE() freopen("in.txt","r",stdin)
#define OUTFILE()freopen("out.txt","w",stdout)
#define in scanf
#define out printf
#define LL long long
#define ll long long
#define ULL unsigned long long
#define ull unsigned long long
#define eps 1e-14
#define MOD 1000000007


//TYO conversion
template<typename T>inline string toString(T a)
{
    ostringstream os("");
    os<<a;
    return os.str();
}
template<typename T>inline ll toLong(T a)
{
    ll res;
    istringstream os(a);
    os>>res;
    return res;
}
//MATHEMATICS
template<typename T>inline T  S(T a)
{
    return a*a;
}
template<typename T>inline T gcd(T a, T b)
{
    if (b == 0)return a;
    else return gcd(b, a % b);
}
template<typename T>inline ull bigmod(T a, T b, T m)
{
    if (b == 0)return 1;
    else if (b % 2 == 0)return S(bigmod(a, b / 2, m)) % m;
    else return (a % m*bigmod(a, b - 1, m)) % m;
}
template<typename T>inline VS parse(T str)
{
    VS res;
    string s;
    istringstream os(str);
    while(os>>s)res.pb(s);
    return res;
}
template<typename T>inline ull  dist(T A,T B)
{
    ull res=(A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y);
    return res;
}
template<typename T>inline double cosAngle(T a,T b,T c)
{
    double res=a*a+b*b-c*c;
    res=res/(2*a*b);
    res=acos(res);
    return res;
}
template<typename T>inline T power(T base,int po)
{
    T res=1;
    if(base==0)return 0;
    FOR(i,0,po)res*=base;
    return res;
}
//BIT
template<typename T>inline bool isOn(T mask,T pos)
{
    return mask&(1<<pos);
}
template<typename T>inline int Off(T mask,T pos)
{
    return mask^(1<<pos);
}
template<typename T>inline int On(T mask,T pos)
{
    return mask|(1<<pos);
}

//node * root =new node(0,n-1);

VI g[1005];

int vis[1005];
int KS;

int dp[1005];
int child[1005];
void solve(int pos , int par)
{
    vis[pos]=KS;
    dp[pos]=10000;
    bool ok=0;
    int n=g[pos].size(),x,y;
    for(int i=n-1; i>=0; i-- )
    {
        x=g[pos][i];
        if(x!=par)
        {
            solve(x,pos);
            ok=1;
        }
    }

    if(!ok)
    {
        child[pos]=0;
        dp[pos]=0;
    }
    else
    {
        // delete all
        int cur=0;
        for(int i=n-1; i>=0; i--)
        {
            x=g[pos][i];
            if(x!=par)
                cur=cur+child[x]+1;
        }
        child[pos]=cur;
        dp[pos]=cur;
        // keep 2 delete others

        if(n>=2)
        {
            vector<PII>v;
            PII p;
            for(int i=n-1; i>=0; i--)
            {

                x=g[pos][i];
                if(x==par)continue;
                p=MP(child[x]-dp[x],x );
                v.PB(p);
            }
            int nn=v.size();

            if(nn>=2)
            {
                sort(ALL(v));
                int tmp=0;
                for(int i=nn-1; i>=0; i--)
                {
                    y=v[i].second;
                    if(i==nn-1 || i==nn-2)
                    {
                        //x=v[i].first;

                        tmp+=dp[y];
                    }
                    else tmp+=child[y]+1;

                }
                dp[pos]=min(dp[pos],tmp);
            }
        }

    }

}


int main()
{

    INFILE();
    OUTFILE();

    int i,j,k;
    int x,y;
    int ks,cas;
    int n,m;
    cin>>ks;
    KS=4;
    for(cas=1; cas<=ks; cas++)
    {
        cin>>n;
        for(i=0; i<=1000; i++)g[i].clear();
        memset(vis,0,sizeof vis);

        for(i=1; i<n; i++)
        {
            scanf("%d%d",&x,&y);
            g[x].PB(y);
            g[y].PB(x);
        }




        int res=n-1;

        for(i=1; i<=n; i++)
        {
            ++KS;
            solve(i,i);
            res=min(res,dp[i]);
        }
        cout<<"Case #"<<cas<<": ";
        cout<<res<<endl;
    }


    return 0;
}
