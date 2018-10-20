#include <iostream>
#include <vector>
#include <map>
#include <utility>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ii> vii;

template<typename T> inline int sz(const T& x) { return (int)x.size(); }

int main() {
	int tc; cin >> tc;

	for(int t = 1; t <= tc; ++t) {
		int n; cin >> n;
		vi a(n);
		for (int i = 0; i < n; ++i) cin >> a[i];

		int inv = 0;
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < i; ++j) {
				if(a[j] > a[i]) inv++;
			}
		}

		if (inv < 244500) {
			cout << "Case #" << t << ": BAD" << endl;
		} else {
			cout << "Case #" << t << ": GOOD" << endl;
		}
	}

	return 0;
}
