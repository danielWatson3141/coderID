#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define INF 999999999
using namespace std;
int dp[155],ans,l;
void dfs(char a[][45],int n,int ll,int ss)
{
    int i,j;
    if(ll==(l-1))
    {
        int s[n+5];
        memset(s,0,sizeof(s));
        for(i=0; i<n; i++)
        {
            for(j=0; j<l; j++)
                s[i]+=pow(2,l-j-1)*(a[i][j]-'0');
        }
        sort(s,s+n);
        for(i=0; i<n; i++)
        {
            if(s[i]!=dp[i])
                break;
        }
        if(i>=n)
            ans=min(ans,ss);
        return ;
    }
    dfs(a,n,ll+1,ss);
    char b[155][45];
    for(i=0; i<n; i++)
    {
        for(j=0; j<l; j++)
            b[i][j]=a[i][j];
    }
    for(i=0; i<n; i++)
    {
        if(b[i][ll+1]=='0')
            b[i][ll+1]='1';
        else
            b[i][ll+1]='0';
    }
    dfs(b,n,ll+1,ss+1);
}
int main()
{
    int t,k,i,j,n;
    char tr[155][45];
    scanf("%d",&t);
    for(k=1; k<=t; k++)
    {
        char num[155][45];
        memset(dp,0,sizeof(dp));
        ans=INF;
        scanf("%d%d",&n,&l);
        for(i=0; i<n; i++)
            scanf("%s",tr[i]);
        for(i=0; i<n; i++)
        {
            scanf("%s",num[i]);
            for(j=0; j<l; j++)
            {
                dp[i]+=pow(2,l-j-1)*(num[i][j]-'0');
            }
        }
        sort(dp,dp+n);
        for(i=0; i<n; i++)
        {
            for(j=0; j<l; j++)
                num[i][j]=tr[i][j];
        }
        dfs(num,n,0,0);
        for(i=0; i<n; i++)
        {
            if(tr[i][0]=='0')
                tr[i][0]='1';
            else
                tr[i][0]='0';
        }
        dfs(tr,n,0,1);
        printf("Case #%d: ",k);
        if(ans==INF)
            printf("NOT POSSIBLE\n");
        else
            printf("%d\n",ans);
    }
    return 0;
}
