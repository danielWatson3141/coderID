#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <queue>

using namespace std;

int N;
vector<int> voisins[1001];
int enfants[1001];
bool visited[1001];

int enfantise(int x)
{
	int total = 1;
	visited[x] = true;
	for(int i = 0; i < voisins[x].size(); i++)
	{
		int y = voisins[x][i];
		if(!visited[y])
		{
			enfants[y] = enfantise(y);
			total += enfants[y];
		}
	}
	return total;
}

int solve(int x)
{
	visited[x] = true;
	vector<pair<int, int> > fils;
	
	for(int i = 0; i < voisins[x].size(); i++)
	{
		int y = voisins[x][i];
		if(!visited[y])
		{
			fils.push_back(make_pair(solve(y), y));
		}
	}
	
	//printf("[Size %d] ", fils.size());
	
	if(fils.size() == 0)
	{
		//printf("En %d : %d\n", x, 0);
		return 0;
	}
	else if(fils.size() == 1)
	{
		//printf("En %d : %d\n", x, enfants[fils[0].second]);
		return enfants[fils[0].second];
	}
	else
	{
		vector<pair<int, int> > fils2;
		for(int i = 0; i < fils.size(); i++)
		{
			fils2.push_back(make_pair(enfants[fils[i].second] - fils[i].first, fils[i].first));
		}
		sort(fils2.begin(), fils2.end());
		int total = 0;
		for(int i = 0; i < fils2.size()-2; i++)
		{
			total += fils2[i].first + fils2[i].second;
		}
		for(int i = fils2.size()-2; i < fils2.size(); i++)
		{
			total += fils2[i].second;
		}
		//printf("XEn %d : %d\n", x, total);
		return total;
	}
}


int main()
{
	int T;
	int x, y;
	int best;
	
	scanf("%d\n", &T);
	
	for(int t = 1; t <= T; t++)
	{
		printf("Case #%d: ", t);
		best = 10000;
		scanf("%d", &N);
		
		for(int i = 1; i <= N; i++) voisins[i].clear();
		
		for(int i = 0; i < N-1; i++)
		{
			scanf("%d %d", &x, &y);
			voisins[x].push_back(y);
			voisins[y].push_back(x);
		}
		
		for(int root = 1; root <= N; root++)
		{
			// printf("Root %d\n", root);
			for(int i = 1; i <= N; i++) visited[i] = false;
			enfants[root] = enfantise(root);
			
			for(int i = 1; i <= N; i++) visited[i] = false;
			int possible = solve(root);
			best = min(best, possible);
		}
		printf("%d\n", best);
	}

	return 0;
}
