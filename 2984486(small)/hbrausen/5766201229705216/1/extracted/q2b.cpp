#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool inset(unsigned int iset, unsigned int i)
{
	return ((iset & 1 << i) != 0);
}

int treesize(vector<vector<bool> >& adjset, int r, int p, int N)
{
	vector<int> children;
	for (int b = 0; b < N; ++b) {
		if (b == p) continue;
		//if (markset[b]) continue;
		if (adjset[r][b]) children.push_back(b);
	}
	if (children.size() == 0) {
		//markset[r] = true;
		return 1;
	}
	if (children.size() == 1) {
		//markset[r] = true;
		return 1;
	}
	vector<int> sizes;
	for (int i = 0; i < children.size(); ++i) {
		sizes.push_back(treesize(adjset, children[i], r, N));
		//cout << "\tSize from " << children[i]+1 << " is " << sizes[i] << endl;
	}
	sort(sizes.begin(), sizes.end());
	return sizes[sizes.size()-1] + sizes[sizes.size()-2]+1;
}

unsigned int countones(unsigned int n)
{
	int ret = 0;
	while (n != 0) {
		if (n & 0x01) ++ret;
		n = n >> 1;
	}
	return ret;
}

int main()
{
	int TC;
	cin >> TC;
	for (int tc = 0; tc < TC; ++tc) {
		int N;
		cin >> N;
		vector<vector<bool> > adjmat;
		for (int i = 0; i < N; ++i) {
			adjmat.push_back(vector<bool>());
			for (int j = 0; j < N; ++j) {
				adjmat[i].push_back(0);
			}
		}
		for (int i = 0; i < N-1; ++i) {
			int a,b;
			cin >> a;
			cin >> b;
			adjmat[a-1][b-1] = 1;
			adjmat[b-1][a-1] = 1;
		}
		int maxsize = -1;
		for (int i = 0; i < N; ++i) {
			int sz = treesize(adjmat, i, -1, N);
			//cout << "Rooted at " << i+1 << " size is " << sz << endl;
			if (sz > maxsize) maxsize = sz;
		}
		cout << "Case #" << tc+1 << ": " << N-maxsize << endl;
	}
	return 0;
}

