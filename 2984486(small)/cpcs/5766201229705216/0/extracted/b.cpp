#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

vector<int> con[1024];
int dp[1024];

int help(int father,int x) {	
vector<int> have;
	for (int i = 0 ; i < con[x].size(); ++i) {
		if (con[x][i] != father) {
			have.push_back(help(x, con[x][i]));
		}

	}
	if (have.size() < 2) {
		return dp[x] = 1;
	}
	sort(have.begin(), have.end());
	return dp[x] = 1 + have[have.size() - 1] + have[have.size() - 2];
 
}

int main() {
int zz;
	scanf("%d",&zz);
	for (int z = 1; z <= zz; ++z) {
		int n;
		scanf("%d",&n);
		for (int i = 0; i < n; ++i) {
			con[i].clear();
		}
		for (int i = 1; i < n; ++i) {
			int x,y;
			scanf("%d%d",&x,&y);
			--x;
			--y;
			con[x].push_back(y);
			con[y].push_back(x);
		}
		int may = 0;
		for (int i = 0; i < n; ++i) {
			may = max(may, help(-1, i));
		}
		printf("Case #%d: %d\n",z, n - may);
	}
	return 0;
}
		
