#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

vector < vector < int > > G;
int N, number, local;

vector <bool> U, used;
vector <int> power;


void dfs(int i)
{
	used[i] = true;
	power[i]++;
	for(int j = 0; j < G[i].size(); ++j)
		if(!used[G[i][j]])
		{
			power[i]++;
			dfs(G[i][j]);
		}
}

bool check() {
	power.resize(N);
	for(int i = 0; i < N; ++i)
	{
		used = U;
		power.assign(N, 0);
		if(!used[i])
		{
			dfs(i);
			power[i]--;
			int p2 = 0, p1 = 0, p3 = 0;
			for(int j = 0; j < N; ++j)
			{
				if(power[j] == 1)
					p1++;
				else if(power[j] == 2)
					p2++;
				else if(power[j] == 3)
					p3++;
			}
			if(p2 == 1 && p3 + 2 == p1 && p1 + p2 + p3 + local == N)
				return true;
		}
	}
	return false;

}

void rec(int i)
{
	if(i == N)
	{
		if(check())
			number = min(number, local);
		return;
	}
	rec(i + 1);

	++local;
	U[i] = true;
	rec(i + 1);
	U[i] = false;
	--local;
}

int main() {
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	int T;
	cin >> T;

	for(int t = 1; t <= T; ++t)
	{
		cin >> N;
		G.clear();
		G.resize(N);
		U.clear();
		U.resize(N);
		power.clear();
		power.resize(N);
		int a, b;
		for(int i = 0; i < N-1; ++i)
		{
			cin >> a >> b;
			G[a-1].push_back(b-1);
			G[b-1].push_back(a-1);
		}

		number = N-1, local = 0;

		rec(0);
		cout << "Case #" << t << ": " << number << endl;
	}

	return 0;
}
