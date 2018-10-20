#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <cstdio>
#include <cmath>
#include <map>
#define PI acos(-1.0)
#define inf 0x3f3f3f3f
#define maxn 160
#define eps 1e-7
using namespace std;

#ifdef __int64
    typedef __int64 LL;
#else
    typedef long long LL;
#endif

char str[maxn][maxn];
char now[maxn][maxn];
char tar[maxn][maxn];
int v[maxn];


int getval(char s[],int l){
    int val=0;
    for(int i=0;i<l;i++){
        val<<=1;
        val^=(s[i]-'0');
    }
    return val;
}
int getans(int pos){
    int cnt=0;
    while(pos){
        if(pos&1)cnt++;
        pos>>=1;
    }
    return cnt;
}
int tt[maxn];

bool judge(int pos,int n,int l){
    for(int i=0;i<l;i++){
        for(int j=0;j<n;j++){
            if(pos&(1<<i))
                now[j][i]=(str[j][i]-'0')^1+'0';
            else
                now[j][i]=str[j][i];
        }
    }
    for(int i=0;i<n;i++){
        tt[i]=getval(now[i],l);
    }
    sort(tt,tt+n);
//    for(int i=0;i<n;i++){
//        printf("%d   ",tt[i]);
//    }
//    puts("");
    for(int i=0;i<n;i++){
        if(tt[i]!=v[i])return false;
    }
    return true;
}

int main(){
    freopen("A-small-attempt0.in","r",stdin);
    freopen("out.out","w",stdout);
    int cas=0,i,j,k;
    int t;
    int n,l;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&l);
        for(i=0;i<n;i++){
            scanf("%s",str[i]);
        }
        for(i=0;i<n;i++){
            scanf("%s",tar[i]);
            v[i]=getval(tar[i],l);
        }
        sort(v,v+n);
//        for(i=0;i<n;i++){
//            printf("%d   ",v[i]);
//        }
//        puts("");
        int ans = inf;
        for(i=0;i<(1<<l);i++){
            if(judge(i,n,l)){
//                printf("%d\n",i);
                ans = min(ans,getans(i));
            }
        }
        printf("Case #%d: ",++cas);
        if(ans==inf){
            puts("NOT POSSIBLE");
        }else{
            printf("%d\n",ans);
        }
//        printf("%d\n",t);
    }
    return 0;
}
