#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

#define sz(v) int(v.size())
#define endl '\n'
typedef long long ll;
typedef pair<int,int> pii;

const int MAXn = 1005;
int a[MAXn];
int n;

int gen() {
	int r = rand() % 2;
	for(int i = 0; i < n; i++)
		a[i] = i;
	for(int i = 0; i < n; i++) {
		int x;
		if(r)
			x = rand()%n;
		else
			x = rand()%(n-i) + i;
		swap(a[i], a[x]);
	}
	return r;
}

int inversion() {
	int ret = 0;
	for(int i = 0; i < n; i++)
		for(int j = i+1; j < n; j++)
			ret += (a[i] > a[j]);
	return ret;
}

int solve() {
	if(inversion() <= n*(n-1)/4)
		return 1;
	else
		return 0;
}

int main() {
	ios::sync_with_stdio(false);
	srand(1000920033);
	int T;
	n = 1000;
	cin >> T;
	for(int t = 1; t <= T; t++) {
		cin >> n;
		for(int i = 0; i < n; i++)
			cin >> a[i];
		int r = solve();
		cout << "Case #" << t << ": " << (r==0?"GOOD":"BAD") << endl;
	}
	/*int c = 0;
	int r = gen();
	if(r == solve())
		c++;
	cout << c << "/" << T << "=" << c/double(T)*100 << endl;*/
	return 0;
}
