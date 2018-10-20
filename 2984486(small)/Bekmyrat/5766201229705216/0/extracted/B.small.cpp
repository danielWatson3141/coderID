#include <iostream>
#include <fstream>
#include <vector>

#define INF 1000000

using namespace std;

ofstream fout("file.out");

int t,n,a,b,ans,mn = INF;

bool vis[19],o;

vector < vector <int> > v(19);

vector <int> P;

void bfs(int x)
{
	vis[x] = 1;
	int j = 0;
	for (int i = 0; i < v[x].size(); i++)
		if (vis[v[x][i]] == 0) j++,P.push_back(v[x][i]);
	
	if (j > 2) ans += j-2;
	if (j == 1 && o == 1) ans++;
	
	o = 1;
	for (int i = 0; i < P.size(); i++)
		if (vis[P[i]] == 0)	bfs(P[i]);
}

int main()
{
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		for (int h = 0; h < n-1; h++)
		{
			cin >> a >> b;
			v[a].push_back(b),v[b].push_back(a);
		}
		
		for (int h = 1; h <= n; h++)
		{
			if (v[h].size() >= 2)
				bfs(h),mn = min(mn,ans);
			o = 0,ans = 0,fill(vis,vis+19,0),P.clear();
		}
		
		if (mn == INF) mn = n/2;
		
		fout << "Case #" << i+1 << ": " << mn << "\n";
		
		mn = INF;
		ans = 0,o = 0,fill(vis,vis+18,0),P.clear();
		for (int h = 1; h <= n; h++)
			v[h].clear();
	}
}
