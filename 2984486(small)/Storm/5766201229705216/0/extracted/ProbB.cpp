#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

int n;
bool tree[1002][1002];
int dp[1002][1002];
int dp_count[1002][1002];

int node_count(int root, int exclude)
{
	if (dp_count[root][exclude] != -1)
		return dp_count[root][exclude];
	int res = 0;
	for (int i=0;i<n;i++) {
		if (i == exclude) continue;
		if (tree[root][i]) {
			res += node_count(i, root);
		}
	}

	dp_count[root][exclude] = res + 1;
	return res + 1;
}

int rec(int root, int exclude)
{
	if (dp[root][exclude] != -1)
		return dp[root][exclude];
	int count = 0;
	int best = -1;
	vector<int> vals;
	vector<int> pos;
	for (int i=0;i<n;i++) {
		if (i == exclude) continue;
		if (tree[root][i]) {
			count++;
			int val = rec(i, root);
			vals.push_back(val);
			pos.push_back(i);
		}
	}

	int res=0;
	if (count == 0) {
		res = 0;
	}
	else if (count == 1) {
		res = node_count(pos[0], root);
	}
	else {
		res = -1;
		for (int i=0;i<pos.size();i++) {
			for (int j=i+1;j<pos.size();j++) {
				int val = vals[i] + vals[j];
				for (int k=0;k<pos.size();k++) {
					if (k == i || k == j)
						continue;
					val += node_count(pos[k], root);
				}

				if (res == -1 || val < res)
					res = val;
			}
		}
	}
	dp[root][exclude] = res;
	return res;
}


int main()
{
	freopen("C:\\Projects\\gcj\\input.txt", "r", stdin);
	freopen("C:\\Projects\\gcj\\output.txt", "w", stdout);

	int z;
	cin >> z;
	for (int q=0;q<z;q++) {
		cin >> n;

		for (int i=0;i<1002;i++) {
			for (int j=0;j<1002;j++) {
				tree[i][j] = false;
				dp[i][j] = -1;
				dp_count[i][j] = -1;
			}
		}

		int a,b;
		for (int i=0;i<n-1;i++) {
			cin >> a >> b;
			a--;b--;
			tree[a][b] = true;
			tree[b][a] = true;
		}

		int best = -1;
		for (int i=0;i<n;i++) {
			int val = rec(i, i);
			//cout << i+1 << " " << node_count(i, i)  << endl;
			if (best == -1 || val < best)
				best = val;
		}

		cout << "Case #" << (q + 1) << ": " << best;
		cout << endl;
	}

	fclose(stdout);
	fclose(stdin);

	return 0;
}