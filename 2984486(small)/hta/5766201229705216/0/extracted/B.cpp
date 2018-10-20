#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <ctime>
#include <set>
#include <bitset>
#include <map>
#define x first
#define y second
#define mp make_pair
#define pb push_back
using namespace std;
inline int get()
{
    int f=0,v=0;char ch;
    while(!isdigit(ch=getchar()))if(ch=='-')break;
    if(ch=='-')f=1;else v=ch-48;
    while(isdigit(ch=getchar()))v=v*10+ch-48;
    if(f==1)return -v;else return v;
}
typedef long long LL;
const int maxn=1003;
int Link[maxn],n,pre[maxn*2],t[maxn*2],f[maxn],a[maxn][maxn],size[maxn];

void dfs(int x,int fa)
{
	bool isleaf=1;
	int cnt=0;
	for(int i=Link[x];i;i=pre[i])
	{
		if(t[i]==fa)continue;else isleaf=0;
		dfs(t[i],x);
		a[x][++cnt]=f[t[i]];
	}
	if(isleaf){f[x]=1;return;}
	if(cnt<2){f[x]=1;return;}
	sort(a[x]+1,a[x]+1+cnt);
	f[x]=a[x][cnt]+a[x][cnt-1]+1;
}

int main()
{
    freopen("B.in","r",stdin);
    freopen("B.out","w",stdout);
    int T=get();
    for(int tt=1;tt<=T;tt++)
    {
		n=get();
		memset(Link,0,sizeof(Link));
		for(int i=1,tot=0;i<n;i++)
		{
			int x=get(),y=get();
			pre[++tot]=Link[x]; Link[x]=tot; t[tot]=y;
			pre[++tot]=Link[y]; Link[y]=tot; t[tot]=x;
		}
		int ans=n;
		for(int i=1;i<=n;i++)
		{
			memset(f,0,sizeof(f));
			dfs(i,0);
			ans=min(ans,n-f[i]);
		}
		printf("Case #%d: %d\n",tt,ans);
	}
    return 0;
}
