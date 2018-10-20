#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int search(int depth, int ret, int N, int L, vector<string> &s0, vector<string> &s1, vector<int> &n0, vector<int> &n1) {
	if (depth == -1) {
		unordered_map<string, int> m0, m1;
		for (int k = 0; k < N; ++ k) {
			++ m0[s0[k]];
			++ m1[s1[k]];
		}
		if (m0.size() == m1.size()) {
			for (auto & k : m0)
				if (k.second != m1[k.first]) {
						ret = -1;
						break;
				}
		}
		else
			ret = -1;
		return ret;
	}
	if (depth < L - 1) {
		unordered_map<string, int> m0, m1;
		for (int k = 0; k < N; ++ k) {
			++ m0[s0[k].substr(depth + 1)];
			++ m1[s1[k].substr(depth + 1)];
		}
		if (m0.size() == m1.size()) {
			for (auto & k : m0)
				if (k.second != m1[k.first]) {
					ret = -1;
					return ret;
				}
		}
	}
	int rret = -1;
	if (n0[depth] == n1[depth])
		rret = search(depth - 1, ret, N, L, s0, s1, n0, n1);
	if (rret < 0 && n0[depth] + n1[depth] == N) {
		for (int k = 0; k < N; ++ k)
			s0[k][depth] = '1' - s0[k][depth] + '0';
		rret = search(depth - 1, ret + 1, N, L, s0, s1, n0, n1);
		for (int k = 0; k < N; ++ k)
			s0[k][depth] = '1' - s0[k][depth] + '0';
	}
	return rret;
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; ++ i) {
		int N, L;
		cin >> N >> L;
		vector<string> s0, s1;
		vector<int> n0(L, 0), n1(L, 0);
		for (int j = 0; j < N; ++ j) {
			string temp;
			cin >> temp;
			s0.push_back(temp);
			for (int k = 0; k < L; ++ k)
				n0[k] += temp[k] - '0';
		}
		for (int j = 0; j < N; ++ j) {
			string temp;
			cin >> temp;
			s1.push_back(temp);
			for (int k = 0; k < L; ++ k)
				n1[k] += temp[k] - '0';
		}
		int ret = 0;
		cout << "Case #" << i + 1 << ": ";
		for (int j = L - 1; j >= 0; -- j) {
			if (n0[j] + n1[j] != N && n0[j] != n1[j]) {
				ret = -1;
				break;
			}
		}
		if (ret < 0) {
			cout << "NOT POSSIBLE" << endl;
			continue;
		}
		ret = search (L - 1, 0, N, L, s0, s1, n0, n1);
		if (ret < 0)
			cout << "NOT POSSIBLE" << endl;
		else
			cout << ret << endl;
	}
	return 0;
}