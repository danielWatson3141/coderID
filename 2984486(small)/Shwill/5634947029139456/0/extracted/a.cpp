#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <map>
#include <set>
#include <iomanip>
#include <climits>
#include <cfloat>
#include <string>
#include <queue>
#include <stack>
#include <sstream>
#include <bitset>
#include <deque>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<double> vd;
typedef pair<double, double> dd;
typedef vector<dd> vdd;
typedef vector<vi> vvi;
typedef unsigned long long ull;
typedef long long ll;
typedef vector<ull> vull;
typedef vector<ll> vll;

int N, L;
vector< bitset<40> > outlets(150);
vector< bitset<40> > attempt(150);
vector< bitset<40> > devices(150);
bitset<40> temp;

bool comp(const bitset<40> &a, const bitset<40> &b) {
	return a.to_ullong() < b.to_ullong();
}

int solve()
{
	ll limit = ((ll)1) << L;
	int best = 41;
	for (ll i = 0; i < limit; i++) {
		temp = i;
		if (temp.count() >= best) continue;
		attempt = outlets;
		for (int j = 0; j < N; j++) {
			attempt[j] ^= temp;
		}
		sort (attempt.begin(), attempt.end(), comp);
		if (attempt == devices)
			best = temp.count();
	}
	return best;
}

int main()
{
	int T; cin >> T;
	for (int caseNum = 1; caseNum <= T; caseNum++) {
		outlets.clear(); devices.clear();
		cin >> N >> L;
		for (int i = 0; i < N; i++) {
			cin >> temp;
			outlets.push_back(temp);
		}
		for (int i = 0; i < N; i++) {
			cin >> temp;
			devices.push_back(temp);
		}
		sort(devices.begin(), devices.end(), comp);
		int solution = solve();
		printf("Case #%i: ", caseNum);
		if (solution == 41)
			printf("NOT POSSIBLE\n");
		else
			printf("%i\n", solution);
	}
	return 0;
}
