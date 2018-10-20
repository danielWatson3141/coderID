#include <string>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <iostream>
#include <functional>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <cmath>
#include <limits>

using namespace std;
typedef long long ll;

int solve(int N, int L, vector<ll> initial, vector<ll> require)
{
	int ans = numeric_limits<int>::max();
	vector<ll> req(require);
	sort(req.begin(), req.end());

	ll bit_mask = (1LL << L) - 1;
	for (ll mask = 0; mask < bit_mask; mask++) {
		vector<ll> init(initial);
		for (int i = 0; i < L; i++) {
			for (int j = 0; j < N; j++) {
				if ((mask & (1LL << i)) != 0) {
					if ((initial[j] & (1LL << i)) != 0)
						init[j] &= ~(1LL << i);
					else
						init[j] |= (1LL << i);
				}
			}
		}
		sort(init.begin(), init.end());
		if (equal(init.begin(), init.end(), req.begin())) {
			int count = 0;
			for (int i = 0; i < L; i++) {
				if ((mask & (1LL << i)) != 0) {
					count++;
				}
			}
			ans = min(ans, count);
		}
	}
	if (ans == numeric_limits<int>::max())
		ans = -1;
	return ans;
}

int main()
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int N, L;
		cin >> N >> L;
		vector<ll> initial(N);
		for (int i = 0; i < N; i++) {
			string val;
			cin >> val;
			initial[i] = stoll(val, 0, 2);
		}
		vector<ll> require(N);
		for (int i = 0; i < N; i++) {
			string val;
			cin >> val;
			require[i] = stoll(val, 0, 2);
		}

		cout << "Case #" << t << ": ";
		int ans = solve(N, L, initial, require);
		if (ans < 0)
			cout << "NOT POSSIBLE";
		else
			cout << ans;
		cout << endl;
	}
	return 0;
}