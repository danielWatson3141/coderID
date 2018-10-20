#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

#define M 1010

int n, d[M];
vector<int> g[M];
bool u[M];

int dfs(int v){
	u[v] = 1;
	d[v] = 1;
	priority_queue<int> q;
	for (auto &to : g[v])
	if (!u[to])
		q.push(dfs(to));

	if (q.size() < 2)
		return d[v];

	int m = min(2, (int) q.size());

	for (int i = 0; i < m; ++i,q.pop())
		d[v] += q.top();


	return d[v];
}

void zero(void){
	for (int i = 1; i <= n; ++i)
		u[i] = 0;
}

void read(void){
	cin >> n;
	for (int i = 1, x, y; i < n; ++i){
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
}

void kill(void){

	int ans = 0;

	for (int i = 1; i <= n; ++i){
		ans = max(ans, dfs(i));
		zero();
	}

	cout << n - ans;

	for (int i = 1; i <= n; ++i)
		g[i].clear();
}

int main(){
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);

	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i){
		read();
		cout << "Case #" << i << ": ";
		kill();
		cout << "\n";
	}

	return 0;
}