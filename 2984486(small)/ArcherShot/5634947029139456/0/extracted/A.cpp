#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cmath>
#include <sstream>
#include <algorithm>
#include <numeric>
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define sqr(x) ((x)*(x))
using namespace std;
const int INF = 0x3f3f3f3f;
typedef long long ll;
template<typename X> inline bool minimize(X&p,X q){if(p<=q)return 0;p=q;return 1;}
template<typename X> inline bool maximize(X&p,X q){if(p>=q)return 0;p=q;return 1;}
const int MAXN = 200 ;
long long A[MAXN],B[MAXN],mask=0;
int T,N,L,cas,C[MAXN],D[MAXN];

bool cmp(ll a,ll b){return (a&mask)<(b&mask);}

int cnt(ll n){
    int res = 0 ;
    while(n){
        ++res;
        n ^= n&-n;
    }
    return res;
}

bool equal(ll flip){
    for(int i=0;i<N;++i)
        A[i] ^= flip;
    sort(A,A+N,cmp);
    for(int i=0;i<N;++i)
        A[i] ^= flip;
    sort(B,B+N,cmp);
    for(int i=0;i<N;++i)
        if(((A[i]&mask)^flip)!=(B[i]&mask))
            return false;
    return true;
}

void solve(){
    mask = 0ll;
    ll flip = 0;
    for(int i=0;i<L;++i){
        if(C[i]!=D[i]){
            if(N-C[i]!=D[i]){
                printf("NOT POSSIBLE\n");
                return;
            }
            flip |= 1ll << i;
        }
        if( C[i] + C[i] != N )
            mask |= 1ll << i;
    }
//    cerr<<flip<<' '<<mask<<endl;
    if(!equal(flip)){
        printf("NOT POSSIBLE\n");
        return;
    }
    vector<ll>vf;
    vf.push_back(flip);
    for(int i=0;i<L;++i){
        if(mask&1ll<<i)continue;
        mask |= 1ll<<i;
        vector<ll> nvf;
        for(int j=vf.size()-1;~j;--j)
            if(equal(vf[j]))
                nvf.push_back(vf[j]);
        if(C[i]+C[i]==N){
            for(int j=vf.size()-1;~j;--j)
                if(equal(vf[j]|1ll<<i))
                    nvf.push_back(vf[j]|1ll<<i);
        }
        vf = nvf;
        if(vf.empty()){
            printf("NOT POSSIBLE\n");
            return;
        }
    }
    int ans = L;
    for(int i=vf.size()-1;~i;--i)
        minimize(ans,cnt(vf[i]));
    printf("%d\n",ans);
}
int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    scanf("%d",&T);
    for(int t=1;t<=T;++t){
        scanf("%d%d",&N,&L);
        memset(C,0,sizeof(C));
        memset(D,0,sizeof(D));
        for(int i=0,k;i<N;++i){
            A[i] = 0;
            for(int j=0;j<L;++j){
                scanf("%1d",&k);
                if(k==1)
                    A[i]|=1ll<<j,++C[j];
            }
        }
        for(int i=0,k;i<N;++i){
            B[i] = 0;
            for(int j=0;j<L;++j){
                scanf("%1d",&k);
                if(k==1)
                    B[i]|=1ll<<j,++D[j];
            }
        }
        printf("Case #%d: ",t);
        solve();
    }
    return 0;
}
