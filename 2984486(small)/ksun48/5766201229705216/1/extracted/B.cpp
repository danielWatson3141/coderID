#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
vector<int> edges[2000];
int n;
int answer[2000];
int vis[2000];
void dfs(int a){
	vis[a] = 1;
	answer[a] = 1;
	int max1 = 0;
	int max2 = 0;
	for(int i = 0; i < edges[a].size(); i++){
		int c = edges[a][i];
		if(vis[c] == 0){
			dfs(c);
			if(answer[c] > max2){
				max2 = answer[c];
			}
			if(max2 > max1){
				swap(max2, max1);
			}
		}
	}
	if(max2 > 0 && max1 > 0){
		answer[a] = max1+max2+1;
	}
	return;
}
main() {
	FILE *fin = freopen("B-large.in", "r", stdin);
	assert( fin!=NULL );
	FILE *fout = freopen("B-large.out", "w", stdout);
	int T;
	cin >> T;
	int ans;
	for(int t = 1; t <= T; t++){
		cout << "Case #" << t << ": ";
		ans = 0;
		cin >> n;
		for(int i = 0; i < 2000; i++){
			edges[i].clear();
		}
		for(int i = 1; i < n; i++){
			int a, b;
			cin >> a >> b;
			edges[a-1].push_back(b-1);
			edges[b-1].push_back(a-1);
		}
		for(int root = 0; root < n; root++){
			for(int i = 0; i < 2000; i++){
				answer[i] = 0;
				vis[i] = 0;
			}
			dfs(root);
			ans = max(ans, answer[root]);
		}
		cout << n-ans << endl;
	}
	exit(0);
}