#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <map>

using namespace std;

#define ll long long
#define pii pair<int,int>

ofstream fout ("1AB.out");
ifstream fin ("1AB.in");

vector<int> edges[1005];
int N;
int dp[1005],cnt[1005];

void dfs(int ind,int prev) {
	dp[ind] = 2000;
	cnt[ind] = 1;
	if (edges[ind].size() == 1 && prev != -1) {
		dp[ind] = 0;
		return;
	}
	for (int i = 0; i < edges[ind].size(); i++) {
		if (edges[ind][i] == prev) continue;
		dfs(edges[ind][i],ind);
		cnt[ind] += cnt[edges[ind][i]];
	}
	int sum = 0;
	for (int i = 0; i < edges[ind].size(); i++) {
		if (edges[ind][i] != prev) sum += cnt[edges[ind][i]];
	}
	dp[ind] = sum;
	if (edges[ind].size() - (prev != -1) == 1) {
		return;
	}
	for (int i = 0; i < edges[ind].size(); i++) {
		if (edges[ind][i] == prev) continue;
		for (int j = i+1; j < edges[ind].size(); j++) {
			if (edges[ind][j] == prev) continue;
			dp[ind] = min(dp[ind],sum-cnt[edges[ind][i]]+dp[edges[ind][i]]-cnt[edges[ind][j]]+dp[edges[ind][j]]);
		}
	}
}

int main() {
	int T;
	fin >> T;
	vector<int> blank;
	for (int t = 1; t <= T; t++) {
		cout << "Working on Case #" << t << endl;
		fin >> N;
		for (int i = 0; i < N; i++) {
			edges[i] = blank;
		}
		for (int i = 0; i < N-1; i++) {
			int a,b;
			fin >> a >> b;
			a--; b--;
			edges[a].push_back(b);
			edges[b].push_back(a);
		}
		int ans = 2000;
		for (int i = 0; i < N; i++) {
			dfs(i,-1);
			ans = min(ans,dp[i]);
		}
		fout << "Case #" << t << ": " << ans << "\n";
	}
    return 0;
}