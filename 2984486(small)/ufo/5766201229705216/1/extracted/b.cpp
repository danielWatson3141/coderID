#include<cstdio>
#include<cstring>
int ans;
int n;
int last[1010],next[2010],to[2010],top;
int dp[1010],tmp;
void dfs(int fa,int now)
{
 	 int max1=0,max2=0,i;
 	 for(i=last[now];i;i=next[i])
 	 if(to[i]!=fa)
 	 {
 	 dfs(now,to[i]);
 	 if(dp[to[i]]>max2)
 	 max2=dp[to[i]];
 	 if(max2>max1)
 	 {
	  tmp=max1;
	  max1=max2;
	  max2=tmp;
	  }
	 }
	 if(max2==0)
	 dp[now]=1;
	 else
	 dp[now]=max1+max2+1;
}
int main()
{
 	int i,j,t,tt,a,b;freopen("b.in","r",stdin);
 	freopen("b.out","w",stdout);
 	for(scanf("%d",&tt),t=1;t<=tt;++t)
 	{
        scanf("%d",&n);
        ans=0;
        memset(last,0,sizeof(last));
        top=0;
        for(i=1;i<n;++i)
        {
		     scanf("%d%d",&a,&b);
		     to[++top]=a;
		     next[top]=last[b];
		     last[b]=top;
		     to[++top]=b;
		     next[top]=last[a];
		     last[a]=top;
		}
		for(i=1;i<=n;++i)
		{
	       memset(dp,0,sizeof(dp));
	       dfs(0,i);
	       if(dp[i]>ans)
	       ans=dp[i];
	 }
	 printf("Case #%d: %d\n",t,n-ans);
    }
 	return 0;
}
