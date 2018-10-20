#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cmath>
#include <deque>
#include <set>


using namespace std;

#define MAXN 1024*1024
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sz(a) (int)(a.size())
#define all(a) a.begin(), a.end()
#define R(a) ((a)%mod)

typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PI;
typedef vector<PI> VPI;
typedef vector<VPI> VVPI;
typedef vector<VVPI> VVVPI;
typedef vector<VVI> VVVI;

int n;
VVI a;

PI get (int nd, int p = -1)
{
	VPI v;
	int total = 1;
	for (int i = 0; i < sz(a[nd]); i += 1)
		if(a[nd][i] != p) {
			v.pb(get(a[nd][i], nd));
			total += v.back().y;
		}
	if(sz(v) <= 1)
		return mp(1, total);
	sort(all(v));
	reverse(all(v));
	return mp(1+v[0].x+v[1].x, total);
}

int main (int argc, char const* argv[])
{
	int t;
	
	cin >> t;
	
	for (int cs = 0; cs < t; cs += 1)
	{
		cin >> n;
		a = VVI(n);
		for (int i = 0; i < n-1; i += 1)
		{
			int p, q;
			cin >> p >> q;
			a[p-1].pb(q-1);
			a[q-1].pb(p-1);
		}
		int ans = 0;
		for (int i = 0; i < n; i += 1)
			ans = max(ans, get(i).x);
		cout << "Case #" << cs+1 << ": " << n-ans << '\n';

	}	
	return 0;
}














