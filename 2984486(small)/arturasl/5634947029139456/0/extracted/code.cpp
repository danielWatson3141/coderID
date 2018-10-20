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

const int oo = numeric_limits<int>::max();
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

void solve() {
	int N, L, r = +oo;
	vector<string> outlets, devices;
	vector<bool> flips;
	cin >> N >> L;
	outlets.resize(N); devices.resize(N); flips.resize(L);

	for (int i = 0; i < N; i += 1) cin >> devices[i];
	for (int i = 0; i < N; i += 1) cin >> outlets[i];

	for (int match = 0; match < N; match += 1) {
		int curFlips = 0;
		for (int l = 0; l < L; l += 1) {
			if (devices[0][l] != outlets[match][l]) {
				flips[l] = 1;
				curFlips += 1;
			} else flips[l] = 0;
		}
		vector<string> modifiedOutlets = outlets;
		for (int n = 0; n < N; n += 1) {
			for (int l = 0; l < L; l += 1) {
				if (flips[l]) {
					modifiedOutlets[n][l] = modifiedOutlets[n][l] == '1' ? '0' : '1';
				}
			}
		}
		if (set<string>(devices.begin(), devices.end()) == set<string>(modifiedOutlets.begin(), modifiedOutlets.end())) {
			r = min(r, curFlips);
		}
	}

	if (r == +oo) cout << "NOT POSSIBLE" << endl;
	else cout << r << endl;
}

int main(int argc, char **argv) {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int T;
	cin >> T;
	for (int i = 1; i <= T; i += 1) {
		cout << "Case #" << i << ": ";
		solve();
	}
	
	return 0;
}
