#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define forr(i,a,b) for(int i = (a); i <= (b); ++i)

typedef long long ll;

vector<vector<int> > g;
vector<int> subSize;
vector<int> used;

void init(int n)
{
	g.resize(n);
	subSize.assign(n,0);
	rep(i,n)
		g[i].clear();
}

int dfs(int v)
{
	used[v] = 1;
	subSize[v] = 1;
	vector<int> ss;
	ss.reserve(g[v].size());
	rep(i,g[v].size())
	{
		int w = g[v][i];
		if (!used[w])
		{
			dfs(w);
			ss.push_back(subSize[w]);
			//subSize[v] += subSize[w];
		}
	}

	if (ss.size() >= 2)
	{
		nth_element(ss.begin(), ss.end() - 2, ss.end());
		subSize[v] += ss.back() + ss[ss.size() - 2];
	}

	return subSize[v];
}


int main()
{
#ifdef my_env_def
    freopen ("out.txt","w",stdout);
    freopen("in.txt","r",stdin);
#endif

    int t;
    cin >> t;

	int n,a,b,s;

	rep(tc,t)
	{
		cin >> n;
		init(n);
		rep(i,n-1)
		{
			cin >> a >> b;
			--a; --b;
			g[a].push_back(b);
			g[b].push_back(a);
		}

		int ans = n,ca;
		rep(i,n)
		{
			used.assign(n,0);
			ca = n - dfs(i);
			if (ca < ans)
				ans = ca;
		}

		cout << "Case #" << tc + 1 << ": " << ans << "\n";
	}

#ifdef my_env_def
    fclose(stdout);
#endif
    return 0;
}