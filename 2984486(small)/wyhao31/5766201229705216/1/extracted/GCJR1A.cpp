#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

ifstream in("B-large.in.txt");
ofstream out("B-large.out");
//#define in cin
//#define out cout

typedef long long ll;

// B

vector<int> tree[1024];
bool vis[1024];
int nodes[1024], mindel[1024];

void getSubtreeNum(int root) {
	int len = tree[root].size();
	vis[root] = true;
	nodes[root] = 0;
	for (int i = 0; i < len; i++) {
		int t = tree[root][i];
		if (!vis[t]) {
			getSubtreeNum(t);
			nodes[root] += (nodes[t]+1);
		}
	}
}

void getMinDel(int root) {
	int childsNum = 0;
	vector<int> childs;
	int len = tree[root].size();
	vis[root] = true;
	for (int i = 0; i < len; i++) {
		int t = tree[root][i];
		if (!vis[t]) {
			childsNum++;
			childs.push_back(t);
		}
	}
	mindel[root] = 0;
	if (childsNum == 0) mindel[root] = 0;
	else if (childsNum == 1) {
		int t = childs[0];
 		mindel[root] = nodes[t]+1;
	} else if (childsNum == 2) {
		for (int i = 0; i < 2; i++) {
			int t = childs[i];
			getMinDel(t);
			mindel[root] += mindel[t];
		}
	} else {
		int total = 0;
		for (int i = 0; i < childsNum; i++) {
			int t = childs[i];
			total += (nodes[t]+1);
			getMinDel(t);
		}
		int res = total;
		for (int i = 0; i < childsNum; i++) {
			for (int j = i+1; j < childsNum; j++) {
				int t1 = childs[i], t2 = childs[j];
				if (total-nodes[t1]-nodes[t2]-2+mindel[t1]+mindel[t2] < res)
					res = total-nodes[t1]-nodes[t2]-2+mindel[t1]+mindel[t2];
			}
		}
		mindel[root] = res;
	}
}

int main()
{
	int T, N;
	in >> T;
	for (int cnt = 1; cnt <= T; cnt++) {
		in >> N;
		int x, y;
		for (int i = 1; i <= N; i++) tree[i].clear();

		for (int i = 1; i <= N-1; i++) {
			in >> x >> y;
			tree[x].push_back(y);
			tree[y].push_back(x);
		}
		int res = N;
		for (int i = 1; i <= N; i++) {
			//memset(nodes, 0, sizeof(nodes));
			memset(vis, 0, sizeof(vis));
			getSubtreeNum(i);
			
			//for (int j = 1; j <= N; j++)
			//	cout << nodes[j] << " ";
			//cout << endl;

			memset(vis, 0, sizeof(vis));
			getMinDel(i);

			//for (int j = 1; j <= N; j++)
			//	cout << mindel[j] << " ";
			//cout << endl;

			if (mindel[i] < res) res = mindel[i];
		}
		out << "Case #" << cnt << ": " << res << endl;
	}
	return 0;
}

/*
// A
string flow[155];
ll f[155][155];
string device[155];
ll one = 1;

int main()
{
	int T, N, L;
	in >> T;
	for (int cnt = 1; cnt <= T; cnt++) {
		in >> N >> L;
		for (int i = 0; i < N; i++) in >> flow[i];
		for (int i = 0; i < N; i++) in >> device[i];
		int res = 0;
		bool flag = false;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				ll t = 0;
				for (int k = 0; k < L; k++) {
					if (flow[i][k] != device[j][k])
						t = t | (one<<(L-k-1));
				}
				f[i][j] = t;
			}
		}
		for (int i = 0; i < N; i++) {
			int j, k;
			for (j = 1; j < N; j++) {
				for (k = 0; k < N; k++) {
					if (f[0][i] == f[j][k]) {
						break;
					}
				}
				if (k == N) break;
			}
			if (j == N) {
				if (!flag) {
					flag = true;
					int t = 0;
					for (k = 0; k < L; k++) {
						if (f[0][i] & (one<<k)) t++;
					}
					res = t;
				} else {
					int t = 0;
					for (k = 0; k < L; k++) {
						if (f[0][i] & (one<<k)) t++;
					}
					if (t < res) res = t;		
				}
			}
		}
		if (flag) out << "Case #" << cnt << ": " << res << endl;
		else out << "Case #" << cnt << ": " << "NOT POSSIBLE" << endl;
	}
	return 0;
}
*/