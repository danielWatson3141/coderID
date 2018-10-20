#include      <algorithm>
#include      <cmath>
#include      <cstdarg>
#include      <cstdio>
#include      <cstdlib>
#include      <iomanip>
#include      <iostream>
#include      <iterator>
#include      <limits>
#include      <list>
#include      <map>
#include      <set>
#include      <queue>
#include      <vector>
#define endl '\n'
#define each(c, e) for (typeof(c.begin()) e = c.begin(); e != c.end(); ++e)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

template<typename T1, typename T2> ostream& operator<<(ostream &o, const pair<T1, T2> &p) {return o << '(' << p.first << ", " << p.second << ')';}
template<typename I> ostream& print(ostream &o, I s, I e, int w = 5, int prec = 2, const string &sep = ", ", const string &lhs = "", const string &rhs = "") {
	o << lhs;
	if (s != e) o << setw(w) << setprecision(prec) << *(s++);
	for (; s != e; ++s) o << sep << setw(w) << setprecision(prec) << *s;
	return o << rhs;
}
template<typename T, template<typename E, typename A=std::allocator<E> > class C>
ostream& operator<<(ostream &o, const C<T>& c) {return print(o, c.begin(), c.end(), 0, 2, ", ", "[", "]");}
template<typename T, template<typename E, typename Compare = less<E>, typename Alloc = allocator<E> > class C>
ostream& operator<<(ostream &o, const C<T>& c) {return print(o, c.begin(), c.end(), 0, 2, ", ", "{", "}");}
template<typename K, typename T, template<typename E1, typename E2, typename Compare = std::less<E1>, class Allocator = std::allocator<std::pair<const E1, E2> > > class C>
ostream& operator<<(ostream &o, const C<K, T>& c) {return print(o, c.begin(), c.end(), 0, 2, ", ", "{", "}");}

bool t1(vector<int> &A) {
	double a1 = 0, a2 = 0;
	const int h = A.size() / 2;
	for (int i = 0; i < h; i += 1) a1 += A[i]; a1 /= h;
	for (int i = h - 1; i < 2 * h - 1; i += 1) a2 += A[i]; a2 /= h;

	return fabs(a1 - a2) < 22;
}

bool t2(vector<int> &A) {
	const int h = A.size() / 2;
	int pos[2] = {0, 0};
	for (int i = 1; i <= 100; i += 1) pos[find(A.begin(), A.end(), i) - A.begin() < h] += 1;
	return abs(pos[0] - 50) < 4;
}

bool t3(vector<int> &A) {
	int r = 0;
	for (int i = 0; i < (int)A.size(); i += 1) {
		r += abs(A[i] - (i + 1)) < 2;
	}
	return r < 5;
}

bool t4(vector<int> &A) {
	int r = 0;
	for (int i = 0; i < (int)A.size(); i += 1) {
		r += abs((find(A.begin(), A.end(), i + 1) - A.begin() + 1) - (i + 1));
	}
	return r < 329000;
}

bool t5(vector<int> &A) {
	return (find(A.begin(), A.end(), 999) - A.begin()) < 500;
}

void shuffle(int s) {
	map<vector<int>, int> h;
	for (int t = 0; t < 10000000; t += 1) {
		vector<int> a; a.resize(s);
		for (int i = 0; i < s; i += 1) a[i] = i + 1;
		for (int i = 0; i < s - 1; i += 1) swap(a[i], a[rand() % s]);
		h[a] += 1;
	}
	vector< pair<int, vector<int> > > ss;
	for (map<vector<int>, int>::const_iterator it = h.begin(); it != h.end(); ++it) ss.push_back(make_pair(it->second, it->first));
	sort(ss.begin(), ss.end());
	for (int i = 0; i < (int)ss.size(); i += 1) cout << ss[i] << endl;
}

bool solve() {
	int N;
	cin >> N;
	vector<int> A; A.resize(N);
	for (int i = 0; i < N; i += 1) cin >> A[i];
	// return t1(A) && t2(A);
	return t5(A);
}

int main(int argc, char **argv) {
	ios_base::sync_with_stdio(false), cin.tie(0);
	// shuffle(9);
	int T;
	cin >> T;
	int g = 0, b = 0;
	for (int t = 1; t <= T; t += 1) {
		bool r = solve();
		if (r) g += 1;
		else b += 1;
		cout << "Case #" << t << ": " << (r ? "GOOD" : "BAD") << endl;
	}
	cerr << g << "  " << b << endl;
	
	return 0;
}
