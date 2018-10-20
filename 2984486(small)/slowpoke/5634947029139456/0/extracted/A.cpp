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

int toBin(string &s){
	int res = 0;
	for (char c : s){
		res *= 2;
		res += c - '0';
	}
	return res;
}

int bitCount(int mask){
	int res = 0;
	while (mask){
		mask &= mask - 1;
		++res;
	}
	return res;
}

bool match(vector<int> &a, vector<int> b, int mask){
	int n = (int)a.size();
	for (int i = 0; i < n; ++i){
		b[i] ^= mask;			
	}

	sort(b.begin(), b.end());

	return a == b;
}

void comp(int tc){
	int N, L;
	cin >> N >> L;
	vector<int> a, b;
	string tmp;
	for (int i = 0; i < N; ++i){
		cin >> tmp;
		a.push_back(toBin(tmp));
	}

	for (int i = 0; i < N; ++i){
		cin >> tmp;
		b.push_back(toBin(tmp));
	}

	sort(a.begin(), a.end());
	int best = L+1;
	for (int i = 0; i < (1 << L); ++i){
		if (match(a, b, i))
			best = min(best, bitCount(i));
	}

	cout << "Case #" << tc << ": ";
	if (best == L + 1)
		cout << "NOT POSSIBLE" << endl;
	else
		cout << best << endl;

}

int main(){
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; ++tc){
		comp(tc);
	}
}