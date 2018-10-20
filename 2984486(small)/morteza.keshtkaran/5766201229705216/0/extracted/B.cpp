#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

vector<int> adj[1010];

#define		PII	pair<int,int>

int r;
int dfs(int x,int p){
	int nc = adj[x].size();
	if (x!=r) nc--;

	if (nc<2) return 0;

	vector<int> c;
	for (int i=0;i<adj[x].size();i++){
		if (adj[x][i]!=p){
			c.push_back(dfs(adj[x][i],x));
		}
	}
	sort(c.begin(),c.end());
	return c[nc-1]+c[nc-2]+2;
	
}

int main(){
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);

	int ntc,n,a,b;
	cin >> ntc;
	for (int tc=1;tc<=ntc;tc++){
		cout << "Case #" << tc << ": ";

		cin >> n;
		for (int i=0;i<n;i++) adj[i].clear();
		for (int i=0;i<n-1;i++){
			cin >> a >> b;
			a--,b--;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		r = 0;
		int res = n-dfs(0,-1)-1,nr;
		for (int i=1;i<n;i++){
			r = i;
			nr = n-dfs(i,-1)-1;
			res = min(res,nr);
		}

		cout << res << endl;
			

	}

	return 0;
}