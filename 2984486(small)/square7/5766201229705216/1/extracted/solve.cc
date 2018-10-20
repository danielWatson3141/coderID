#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(const vector<vector<int> >& g, int root, int p)
{
  vector<int> n;
  for(int i = 0; i < g[root].size(); ++i)
    {
      if(g[root][i]==p)
	{continue;}
      else
	{
	  n.push_back(solve(g, g[root][i], root));
	}
    }
  if(n.size()==0) //leaf
    {return 1;}
  if(n.size()==1)
    {return 1;}
  sort(n.begin(), n.end());
  return n[n.size()-2]+n[n.size()-1]+1;
}

int main()
{
  int tot;
  cin >> tot;
  for(int i = 0; i < tot; ++i)
    {
      int N;
      cin >> N;
      vector<vector<int> > graph(N, vector<int>());
      for(int j = 0; j < N-1; ++j)
	{
	  int a,b;
	  cin >> a >> b;
	  --a;
	  --b;
	  graph[a].push_back(b);
	  graph[b].push_back(a);
	}
      int ans=N+5000;
      for(int j = 0; j < graph.size(); ++j)
	{
	  int trail=N-solve(graph, j, -1);
	  if(ans>trail)
	    {ans=trail;}
	}
      cout << "Case #" << i+1 << ": " << ans << endl;;
    }
}
