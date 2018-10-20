// Submitted by Silithus @ Macau
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin(); itr!=(c).end(); itr++)
#define INF 0x7fffffff

using namespace std;

vector<int> link[1001];
int vis_node;

int DFS(int u, int father)
{
	int v=1, vv;
	vector<int> pt;

	foreach(link[u], it)
		if( *it != father ) {
			vv = DFS(*it, u);
			pt.push_back(vv);
		}
	
	if( pt.size() >= 2 ) {
		sort(pt.begin(), pt.end(), greater<int>());
		v += pt[0] + pt[1];
	}
	
	return v;
}

void solve(void)
{
	int N,ans,i,x,y;
	
	cin >> N;
	for(i=1; i<=N; i++) link[i].clear();
	
	for(i=0; i<N-1; i++) {
		cin >> x >> y;
		link[x].push_back(y);
		link[y].push_back(x);
	}
	
	for(i=1,ans=INF; i<=N; i++) {
		x = DFS(i,-1);
		ans = min(ans, N-x);
	}
	
	cout << ans << endl;
}

int main(void)
{
	int t,T;
	
	cin >> T;

	for(t=1; t<=T; t++) {
		cout << "Case #" << t << ": ";
		solve();
	}
	
	return 0;
}
