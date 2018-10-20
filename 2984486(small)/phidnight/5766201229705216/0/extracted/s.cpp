#include <cstdio>
#include <cstdlib>

typedef struct {
	int fr;
	int to;
} eds;
eds ed[2014];
int deg[1014];
int T,N;
int cmp(const void *ka,const void *kb) {
	eds *a=(eds *)ka;
	eds *b=(eds *)kb;
	if(a->fr!=b->fr) return a->fr-b->fr;
	return a->to-b->to;
}
int dfs(int nw,int frm) {
	int used=0;
	if(frm!=-1) used=1;
	if(deg[nw]-deg[nw-1]-used<2) {
		return 1;
	} else {
		int optx=0;
		int opty=0;
		int kopt;
		for(int i=deg[nw-1];i<deg[nw];i++) {
			if(ed[i].to!=frm) {
				kopt=dfs(ed[i].to,nw);
				if(optx<kopt) {
					opty=optx;
					optx=kopt;
				} else {
					if(opty<kopt) opty=kopt;
				}
			}
		}
		return optx+opty+1;
	}
}
int main() {
	scanf("%d",&T);
	for(int ts=1;ts<=T;ts++) {
		scanf("%d",&N);
		deg[0]=0;
		for(int i=1;i<=N;i++) deg[i]=0;
		for(int i=0;i<N-1;i++) {
			scanf("%d%d",&ed[i+i].fr,&ed[i+i].to);
			ed[i+i+1].fr=ed[i+i].to;
			ed[i+i+1].to=ed[i+i].fr;
			deg[ed[i+i].fr]++;
			deg[ed[i+i].to]++;
		}
		for(int i=1;i<=N;i++) deg[i]+=deg[i-1];
		qsort(ed,N+N-2,sizeof(eds),cmp);
		int smax=0;
		for(int i=1;i<=N;i++) {
			int kmax=dfs(i,-1);
			if(smax<kmax) smax=kmax;
		}
		printf("Case #%d: %d\n",ts,N-smax);
	}
	return 0;
}
