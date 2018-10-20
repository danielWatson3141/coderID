/*
 * Bidhan Roy
 * University of Dhaka
 */

using namespace std;
#include <bits/stdc++.h>

#define foreach(i,n) for(__typeof((n).begin())i =(n).begin();i!=(n).end();i++)
#define sgn(x,y) ((x)+eps<(y)?-1:((x)>eps+(y)?1:0))
#define rep(i,n) for(__typeof(n) i=0; i<(n); i++)
#define mem(x,val) memset((x),(val),sizeof(x));
#define rite(x) freopen(x,"w",stdout);
#define read(x) freopen(x,"r",stdin);
#define all(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define sqr(x) ((x)*(x))
#define pb push_back
#define mp make_pair
#define clr clear()
#define inf (1<<30)
#define ins insert
#define xx first
#define yy second
#define eps 1e-9

typedef long long i64;
typedef unsigned long long ui64;
typedef string st;
typedef vector<int> vi;
typedef vector<st> vs;
typedef map<int,int> mii;
typedef map<st,int> msi;
typedef set<int> si;
typedef set<st> ss;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

#define mx 0

st toggle(st &a,st &b){
    st ret;
    rep(i,sz(a)) if(a[i]==b[i]) ret+='0';
    else ret+='1';
    return ret;
}

st change(st a,st ref){
    rep(i,sz(a)) if(ref[i]=='1'){
        if(a[i]=='1') a[i]='0';
        else a[i]='1';
    }
    return a;
}

int main(){
    ios_base::sync_with_stdio(0);
    read("in.txt");
    rite("out.txt");
    clock_t start=clock();
    int test, kas=0;
    cin>>test;
    while( test-- ){
        int n,l;
        cin>>n>>l;
        vs a,b;
        map<st,int> AA;
        rep(i,n){
            st str;
            cin>>str;
            a.pb(str);

        }
        rep(i,n){
            st str;
            cin>>str;
            b.pb(str);
            AA[str]++;
        }
        int ans=inf;
        rep(i,n){
            rep(j,n){
                //if(i!=0 || j!=1) continue;
                st tog=toggle(a[i],b[j]);
                //cout<<"tog = "<<tog<<endl;
                map<st,int> BB;
                rep(k,n){
                    BB[ change(a[k],tog) ]++;
                }
                if(AA!=BB) continue;
                int cnt=0;
                rep(ii,sz(tog)) cnt+=tog[ii]-'0';
                ans=min(ans,cnt);
            }
        }
        cout<<"Case #"<<++kas<<": ";
        if(ans>=inf) cout<<"NOT POSSIBLE"<<endl;
        else cout<<ans<<endl;
        //return 0;
    }
    cerr<<" Time taken "<<( clock()-start ) / 1000.0 <<" second/s "<<endl;
    return 0;
}
