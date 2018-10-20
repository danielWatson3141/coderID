//Seikang

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#include <vector>
#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>

#include <cmath>
#include <complex>
#include <algorithm>

#include <ctime>
#define gtime clock()

using namespace std;

#define SZ(cont) (int)(cont.size())
#define ALL(cont) (cont).begin(), (cont).end()
#define DEBUG(x) cerr << ">" << #x << ":" << x << endl

typedef long long int64;
typedef pair<int64, int64> ii;
typedef vector<int64> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<string> vs;

const int64 oo32 = 1ll << 30, oo64 = 1ll << 60;
const double pi = acos(-1.0), eps = 1e-9;
inline bool equal(const double &a, const double &b){return abs(a - b) < eps;}

int evaluate(vi &l)
{
	int N = l.size();
	srand(gtime);
		
		vi good = l;
		vi bad = l;

		for (int j = 0; j < N; ++j)
		{
			int r = rand();
			int good_p = (r % (N - j)) + j;
			int bad_p = r % N;
			
		//	cout << "good random " << r << endl; 
  			swap(good[j], good[good_p]);
  			swap(bad[j], bad[bad_p]);
		}
		int good_val = 0, bad_val = 0;
		for (int j = 0; j < N; ++j)
		{
			good_val += abs(good[j] - j);
			bad_val += abs(bad[j] - j);
		//	cout << good_val << " ALONE" << endl;
		//	cout << bad_val << " BLONE" << endl;
		}

		//cout << "GOOD ";for (int j = 0; j < N; ++j) cout << good[j] << ' '; cout << endl;
		//cout << "BAD ";for (int j = 0; j < N; ++j) cout << bad[j] << ' '; cout << endl;
		//cout << good_val << ' ' << bad_val << endl;

		return bad_val - good_val;
}
const int RISK = 1000;
int main()
{
	freopen ("c.in", "rt", stdin);
	freopen ("c.out", "wt", stdout);

	int C;
	cin >> C;
	for (int i = 0; i < C; ++i)
	{
		cout << "Case #" << (i + 1) << ": ";
		int N;
		cin >> N;

		vi l = vi(N);
		for (int j = 0; j < N; ++j)
		{
			cin >> l[j];
		}

		int good = 0, bad = 0;
		for (int risk = 0; risk < RISK; ++risk)
		{
			int v = evaluate(l);
			if(v > 0)
				good++;
			if(v < 0)
				bad++;
		}
		//cout << good << ' ' << bad << endl;
		cout << (good >= bad ? "GOOD" : "BAD") << endl;
	}
	return 0;
}
