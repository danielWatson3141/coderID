#include<cstdio>
#include<bitset>

using namespace std;

const int inf=1e9;

bitset<1010> v;

int t,n;
int f1[1010],f2[1010];

struct size
{
	int ch;
	size *next;
}*g[1010];

inline int min(int a,int b)
{
	return a<b?a:b;
}

inline void add_edge(int x,int y)
{
	size *p=new size;
	p->ch=y;
	p->next=g[x];
	g[x]=p;
	
	p=new size;
	p->ch=x;
	p->next=g[y];
	g[y]=p;
}

void dfs(int x)
{
	v.set(x);
	int ma1=0,ma2=0;
	
	for(size *p=g[x];p!=NULL;p=p->next)
		if(!v.test(p->ch))
		{
			dfs(p->ch);
			if(f2[p->ch]+1-f1[p->ch]>=ma1)
				ma2=ma1,ma1=f2[p->ch]-f1[p->ch]+1;
			else
				if(f2[p->ch]-f1[p->ch]+1>ma2)
					ma2=f2[p->ch]-f1[p->ch]+1;
			
			f2[x]+=f2[p->ch]+1;
		}
	
	if(ma2>0)
		f1[x]=f2[x]-ma1-ma2;
	else
		f1[x]=f2[x];
}

int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	
	scanf("%d",&t);
	
	for(int t1=1;t1<=t;t1++)
	{
		scanf("%d",&n);
		
		int ans=inf;
		
		for(int i=1;i<=n;i++)
			g[i]=NULL;
		
		for(int i=1;i<n;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			add_edge(x,y);
		}
		
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
				f1[j]=f2[j]=0;
			
			v.reset();
			dfs(i);
			ans=min(ans,f1[i]);
		}
		printf("Case #%d: %d\n",t1,ans);
	}
	
	return 0;
} 
