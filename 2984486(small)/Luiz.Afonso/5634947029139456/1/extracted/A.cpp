#include <bits/stdc++.h>
using namespace std;

#define fr(a,b,c) for (int a = b; a < c; ++a)
#define db(x) cerr << #x " == " << endl
#define _ << ", " <<
typedef long long ll;

int n, l;

ll mask;
bool compSort(ll a, ll b) {
	return (a&mask) < (b&mask);
}
bool compEqual(ll a, ll b) {
	return (a&mask) == (b&mask);
}

int bt(const vector<ll>& dev, const vector<ll>& out, int idx) {
	if (idx == l) {
		return 0;
	}
	
	int r = 10000;
	vector<ll> a = dev, b = out;
	mask = (1LL<<idx+1)-1;
	sort(a.begin(), a.end(), compSort);
	sort(b.begin(), b.end(), compSort);
	if (equal(a.begin(), a.end(), b.begin(), compEqual)) {
		r = min(r, bt(a,b,idx+1));
	}
	
	fr(i,0,n) b[i] ^= 1LL<<idx;
	mask = (1LL<<idx+1)-1;
	sort(b.begin(), b.end(), compSort);
	if (equal(a.begin(), a.end(), b.begin(), compEqual)) {
		r = min(r, bt(a,b,idx+1)+1);
	}
	return r;
}

int main() {
	int t, caso = 1;
	for (cin >> t; caso <= t; ++caso) {
		printf("Case #%d: ", caso);
		
		ll a[200], b[200];
		cin >> n >> l;
		fr(i,0,n) {
			string tmp;
			cin >> tmp;
			int x = 0;
			fr(j,0,l) x = (x << 1) | (tmp[j] == '1');
			a[i] = x;
		}
		fr(i,0,n) {
			string tmp;
			cin >> tmp;
			int x = 0;
			fr(j,0,l) x = (x << 1) | (tmp[j] == '1');
			b[i] = x;
		}
		vector<ll> dev(a,a+n), out(b,b+n);
		
		int r = bt(dev,out,0);
		if (r > l) puts("NOT POSSIBLE");
		else printf("%d\n", r);
	}
	return 0;
}
