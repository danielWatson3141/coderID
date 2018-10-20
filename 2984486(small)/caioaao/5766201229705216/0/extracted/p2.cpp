#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
typedef vector<int> vi;
typedef long long ll;

int n, t;

vector<vi> AdjList;
vector<int> deg;

ll memoDel[1010][1010], memoMakeTree[1010][1010];

int calcDel(int u, int p){
	if(memoDel[u][p] != -1) return memoDel[u][p];
	memoDel[u][p] = 1;
	for(int i = 0; i < (int)AdjList[u].size(); i++){
		int v = AdjList[u][i];
		if(v != p) memoDel[u][p] += calcDel(v,u);
	}
	return memoDel[u][p];
}

int makeTree(int r, int p){
	//~ cout << r << ',' << p << endl;
	if(memoMakeTree[r][p] != -1) return memoMakeTree[r][p];
	if((p != 0 && deg[r] == 1) || (p == 0 && deg[r] == 0)) return 0;
	if((p != 0 && deg[r] == 2) || (p == 0 && deg[r] == 1)) {
		int v = AdjList[r][0];
		if(v == p) v = AdjList[r][1];
		return memoMakeTree[r][p] = calcDel(v, r);
	}
	
	ll dels = 0;
	for(int i = 0; i < (int)AdjList[r].size(); i++){
		int v = AdjList[r][i];
		if(v != p) dels += calcDel(v,r);
	}
	memoMakeTree[r][p] = dels;
	for(int i = 0; i < (int)AdjList[r].size(); i++){
		int v1 = AdjList[r][i], v2;
		if(v1 != p){
			for(int j = 0; j < (int)AdjList[r].size(); j++){
				v2 = AdjList[r][j];
				if(j != i && v2 != p){
					memoMakeTree[r][p] = min(memoMakeTree[r][p], dels - (calcDel(v1,r)+calcDel(v2,r)) + makeTree(v1,r) + makeTree(v2,r));
				}
			}
		}
	}
	
	return memoMakeTree[r][p];
}

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> t;
	for(int caso = 1; caso <= t; caso++){
		cout << "Case #" << caso << ": ";
		cin >> n;
		
		AdjList.assign(n+1,vi());
		deg.assign(n+1,0);
		memset(memoDel, -1, sizeof memoDel);
		memset(memoMakeTree, -1, sizeof memoMakeTree);
		int x, y;
		for(int i = 0; i < n-1; i++){
			cin >> x >> y;
			deg[x]++;
			deg[y]++;
			AdjList[x].push_back(y);
			AdjList[y].push_back(x);
		}
		int ans = makeTree(1,0);
		for(int i = 2; i <= n; i++){
			ans = min(ans, makeTree(i,0));
		}
		cout << ans << '\n';
	}
}
