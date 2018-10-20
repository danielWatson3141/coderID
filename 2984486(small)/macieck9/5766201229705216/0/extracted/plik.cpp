#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

vector<int> v[1005];
int vst[1005];
int size[1005];
int children[1005];

int dfs1(int s, int r)
{
	vst[s] = true;
	int w = 0;
	for (int i = 0; i < v[s].size(); i++)
	{
		int u = v[s][i];
		if (vst[u]) continue;
		w += dfs1(u,r);
	}
	if (s == r) children[s] = v[s].size();
	else children[s] = v[s].size()-1;
	return (size[s] = w+(s == r ? v[s].size() : v[s].size()-1));
}
int res = 0;
void dfs2(int s)
{
	vst[s] = true;
	if (children[s] == 1) {res += size[s]; return;}
	for(int i = 0; i < v[s].size(); i++)
	{
		int u = v[s][i];
		if (vst[u]) continue;
		dfs2(u);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++)
	{
		int n;
		cin >> n;
		for (int i = 0; i < n-1; i++)
		{
			int a,b;
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		int ans = 1000000;
		for(int i = 1; i <= n; i++)
		{
			dfs1(i,i);
			memset(vst,0,sizeof(vst));
			res = 0;
			dfs2(i);
			//cout << i << " " << res << "\n";
			ans = min(ans,res);
			
			/*
			for(int j = 1; j <= n; j++) cout << children[j] << " ";
			cout << "\n";
			for(int j = 1; j <= n; j++) cout << size[j] << " ";
			cout << "\n\n";
			*/
            memset(vst,0,4*n+4);
			memset(children,0,4*n+4);
			memset(size,0,4*n+4);
		}
		cout << "Case #" << t << ": " << ans << "\n";
		memset(v,0,sizeof(v));
	}
	
	
	return 0;
}
