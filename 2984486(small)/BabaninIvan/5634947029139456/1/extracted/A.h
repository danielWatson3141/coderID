#include <iostream> 
#include <cstdio> 
#include <set> 
#include <map> 
#include <vector> 
#include <queue> 
#include <stack> 
#include <cmath> 
#include <algorithm> 
#include <cstring> 
#include <bitset> 
#include <ctime> 
#include <sstream>
#include <stack> 
#include <cassert> 
#include <list> 
//#include <unordered_set> 
using namespace std;
typedef long long li;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;

#define mp make_pair 
#define pb push_back 
#define all(s) s.begin(), s.end() 
void solve();

#define NAME "changemeplease"
int main() {
#ifdef YA 
	cerr << NAME << endl;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout); 
	clock_t start = clock();
#else 
	freopen("input.txt", "r", stdin); 
	freopen("output.txt", "w", stdout); 
#endif 
	ios_base::sync_with_stdio(false);
	cout << fixed;
	cout.precision(10);
	int t = 1;
	cin >> t;	 
	for (int i = 1; i <= t; ++i) {
		cout << "Case #" << i << ": ";
		solve();
	}

#ifdef YA 
	//cout << "\n\n\nTime:" << ((clock() - start) / 1.0 / CLOCKS_PER_SEC);
#endif 
	return 0;
}

int n, l;
vector <string> a;
vector <string> b;
vector <bool> c;	

bool check() {
	vector <string> cur = a;
	for (int i = 0; i < cur.size(); ++i) {
		for (int j = 0; j < l; ++j) {
			if (c[j]) {
				if (cur[i][j] == '0')
					cur[i][j] = '1';
				else {
					cur[i][j] = '0';
				}
			}
		}
	}
	sort(cur.begin(), cur.end());
	for (int i = 0; i < n; ++i) {
		if (cur[i] != b[i])
			return false;
	}
	return true;
}

void solve() {
	cin >> n >> l;
	a.resize(n);
	b.resize(n);
	
	c.resize(l);

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}
	sort(b.begin(), b.end());
	int ans = -1;
	for (int i = 0; i < n; ++i) {
		int sum = 0;
		for (int j = 0; j < l; ++j) {
			if (a[i][j] != b[0][j]) {
				++sum;
				c[j] = true;
			}
			else {
				c[j] = false;
			}
		}
		if (ans != -1 && ans <= sum)
			continue;
		if (check()) {
			ans = sum;
		}
	}
	if (ans == -1) {
		cout << "NOT POSSIBLE\n";
	}
	else {
		cout << ans << endl;
	}
}