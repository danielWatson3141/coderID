#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <string>
#include <math.h>
#include <time.h>
#include <vector>
#include <queue>
#define INF (1<<30)
#define MXN 1010
#define MXM 2010
using namespace std;
int n,last[1010],next[2010],to[2010],top,ans,dp[1010],tmp;
void dfs(int fa,int now) {
 	 int max1=0,max2=0,i;
 	 for(i=last[now];i;i=next[i])
 	 if(to[i]!=fa) {
 	 dfs(now,to[i]);
 	 if(dp[to[i]]>max2)
 	 max2=dp[to[i]];
 	 if(max2>max1) {
 	 	swap(max1,max2);
	  }
	 }
	 if(max2==0) dp[now]=1;
	 else dp[now]=max1+max2+1;
}
inline void solve() {
	int tt,a,b;
	scanf("%d",&tt);
	for(int t=1;t<=tt;t++){
        scanf("%d",&n);ans=top=0;memset(last,0,sizeof(last));
        for(int i=1;i<n;++i) {
		     scanf("%d%d",&a,&b);
		     to[++top]=a; next[top]=last[b]; last[b]=top;
		     to[++top]=b; next[top]=last[a]; last[a]=top;
		}
		for(int i=1;i<=n;++i) {
	       memset(dp,0,sizeof(dp));
	       dfs(0,i);
	       if(dp[i]>ans)
	       ans=dp[i];
	 }
	 printf("Case #%d: %d\n",t,n-ans);
    }
}
int main() {
	freopen("gcj20141AB.in","r",stdin);freopen("gcj20141AB.out","w",stdout);
	solve();
 	return 0;
}
