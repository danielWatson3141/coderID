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

//total node, del node
pair<int, int> processTree(const vi& pred, const vvi& adjList, int V) {
	int numnodes = 1;
	vector<pii> children;

	irep(v, adjList[V]) {
		if (v != pred[V]) {
			children.pb(processTree(pred, adjList, v));
			numnodes += children.back().first;
		}
	}

	if (children.sz == 0) {
		return{ 1, 0 };
	} else if (children.sz == 1) {
		return{ numnodes, numnodes - 1 };
	} else {
		int best = inf;
		rep(i, 0, children.sz) {
			rep(j, i + 1, children.sz) {
				best = min(best, numnodes - 1 - children[i].first - children[j].first + children[i].second + children[j].second);
			}
		}

		return{ numnodes, best };
	}
}

int main() {
	fastio;
	int T, N;
	cin >> T;

	rep(X, 1, T + 1) {
		cin >> N;
		vvi adjList(N);
		int v1, v2;
		rep(i, 0, N - 1) {
			cin >> v1 >> v2;
			adjList[v1 - 1].pb(v2 - 1);
			adjList[v2 - 1].pb(v1 - 1);
		}

		int best = inf;

		rep(V, 0, N) {
			vi pred(N, -1);
			queue<int> q;
			q.push(V);

			while (!q.empty()) {
				int v = q.front();
				q.pop();

				irep(x, adjList[v]) {
					if (x != V && pred[x] == -1) {
						pred[x] = v;
						q.push(x);
					}
				}
			}

			//rep(i, 0, N)
			//	cout << pred[i] + 1 << ' ';
			//cout << endl;

			best = min(processTree(pred, adjList, V).second, best);
		}

		cout << "Case #" << X << ": " << best << endl;
	}
}