#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<map>
#include<vector>
#include<string>
#include<set>
#include<queue>
#define MP(x,y) make_pair(x,y)
#define clr(x,y) memset(x,y,sizeof(x))
#define forn(i,n) for(int i=0;i<n;i++)
#define sqr(x) ((x)*(x))
#define ll long long
using namespace std;

int n,l,ans;
char s[100];
ll a[1000],b[1000],x[1000],y[1000];

ll get(char s[]){
    ll ans=0;
    for(int i=0;i<l;i++)
        ans=ans*2+s[i]-'0';
    return ans;
}
void dfs(int d,int num){
    if(num>=ans) return;
    for(int i=0;i<n;i++){
        x[i] = a[i]&((1LL<<d)-1);
        y[i] = b[i]&((1LL<<d)-1);
    }
    sort(x,x+n);
    sort(y,y+n);
    bool flag=true;
    for(int i=0;i<n;i++)
        if(x[i]!=y[i])
            flag=false;
    if(!flag) return;
    if(d==l){
        ans = num;
        return ;
    }
    dfs(d+1,num);
    for(int i=0;i<n;i++) a[i] ^= (1<<d);
    dfs(d+1,num+1);
    for(int i=0;i<n;i++) a[i] ^= (1<<d);
}
int main() {
    freopen("/home/zyc/Downloads/in","r",stdin);
    freopen("/home/zyc/Downloads/out","w",stdout);
//    freopen("/home/zyc/Documents/Code/cpp/in","r",stdin);
    int T,cas=0;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&l);
        ans = l+1;
        for(int i=0;i<n;i++){
            scanf("%s",s);
            a[i] = get(s);
        }
        for(int i=0;i<n;i++){
            scanf("%s",s);
            b[i] = get(s);
        }
        sort(b,b+n);
        dfs(0,0);
        if(ans!=l+1) printf("Case #%d: %d\n",++cas,ans);
        else printf("Case #%d: NOT POSSIBLE\n",++cas);
    }
    return 0;
}

