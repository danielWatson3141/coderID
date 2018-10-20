#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <cstring>

using namespace std;

vector<string> out_v, charge_v;
int T, N, L, flips[40], min_flips;

void solve() {
	out_v.clear();
	charge_v.clear();
	min_flips = -1;
	for (int i = 0; i < N; ++i) {
		string str;
		cin >> str;
		out_v.push_back(str);
	}
	for (int i = 0; i < N; ++i) {
		string str;
		cin >> str;
		charge_v.push_back(str);
	}

	// test
	string ref_dev = charge_v[0];
	int temp_flips = 0;
	for (int ii = 0; ii < N; ++ii) {
		temp_flips = 0;
		// compare ref_dev with out_v[ii]
		string str = out_v[ii];
		for (int i = 0; i < L; ++i) {
			if (str[i] == ref_dev[i])
				flips[i] = 0;
			else {
				flips[i] = 1;
				temp_flips++;
			}
		}

		// modify out_v accordingly and generate a map
		map<string, int> mp;
		for (int i = 0; i < N; ++i) {
			string str_t = out_v[i];
			for (int j = 0; j < L; ++j) {
				if (flips[j] == 1) {
					if (str_t[j] == '0')
						str_t[j] = '1';
					else
						str_t[j] = '0';
				}
			}
			mp[str_t]++;
		}

		// see if map vanishes or not
		for (int i = 0; i < N; ++i) {
			mp[charge_v[i]]--;
		}
		int tmp_c = 0;
		for (map<string, int>::iterator it = mp.begin(); it != mp.end(); ++it) {
			if (it->second > 0) {
				tmp_c = 1;
				break;
			}
		}
		if (!tmp_c) {
			if (min_flips < 0)
				min_flips = temp_flips;
			else
				min_flips = min(min_flips, temp_flips);
		}
	}
	if (min_flips < 0)
		printf("NOT POSSIBLE\n");
	else
		printf("%d\n", min_flips);

}

int main()
{
	cin >> T;
	for (int i = 0; i < T; ++i) {
		cin >> N >> L;
		printf("Case #%d: ", i+1);
		solve();
	}
	return 0;
}
