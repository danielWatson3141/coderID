#include <iostream>
#include <vector>
using namespace std;
const int maxn = 1000 + 10;
vector<int> edge[maxn];
int n;
int dfs(int k, int fa){
	int min1 = 0, min2 = 0;
	int son = 0;
	for (int i = 0; i<edge[k].size(); i++) if (edge[k][i] != fa){
		son++;
		int v = edge[k][i];
		int x = dfs(v, k);
		if (x>min1){
			min2 = min1;
			min1 = x;
		}else if (x>min2){
			min2 = x;
		}
	}
	if (son == 0) return 1;
	if (son < 2) return 1;
	return min1+min2+1;
}
int main(){
	int T, cas = 0;
	for (cin>>T; T--;){
		cas++;
		cout<<"Case #"<<cas<<": ";
		cin>>n;
		for (int i = 0; i<maxn; i++) edge[i].clear();
		for (int i = 1; i<n; i++){
			int x, y;
			cin>>x>>y;
			edge[x].push_back(y);
			edge[y].push_back(x);
		}
		int mindel = 99999;
		for (int i = 1; i<=n; i++){
			int res = dfs(i, 0);
			mindel = min(mindel, n-res);
		}
		cout<<mindel<<endl;
	}
	return 0;
}
