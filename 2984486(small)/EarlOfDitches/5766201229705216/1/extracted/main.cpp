//==================================
//==========   WARNING   ===========
//==================================
//===   Contains too many bugs   ===
//==================================
#include <deque>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <set>
#include <functional>
#include <queue>
#include <iomanip>

using namespace std;

#define NAME "B-large"

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pr;
typedef pair<ll,ll> prl;

#define double long double

const ll mod7 = 1000000007;

bool used[10000];
vector<int> gr[10000];

int dp[2001][3];
int data[2001][2001];
int sz[2001][2001];


pair<int,int> dfs(int v)
{
	pair<int,int> res;
	res.second = 1;
	used[v] = true;
	
	int cnt = 0;
	for(int i=0;i<gr[v].size();++i)
	{
		int to = gr[v][i];
		if(!used[to])
		{
			pair<int,int> tak = dfs(to);
			data[v][cnt] = tak.first;
			sz[v][cnt] = tak.second;
			++cnt;
			res.second += tak.second;
		}
	}

	dp[0][0] = 0;
	dp[0][1] = dp[0][2] = 1000000;
	for(int i=1;i<=cnt;++i)
	{
		
		dp[i][0] = dp[i][1] = dp[i][2] = 1000000;
		
		dp[i][0] = min(dp[i][0],dp[i-1][0] + sz[v][i-1]);

		dp[i][1] = min(dp[i][1],
				min(dp[i-1][1] + sz[v][i-1],dp[i-1][0]+data[v][i-1]));
		
		dp[i][2] = min(dp[i][2],
				min(dp[i-1][2] + sz[v][i-1],dp[i-1][1]+data[v][i-1]));
	}

	res.first = min(dp[cnt][0],dp[cnt][2]);
	return res;
}


int main()
{
    freopen(NAME".in","r",stdin); freopen(NAME".out","w",stdout);

	int T;
	cin >> T;
	for(int Case=1;Case<=T;Case++)
	{
		cout << "Case #" << Case << ": ";
		int a,b,n,ans=10000000;
		cin >> n;
		for(int i=1;i<=n;++i)
			gr[i].clear();

		for(int i=0;i<n-1;++i)
		{
			cin >> a >> b;
			gr[a].push_back(b);
			gr[b].push_back(a);
		}

		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=n;++j)
				used[j] = false;
			
			pair<int,int> Gets = dfs(i);
			ans = min(ans,Gets.first);
		}

		cout << ans;
		cout << endl;
	}


    return 0;
}