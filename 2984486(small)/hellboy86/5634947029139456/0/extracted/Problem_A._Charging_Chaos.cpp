#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define S(x) scanf("%lld", &x);
#define div /

ll solve(vector<string> ve1, vector<string> ve2, ll curr, ll mov) {
	if(curr >= ve1[0].length() ) {
		return INT_MAX;
	}
	else {
		ll i;
		if(ve1 == ve2) {
			return mov;
		}
		vector<string> ve3 = ve1;
		for(i = 0;i < ve1.size();i++) {
			ve1[i][curr] = (1 - (ve1[i][curr] - 48) ) + 48;
		}
		sort(ve1.begin(), ve1.end());
		if(ve1 == ve2) {
			return mov + 1;
		}
		else {
			ll mi = INT_MAX;
			for(i = curr + 1;i < ve1[0].length();i++) {
				mi = min(mi, min(solve(ve1, ve2, i, mov+ 1), solve(ve3, ve2, i, mov)));
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
	for(i = 1; i <= T;i++) {
		ll N, L;
		ll j;
		S(N);
		S(L);
		vector <string> ve1,ve2;
		for(j = 0;j < N;j++) {
			string s;
			cin>>s;
			ve1.push_back(s);
		}
		for(j = 0;j < N;j++) {
			string s;
			cin>>s;
			ve2.push_back(s);
		}
		sort(ve1.begin(), ve1.end());
		sort(ve2.begin(), ve2.end());
		ll h = solve(ve1, ve2, 0,0);
		if(h !=INT_MAX) {
			printf("Case #%lld: %lld\n", i, h);
		}
		else {
			printf("Case #%lld: NOT POSSIBLE\n", i);
		}
		
	}
}


