#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define S(x) scanf("%lld", &x);
#define div /

ll solve(vector<string> outlets, vector<string> devices, ll cur, ll cnt) {
	if (cur >= outlets[0].length()) {
		return INT_MAX;
	}
	else {
		ll i;
		if (outlets == devices) {
			return cnt;
		}
		vector<string> ve3 = outlets;
		for (i = 0; i < outlets.size(); i++) {
			outlets[i][cur] = (1 - (outlets[i][cur] - 48)) + 48;
		}
		sort(outlets.begin(), outlets.end());
		if (outlets == devices) {
			return cnt + 1;
		}
		else {
			ll mi = INT_MAX;
			for (i = cur + 1; i < outlets[0].length(); i++) {
				mi = min(mi, min(solve(outlets, devices, i, cnt + 1), solve(ve3, devices, i, cnt)));
			}
			return mi;
		}
	}
	return INT_MAX;
}

int main()
{
	ll T;
	freopen("inpp", "r", stdin);
	freopen("out.txt", "w", stdout);
	S(T);
	ll i;
	for (i = 1; i <= T; i++) {
		ll N, L;
		ll j;
		S(N);
		S(L);
		vector <string> outlets, devices;

		for (j = 0; j < N; j++) {
			string s;
			cin >> s;
			outlets.push_back(s);
		}
		for (j = 0; j < N; j++) {
			string s;
			cin >> s;
			devices.push_back(s);
		}
		sort(outlets.begin(), outlets.end());
		sort(devices.begin(), devices.end());

		ll h = solve(outlets, devices, 0, 0);
		if (h != INT_MAX) {
			printf("Case #%lld: %lld\n", i, h);
		}
		else {
			printf("Case #%lld: NOT POSSIBLE\n", i);
		}

	}
}



