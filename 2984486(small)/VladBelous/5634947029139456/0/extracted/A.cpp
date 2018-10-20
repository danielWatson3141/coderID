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
		int N, L; cin >> N >> L;
		
		vector<string> flow(N), dev(N);
		for(int i = 0; i < N; ++i) cin >> flow[i];
		for(int i = 0; i < N; ++i) cin >> dev[i];
		sort(dev.begin(), dev.end());
		//cerr << "input read" << endl;

		if (L > 10) { cerr << "error" << endl; return 0; }
	
		int best = L+1;
		for (int m = 0; m < (1<<L); ++m) {
			vector<string> f(flow);
			int cnt = 0;

			for(int k = 0, pos=1; k < L; ++k, pos+=pos) {
				if(m&pos) {
					++cnt;
					for(int j = 0; j < N; ++j) {
						f[j][k] = f[j][k] == '1' ? '0' : '1';
					}
				}
			}
			sort(f.begin(), f.end());
			if (f == dev) {
				best = min(best, cnt);
			}
		}

		if (best == L+1) {
			cout << "Case #" << t << ": " << "NOT POSSIBLE" << endl;
		} else {
			cout << "Case #" << t << ": " << best << endl;
		}
	}

	return 0;
}
