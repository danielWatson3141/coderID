

#include<iostream>
#include<iomanip>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#include<functional>
using namespace std;
const int maxn = 2000;
vector<int> v[maxn];
int n;

bool visit[maxn];
int N;

int solve(int u){
	visit[u] = true;
	vector<int> tree;
	tree.clear();
	for (int i = 0; i < v[u].size(); i++){
		int temp = v[u][i];
		if (visit[temp]==false){
			tree.push_back(solve(temp));
		}
	}
	if (tree.size() <= 1) return 1;
	sort(tree.begin(), tree.end(), greater<int>());
	return tree[0] + tree[1] + 1;
}

int main()
{
	errno_t err1;
	errno_t err2;
	FILE *fin, *fout;
	err1 = freopen_s(&fin, "in.txt", "r", stdin);
	err2 = freopen_s(&fout, "out.txt", "w", stdout);
	int t;
	cin >> t;
	for (int z = 0; z < t; ++z)
	{
		cin >> n;
		for (int i = 0; i < n; ++i)
			v[i].clear();
		int x;
		int y;
		
		for (int i = 0; i < n - 1; ++i)
		{
			cin >> x >> y;
			v[x-1].push_back(y-1);
			v[y-1].push_back(x-1);
		}
		int sol = 0;
		for (int r = 0; r < n; ++r)
		{
			memset(visit, 0, sizeof(visit));
			sol = max(sol, solve(r));
		}
		cout << "case #" << z+1 << ": " << n-sol << endl;
	}

}

