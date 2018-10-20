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

#ifndef INF
#define INF (100000)
#endif

std::vector<string> A, B;
bool test(std::vector<long long> AT, std::vector<long long> BT){
	sort(AT.begin(), AT.end());
	sort(BT.begin(), BT.end());
	bool ret = true;
	for(size_t i = 0; i < AT.size(); ++i)
	{
		if (AT[i] != BT[i]) ret = false;
	}
	return ret;
}
int solve(std::vector<long long> AT, std::vector<long long> BT, int x) {
	if (x == A[0].size()) return 0;
	for (size_t i = 0 ; i < A.size() ; ++i) {
		assert(A[i][x] - '0' < 2);
		AT[i] <<= 1;
		AT[i] |= (A[i][x]-'0');
		BT[i] <<= 1;
		BT[i] |= (B[i][x]-'0');
		// cout << AT[i] << " " << AT2[i] << std::endl;
	}
	int ret = INF;
	if (test(AT, BT))
		ret = min(ret, solve(AT, BT, x+1));
	for (size_t i = 0 ; i < AT.size() ; ++i) AT[i] ^= 0x01;
	if (test(AT, BT))
		ret = min(ret, solve(AT, BT, x+1) + 1);
	return ret;
}

int main(){
	int tcase;
	std::vector<long long> AT, BT;
	
	cin >> tcase;
	
	for(size_t casen = 0; casen < tcase; ++casen)
	{
		int N, L;
		cin >> N >> L;
		A.resize(N), B.resize(N);
		AT.resize(N), BT.resize(N);
		for(size_t i = 0; i < N; ++i) {
			cin >> A[i];
			AT[i] = 0;
		}
		for(size_t i = 0; i < N; ++i) {
			cin >> B[i];
			BT[i] = 0;
		}
		cout << "Case #" << casen + 1 << ": ";
		int sol = solve(AT, BT, 0);
		if (sol < INF) cout << sol << endl;
		else cout << "NOT POSSIBLE" << endl;
	}
	

	return 0;
}
