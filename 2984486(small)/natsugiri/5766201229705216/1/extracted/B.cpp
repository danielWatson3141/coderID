#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
typedef vector<vector<int> > Mat;

Mat G;

pair<int,int> dfs(int v, int p) { // (rest, del)
    vector<pair<int,int> > z;
    for (int i=0; i<(int)G[v].size(); i++) {
	if (G[v][i] == p) continue;
	z.push_back(dfs(G[v][i], v));
    }

    if ((int)z.size() == 0) {
	return make_pair(1, 0);
    } else if ((int)z.size() == 1) {
	return make_pair(1, z[0].first + z[0].second);
    } else {

	sort(z.begin(), z.end());
	int rest = 1, del = 0;
	for (int i=0; i<(int)z.size()-2; i++) del += z[i].first + z[i].second;
	for (int i=max(0, (int)z.size()-2); i<(int)z.size(); i++) {
	    rest += z[i].first;
	    del += z[i].second;
	}
	return make_pair(rest, del);
    }
}

int main() {
    int T;
    scanf("%d", &T);

    for (int tc=1; tc<=T; tc++) {
	int N;
	scanf("%d", &N);
	G = Mat(N);

	for (int i=1; i<N; i++) {
	    int a, b;
	    scanf("%d%d", &a, &b);
	    a--; b--;
	    G[a].push_back(b);
	    G[b].push_back(a);
	}

	int ans = N+99;
	for (int r=0; r<N; r++) ans = min(ans, dfs(r, -2).second);

	printf("Case #%d: %d\n", tc, ans);
	
    }
    return 0;
}
