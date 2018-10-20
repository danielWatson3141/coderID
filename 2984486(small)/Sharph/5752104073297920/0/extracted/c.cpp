// Compiler: g++-4.8 (Ubuntu/Linaro 4.8.1-10ubuntu9) 4.8.1
// Flags: -O2 -Wall -g -std=c++0x
// Aina häviää

#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <random>
#include <queue>

using namespace std;

int N = 1000;
mt19937 rng;

vector<int> good() {
	vector<int> ret(N);
	for(int i = 0; i < N; ++i) ret[i] = i;
	for(int i = 0; i < N; ++i) {
		int p = uniform_int_distribution<int>(i, N - 1)(rng);
		swap(ret[i], ret[p]);
	}
	return ret;
}
vector<int> bad() {
	vector<int> ret(N);
	for(int i = 0; i < N; ++i) ret[i] = i;
	for(int i = 0; i < N; ++i) {
		int p = uniform_int_distribution<int>(0, N - 1)(rng);
		swap(ret[i], ret[p]);
	}
	return ret;
}

struct Medianer {
	void add(int x) {
		left.push(x);
		while(left.size() >= right.size()) {
			int x = left.top();
			left.pop();
			right.push(-x);
		}
		while(left.size() <= right.size()) {
			int x = -right.top();
			right.pop();
			left.push(x);
		}
	}
	int med() {
		if(left.empty()) return 0;
		return left.top();
	}
	priority_queue<int> left;
	priority_queue<int> right;
};


int64_t count2(const vector<int>& v) {
	int64_t ret = 0;
	for(int i = 0; i < N; ++i) {
		ret += (int64_t)i * (int64_t)v[i];
	}
	return ret;
}

int64_t count(const vector<int>& v) {
	int64_t ret = 0;
	Medianer m;
	for(int i = N - 1; i >= 0; --i) {
		ret += m.med();
		m.add(v[i]);
	}
	return ret;
}

int main() {
	cin.sync_with_stdio(false);
	
	int T;
	cin >> T;
	
	for(int t = 0; t < T; ++t) {
		cin >> N;
		
		vector<int> a(N);
		for(int i = 0; i < N; ++i) {
			cin >> a[i];
		}
		
		if(count(a) + 3 * count2(a) < 755637578) {
			cout << "Case #" << t + 1 << ": GOOD\n";
		} else {
			cout << "Case #" << t + 1 << ": BAD\n";
		}
	}
	
	return 0;
}
