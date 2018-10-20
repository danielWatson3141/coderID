#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<set>
#include<map>
#include<list>
#include<cmath>
#include<iomanip>
#include<utility>
#include<vector>
#include<cstdlib>
#include<ctime>
using namespace std;
typedef long long LL;
typedef pair<LL,int> PII;
const int maxn = 311;
const int inf = 0x7f7f7f7f;
const int mod = (int)(1e9+7);
const LL INF = 1LL<<50;
const double eps = 1e-8;
const double pi = acos(-1.0);
const int mask = 65535;
char s[maxn];
int a[maxn];
int b[maxn];
LL A[maxn];
LL B[maxn];
int x[maxn];
int get(LL n){
    int ans=0;
    while(n){
        n = n&(n-1);
        ++ans;
    }
    return ans;
}
void solve(){
    int n,m,i,j;
    scanf("%d%d",&n,&m);
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(x,0,sizeof(x));
    for(i=0;i<n;++i){
        scanf("%s",s);
        LL t=0;
        int k;
        for(j=0;j<m;++j){
            k=s[j]^0x30;
            t=t<<1|k;
            a[j]+=k;
        }
        A[i]=t;
    }
    for(i=0;i<n;++i){
        scanf("%s",s);
        LL t=0;
        int k;
        for(j=0;j<m;++j){
            k=s[j]^0x30;
            t=t<<1|k;
            b[j]+=k;
        }
        B[i]=t;
    }  
    set<LL>S;
    set<LL>::iterator it;
    set<LL>now;
    for(i=0;i<n;++i){
        set<LL>tmp;
        tmp.clear();
        now.clear();
        LL k;
        for(j=0;j<n;++j){
            k=A[i]^B[j];
            tmp.insert(k);
        }
        if(i==0){
            now=tmp;
        }else if(!S.empty()){
            for(it=S.begin();it!=S.end();++it){
                k=*it;
                if(tmp.count(k)){
                    now.insert(k);
                }
            }
        }
        S=now;
    }
    if(S.empty()){
        puts("NOT POSSIBLE");
    }else{
        int ans=22222,t;
        for(it=S.begin();it!=S.end();++it){
            LL k=*it;
            t=get(k);
            if(t<ans){
                ans=t;
            }
        }
        printf("%d\n",ans);
    }
}
int main(){
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
    int T,cas;
    scanf("%d",&T);
    for(cas=1;cas<=T;++cas){
        printf("Case #%d: ",cas);
        solve();
    }
    return 0;
}
