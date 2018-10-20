#include<cstdio>
#include<algorithm>
using namespace std;
struct ty{bool p[45];} s1[160],s2[160];
int n,l,ans;
char w[45];
int cnt0[50],cntx[50];
int k[50];
bool operator < (ty x,ty y)
{
 	 for(int i=1;i<=l;++i)
 	 {
	  		 if((x.p[i]^k[i])<(y.p[i]^k[i]))
				  return 1;
	  		 if((x.p[i]^k[i])>(y.p[i]^k[i]))
				  return 0;
	 }
	 return 0;
}
bool operator == (ty x,ty y)
{
 	 for(int i=1;i<=l;++i)
	  		 if((x.p[i]^k[i])!=y.p[i])
				  return 0;
	 return 1;
}
bool judge()
{
 	 sort(s1+1,s1+n+1);
 	 for(int i=1;i<=n;++i)
 	    if((s1[i]==s2[i])==0)
 	    return 0;
   return 1;
}
void dfs(int now,int val)
{
 	 if(val>=ans)
		 return;
		 if(now==l+1)
		 {
		     if(judge())
			 ans=val;
		     return;
		 }
     if(cnt0[now]==cntx[now])
     dfs(now+1,val);
     if(cnt0[now]==n-cntx[now])
     {
		   k[now]=1;
     	 dfs(now+1,val+1);
     	 k[now]=0;
		 }
}
int main()
{
 	freopen("a.in","r",stdin);
 	freopen("a.out","w",stdout);
    int i,t,tt,j;
    for(scanf("%d",&tt),t=1;t<=tt;++t)
    {
		  ans=2147483647;
         scanf("%d%d",&n,&l);
         for(i=1;i<=l;++i)
         cnt0[i]=cntx[i]=0;
         for(i=1;i<=n;++i)
         {
		    scanf("%s",w+1);
		    for(j=1;j<=l;++j)
		    {
		        s1[i].p[j]=w[j]-'0';
		        if(s1[i].p[j])
		        ++cnt0[j];
				}
         }
         for(i=1;i<=n;++i)
         {
		    scanf("%s",w+1);
		    for(j=1;j<=l;++j)
		    {
		        s2[i].p[j]=w[j]-'0';
		        if(s2[i].p[j])
		        ++cntx[j];
				}
         }
         sort(s2+1,s2+n+1);
         dfs(1,0);
         if(ans>1000)
         printf("Case #%d: NOT POSSIBLE\n",t);
         else
         printf("Case #%d: %d\n",t,ans);
    }
    return 0;
}
