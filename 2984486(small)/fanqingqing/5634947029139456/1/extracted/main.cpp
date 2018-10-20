#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define INF 999999999
using namespace std;
long long dp[155];
char tr[155][45],num[155][45];
int main()
{
    int t,k,i,j,m,l,n;
    scanf("%d",&t);
    for(k=1; k<=t; k++)
    {
        scanf("%d%d",&n,&l);
        for(i=0; i<n; i++)
            scanf("%s",tr[i]);
        memset(dp,0,sizeof(dp));
        for(i=0; i<n; i++)
        {
            scanf("%s",num[i]);
            for(j=0; j<l; j++)
                dp[i]+=pow(2,l-j-1)*(num[i][j]-'0');
        }
        sort(dp,dp+n);
        int ans=INF;
        for(i=0; i<n; i++)
        {
            int sum=0;
            char a[155][45];
            for(m=0; m<n; m++)
                for(j=0; j<l; j++)
                    a[m][j]=tr[m][j];
            for(j=0; j<l; j++)
            {
                if(a[0][j]!=num[i][j])
                {
                    sum++;
                    for(m=0; m<n; m++)
                    {
                        if(a[m][j]=='0')
                            a[m][j]='1';
                        else
                            a[m][j]='0';
                    }
                }
            }
            long long b[155];
            memset(b,0,sizeof(b));
            for(m=0; m<n; m++)
            {
                for(j=0; j<l; j++)
                    b[m]+=pow(2,l-j-1)*(a[m][j]-'0');
            }
            sort(b,b+n);
            for(j=0; j<n; j++)
            {
                if(b[j]!=dp[j])
                    break;
            }
            if(j>=n)
                ans=min(ans,sum);
        }
        printf("Case #%d: ",k);
        if(ans==INF)
            printf("NOT POSSIBLE\n");
        else
            printf("%d\n",ans);
    }
    return 0;
}
