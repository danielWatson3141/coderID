#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cassert>
#include <algorithm>
#include <utility>

using namespace std;

#define loop(i, x) for (int i = 0; i < (x); i++)
#define rep(x) loop(COUNTER, x)
#define INF ((int) 1e9)
#define rint(x) scanf("%d", &(x))
#define MAXN 1000
#define mp make_pair

typedef long long ll;

struct node
{
	vector<node*> edges;
	vector<node*> children;
	int cost;
	int size;
	
	void reset()
	{
		children.clear();
		cost = size = -1;
	}
	
	void fullreset()
	{
		reset();
		edges.clear();
	}
	
	void resolve_root(node* prev)
	{
		for (auto& n : edges)
		{
			if (n != prev)
			{
				n->resolve_root(this);
				children.push_back(n);
			}
		}
	}
	
	int* getdp(int a, int b)
	{
		int* ans = new int[3];
		if (a == b)
		{
			ans[0] = children[a]->size;
			ans[1] = children[a]->cost;
			ans[2] = INF;
		}
		else
		{
			int mid = (a+b) / 2;
			int* d1 = getdp(a, mid);
			int* d2 = getdp(mid+1, b);
			
			ans[0] = d1[0] + d2[0];
			ans[1] = min(d1[1] + d2[0], d1[0] + d2[1]);
			
			ans[2] = INF;
			ans[2] = min(ans[2], d1[0] + d2[2]);
			ans[2] = min(ans[2], d1[1] + d2[1]);
			ans[2] = min(ans[2], d1[2] + d2[0]);
			
			delete[] d1;
			delete[] d2;
		}
		return ans;
	}
	
	int solve()
	{
		size = 1;
		for (auto& n : children)
		{
			n->solve();
			size += n->size;
		}
		
		int& ans = cost;
		ans = 0;
		
		if (children.size() < 2)
		{
			for (auto& n : children)
				ans += n->size;
		}
		else
		{
			int* best = getdp(0, children.size() - 1);
			ans = best[2];
			delete[] best;
		}
		
		return ans;
	}
} nodes[MAXN];

int main()
{
	int T;
	rint(T);
	
	loop(testcase, T)
	{
		int N;
		
		rint(N);
		
		loop(i, N)
			nodes[i].fullreset();
		
		loop(i, N-1)
		{
			int a, b;
			rint(a), rint(b);
			a--, b--;
			nodes[a].edges.push_back(nodes + b);
			nodes[b].edges.push_back(nodes + a);
		}
		
		int best = INF;
		
		loop(i, N)
		{
			loop(j, N)
				nodes[j].reset();
			nodes[i].resolve_root(NULL);
			best = min(best, nodes[i].solve());
		}
		
		printf("Case #%d: %d\n", testcase+1, best);
		
		fprintf(stderr, "Finished #%d\n", testcase+1);
	}
}