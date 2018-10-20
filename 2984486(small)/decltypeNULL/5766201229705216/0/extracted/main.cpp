#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <iomanip>
#include <cassert>

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int N;
const int MAXN = 1009;
vector<int> e[MAXN];

int solve_root(int root, int prev)
{
	//cout << root << ' ' << prev << endl;
	vector<int> child_ans;
	//for (const auto& x : e[root])
	for (int i = 0; i < e[root].size(); i++)
	{
		int x = e[root][i];
		if (x != prev)
		{
			child_ans.push_back(solve_root(x, root));
		}
	}

	int len = child_ans.size();
	if (len <= 1) return 1;

	sort(child_ans.begin(), child_ans.end());
	return 1 + child_ans[len - 2] + child_ans[len-1];
}

int solve(void)
{
	int result = 0;
	for (int i = 1; i <= N; i++)
	{
		result = max(result, solve_root(i, -1));
	}

	return N - result;
}

void solve_B(void)
{
	ifstream in("input.txt");
	ofstream out("output.txt");

	int T;
	in >> T;

	for (int tt = 1; tt <= T; tt++)
	{
		in >> N;
		for (int i = 1; i <= N; i++) e[i].clear();

		
		int a, b;
		
		for (int i = 0; i < N - 1; i++)
		{
			in >> a >> b;
			e[a].push_back(b);
			e[b].push_back(a);
		}

		int res = solve();
		out << "Case #" << tt << ": " << res << '\n';
	}

	in.close();
	out.close();
}

int main()
{
	//solve_A();
	solve_B();
	//solve_C();
	return 0;
}