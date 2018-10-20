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
    freopen("A-large.in","r",stdin);
    freopen("A-out1","w",stdout);
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
        }
        for(i=0;i<n;i++)
        {
            scanf("%s",str);
            b[i]=change(str);
        }
        sort(b,b+n);
        int ans = INF;
        for(i=0;i<n;i++)
        {
            int ch;
            for(j=0;j<n;j++)
            {
                ch = a[i]^b[j];
                bool flag = false;
                for(k=0;k<n;k++)
                    c[k] = a[k]^ch;
                sort(c,c+n);
                for(k=0;k<n;k++)
                    if(c[k]!=b[k]) flag =true;
                int sum=0;
                //printf("%d\n",ch);
                if(flag == false)
                {
                    for(k=0;k<l;k++)
                        if(ch&(1<<k)) sum++;
                    ans = MIN(ans,sum);
                }
            }
        }
        if(ans == INF)
            printf("Case #%d: NOT POSSIBLE\n",cas);
        else
            printf("Case #%d: %d\n",cas,ans);

        
    }
}
