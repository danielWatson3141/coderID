/*
* Google Code Jam 2014
* @author: Sohel Hafiz
*/

#include<cstdio>
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<sstream>
#include<cmath>
#include<cctype>
#include<cassert>
#include<cstring>
#include<cstdlib>

using namespace std;
int N, L;
vector<string> v1, v2;
int res;
int findVal(vector<string> &v1, vector<string> &v2) {
	bool press[15] = {false};
	int cnt = 0;
	for (int i = 0; i < L; i++) {
		if (v1[0][i] != v2[0][i]) press[i] = true, cnt++;
	}

	int inf = 1000000000;
	if (cnt >= res) return inf;
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < L; j++) {
			if (v1[i][j] == v2[i][j]) {
				if (press[j]) { return inf; }
			} else {
				if (press[j] == false) { return inf; }
			}
		}
	}
	return cnt;
}

int main() {
	int test, cases = 1;
	cin >> test;
	for (cases = 1; cases <= test; cases++) {
		cin >> N >> L;
		v1.clear(); v2.clear();
		for (int i = 0; i < N; i++) {
			string a; cin >> a; v1.push_back(a);
		}

		for (int i = 0; i < N; i++) {
			string a; cin >> a; v2.push_back(a);
		}

		res = 1000000000;

		sort(v1.begin(), v1.end());

		do {
			int k = findVal(v1, v2);
			res = min(res, k);
		}while(next_permutation(v1.begin(), v1.end()));

		printf("Case #%d: ", cases);
		if (res == 1000000000) {
			cout << "NOT POSSIBLE" << endl;
		} else {
			cout << res << endl;
		}

	}
	return 0;
}
