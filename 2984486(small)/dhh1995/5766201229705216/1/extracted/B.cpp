#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define rep(i,n) for (int i=1;i<=n;++i)
typedef long long LL;
const int N=2005;
int T,Case,ans,n,l,x,y,f[N],s[N],son[N],next[N],ed[N];
void dfs(int x,int fa)
{
	f[x]=0; int cnt=0,m0=0,m1=0;
	for (int y,p=son[x];p;p=next[p]) if ((y=ed[p])!=fa){
		dfs(y,x),f[x]+=f[y],++cnt;
		if (s[y]>m0) f[x]+=m1,m1=m0,m0=s[y];
		else if (s[y]>m1) f[x]+=m1,m1=s[y];
			else f[x]+=s[y];
	}
	s[x]=m0+m1+1;
	if (cnt==1) f[x]+=s[x]-1,s[x]=1;
//	printf("%d %d %d\n",x,f[x],s[x]);
}
int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n),l=1,ans=n; rep(i,n) son[i]=0;
		rep(i,n-1) scanf("%d%d",&x,&y),
			ed[++l]=y,next[l]=son[x],son[x]=l,
			ed[++l]=x,next[l]=son[y],son[y]=l;
		rep(i,n) dfs(i,0),ans=min(ans,f[i]);
		printf("Case #%d: %d\n",++Case,ans);
	}
	return 0;
}

