#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cstdlib>
#include <cctype>
using namespace std;
#define FOR(i,s,e) for(int i=(s);i<(int)(e);i++)
#define FORS(i,s) for(int i=0;(s)[i];i++)
#define FOE(i,s,e) for(int i=(s);i<=(int)(e);i++)
#define CLR(s) memset(s,0,sizeof(s))
typedef long long LL;
#define PB push_back
#define INF 1000000000

int n;
int f[1111],sz[1111];
bool v[1111];
vector<int> e[1111];
int q[1111], qs,qe;
int x[1111];

int main() {	
int nt; scanf("%d", &nt); FOR(tt,1,nt+1){
	scanf("%d", &n);
	FOR(i,0,n) e[i].clear();
	FOR(i,0,n-1){
		int a,b;
		scanf("%d%d", &a,&b); a--;b--;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	int ans = INF;
	FOR(i,0,n){
		FOR(j,0,n) v[j] = false;
		qs=qe=0;
		x[i] = qe; q[qe++] = i; v[i] = true;
		while(qs < qe){
			int c = q[qs++];
			FOR(k,0,e[c].size()){
				int d = e[c][k];
				if(v[d]) continue;
				x[d] = qe; q[qe++] = d; v[d] = true;
			}
		}
		
		for(int j=n-1; j>=0; j--){
			int c = q[j];
			sz[c] = 1;
			f[c] = 0;
			int m0 = INF, m1 = INF, sf = 0;
			FOR(k,0,e[c].size()){
				int d = e[c][k];
				if(x[d] < j) continue;
				sz[c] += sz[d];
				sf += f[d];
				int cfd = f[d] - sz[d];
				if(cfd < m0){
					m1 = m0; m0 = cfd;
				}else if(cfd < m1) m1 = cfd;
			}
			f[c] = sz[c]-1;
			if(m1 != INF){
				f[c] = min(f[c], m0+m1+sz[c]-1);
			}
		}
		ans = min(ans, f[q[0]]);
	}
	printf("Case #%d: ", tt);
	printf("%d\n", ans);

}	
return 0;
}


