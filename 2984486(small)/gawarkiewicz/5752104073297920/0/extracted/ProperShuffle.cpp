#include <iostream>
#include <vector>
#include <random>
#include <functional>
#include <map>
#include <set>
#include <string>

using namespace std;

vector<int> good(int len) {
	vector<int> a(len);
	for (int i = 0; i < len; ++i) a[i] = i;
	/*std::uniform_int_distribution<int> distribution(0, len-1);
	std::mt19937 engine; // Mersenne twister MT19937
	auto generator = std::bind(distribution, engine);*/
	for (int k = 0; k < len; ++k) {
		//int random = generator(); // Generate a uniform integral variate between 0 and len.
		int p = (rand() % (len - k)) + k;
		swap(a[k], a[p]);
	}
	return move(a);
}

vector<int> bad(int len) {
	vector<int> a(len);
	for (int i = 0; i < len; ++i) a[i] = i;
	/*std::uniform_int_distribution<int> distribution(0, len-1);
	std::mt19937 engine; // Mersenne twister MT19937
	auto generator = std::bind(distribution, engine);*/
	for (int k = 0; k < len; ++k) {
		//int random = generator(); // Generate a uniform integral variate between 0 and len.
		int p = (rand() % len);
		swap(a[k], a[p]);
	}
	return move(a);
}

int test() {
	map<vector<int>, int> m;
	int iters = 10000000;
	for (int i = 0; i < iters; ++i) {
		m[bad(6)] ++;
	}

	set < pair<int, vector<int>>> s;
	for (auto& t : m) {
		s.insert(make_pair(t.second, t.first));
	}

	/*for (auto& t : m) {
		cout << "[";
		for (auto& v : t.first) {
			cout << v << ",";
		}
		cout << "] " << (double)t.second / iters << endl;
	}*/

	for (auto& t : s) {
		cout << "[";
		for (auto& v : t.second) {
			cout << v << ",";
		}
		cout << "] " << (double)t.first / iters << endl;
	}

	for (int i = 0, len = m.begin()->first.size(); i < len; ++i) {
		map<int, int> ci;
		for (auto& t : m) {
			ci[t.first[i]] += t.second;
		}
		cout << i << ":";
		for (auto c : ci) cout << " " << c.first << " (" << c.second << ")";
		cout << endl;
	}
	return 0;
}

string guess(vector<int>& a) {
	int prob = 0;
	for (int i = 0, len = a.size(); i < len; ++i) {
		if (a[i] > i) prob += a[i] - i;
		else prob += len - (i - a[i]);
	}
	return prob < a.size() * a.size() / 2 ? "BAD" : "GOOD";
}

int main() {
	//test();
	int T;
	cin >> T;
	for (int q = 1; q <= T; ++q) {
		int N;
		cin >> N;
		vector<int> a(N);
		for (auto& i : a) cin >> i;
		cout << "Case #" << q << ": " << guess(a) << endl;
	}
	return 0;
}