#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> PI;
typedef vector<int> VI;
typedef long long LL;

#define FOR(i,a,b) for(register int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define REP(i,n) FOR(i,0,n)
#define PB push_back
#define mod 1000000007
#define MP make_pair
#define INF mod

int main()
{
#ifndef ONLINE_JUDGE
    freopen("A-small-attempt0.in","r",stdin);
    freopen("a.out","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    int t;
    int n,l,ans,ct;
    cin>>t;
    REP(tc,t)
    {
        cout<<"Case #"<<tc+1<<": ";
        cin>>n>>l;
        string a[n],b[n],c[n],d[n];
        REP(i,n) cin>>a[i];
        REP(i,n) cin>>b[i];
        ans=-1;
        sort(a,a+n);
        REP(i,n)
        {
            REP(k,n) {c[k]=a[k];d[k]=b[k];}
            ct=0;
            REP(j,l)
            {
                if(c[0][j]!=d[i][j])
                {
                    ct++;
                    REP(k,n)
                        if(d[k][j]=='0') d[k][j]='1';
                        else d[k][j]='0';
                }
            }
            sort(d,d+n);
            //REP(i,n) cout<<d[i]<<' ';cout<<endl;
            int f=0;
            REP(k,n) f+=(c[k]!=d[k]);
            if(f!=0) ct=-1;
            if(ct!=-1){
            if(ans==-1) ans=ct;
            else ans=min(ans,ct);
            }
        }
        if(ans==-1) cout<<"NOT POSSIBLE\n";
        else cout<<ans<<endl;
    }
    return 0;
}
