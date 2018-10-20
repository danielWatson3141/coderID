#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <functional>
#include <iostream>
#include <sstream>
#include <cctype>
#include <cmath>
//#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
//using namespace boost::multiprecision;

vector<vector<int>> g;
vector<bool> f;
int N, root;

int bitCount(int mask){
	int res = 0;
	while (mask){
		mask &= mask - 1;
		++res;
	}
	return res;
}

bool dfs(int prev, int cur, int mask){
	if (mask & (1 << cur))
		return false;

	f[cur] = true;

	int count = 0;
	for (int j : g[cur]){
		if (j != prev){
			if (mask & (1 << j)){
			}
			else{
				++count;
				if (!dfs(cur, j, mask))
					return false;
			}
		}
	}

	return count == 0 || count == 2;
}

bool calc(int mask){
	for (int i = 0; i < N; ++i){
		f.assign(N, false);
		if (dfs(-1, i, mask)){
			bool ok = true;
			for (int i = 0; i < N; ++i){
				if (!f[i] && !((1<<i) & mask)){
					ok = false;
					break;
				}
			}
			if (ok)
				return true;
		}
	}
	return false;
}

void comp(int tc){
	N;
	cin >> N;

	g.assign(N, vector<int>());

	for (int i = 0; i < N - 1; ++i){
		int a, b;
		cin >> a >> b;
		g[a - 1].push_back(b - 1);
		g[b - 1].push_back(a - 1);
	}

	int best = N;
	for (int i = 0; i < (1<<N); ++i){
		if (calc(i))
			best = min(best, bitCount(i));
	}

	cout << "Case #" << tc << ": " << best << endl;

}

int main(){
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; ++tc){
		comp(tc);
	}
}