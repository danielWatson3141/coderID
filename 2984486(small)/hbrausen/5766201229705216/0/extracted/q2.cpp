#include <iostream>
#include <vector>

using namespace std;

bool inset(unsigned int iset, unsigned int i)
{
	return ((iset & 1 << i) != 0);
}

bool isbinary(vector<vector<bool> >& adjset, int r, vector<bool>& markset, unsigned int removeset, int N)
{
	markset[r] = true;
	vector<int> children;
	for (int b = 0; b < N; ++b) {
		if (inset(removeset, b)) continue;
		if (markset[b]) continue;
		if (adjset[r][b]) children.push_back(b);
	}
	if (children.size() == 0) return true;
	if (children.size() != 2) return false;
	return isbinary(adjset, children[0], markset, removeset, N) && isbinary(adjset, children[1], markset, removeset, N);
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
		int minones = 1024;
		for (unsigned int removeset = 0; removeset < 1<<N; ++removeset) {
			bool hasroot = false;
			int r;
			for (r = 0; r < N; ++r) {
				if (inset(removeset, r)) continue;
				int childcount = 0;
				for (int c = 0; c < N; ++c) {
					if (inset(removeset, c)) continue;
					if (adjmat[r][c]) childcount += 1;
				}
				if (childcount == 2 || childcount == 0) {
					hasroot = true;
					break;
				}
			}
			if (!hasroot) continue;
			vector<bool> marks;
			for (int i = 0; i < N; ++i) {
				marks.push_back(inset(removeset, i));
			}
			if (isbinary(adjmat, r, marks, removeset, N)) {
				bool isgood = true;
				for (int i = 0; i < marks.size(); ++i) {
					if (marks[i] == false) {
						isgood = false;
						break;
					}
				}
				if (!isgood) continue;
				if (countones(removeset) < minones) {
					minones = countones(removeset);
				}
			}
		}
		cout << "Case #" << tc+1 << ": " << minones << endl;
	}
	return 0;
}

