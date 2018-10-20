#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int MaxN = 1005;

vector<int> edge[MaxN];

int ans = 0, N;
int res[MaxN][MaxN];

void dfs(int v, int fa){
	int tmp[6], len = 0;
	for (int i = 0; i < edge[v].size(); ++i)
		if (edge[v][i] != fa){
			dfs(edge[v][i], v);
			tmp[len++] = res[edge[v][i]][v];
			for (int i = 0; i < len; ++i)
				for (int j = i + 1; j < len; ++j)
					if (tmp[i] < tmp[j])
						swap(tmp[i], tmp[j]);
			if (len > 2)
				--len;
		}
	int tot = 0;
	if (len >= 2){
		for (int i = 0 ; i < 2; ++i)
			tot += tmp[i];
	}
	if (fa == -1){
		ans = max(ans, tot + 1);
	}
	else 
		res[v][fa] = tot + 1;
}

int main(){
	int T = 0;
	cin >> T;
	for (int testcase = 1; testcase <= T; ++testcase){
		cin >> N;
		for (int i = 0; i < N; ++i)
			edge[i].clear();

		memset(res, 0, sizeof(res));

		ans = 0;
		for (int i = 0; i < N - 1; ++i){
			int x, y;
			cin >> x >> y;			
			--x;--y;
			edge[x].push_back(y);
			edge[y].push_back(x);
		}
		for (int i = 0; i < N; ++i)
			dfs(i, -1);
		cout << "Case #" << (testcase) << ": " << (N - ans) << endl;
	}
	return  0;
}