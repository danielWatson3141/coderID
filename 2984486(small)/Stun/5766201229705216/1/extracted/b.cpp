#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <map>
#include <stack>
#include <cassert>

using namespace std;

vector< vector<int> > E;

std::pair<int, int> solve(int i, int p = -1) {
	std::vector<pair<int, int> > S(0);
	for (int j = 0 ; j < E[i].size() ; j++) {
		if (E[i][j] != p) S.push_back(solve(E[i][j], i));
	}
	if (S.empty()) return make_pair(0, 1);
	if (S.size() == 1) return make_pair(S[0].second, 1+S[0].second);
	int ret = 0, tot = 0;
	for(size_t i = 0; i < S.size(); ++i) {
		tot += S[i].second;
	}
	ret = tot;
	for (int i = 0 ; i < S.size() ; i++) {
		for (int j = i+1 ; j < S.size() ; j++) {
			ret = min(ret, tot - (S[i].second - S[i].first) - (S[j].second - S[j].first));
		}
	}
	return make_pair(ret, tot+1);
}

int main(){
	int tcase;
	cin >> tcase;
	
	for(size_t casen = 0; casen < tcase; ++casen)
	{
		int N;
		cin >> N;
		E.clear();
		E.resize(N);
		for(size_t i = 0; i < N; ++i) {
			E[i].clear();
		}
		for(size_t i = 0; i < N - 1; ++i) {
			int a, b;
			cin >> a >> b;
			E[a-1].push_back(b-1);
			E[b-1].push_back(a-1);
		}
		int ret = N+1;
		for(size_t i = 0; i < N; ++i) {
			ret = min(ret, solve(i).first);
		}
		cout << "Case #" << casen + 1 << ": ";
		cout << ret << endl;
		
	}
	

	return 0;
}
