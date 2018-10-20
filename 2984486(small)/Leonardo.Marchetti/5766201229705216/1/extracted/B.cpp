#include<cstdio>
#include<vector>
using namespace std;
#define pb(X) push_back(X)
#define sz(X) (int)X.size()
#define pii pair< int, int>
#define mp(X,Y) make_pair(X,Y);

vector<int> adj[1010];
pii PD[1010][1010];
int n;
int C,caso;

pii solve(int v, int pai) {
	int nv = pai == -1 ? sz(adj[v]) : sz(adj[v]) -1;
	if(nv==0) {
	  if(caso==C) printf("BASE %d\n",v); 
		return mp(1, 0);
	}	
	if(PD[v][pai+1].first!=-1)return PD[v][pai+1];
	int cst=0, m1 =0, m2=0;
	for(int k=0;k<sz(adj[v]);k++) {
		if(adj[v][k] != pai) {
		  pii p =  solve(adj[v][k], v);
			if(p.first>m1){ m2=m1; m1 = p.first; }
			else if(p.first>m2) m2 = p.first; 
			cst += p.first + p.second;
		}
	}
	if(nv==1) {
	 if(caso==C)
     printf("no %d nv %d (%d, %d)\n",v,nv,1,cst);
	 PD[v][pai+1]=mp(1, cst);
	 return mp(1, cst);
	}
	 if(caso==C)
     printf("no %d nv %d (%d, %d)\n",v,nv,m1+m2+1,cst-m1-m2);
	PD[v][pai+1]= mp(m1+m2+1,cst -m1 - m2);
	return mp(m1+m2+1,cst -m1 - m2);
}

int main(){
	int t;
	scanf("%d", &t);
	C=-1;
	for(caso=1;caso<=t;caso++) {
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			adj[i].clear();
		for(int i=1;i<n;i++) {
			int x,y;
			scanf("%d %d",&x,&y);
			x--;y--;
			if(caso == C) printf("ARESTA %d %d\n",x,y);
			adj[x].pb(y);
			adj[y].pb(x);
		}
		for(int i=0;i<1010;i++)
			for(int j=0;j<1010;j++)
				PD[i][j]=mp(-1,-1);
		int mi = 2000;
		for(int i=0;i<n;i++){
			pii x = solve(i,-1);
			if(caso==C)
			 printf("%d %d %d\n",i,x.first, x.second);
			mi = min(mi, x.second);
		}
		printf("Case #%d: %d\n",caso,mi);
	}
	return 0;
}
