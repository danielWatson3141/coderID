#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

char str[3][155][55];
int zero[3][155];
int ok,n,m;
char newstr[3][155][55];
int vis[3][155];

void PRINT()
{
    printf("---------\n");
    int i,j;
    for (i=0;i<n;i++)
    {
        for (j=0;j<m;j++)
        {
            printf("%c",newstr[0][i][j]);
        }
        printf(" ");
    }
    printf("\n");
}

bool Check()
{
    int i,j,k;
    for (i=0;i<n;i++)
    {
        newstr[0][i][m]='\0';
    }
    memset(vis,0,sizeof(vis));
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            if (vis[1][j]==1) continue;
            if (strcmp(newstr[0][i],str[1][j])==0)
            {
                vis[1][j]=vis[0][i]=1;
                break;
            }
        }
        if (vis[0][i]==0) return false;
    }
    return true;
}

void DFS(int t,int num)
{
    int i,j,k;
    if (t==m)
    {
       // PRINT();
        if (Check()==true) ok=min(ok,num);
        return;
    }
    if (ok==1) return;
    if (zero[0][t]==zero[1][t])
    {
        for (i=0;i<n;i++)
        {
            newstr[0][i][t]=str[0][i][t];
        }
        DFS(t+1,num);
    }
    if (zero[0][t]+zero[1][t]==n)
    {
        for (i=0;i<n;i++)
        {
            newstr[0][i][t]=(str[0][i][t]=='1'?'0':'1');
        }
        DFS(t+1,num+1);
    }
}

int main()
{
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    int i,j,k,cnt=1,T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for (i=0;i<2;i++)
        {
            for (j=0;j<n;j++)
            {
                scanf("%s",str[i][j]);
            }
        }
        memset(zero,0,sizeof(zero));
        for (i=0;i<2;i++)
        {
            for (j=0;j<n;j++)
            {
                for (k=0;k<m;k++)
                {
                  //  printf("%d %d %d: %c\n",i,j,k,str[i][j][k]);
                    if (str[i][j][k]=='0') zero[i][k]++;
                }
            }
        }
        ok=1000000;
        DFS(0,0);
        if (ok==1000000) printf("Case #%d: NOT POSSIBLE\n",cnt++);
        else printf("Case #%d: %d\n",cnt++,ok);
    }
}
