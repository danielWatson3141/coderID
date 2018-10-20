#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vnt;

vnt way[1005];
int n;
int nds[1005], kil[1005];

int go(int u, int p)
{
	int i;
	int a,b;
	nds[u] = 1;
	if(way[u].size()==1 and p!=-1) return (kil[u] = 0);
	for(i=0;i<way[u].size();i++) {
		if(way[u][i]!=p) {
			go(way[u][i], u);
			nds[u] += nds[way[u][i]];
		}
	}
	if((way[u].size()==2 and p!=-1) or (way[u].size()==1 and p==-1)) {
		return (kil[u] = nds[u]-1);
	} 
	a = b = 0;
	for(i=0;i<way[u].size();i++) {
		if(way[u][i]==p) continue;
		if(nds[way[u][i]]-kil[way[u][i]] > a) {
			b = a;
			a = nds[way[u][i]]-kil[way[u][i]];
		} else if (nds[way[u][i]]-kil[way[u][i]] > b) {
			b = nds[way[u][i]]-kil[way[u][i]];
		}
	}
	return (kil[u] = nds[u]-1-a-b);
}

int sol(int cse)
{
	
	int i,j,k;
	int a,b;
	int bst = 1000;
	scanf("%d",&n);
	for(i=0;i<n;i++) {
		way[i].clear();
		nds[i] = kil[i] = 0;
	}
	for(i=0;i<n-1;i++) {
		scanf("%d %d",&a,&b); a--; b--;
		way[a].push_back(b);
		way[b].push_back(a);
	}
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) nds[j] = kil[j] = 0;
		bst = min(bst, go(i,-1));
	}
	printf("Case #%d: %d\n", cse, bst);
}


int main()
{
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;sol(i), i++);
	return 0;
}