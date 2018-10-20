#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
const int N = 155;
const int INF = 1000000;
int T,n,l;
int cases=0;
int a[N][45];
int b[N][45];
char tmp[45];
int now[45];
int res;
int checked[2][45];
int s1,s2;

bool check()
{
    memset(checked,0,sizeof(checked));
    s1=0,s2=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            bool flag=1;
            for(int k=0;k<l;k++){
                if((a[i][k]^now[k]) == b[j][k])
                    continue;
                else{
                    flag=0;
                    break;
                }
            }
            if(flag){
                if(!checked[0][i]) s1++;
                checked[0][i]=1;
                if(!checked[1][j]) s2++;
                checked[1][j]=1;
            }
        }
    }
    if(s1==n && s2==n) return true;
    return false;
}

void dfs(int dep,int sum)
{
    if(dep==n){
        if(check()){
            res=min(res,sum);
            return;
        }
    }
    else{
        now[dep]=1;
        if(sum+1<res){
          dfs(dep+1,sum+1);
        }
        now[dep]=0;
        if(sum<res){
            dfs(dep+1,sum);
        }
    }
}

int main()
{
    int i,j,k;
    freopen("A-small-attempt0.in","r",stdin);
    freopen("chaos.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        scanf("%d%d",&n,&l);
        for(int i=0;i<n;i++){
            scanf("%s",tmp);
            for(int j=0;j<l;j++)
                a[i][j]=tmp[j]-'0';
        }
        for(int i=0;i<n;i++){
            scanf("%s",tmp);
            for(int j=0;j<l;j++)
                b[i][j]=tmp[j]-'0';
        }
        memset(now,0,sizeof(now));
        res=INF;
        dfs(0,0); 
        printf("Case #%d: ",++cases);
        if(res==INF)
            printf("NOT POSSIBLE");
        else printf("%d",res);
        printf("\n");
    }

    return 0;
}
