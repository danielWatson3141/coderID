//Full Binary Tree
//g++ --std=c++11 -W -Wall -Wno-sign-compare -O2 -s -pipe -mmmx -msse -msse2 -msse3
#include <iostream>
#include <iterator>
#include <algorithm>
#include <limits>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <numeric>
#include <iomanip>
#include <cmath>
#include <queue>
using namespace std;

#define forl(i, s, t) for(__typeof(s) i = s; i != t; i++)
#define rforl(i, s, t) for(__typeof(s) i = s; i != t; i--)
#define foreach(itr, c) forl(itr, (c).cbegin(), (c).cend())
#define rforeach(itr, c) forl(itr, (c).crbegin(), (c).crend())

#define rep(n) forl(rep_c, 0, n)
#define fill2d_nn(g, s, z, v) forl(i, 0, s) fill_n(g[i], z, v)
#define fill2d_n(g, s, v) fill2d_nn(g, s, s, v)
//#define read(s, t) forloop(read_c, s, t) cin >> *read_c
//inline void read(ForwardIterator s, ForwardIterator e) { forloop(i, s, e) cin >> *i; }
//#define read_n(x, n) forl(read_n_c, 0, n) cin >> x[read_n_c]
//#define rread_n(x, n) rforl(rread_n_c, n-1, -1) cin >> x[rread_n_c]

#define tpop(x) (x).top(); (x).pop()
#define fpop(x) (x).front(); (x).pop()
//#define all(x) (x).begin(), (x).end()
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)

//#define chmin(a, b) a = min(a, b)
//#define chmax(a, b) a = max(a, b)
template<typename T> inline void chmin(T& a, const T& b) { a = min(a, b); }
template<typename T> inline void chmax(T& a, const T& b) { a = max(a, b); }

template<typename T> T gcd(T a, T b) { if(b == (T)0) return a; return gcd(b, a % b); }
#define gcd_n(a, n) accumulate(a+1, a+n, a[0], gcd);
template <class ForwardIterator>
inline int gcd_r(ForwardIterator s, ForwardIterator e) { return accumulate(s+1, e, s[0], gcd); }

#ifdef DEBUG
#define varcontent(v) #v << '=' << v
#define debug(v) cerr << varcontent(v) << endl
#define pdebug(v, w) cerr << '(' << varcontent(v) << ',' << varcontent(w) << ')' << endl
#define dmsg(a) cerr << a << endl
#else
#define varcontent(v) 0
#define debug(v) 0
#define pdebug(v, w) 0
#define dmsg(a) 0
#endif

#define printarr(a, n) cerr << #a << " = ["; forloop(i, 0, n) cerr << a[i] << ' '; cerr.seekp(cerr.tellp()-1L); cerr << ']' << endl
#define printgrid(g, y, x) cerr << endl << #g << ':' << endl; forl(i, 0, y) { forl(j, 0, x) cerr << g[i][j] << ' '; cerr << endl; } cerr << endl
#define rprintgrid(g, x, y) cerr << endl << #g << ':' << endl; forl(i, 0, x) { forl(j, 0, y) cerr << g[j][i] << ' '; cerr << endl; } cerr << endl
/*inline void printgrid(RandomAccessIterator g, int y, int x) {
	cerr << endl << #g << ':' << endl;
	forloop(i, 0, y) {
		forloop(j, 0, x) cout<< g[i][j] << ' ';
		cout << endl;
	}
	cerr << endl;
}*/
/*inline void rprintgrid(RandomAccessIterator g, int x, int y) {
	cerr << endl << #g << ':' << endl;
	forloop(i, 0, x) {
		forloop(j, 0, y) cout<< g[j][i] << ' ';
		cout << endl;
	}
	cerr << endl;
}*/

const int INF = numeric_limits<int>::max()/2;
const double EPS = INF*numeric_limits<double>::epsilon();

int dfs(vector< set<int> >& adjlist, vector<bool>& visited, int s) {
	visited[s] = true;
	int besta = 0, bestb = 0;
	foreach(a, adjlist[s]) {
		if(visited[*a]) continue;
		int v = dfs(adjlist, visited, *a);
		if(v > besta) {
			bestb = besta;
			besta = v;
		}
		else if(v > bestb) {
			bestb = v;
		}
	}
	if(bestb == 0) besta = 0;
	visited[s] = false;
	return 1+besta+bestb;
}

void gcjmain() {
	int N;
	cin >> N;
	vector< set<int> > adjlist(N);
	forl(n, 0, N-1) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		adjlist[x].insert(y);
		adjlist[y].insert(x);
	}
	int ans = INF;
	forl(n, 0, N) {
		vector<bool> visited(N, false);
		int count = dfs(adjlist, visited, n);
		/*queue< pair<int,int> > q;
		q.push(pair<int,int>(n, 0));
		//int cutoff = INF;
		int count = 0;
		while(!q.empty()) {
			pair<int,int> cur = q.front(); q.pop();
			//if(cur.second > cutoff) continue;
			visited[cur.first] = true;
			count++;
			int pushed = 0;
			foreach(a, adjlist[cur.first]) {
				if(visited[*a]) continue;
				//q.push(pair<int,int>(*a, cur.second+1));
				pushed++;
			}
			if(pushed == 2) {
				foreach(a, adjlist[cur.first]) {
					if(visited[*a]) continue;
					q.push(pair<int,int>(*a, cur.second+1));
				}
				//cutoff = cur.second;
			}
		}*/
		ans = min(ans, N - count);
	}
	cout << ans << endl;
}

int main() {
	int T;
	cin >> T;
	forl(t, 1, T+1) {
		cerr << "Case: " << t << '/' << T << endl;
		cout << "Case #" << t << ": ";
		gcjmain();
	}
}
