#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

class fullbinarytree
{
	private:
		int n;

		vector<vector<int> > tree;

		vector<vector<int> > memo;

		int solroot(int p, int par) {
			if (memo.at(p).at(par) < 0) {
				vector<int> chws;
				chws.reserve(tree.at(p).size());
				for (vector<int>::iterator c = tree.at(p).begin(); c < tree.at(p).end(); ++c) {
					if (*c == par) {
						continue;
					}
					chws.push_back(solroot(*c, p));
				}
				sort(chws.begin(), chws.end(), greater<int>());
				if (chws.size() < 2) {
					memo.at(p).at(par) = 1;
				} else {
					memo.at(p).at(par) = 1 + chws.at(0) + chws.at(1);
				}
			}
			return memo.at(p).at(par);
		}

	public:
		fullbinarytree() {}

		void input() {
			cin >> n;
			tree.resize(n);
			int b, e;
			for (int f = 0; f < n - 1; ++f) {
				cin >> b >> e;
				--b; --e;
				tree.at(b).push_back(e);
				tree.at(e).push_back(b);
			}
		}

		string solve() {
			ostringstream oss;
			memo.resize(n, vector<int>(n, -1));
			int sol = 1;
			for (int f = 0; f < n; ++f) {
				sol = max(sol, solroot(f, f));
			}
			oss << (n - sol);
			return oss.str();
		}
};

int main(void) {
	int nt;
	cin >> nt;
	for (int znj = 0; znj < nt; ++znj) {
		fullbinarytree task;
		task.input();
		cout << "Case #" << (znj + 1) << ": " << task.solve() << endl;
	}
	return 0;
}
