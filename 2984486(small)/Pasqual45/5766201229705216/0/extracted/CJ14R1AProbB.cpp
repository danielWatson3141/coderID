#include<fstream>
#include<iostream>
#include<sstream>
#include<iomanip>
#include<string>
#include<vector>
#include<list>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#include<functional>
#include<numeric>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define mp make_pair

namespace
{
	const static int MAX = 1001;

	int N;
	vector<int> vv[MAX];
	
	bool seen[MAX];
	int tot[MAX], cost[MAX];
	vector<int> allCosts[MAX];

	void dig(int root)
	{
		seen[root] = true;
		tot[root] = 1;
		const vector<int>& v = vv[root];

		vector<int>& w = allCosts[root];
		for (int i = 0; i < v.size(); ++i)
		{
			int x = v[i];
			if (seen[x]) continue;

			dig(x);
			tot[root] += tot[x];
			w.push_back(tot[x] - cost[x]);
		}

		sort(w.begin(), w.end(), greater<int>());
		cost[root] = tot[root] - 1;

		if (w.size() > 1)
			cost[root] -= (w[0] + w[1]);
	}

	int calc(int root)
	{
		memset(seen, 0, sizeof(seen));
		memset(tot, 0, sizeof(tot));
		memset(cost, 0, sizeof(cost));
		fill(allCosts, allCosts + MAX, vector<int>());
		dig(root);
		return cost[root];
	}
}

//int main14R1A_B()
int main()
{
	ifstream fin("B-small-attempt0.in");
	ofstream fout("B-small-attempt0.out");
	//ifstream fin("test.in");
	//ofstream fout("test.out");

	unsigned int numberOfCases;
	fin >> numberOfCases;

	for (unsigned int zz = 1; zz <= numberOfCases; ++zz)
	{
		fill(vv, vv + MAX, vector<int>());

		fin >> N;
		for (int i = 1; i < N; ++i)
		{
			int X, Y;
			fin >> X >> Y;
			--X;
			--Y;
			vv[X].push_back(Y);
			vv[Y].push_back(X);
		}

		int result = 9999;
		for (int i = 0; i < N; ++i)
		{
			int next = calc(i);
			result = min(result, next);
		}

		fout << "Case #" << zz << ": " << result << endl;
	}

	return 0;
}
