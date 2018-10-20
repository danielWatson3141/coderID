// karanaggarwal
#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define CLR(a) a.clear()
#define SET(a,b) memset(a,b,sizeof(a))
#define LET(x,a) __typeof(a) x(a)
#define TR(v,it) for( LET(it,v.begin()) ; it != v.end() ; it++)
#define FORi(i,a,b) for(LET(i,a) ; i<b; i++)
#define repi(i,n) FORi(i,(__typeof(n))0,n)
#define FOR(i,a,b) for(i=a ; i<b; i++)
#define rep(i,n) FOR(i,0,n)
#define si(n) scanf("%d",&n)
#define sll(n) scanf("%lld",&n)
#define pi(n) printf("%d",n)
#define piw(n) printf("%d ",n)
#define pin(n) printf("%d\n",n)
using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;
LL power(LL a, LL p, LL mod)
{LL ret = 1;while(p){if(p&1)ret = (ret*a)%mod;a=(a*a)%mod;p/=2;}return ret;}

VI E[1001];
int dfs(int x, int p)
{
    VI tp;
    TR(E[x],i)
    {
        if(*i == p)continue;
        tp.PB(dfs(*i,x));
    }
    int N = SZ(tp);
    int sum = 0;
    if(N>1)
    {
       sort(tp.begin(),tp.end());
       sum += tp[N-1]; 
       sum += tp[N-2];
    }
    return sum+1;
}
int main()
{
    int t; si(t); int T = t; while(t--)
    {
        int N; cin>>N;
        repi(i,N) E[i+1].clear();
        repi(i,N-1)
        {
            int x,y; si(x); si(y); E[x].PB(y); E[y].PB(x);
        }
        int ans = 1;
        for(int i=1; i<=N; i++)
        {
            ans = max(ans , dfs(i,0));
        }
        cout<<"Case #"<<T-t<<": ";
        cout<<N - ans<<endl;
    }
    return 0;
}

