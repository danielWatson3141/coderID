/*************************************************************************
	> File Name: roundA1.cpp
	> Author: qianlv
	> Mail: qianlv7@qq.com 
	> Created Time: 2014年04月26日 星期六 08时43分11秒
    > google code jam RoundA_1
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#define N 1000
#define INF 0x7ffffff
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define CL(a,b) memset(a,b,sizeof(a))
#define LL long long int
using namespace std;
int change(char *str)
{
    int i;
    int sum=0;
    int t = 1;
    for(i=0;str[i];i++)
    {
        if(str[i]=='1') sum += t;
        t<<=1;
    }
    return sum;
}
int a[N],b[N],c[N];
int main()
{
    freopen("A-small-attempt1.in","r",stdin);
    freopen("A-out","w",stdout);
    int T;
    int cas;
    char str[50];
   // printf("%d\n",change(str));
    scanf("%d",&T);
    for(cas=1;cas<=T;cas++)
    {
        int n,l;
        scanf("%d%d",&n,&l);
        int i,j,k;
        for(i=0;i<n;i++)
        {
            scanf("%s",str);
            a[i]=change(str);
     //       printf("%d\n",a[i]);
        }
        for(i=0;i<n;i++)
        {
            scanf("%s",str);
            b[i]=change(str);
        }
        sort(b,b+n);
       // for(i=0;i<n;i++)
       //     printf("%d ",b[i]);
       // printf("\n");
        int ans = INF;
        for(i=0;i<(1<<l);i++)
        {
            for(j=0;j<n;j++)
                c[j]=a[j];
            for(j=0;j<n;j++)
            {
                c[j] = c[j]^i;
            }
            sort(c,c+n);
       //     for(j=0;j<n;j++)
       //         printf("%d ",c[j]);
       //     printf("\n");
            int flag = 0;
            for(j=0;j<n;j++)
                if(c[j]!=b[j]) flag = 1;
            if(flag==0)
            {
                int sum=0;
                for(j=0;j<l;j++)
                    if(i&(1<<j)) sum++;
                ans = MIN(ans,sum);
            }
        }
        if(ans == INF)
            printf("Case #%d: NOT POSSIBLE\n",cas);
        else
            printf("Case #%d: %d\n",cas,ans);

        
    }
}
