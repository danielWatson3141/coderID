/*
 * $File: a.cc
 * $Date: Sat Apr 26 09:24:35 2014 +0800
 * $Author: Xinyu Zhou <zxytim[at]gmail[dot]com>
 */

#include <cassert>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <map>
#include <tuple>

using namespace std;

bool same(const vector<int> &a, const vector<int> &b) {
	if (a.size() != b.size())
		return false;
	for (size_t i = 0; i < a.size(); i ++)
		if (a[i] != b[i])
			return false;
	return true;
}
bool vector_cmp(const vector<int> &a, const vector<int> &b){
	if (a.size() != b.size())
		return a.size() < b.size();
	for (size_t i = 0; i < a.size(); i ++)
		if (a[i] != b[i])
			return a[i] < b[i];
	return false;
}

bool data_cmp(const pair<vector<int>, pair<int, int>> &a, const pair<vector<int>, pair<int, int>> &b){
	return vector_cmp(a.first, b.first);
}

void print_vec(const vector<int> &a) {
	for (auto &v: a)
		fprintf(stderr, "%d ", v);
	fprintf(stderr, "\n");
}

void solve() {
	vector<string> A, B;

	int N, L;
	cin >> N >> L;
	vector<vector<vector<int>>> g(N, vector<vector<int>>(N));

	A.resize(N);
	B.resize(N);
	for (int i = 0; i < N; i ++)
		cin >> A[i];
	for (int i = 0; i < N; i ++)
		cin >> B[i];

	vector<pair<vector<int>, pair<int, int>>> data;

	for (int i = 0; i < N; i ++)
		for (int j = 0; j < N; j ++) {
			vector<int> t;
			for (int l = 0; l < L; l ++)
				if (A[i][l] != B[j][l])
					t.push_back(l);
			data.push_back(make_pair(t, make_pair(i, j)));
		}

	sort(data.begin(), data.end(), data_cmp);
//    print_vec(data[0].first);

	for (size_t i = 0; i < data.size(); ) {
		size_t j = i;
		while (same(data[j].first, data[i].first))
			j ++;
		assert(j <= i + N);
		if (j == i + N) {
			printf("%lu\n", data[i].first.size());
			return;
		}
		i = j;
	}
	printf("NOT POSSIBLE\n");
}

int main() {
	int T;
	cin >> T;
	for (int i = 1; i <= T; i ++) {
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}

/*
 * vim: syntax=cpp11.doxygen foldmethod=marker
 */

