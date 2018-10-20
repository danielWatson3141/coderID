#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
const int N=210;
const int L=50;
char buf[L];
int n,l;
typedef long long LL;
bool use[L];
LL all[N],dev[N],co[N];
bool ok(int n){
    bool w=true;
    sort(co,co+n);
    for(int i=0;i<n;i++){
        if(co[i]!=dev[i]){
            w=false;break;
        }
    }
    return w;
}
int num(LL a){
    int ans=0;
    while(a){
        if(a%2)ans++;
        a=a>>1;
    }
    return ans;
}
int main(){
    int T,idx=0;
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&n,&l);
        for(int i=0;i<n;i++){
            scanf("%s",buf);
            LL tmp=0;
            for(int r=0;buf[r];r++){
                if(buf[r]=='1')tmp++;
                if(r!=l-1)tmp=tmp<<1;
            }
            all[i]=tmp;
        }
        for(int i=0;i<n;i++){
            scanf("%s",buf);
            LL tmp=0;
            for(int r=0;buf[r];r++){
                if(buf[r]=='1')tmp++;
                if(r!=l-1)tmp=tmp<<1;
            }
            dev[i]=tmp;
        }
        sort(dev,dev+n);
        int ans=1<<30;
        for(int i=0;i<n;i++){
            
            LL mask=all[0]^dev[i];
            int c=num(mask);
            for(int i=0;i<n;i++){co[i]=mask^all[i];}
            if(ok(n))ans=min(ans,c);
        }
        idx++;
        printf("Case #%d: ",idx);
        if(ans==(1<<30))puts("NOT POSSIBLE");
        else printf("%d\n",ans);
    }
}
