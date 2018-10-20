#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <map>
#include <set> 
#include <sstream>
#include <fstream>
#include <utility>
#include <string>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
#define REP(i,a) for(int i=0;i<a;i++)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define FOREACH(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define SIZE(c) (int)c.size()
#define ALL(c) (c).begin(),(c).end() 
typedef pair<int, int> PII;
const int INF = 1000000000;
int N;
vector<vector<int> > adj;
bool vis[20];
bool go(int idx, int mask){
	vis[idx] = true;
	vector<int> can;
	for(int i = 0; i < adj[idx].size(); i ++){
		if((mask & (1<<adj[idx][i])) && !vis[adj[idx][i]]){
			can.push_back(adj[idx][i]);
		}
	}
	if(SIZE(can) == 0) {
		return true;
	} else if(SIZE(can) == 2) {
		return go(can[0], mask) && go(can[1], mask);
	} else {
		return false;
	}
}
int main() {
	//freopen("b.in", "r", stdin); 
	freopen("B-small-attempt0.in", "r", stdin); freopen("B-small-attempt0.out", "w", stdout);
	//freopen("B-small-attempt1.in", "r", stdin); freopen("B-small-attempt1.out", "w", stdout);
	//freopen("B-small-attempt2.in", "r", stdin); freopen("B-small-attempt2.out", "w", stdout);
	//freopen("B-small-attempt3.in", "r", stdin); freopen("B-small-attempt3.out", "w", stdout);
	
	//freopen("B-large.in", "r", stdin); freopen("B-large.out", "w", stdout);
	
	int nT;
	cin>>nT;
	for (int t=1; t<=nT; t++) {
		printf("Case #%d: ", t);
		cin>>N;
		vector<vector<int> > c;
		c.resize(N);
		adj = c;
		memset(vis, false, sizeof vis);
		REP(i, N - 1){
			int a; int b; cin>>a>>b;
			a --, b --;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		int ret = INF;
		for(int mask = 0; mask < (1<<N); mask ++){
			bool ok = false;
			for (int i = 0; i < N; i ++) if(mask & (1<<i)) {
				memset(vis, false, sizeof vis);
				if(go(i, mask)) {
					ok = true;
					for (int j = 0; j < N; j ++) if((mask & (1<<j)) && !vis[j]) {
						ok = false;
					} 
					if(ok){
						ok = true;
						break;
					}
				}
			}
			if(ok) {
				ret = min(ret, N - __builtin_popcount(mask));
			}
		}
		cout<<ret<<endl;
	}
	return 0;
}
