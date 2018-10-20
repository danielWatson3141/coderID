#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <tuple>
#include <typeinfo>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vector<int>> vvi;
typedef vector<vector<double>> vvd;
typedef pair<int, int> pii;

#define sz size()
#define pb push_back
#define rep(k,a,b) for (int k = (a); k < (int)(b); k++)
#define rrep(k,a,b) for (int k = (a); k >= (int)(b); k--)
#define irep(k,a) for (auto& k: a)
#define all(c) (c).begin(), (c).end()
#define clr(a) memset((a),0,sizeof(a))
#define mi(r, c, v) vvi(r, vi(c, v))
#define md(r, c, v) vvd(r, vd(c, v))
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

const double eps = 10e-10;
const int inf = 0x3f3f3f3f;

void rand1(vi& v, int t) {
	rep(i, 0, v.sz) {
		int r = t % v.sz - i;
		swap(v[i], v[r + i]);
		t /= v.sz - i;
	}
}

void rand2(vi& v, int t) {
	rep(i, 0, v.sz) {
		int r = t % v.sz;
		swap(v[i], v[r]);
		t /= v.sz;
	}
}

void init(vi& v) {
	rep(i, 0, v.sz)
		v[i] = i;
}

int inver(const vi& v) {
	int inv = 0;
	rep(i, 0, v.sz) {
		rep(j, i + 1, v.sz) {
			if (v[i] > v[j])
				inv++;
		}
	}
	return inv;
}

int sortnum(vi v) {
	int s = 0;
	rep(i, 0, v.sz) {
		if (v[i] == i)
			continue;
		rep(j, i + 1, v.sz) {
			if (v[j] == i) {
				s++;
				rrep(k, j, i + 1)
					v[k] = v[k - 1];
				v[i] = i;
			}
		}
	}
	return s;
}

int main() {
	fastio;
	int T, N, cutoff = 245000, numbad = 0;
	cin >> T;
	rep(X, 1, T + 1) {
		cin >> N;
		vi vec(N);

		irep(v, vec)
			cin >> v;
		irep(v, vec) {
			if (v == N) {
				cout << "evil" << endl;
				return 0;
			}
			if (v == 0) {
				swap(v, vec.back());
				break;
			}
		}

		int rightpos = 0;

		rep(i, 0, vec.sz) {
			vec[i] = (vec[i] + N - 1) % N;
			if (vec[i] == i)
				rightpos++;
		}

		int s = inver(vec);
		cout << "Case #" << X << ": ";
		if (s > cutoff)
			cout << "GOOD" << endl;
		else {
			cout << "BAD" << endl;
			numbad++;
		}
		//cout << s << ' ' << rightpos << endl;
	}
	//cout << numbad << endl;
}

int dummu() {
	int n;
	while (cin >> n) {
		int k1 = 1, k2 = 1;
		vi v(n);
		rep(i, 0, n) {
			k1 *= n - i;
			k2 *= n;
		}

		map<vi, int> invnum2;

		rep(i, 0, k2) {
			init(v);
			rand2(v, i);
			invnum2[v]++;
		}

		int total = 0;
		int average = k2 / k1 * 1.5;

		irep(t, invnum2) {
			if (t.second < average) {
				cout << "   ";
			}
			irep(x, t.first) {
				cout << x << ' ';
			}

			vi vv = t.first;
			rep(i, 0, vv.sz) {
				if (vv[i] == 0) {
					swap(vv[i], vv.back());
					break;
				}
			}

			int rightpos = 0;
			rep(i, 0, vv.sz) {
				vv[i] = (vv[i] + n - 1) % n;
				if (vv[i] == i)
					rightpos++;
			}

			cout << "   " << t.second << ' ' << inver(vv) << ' ' << rightpos << endl;
			total += t.second;
		}
		cout << total - k2 << endl;
	}
}