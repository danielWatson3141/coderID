#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
using namespace std;
#define INFF 1000111222
int mat[250][250];
int ans[250][250];
int tmp[250][250];
bool fg[250];
int N,L,T;
void change(int y)
{
    int i;
    for(i=1;i<=N;i++)
    {
        tmp[i][y]=1-tmp[i][y];
    }
}
bool fun()
{
    int i,j;
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
        char s[250];
        for(i=1;i<=N;i++)
        {
            scanf("%s",s);
            for(j=1;j<=L;j++)
                mat[i][j]=s[j-1]-'0';
        }
        for(i=1;i<=N;i++)
        {
            scanf("%s",s);
            for(j=1;j<=L;j++)
                ans[i][j]=s[j-1]-'0';
        }
        int k;
        int ANS=INFF;
        for(k=1;k<=N;k++)
        {
            for(i=1;i<=N;i++)
                for(j=1;j<=L;j++)
                    tmp[i][j]=mat[i][j];
            int num=0;
            for(i=1;i<=L;i++)
            {
                if(mat[1][i]!=ans[k][i])
                {
                    num++;
                    change(i);
                }
            }
            if(fun())
            {
                ANS=min(ANS,num);
            }
        }
        printf("Case #%d: ",++ncase);
        if(ANS!=INFF)
            printf("%d\n",ANS);
        else printf("NOT POSSIBLE\n");

    }
    return 0;
}
