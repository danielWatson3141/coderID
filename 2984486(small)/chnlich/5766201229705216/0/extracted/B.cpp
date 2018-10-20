/*
	Author : ChnLich
*/
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<iostream>
#include<sstream>
#include<fstream>
#include<algorithm>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<string>
#include<bitset>
#include<functional>
#include<utility>

using namespace std;

typedef long long llint;
typedef pair<int,int> ipair;
typedef unsigned int uint;
#define pb push_back
#define fi first
#define se second
#define mp make_pair

const int MOD=1000000007,dx[]={0,1,0,-1},dy[]={1,0,-1,0};
const double eps=1e-8;

void read(int &k)
{
	k=0; char x=getchar();
	while(x<'0'||x>'9') x=getchar();
	while(x>='0'&&x<='9') { k=k*10-48+x; x=getchar(); }
}

int siz[1010];
int n,x,y,ans;

struct graph
{
	int a[1010],b[2010],c[2010],p;
	void clear()
	{
		memset(a,0,sizeof a);
		p=0;
	}
	void addedge(int x,int y)
	{
		c[++p]=a[x]; a[x]=p; b[p]=y;
		c[++p]=a[y]; a[y]=p; b[p]=x;
	}
	void dfs(int k,int fa)
	{
		int tot=0;
		siz[k]=1;
		for(int i=a[k];i;i=c[i]) if (b[i]!=fa)
		{
			dfs(b[i],k);
			siz[k]+=siz[b[i]];
			tot++;
		}
		if (tot==1)
		{
			siz[k]=1;
		} else if (tot>2)
		{
			int ma=0,sma=0;
			for(int i=a[k];i;i=c[i]) if (b[i]!=fa)
			{
				if (siz[b[i]]>ma) sma=ma,ma=siz[b[i]];
				else if (siz[b[i]]>sma) sma=siz[b[i]];
			}
			siz[k]=ma+sma+1;
		}
	}
} A;

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	
	int T;
	scanf("%d",&T);
	for(int tt=1;tt<=T;tt++)
	{
		A.clear();
		scanf("%d",&n);
		for(int i=1;i<n;i++)
		{
			scanf("%d%d",&x,&y);
			A.addedge(x,y);
		}
		ans=n;
		for(int i=1;i<=n;i++)
		{
			A.dfs(i,0);
			if (n-siz[i]<ans) ans=n-siz[i];
		}
		printf("Case #%d: %d\n",tt,ans);
	}
	
	return 0;
}
