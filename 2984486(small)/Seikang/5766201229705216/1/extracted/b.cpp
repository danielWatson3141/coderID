//Seikang

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <stdlib.h>
#include <assert.h>

#include <vector>
#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>

#include <cmath>
#include <complex>
#include <algorithm>

#include <ctime>
#define gtime clock()

using namespace std;

#define SZ(cont) (int)(cont.size())
#define ALL(cont) (cont).begin(), (cont).end()
#define DEBUG(x) cerr << ">" << #x << ":" << x << endl

typedef long long int64;
typedef pair<int64, int64> ii;
typedef vector<int64> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<string> vs;

const int64 oo32 = 1ll << 30, oo64 = 1ll << 60;
const double pi = acos(-1.0), eps = 1e-9;
inline bool equal(const double &a, const double &b){return abs(a - b) < eps;}

int64 counter(vvi &graph, int root, int parent)
{
	vector<bool> mark = std::vector<bool>(graph.size(), false);
	mark[root] = true;
	mark[parent] = true;

	queue<int> q;
	q.push(root);
	int64 ans = 0;
	while(!q.empty())
	{
		ans++;
		int n = q.front();q.pop();
		for(int e = 0; e < graph[n].size(); e++)
		{
			//cout << n << "reach" << e << endl;
			int new_n = graph[n][e];
			if(!mark[new_n])
			{
				mark[new_n] = true;
				//cout << "reach" << endl;
				q.push(new_n);
			}
		}
	}
	return ans;
}

int64 bfs(vvi &graph, int root)
{
	vector<bool> mark = std::vector<bool>(graph.size(), false);
	mark[root] = true;

	queue<int> q;
	q.push(root);
	int64 ans = 0;
	while(!q.empty())
	{
		int n = q.front();q.pop();
		if(n == root)
		{
			if(graph[n].size() == 1)
			{
				for(int e = 0; e < graph[n].size(); e++)
				{
						//cout << n << "reach" << e << endl;
					int new_n = graph[n][e];
					if(!mark[new_n])
					{
						mark[new_n] = true;
						//cout << "reach" << endl;
						ans += counter(graph, new_n, n);
					}
				}	
			}
			else if(graph[n].size() > 2)
			{
				std::vector<ii> nodes;
				for(int e = 0; e < graph[n].size(); e++)
				{
						//cout << n << "reach" << e << endl;
					int new_n = graph[n][e];
					if(!mark[new_n])
					{
						//cout << "reach" << endl;
						nodes.push_back(ii(counter(graph, new_n, n), new_n));
					}
				}
				sort(ALL(nodes));
				reverse(ALL(nodes));
				
				mark[nodes[0].second] = true;
				mark[nodes[1].second] = true;

				q.push(nodes[0].second);
				q.push(nodes[1].second);

				for (int p = 2; p < nodes.size(); ++p)
				{
					ans += nodes[p].first;
				}
			}
			else
			{
				for(int e = 0; e < graph[n].size(); e++)
				{
						//cout << n << "reach" << e << endl;
					int new_n = graph[n][e];
					if(!mark[new_n])
					{
						mark[new_n] = true;
						//cout << "reach" << endl;
						q.push(new_n);
					}
				}	
			}	
			continue;
		}
		if(graph[n].size() == 2)
		{
			for(int e = 0; e < graph[n].size(); e++)
			{
					//cout << n << "reach" << e << endl;
				int new_n = graph[n][e];
				if(!mark[new_n])
				{
					mark[new_n] = true;
					//cout << "reach" << endl;
					ans += counter(graph, new_n, n);
				}
			}	
		}
		else if(graph[n].size() > 3)
		{
			std::vector<ii> nodes;
			for(int e = 0; e < graph[n].size(); e++)
			{
					//cout << n << "reach" << e << endl;
				int new_n = graph[n][e];
				if(!mark[new_n])
				{
					//cout << "reach" << endl;
					nodes.push_back(ii(counter(graph, new_n, n), new_n));
				}
			}
			sort(ALL(nodes));
			reverse(ALL(nodes));
			
			mark[nodes[0].second] = true;
			mark[nodes[1].second] = true;

			q.push(nodes[0].second);
			q.push(nodes[1].second);

			for (int p = 2; p < nodes.size(); ++p)
			{
				ans += nodes[p].first;
			}
		}
		else
		{
			for(int e = 0; e < graph[n].size(); e++)
			{
					//cout << n << "reach" << e << endl;
				int new_n = graph[n][e];
				if(!mark[new_n])
				{
					mark[new_n] = true;
					//cout << "reach" << endl;
					q.push(new_n);
				}
			}	
		}
	}

	return ans;
}

int main()
{
	//freopen ("b.in", "rt", stdin);
	//freopen ("b2.out", "wt", stdout);
	int C;
	cin >> C;
	for (int i = 0; i < C; ++i)
	{
		cout << "Case #" << (i + 1) << ": ";
		int N;
		cin >> N;

		vvi graph = vvi(N);
		for (int e = 0; e < N - 1; ++e)
		{
			int a, b;
			cin >> a >> b;
			graph[a - 1].push_back(b - 1);
			graph[b - 1].push_back(a - 1);
		}

		for (int k = 0; k < graph[0].size(); ++k)
		{
			//cout << graph[0][k] << ' ';
		}
		//cout << endl;

		int64 ans = oo32;
		for (int n = 0; n < N; ++n)
		{
			int64 tmp = bfs(graph, n);
			//cout << tmp << ' ' << n << endl;
			ans = min(ans, tmp);
		}
		cout << ans << endl;
	}
	return 0;
}
