#include <cstdio>
#include <cstring>

#define N 10000

using namespace std;

int T,n,t,x,y,mm,next[N+10],son[N+10],ed[N+10],q[N+10],fa[N+10],s[N+10],f[N+10];

inline int max(int a,int b){
	return a>b?a:b;
}

void add(int x,int y){
	next[++mm]=son[x],son[x]=mm,ed[mm]=y;
}

void bfs(int rt){
	memset(f,130,sizeof(f));
	memset(fa,0,sizeof(fa));
	q[1]=rt,fa[rt]=-1;
	int l=0,r=1;
	while (l<r){
		int x=q[++l];
		for (int i=son[x];i;i=next[i]){
			int y=ed[i];
			if (!fa[y]) q[++r]=y,fa[y]=x;
		}
	}
	for (int i=n;i;--i){
		int x=q[i],m1=0,m2=0;
		s[x]=1;
		for (int j=son[x];j;j=next[j]){
			int y=ed[j];
			if (fa[y]==x){
				s[x]+=s[y];
				if (f[y]>m1) m2=m1,m1=f[y];
				else if (f[y]>m2) m2=f[y];
			}
		}
		if (!m2) f[x]=1;
		else f[x]=m1+m2+1;
	}
	t=max(t,f[rt]);
}

int main(){
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	scanf("%d",&T);
	for (int kase=1;kase<=T;++kase){
		scanf("%d",&n);
		memset(son,0,sizeof(son));
		mm=0;
		for (int i=1;i<n;++i) scanf("%d%d",&x,&y),add(x,y),add(y,x);
		t=0;
		for (int i=1;i<=n;++i) bfs(i);
		printf("Case #%d: %d\n",kase,n-t);
	}
	return 0;
}
