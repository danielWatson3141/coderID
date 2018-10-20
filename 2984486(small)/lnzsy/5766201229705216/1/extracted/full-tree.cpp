#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cstdint>
#include <cmath>
#include <utility>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <string.h>

using namespace std;

#define REP(i, p, n) for (int i=p; i<n; ++i)
#define FOR(i, c) for (__typeof ((c).begin()) i=(c).begin(); i!=(c).end(); ++i)

int dp[1005][1005];

int trim (vector<vector<int> > &e, int pre, int root, vector<int> &mark) {
	if (dp[pre][root] != -1) {
		return dp[pre][root];
	}
	if (e[root].size() == 0) return 0;

	if (e[root].size()==1) {
		dp[pre][root] = 1;
		return 1;
	}
	if (e[root].size()==2) {
		if (e[root][0]==pre || e[root][1]==pre) {
			dp[pre][root] = 1;
			return 1;
		}
	}
	vector<int> tmp;

	REP (i, 0, e[root].size()) {
		if (e[root][i] == pre)
			continue;
		int next = trim (e, root, e[root][i], mark);
		tmp.push_back (next);
	}
	sort(tmp.begin(), tmp.end());
	int size = tmp.size();
	if (size < 2) {
		dp[pre][root] = 1;
		return 1;
	}
	if (tmp[size-1] == 0) {
		dp[pre][root] = 1;
		return 1;
	}
	if (tmp[size-2] == 0) {
		dp[pre][root] = 1;
		return 1;
	}
	dp[pre][root] = tmp[size-1]+tmp[size-2]+1;
	return dp[pre][root];
}


int main (int argc, char **argv)
{
	FILE *fin = fopen(argv[1], "r");
	FILE *fout = fopen (argv[2], "w");
	if (fin==NULL || fout==NULL) exit(1);

	int num_cases;
	fscanf (fin, "%d", &num_cases);

	REP (i, 0, num_cases) {
		int N;
		fscanf (fin, "%d", &N);
		vector<vector<int> > e (N+1, vector<int>());
		REP (j, 0, N-1) {
			int A, B; fscanf (fin, "%d%d", &A, &B);
			e[A].push_back (B);
			e[B].push_back (A);
		}
		int ans=N-1;

		memset(dp, -1, sizeof (dp));
		REP (j, 1, N+1) {
			// root
			vector<int> mark (N+1, 0);
			int num_nodes = trim (e, 0, j, mark);
			ans = min(ans, N-num_nodes);
		}
		fprintf (fout, "Case #%d: %d\n", i+1, ans);
		printf ("Case #%d: %d\n", i+1, ans);
	}

	fclose(fin);
	fclose(fout);
	return 0;
}






