#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define	For(i,a,b)				for(int i=(a);i<(b);++i)
#define	rep(i,n)				For(i,0,(n))

long long bin2ll(string s)
{
	long long res = 0;
	rep(i, s.size()) {
		res <<= 1;
		res |= (s[i] == '0') ? 0 : 1;
	}
	return res;
}

long long countbit(long long v, int l)
{
	long long res = 0;
	rep(i, l) {
		if(v & 0x01)
			++res;
		v >>= 1;
	}
	return res;
}

string solve()
{
	int N, L;
	vector<long long> d;
	vector<long long> o;

	cin >> N >> L;
	rep(i, N) {
		string s;
		cin >> s;
		o.push_back(bin2ll(s));
	}
	rep(i, N) {
		string s;
		cin >> s;
		d.push_back(bin2ll(s));
	}

	vector<long long> r;
	sort(d.begin(), d.end());
	rep(i, 1 << L) {
		vector<long long> t;
		rep(j, N)
			t.push_back(o[j] ^ i);
		sort(t.begin(), t.end());

		if(d == t)
			r.push_back(countbit(i, L));
	}

	if(r.empty())
		return "NOT POSSIBLE";
	return to_string(*min_element(r.begin(), r.end()));
}

int main()
{
	int T;

	cin >> T;
	rep(i, T)
		cout << "Case #" << (i + 1) << ": " << solve() << endl;
}
