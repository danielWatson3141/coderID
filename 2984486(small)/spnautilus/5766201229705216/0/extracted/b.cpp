#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define MAXN (1024)

typedef long long ll;
typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <PII> VP;

int T;
int N;

int V[MAXN];
int rit;
VI edge[MAXN];

bool cmpf(PII a, PII b)
{
	return a.first - a.second > b.first - b.second;
}

PII dfs(int id)
{
	V[id] = rit;

	int i, sz;
	sz = edge[id].size();

	int all = 1;
	int cut = 0;

	VP v;

	for(i = 0; i < sz; ++i)
	{
		int a = edge[id][i];
		if(V[a] != rit)
			v.push_back(dfs(a));
	}

	sz = v.size();
	for(i = 0; i < sz; ++i)
		all += v[i].first;

	if(sz == 1)
		cut = all - 1;
	else if(sz >= 2)
	{
		sort(v.begin(), v.end(), cmpf);

		cut += v[0].second + v[1].second;
		for(i = 2; i < sz; ++i)
			cut += v[i].first;
	}

	return PII(all, cut);
}

int main()
{
	scanf("%d", &T);
	for(int TT = 1; TT <= T; ++TT)
	{
		int i;
		scanf("%d", &N);

		for(i = 1; i < N; ++i)
		{
			int a, b;
			scanf("%d %d", &a, &b);

			edge[a].push_back(b);
			edge[b].push_back(a);
		}

		int sol = N - 1;

		for(i = 1; i <= N; ++i)
		{
			++rit;
			sol = min <int> (sol, dfs(i).second);
		}

		printf("Case #%d: %d\n", TT, sol);

		for(i = 1; i <= N; ++i)
			edge[i].clear();
	}

	return 0;
}
