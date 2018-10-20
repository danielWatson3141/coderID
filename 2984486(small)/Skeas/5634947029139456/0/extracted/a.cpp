#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <sstream>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <ctime>

using namespace std;

vector<int> adj[200];
bool seen[200];
int R[200];

int N,L;
vector<string> ori,list;

bool bpm(int u) {
	for(int i=0;i<adj[u].size();++i) {
		int v = adj[u][i];
		if(seen[v]) continue;
		seen[v] = 1;

		if(R[v] == -1 || bpm(R[v])) {
			R[v] = u; return 1;
		}
	} return 0;
}

int match() {
	memset(R,-1,sizeof(R));
	int ret = 0;
	for(int u=0;u<N;++u) {
		memset(seen,0,sizeof(seen));
		ret += bpm(u);
	} return ret;
}

int main() {
#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int Ts;
	scanf("%d",&Ts);
	for(int cs=1;cs<=Ts;++cs) {
		printf("Case #%d: ", cs);
		ori.clear(),list.clear();

		scanf("%d%d",&N,&L);
		for(int i=0;i<N;++i) {
			string tmp; cin>>tmp;
			ori.push_back(tmp);
		}
		for(int i=0;i<N;++i) {
			string tmp; cin>>tmp;
			list.push_back(tmp);
		}

		int ans = 1000000;
		for(int i=0;i<N;++i) {
			for(int j=0;j<200;++j) adj[j].clear();
			bool on[44]={0};
			int tmp = 0;
			vector<string> nw = ori;
			for(int j=0;j<L;++j) if(list[0][j] != ori[i][j]) {
				on[j] = 1, tmp++;
			}
			for(int j=0;j<L;++j) if(on[j]) {
				for(int k=0;k<N;++k) {
					nw[k][j] = (ori[k][j]=='0'?'1':'0');
				}
			}
			for(int j=0;j<N;++j) for(int k=0;k<N;++k) if(nw[j] == list[k]) {
				adj[j].push_back(k);
			}

			if(match() == N) ans = min(ans, tmp);
		}

		if(ans == 1000000) printf("NOT POSSIBLE\n");
		else printf("%d\n",ans);
	}
}