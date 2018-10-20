#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

char str1[200][50], str2[200][50];

int n, L;

int matrix[200][200], degrees1[200], degrees2[200], vy[200], mx[200], my[200];

void input() {
	scanf("%d%d", &n, &L);
	for(int i = 0;i < n;i ++) scanf("%s", str1[i]);
	for(int i = 0;i < n;i ++) scanf("%s", str2[i]);
}

int path(int v) {
	for(int i = 0;i < degrees1[v];i ++) {
		if(!vy[matrix[v][i]]) {
			vy[matrix[v][i]]=1;
			if(my[matrix[v][i]]==-1||path(my[matrix[v][i]])) {
				mx[v] = matrix[v][i];
				my[matrix[v][i]] = v;
				return 1;
			}
		}
	}
	return 0;
}

int maximum_match() {
	int res = 0;
	for(int i = 0;i < n;i ++) mx[i] = my[i] = -1;

	for(int i = 0;i < n;i ++) if(mx[i] == -1)
	memset(mx,-1,sizeof(int));
	memset(my,-1,sizeof(my));
	for(int i = 0;i < n;i ++) for(int j = 0;j < degrees1[i];j ++) if(my[matrix[i][j]] == -1) {
		mx[i] = matrix[i][j];
		my[matrix[i][j]] = i;
		++ res;
		break;
	}

	for(int i = 0;i < n;i ++) if(mx[i] == -1) {
		memset(vy, 0, sizeof(int)*n);
		if(path(i)) ++ res;
	}
	return res;
}

void output() {
	vector<pair<pair<int,long long>, pair<int,int> > > vp;
	vp.reserve(n*n);
	
	for(int i = 0;i < n;i ++) for(int j = 0;j < n;j ++) {
		int cnt = 0;
		long long bitset = 0;
		for(int k = 0;k < L;k ++) if(str1[i][k] != str2[j][k]) {
			++ cnt;
			bitset = bitset | (((long long)1)<<k);
		}

		vp.push_back(make_pair(make_pair(cnt, bitset), make_pair(i, j)));
	}

	sort(vp.begin(), vp.end());

	for(int i = 0;i < n;i ++) for(int j = 0;j < n;j ++) matrix[i][j] = 0;

	int j;
	for(int i = 0;i < (int)vp.size();i = j) {
		j = i;
		while(j < (int)vp.size()&&vp[j].first.second == vp[i].first.second) ++ j;

		if(j - i < n) continue;

		for(int k = 0;k < n;k ++) degrees1[k] = degrees2[k] = 0;
		for(int k = i;k < j;k ++) {
			matrix[vp[k].second.first][degrees1[vp[k].second.first]] = vp[k].second.second;
			++ degrees1[vp[k].second.first];
			++ degrees2[vp[k].second.second];
		}

		int ok = 1;
		for(int k = 0;k < n&&ok;k ++) if(degrees1[k] == 0||degrees2[k] == 0) ok = 0;

		if(ok&&maximum_match() == n) {
			printf("%d\n", vp[i].first.first);
			return ;
		}
	}
	printf("NOT POSSIBLE\n");
}

int main() {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for(int cas = 1;cas <= t;cas ++) {
		input();
		printf("Case #%d: ", cas);
		output();
	}
	return 0;
}