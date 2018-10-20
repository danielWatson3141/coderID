#include <fstream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 1000;
int N;
vector<int> E[MAXN];
int total[MAXN];

int count(int node, int par)
{
	int cnt = 1;
	for (int i = 0; i < E[node].size(); i++)
		if (E[node][i] != par)
			cnt += count(E[node][i], node);
	return total[node] = cnt;
}

int dfs(int node, int par)
{
	if ((par != -1 && (E[node].size() == 1 || E[node].size() == 3)) || (par == -1 && E[node].size() == 2))
	{
		int cnt = 0;
		for (int i = 0; i < E[node].size(); i++)
			if (E[node][i] != par)
				cnt += dfs(E[node][i], node);
		return cnt;
	}
	else
	{
		vector<pair<int, int> > rem;
		for (int i = 0; i < E[node].size(); i++)
			if (E[node][i] != par)
				rem.push_back(make_pair(total[E[node][i]], E[node][i]));

		sort(rem.begin(), rem.end());

		if (rem.size() == 1)
			return rem[0].first;

		int cnt = 0;
		for (int i = 0; i < rem.size() - 2; i++)
			cnt += rem[i].first;
		
		cnt += dfs(rem[rem.size() - 2].second, node);
		cnt += dfs(rem[rem.size() - 1].second, node);
		return cnt;
	}
}

int main()
{
	ifstream in ("2014round1AB.in");
	ofstream out ("2014round1AB.out");

	int T;
	in >> T;

	for (int t = 1; t <= T; t++)
	{
		in >> N;
		
		for (int i = 0; i < N; i++)
			E[i].clear();
		memset(total, 0, sizeof(total));

		for (int i = 0; i < N - 1; i++)
		{
			int a, b;
			in >> a >> b;
			E[a-1].push_back(b-1);
			E[b-1].push_back(a-1);
		}

		int best = 1000000000;
		for (int i = 0; i < N; i++)
		{
			count(i, -1);
			best = min(best, dfs(i, -1));
		}

		out << "Case #" << t << ": " << best << "\n";
	}

	in.close();
	out.close();
	return 0;
}