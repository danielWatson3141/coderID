
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

int T,n,gs,x,y;
int lst[1024];
int f[1024];
struct edge {
	int d,s;
}e[2048];

void addedge(int x,int y) {
	e[++gs].d=y;
	e[gs].s=lst[x];
	lst[x]=gs;
}

int dp(int x,int fa) {
	int v1=0,v2=0,t;
	for (int i=lst[x];i>0;i=e[i].s)
		if (e[i].d!=fa) {
			t=dp(e[i].d,x);
			if (t>=v1) {
				v2=v1;
				v1=t;
			}
			else if (t>v2) {
				v2=t;
			}
		}
	if (v2==0) return 1;
	else return v1+v2+1;
}

int main() {
	freopen("inl.txt","r",stdin);
	freopen("outl.txt","w",stdout);
	scanf("%d",&T);
	for (int ww=1;ww<=T;ww++) {
		gs=0;
		memset(lst,0,sizeof(lst));
		scanf("%d",&n);
		for (int i=1;i<n;i++) {
			scanf("%d%d",&x,&y);
			addedge(x,y);
			addedge(y,x);
		}
		int ans=0;
		for (int i=1;i<=n;i++) ans=max(ans,dp(i,0));
		printf("Case #%d: %d\n",ww,n-ans);
	}
	return 0;
}
