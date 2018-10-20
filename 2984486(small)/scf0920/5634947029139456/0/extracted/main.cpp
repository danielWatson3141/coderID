#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include<algorithm>

using namespace std;
int n, m, s1[20][20], s2[20][20];
struct node
{
    int a[20][20];
    int ans, x;
} q[1000000];
void bfs()
{
    int i, j, s=0, e=0, k, x, y, z;
    node f1, f2;
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            f1.a[i][j]=s1[i][j];
        }
    }
    f1.ans=0;
    f1.x=-1;
    q[s++]=f1;
    while(s>e)
    {
        f1=q[e++];
        /*for(i=0;i<n;i++)
            {
                for(j=0;j<m;j++)
                {
                    printf("%d ",f1.a[i][j]);
                }
                printf("\n");
            }*/
        x=0;
        for(i=0; i<n; i++)
        {
            y=0;
            for(j=0; j<n; j++)
            {
                z=0;
                for(k=0; k<m; k++)
                {
                    if(f1.a[i][k]!=s2[j][k])
                    {
                        z=1;
                        break;
                    }
                }
                if(z==0)
                {
                    y=1;
                    break;
                }
            }
            if(y==0)
            {
                x=1;
                break;
            }
        }
        if(x==0)
        {
            /*for(i=0;i<n;i++)
            {
                for(j=0;j<m;j++)
                {
                    printf("%d ",f1.a[i][j]);
                }
                printf("\n");
            }*/
            printf("%d\n",f1.ans);
            return ;
        }
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                f2.a[i][j]=f1.a[i][j];
            }
        }
        if(f1.x<m)
        {
            f2.x=f1.x+1;
            f2.ans=f1.ans;
            q[s++]=f2;
        }
        for(i=f1.x+1; i<m; i++)
        {
            for(int i1=0; i1<n; i1++)
            {
                for(int j1=0; j1<m; j1++)
                {
                    f2.a[i1][j1]=f1.a[i1][j1];
                }
            }
            for(j=0; j<n; j++)
            {
                f2.a[j][i]=1-f1.a[j][i];
            }
            f2.ans=f1.ans+1;
            f2.x=i;
            q[s++]=f2;
        }

    }
    printf("NOT POSSIBLE\n");
    return ;
}
int main()
{
    int t, i, j, num=0;
    char s[20];
    freopen("1.txt","r",stdin);
    freopen("2.txt","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        num++;
        scanf("%d%d ",&n,&m);
        for(i=0; i<n; i++)
        {
            scanf("%s",s);
            for(j=0; j<m; j++)
                s1[i][j]=s[j]-'0';
        }
        for(i=0; i<n; i++)
        {
            scanf("%s",s);
            for(j=0; j<m; j++)
                s2[i][j]=s[j]-'0';
        }
        printf("Case #%d: ",num);
        bfs();
    }
    return 0;
}
