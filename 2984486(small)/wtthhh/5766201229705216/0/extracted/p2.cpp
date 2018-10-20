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
int b[N],nt[N],w[N],h[N],del[N],use[N],p[N];
void wist(int x,int y){
	b[++e] = y; nt[e] = h[x]; h[x] = e;
}
bool check(int x,int fa){
	int now = 0;
	st++;
	FORG(j,x) if(!del[v] && v != fa){
		now++;
		if(!check(v,x)) return false;
	}
	if(now == 2 || now == 0) return true;
	return false;
}
bool get(int y){
	int tot = 0;
	FILL(use,0);
	FOR(i,1,n) if(!del[i] && !use[i]){
		st = 0;
		if(!check(i,0)) continue;
		if(st + y != n) return false;
		return true;
	}
	return false;
}
void dfs(int x,int y){
	if(y > ans) return;
	if(x > n){
		if(get(y)) ans = min(ans, y);
		return;
	}
	FOR(i,x+1,n+1){
		del[i] = true;
		dfs(i,y+(i != n+1));
		del[i] = false;
	}
}
int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
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
		ans = n;
		dfs(0,0);
		printf("Case #%d: %d\n",cas,ans);
	}
	return 0;
}
