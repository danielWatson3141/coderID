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
typedef vector<ll> VL;
typedef pair<double, double> PI;
typedef vector<PI> VPI;
typedef vector<VPI> VVPI;
typedef vector<VVPI> VVVPI;
typedef vector<VVI> VVVI;


vector<string> x, y;
int n, l;
VL r;

void find ( VI &A, VI &B, int idx, VL &Ret )
{
	VI a[2], b[2];
	VL ret[2];
	int k = sz(A);
	Ret.clear();
	if(k == 0 || idx == l)
	{
		if(idx == l)	Ret.pb(0);
		if(k == 0)	Ret.pb(-1);
		return;
	}
	for (int i = 0; i < k; i += 1)
	{
		a[x[A[i]][idx]-'0'].pb(A[i]);
		b[y[B[i]][idx]-'0'].pb(B[i]);
	}
	
	int na[2] = {sz(a[0]), sz(a[1])}, nb[2] = {sz(b[0]), sz(b[1])};
	
	if(na[0] == nb[0])
	{
		find(a[0], b[0], idx+1, ret[0]);
		find(a[1], b[1], idx+1, ret[1]);
		if(!ret[0].empty() && ret[0][0] == -1) {
			for (int i = 0; i < sz(ret[1]); i += 1)
				Ret.pb(((ll)ret[1][i])<<1);
		}
		else if(!ret[1].empty() && ret[1][0] == -1) {
			for (int i = 0; i < sz(ret[0]); i += 1)
				Ret.pb(((ll)ret[0][i])<<1);
		} else for (int i = 0, j = 0; i < sz(ret[0]) && j < sz(ret[1]);) {
			if(ret[0][i] > ret[1][j]) {
				if(j+1 < sz(ret[1]))
					j++;
				else	break;
			}
			else if(ret[0][i] < ret[1][j]) {
				if(i+1 < sz(ret[0]))
					i++;
				else	break;
			}
			else {
				Ret.pb(((ll)ret[0][i])<<1);
				i++, j++;
			}
		}
	}
	if(na[0] == nb[1])
	{
		find(a[0], b[1], idx+1, ret[0]);
		find(a[1], b[0], idx+1, ret[1]);
		if(!ret[0].empty() && ret[0][0] == -1) {
			for (int i = 0; i < sz(ret[1]); i += 1)
				Ret.pb((((ll)ret[1][i])<<1)+1LL);
		}
		else if(!ret[1].empty() && ret[1][0] == -1) {
			for (int i = 0; i < sz(ret[0]); i += 1)
				Ret.pb((((ll)ret[0][i])<<1)+1LL);
		} else for (int i = 0, j = 0; i < sz(ret[0]) && j < sz(ret[1]);) {
			if(ret[0][i] > ret[1][j]) {
				if(j+1 < sz(ret[1]))
					j++;
				else	break;
			}
			else if(ret[0][i] < ret[1][j]) {
				if(i+1 < sz(ret[0]))
					i++;
				else	break;
			}
			else {
				Ret.pb((((ll)ret[0][i])<<1)+1LL);
				i++, j++;
			}
		}
	}
}

int main (int argc, char const* argv[])
{
	int t;
	VI a, b;
	
	cin >> t;
	
	for (int cs = 0; cs < t; cs += 1)
	{
		cin >> n >> l;
		x = vector<string> (n);
		y = vector<string> (n);
		for (int i = 0; i < n; i += 1)
			cin >> x[i];
		for (int i = 0; i < n; i += 1)
			cin >> y[i];
		a.clear();
		b.clear();
		for (int i = 0; i < n; i += 1)
		{
			a.pb(i);
			b.pb(i);
		}
		find(a, b, 0, r);
		cout << "Case #" << cs+1 << ": ";
		int ans = 2*l*l;
		for (int i = 0; i < sz(r); i += 1)
			ans = min(ans, __builtin_popcountll(r[i]));
		if(ans <= l)
			cout << ans << '\n';
		else	cout << "NOT POSSIBLE\n";
	}
	
	return 0;
}














