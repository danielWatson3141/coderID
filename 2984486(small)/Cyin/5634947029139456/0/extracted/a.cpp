#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
long long a[2][50];
char s[2][50][50];
int n,m;
int ans;
int vis[50];
void geta(){
     int i,j,k;
     for (i=0;i<2;i++)
         for (j=0;j<n;j++)
             for (k=0;k<m;k++) 
                 if (s[i][j][k]=='1') a[i][j]=a[i][j]|(1LL<<k);
} 
int get1(long long x){
    int res=0;
    while (x){
        if (x&1) res++;
        x>>=1;
    }
    return res;
}
int main(){
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    int cc,ca;
    int i,j,k,flag;
    long long d;
    scanf("%d",&ca);
    for (cc=1;cc<=ca;cc++){
        printf("Case #%d: ",cc);
        scanf("%d%d",&n,&m);
        for (i=0;i<n;i++) scanf("%s",s[0][i]);
        for (i=0;i<n;i++) scanf("%s",s[1][i]);
        memset(a,0,sizeof(a));
        geta();
        ans=100;
        for (i=0;i<n;i++){
            d=a[0][0]^a[1][i];
            memset(vis,0,sizeof(vis));
            vis[i]=1;
            flag=1;
            for (j=1;j<n;j++)
                for (k=0;k<n;k++)
                    if ((a[0][j]^a[1][k])==d&&vis[k]==0){
                        vis[k]=1;
                        break;
                    }
            for (j=0;j<n;j++)
                if (vis[j]==0) flag=0;
            if (flag) ans=min(ans,get1(d));
        }
        if (ans==100) printf("NOT POSSIBLE\n");
        else printf("%d\n",ans);
    }
    return 0;
}
                                           
