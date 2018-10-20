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
int n,l;
string A[10],B[10];
void change(int x)
{
    repi(i,n)   
        if(A[i][x]=='0') A[i][x]++; else A[i][x]--;
}
bool check()
{
    sort(A,A+n);
    repi(i,n)   
        if(A[i]!=B[i])return false;
    return true;
}
int main()
{
    int t,T; si(t);T=t; while(t--)
    {
        cin>>n>>l;
        repi(i,n) cin>>A[i];
        repi(i,n) cin>>B[i];
        sort(B,B+n);
        int ans = 100;
        repi(i,1<<l)
        {
            int c = 0;
            repi(j,l)
                if( (i>>j)&1)
                {
                    change(j);c++;
                }
            if(check())
                ans = min(ans,c);
            repi(j,l)
                if( (i>>j)&1)
                    change(j);
        }
        cout<<"Case #"<<T-t<<": ";
        if(ans==100)cout<<"NOT POSSIBLE"<<endl;
        else
            cout<<ans<<endl;
    }
    return 0;
}

