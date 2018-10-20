#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int mat[41][41];
int ans[41][41];
int tmp[41][41];
bool fg[41],fg2[41];

int T,N,L;
void change(int y)
{
    int i;
    for(i=1;i<=N;i++)
    {
        tmp[i][y]=1-tmp[i][y];
    }
}
bool fun(int x)
{
    int i,j=1;
    //printf("YES\n");
    for(i=1;i<(1<<L);i=i<<1,j++)
    {
        if(x&i)
        {
            change(j);
           // printf("%d......j\n",j);
        }
    }
    memset(fg,false,sizeof(fg));
    for(i=1;i<=N;i++)
    {
        for(j=1;j<=N;j++)
        {
            if(!fg[j])
            {
                int vis=1;
                for(int e=1;e<=L;e++)
                {
                    if(tmp[i][e]!=ans[j][e])
                    {
                        vis=0;
                        break;
                    }
                }
                if(vis)
                {
                    fg[j]=true;
                }
            }
        }
    }
    for(i=1;i<=N;i++)
    {
        if(!fg[i])
            return false;
    }
    return true;
}
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d",&T);
    int ncase=0;
    int i,j;
    while(T--)
    {
        scanf("%d %d",&N,&L);
        char s[50];
        for(i=1;i<=N;i++)
        {
            scanf("%s",s);
            for(j=1;j<=L;j++)
            {
                mat[i][j]=s[j-1]-'0';
            }
        }
        for(i=1;i<=N;i++)
        {
            scanf("%s",s);
            for(j=1;j<=L;j++)
            {
                ans[i][j]=s[j-1]-'0';
                //printf("%d...",ans[i][j]);
            }
            //puts("");
        }
        bool ANS=false;
        int k;
        for(k=0;k<(1<<L);k++)
        {
            for(i=1;i<=N;i++)
            {
                for(j=1;j<=L;j++)
                {
                    tmp[i][j]=mat[i][j];
                    //printf("%d...",tmp[i][j]);
                }
                //printf("\n");
            }
            if(fun(k))
            {
                ANS=true;
                break;
            }
        }
        printf("Case #%d: ",++ncase);
        if(ANS)
        {
            int num=0;
            while(k>0)
            {
                if(k&1)
                    num++;
                k=k>>1;
            }
            printf("%d\n",num);
        }
        else printf("NOT POSSIBLE\n");
    }
    return 0;
}
