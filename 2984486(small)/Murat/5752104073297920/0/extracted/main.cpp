#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cassert>
#include <memory.h>
#include <ctype.h>
  
#include <iostream>
  
#include <string>
#include <complex>
#include <numeric>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <sstream>

#include <chrono>
#include <random>
  
using namespace std;
  
template<typename TYPE> inline TYPE sqr(const TYPE& a) { return (a) * (a); }
  
#define forn(i, n) for(int i = 0; i < int(n); ++i)
#define for1(i, n) for(int i = 1; i <= int(n); ++i)
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
  
typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;
  
const int INF = 1000 * 1000 * 1000;
const ld EPS = 1e-9;
const ld PI = 2 * acos(0.0);
const int N = 100;

default_random_engine gen;
uniform_int_distribution<int> distribution;

void init() {
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	gen = default_random_engine(seed);
}

int gr() {
	return distribution(gen);
}

int gr(int fm, int to) {
	distribution = uniform_int_distribution<int>(fm, to);
	return distribution(gen);
}

vector<int> good(int n) {
	vector<int> v(n);
	forn (i, n)
		v[i] = i;
	forn (i, n) {
		int j = gr(i, n - 1);
		assert(0 <= j && j < n);
		swap(v[i], v[j]);
	}
	return v;
}

vector<int> bad(int n) {
	std::vector<int> v(n);
	forn (i, n)
		v[i] = i;
	distribution = uniform_int_distribution<int>(0, n - 1);
	forn (i, n) {
		int j = gr();
		assert(0 <= j && j < n);
		swap(v[i], v[j]);
	}
	return v;
}

void print(const vector<int> &v) {
	forn (i, v.size())
		printf("%d ", v[i]);
	puts("");
}

void stat(int n, int m) {
	init();
	puts("good");
	vector<vector<int> > c(n, vector<int>(n, 0));
	forn (it, m) {
		auto v = good(n);
		forn (i, v.size())
			++c[i][v[i]];
	}
	forn (i, n) {
		int pst = 0;
		forn (j, n) {
			if (c[i][j] > c[i][pst])
				pst = j;
			printf("\t%.3lf", double(c[i][j]) / m);
		}
		printf(", at %d: %d\n", i, pst);
	}
	puts("bad");
	vector<vector<int> > d(n, vector<int>(n, 0));
	forn (it, m) {
		auto v = bad(n);
		forn (i, v.size())
			++d[i][v[i]];
	}
	forn (i, n) {
		int pst = 0;
		forn (j, n) {
			if (d[i][j] > d[i][pst])
				pst = j;
			printf("\t%.3lf", double(d[i][j]) / m);
		}
		printf(", at %d: %d\n", i, pst);
	}
}

void generate(int n, int m) {
	printf("%d\n", m * 2);
	init();
	forn (i, m) {
		vector<int> v = good(n);
		printf("%d\n", n); 
		print(v);
	}
	forn (i, m) {
		std::vector<int> v = bad(n);
		printf("%d\n", n);
		print(v);
	}
}

bool say(const vector<int> &p) {
	int c = 0;
	int rg = int(p.size()) * 0.35;
	forn (i, p.size()) {
		int v = p[i];
		if (i + 1 <= v && v < i + rg)
			++c;
	}
	//printf("c = %d\n", c);
	return c < int(p.size()) * 0.3;
}

void solve() {
	int tests;
	scanf("%d", &tests);
	for1 (it, tests) {
		int n;
		scanf("%d", &n);
		vector<int> v(n);
		forn (i, n) {
			int t;
			scanf("%d", &t);
			v[i] = t;
		}
		printf("Case #%d: %s\n", it, say(v) ? "GOOD" : "BAD");
	}
}

int main() {
	solve();
	return 0;
	int n;
	scanf("%d", &n);
	generate(n, 10);	
    return 0;
}
