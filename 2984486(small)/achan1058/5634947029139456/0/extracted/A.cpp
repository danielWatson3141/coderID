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

int main() {
	fastio;
	int T, N, L;
	cin >> T;

	rep(X, 1, T + 1) {
		cin >> N >> L;
		vs source(N), target(N);
		rep(i, 0, N)
			cin >> source[i];
		rep(i, 0, N)
			cin >> target[i];

		sort(all(target));
		int best = inf;

		rep(i, 0, N) {
			int flip = 0;
			vs dummy = source;
			rep(j, 0, L) {
				if (dummy[i][j] != target[0][j]) {
					flip++;
					rep(k, 0, N)
						dummy[k][j] = '1' + '0' - dummy[k][j];
				}
			}

			sort(all(dummy));
			bool good = true;

			rep(k, 0, N) {
				if (dummy[k] != target[k]) {
					good = false;
					break;
				}
			}

			if (good)
				best = min(best, flip);
		}

		cout << "Case #" << X << ": ";
		
		if (best == inf)
			cout << "NOT POSSIBLE" << endl;
		else
			cout << best << endl;
	}
}