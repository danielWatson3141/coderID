#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

#define REP(i,n) FOR(i,0,n)
#define REPR(i,n) FORR(i,n,0)
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORR(i,a,b) for(int i=a;i>=0;i--)
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define inf mod

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("a.in","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);
    int t,n,l;
    cin>>t;
    REP(i,t)
    {
        cout<<"Case #"<<i+1<<": ";
        cin>>n>>l;
        int ans=50,c1=0;
        vector<int> v;
        string a[151],b[151],c[151];
        REP(j,n)
            cin>>c[j];
        REP(j,n)
            cin>>a[j];
        sort(c,c+n);
        sort(a,a+n);
        REP(j,n)
            b[j]=a[j];
        REP(j,n)
        {
            v.clear();
            c1=0;
            REP(k,l)
            {
                if(a[j][k]!=c[0][k])
                    v.pb(k);
            }
            REP(k,n)
            {
                REP(w,v.size())
                    b[k][v[w]]^=1;
            }
            sort(b,b+n);
            REP(k,n)
            {
                if(c[k]!=b[k])
                {
                    c1=1;
                    break;
                }
            }
            int c2 = v.size();
            if(c1==0)
                ans = min(ans,c2);
            REP(k,n)
                b[k]=a[k];
        }
        if(ans == 50)
            cout<<"NOT POSSIBLE"<<endl;
        else
            cout<<ans<<endl;
    }
    return 0;
}
