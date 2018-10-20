#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define FOR(i,l,r) for(int i=l; i<=r; i++)
#define COR(i,r,l) for(int i=r; i>=l; i--)
#define FORG(j,x) for(int j=h[x],v=b[j]; j; j=nt[j],v=b[j])
#define FILL(a,b) memset(a,b,sizeof(a))
#define INF 1000000000
#define N 120001
int n,m,e = 1,ans,st,T;
int b[N],nt[N],w[N],h[N],cnt[N];
void wist(int x,int y){
	b[++e] = y; nt[e] = h[x]; h[x] = e;
}
void get(int x,int fa){
	int son1 = -1, son2 = -1;
	FORG(j,x) if(v != fa){
		get(v,x);
		if(cnt[v] > son1) son2 = son1, son1 = cnt[v];
		else if(cnt[v] > son2) son2 = cnt[v];
	}
	cnt[x] = son1 + son2 + 1;
	if(son1 == -1 || son2 == -1) cnt[x] = 1;
}
int main(){
	freopen("a.in","r",stdin);
	freopen("b.out","w",stdout);
//  根节点有三个孩子的话必须只有一个节点只有==1个孩子 其他必须合法 
//  根节点有一个孩子的话必须只有一个节点只有==1个孩子 其他必须合法
//  根节点两个孩子为合法二叉树   
	scanf("%d",&T);
	FOR(cas,1,T){
		scanf("%d",&n);
		int x,y;
		e = 1; FILL(h,0);
		FOR(i,1,n-1){
			scanf("%d%d",&x,&y);
			wist(x,y);
			wist(y,x);
		}
		ans = 0;
		FOR(i,1,n){
			FILL(cnt,0);
			get(i,0);
			ans = max(ans, cnt[i]);
		}
		printf("Case #%d: %d\n",cas,n - ans);
	}
	return 0;
}
