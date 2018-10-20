#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

const unsigned MaxN = 155, inf = ~0u >> 1;

unsigned T, N, L, cs, pos[MaxN], ans;
string a[MaxN], b[MaxN], c[MaxN];

void check(unsigned x, unsigned y) {
	unsigned tmp = 0;
	for(unsigned i = 0; i < L; ++i) {
		pos[i] = a[x][i] != b[y][i];
		tmp += pos[i];
	}
	for(unsigned i = 0; i < N; ++i) {
		c[i] = string();
		for(unsigned j = 0; j < L; ++j) {
			c[i] += pos[j] ? (a[i][j] == '0' ? '1' : '0') : a[i][j];
		}
	}
	sort(c, c + N);
	for(unsigned i = 0; i < N; ++i) {
		if(c[i] != b[i]) {
			return;
		}
	}
	ans = tmp < ans ? tmp : ans;
}

int main() {
	freopen("A-large.in", "r", stdin);
	freopen("out", "w", stdout);
	cin >> T;
	while(T--) {
		cin >> N >> L;
		ans = inf;
		for(unsigned i = 0; i < N; ++i) {
			cin >> a[i];
		}
		for(unsigned i = 0; i < N; ++i) {
			cin >> b[i];
		}
		sort(b, b + N);
		for(unsigned i = 0; i < N; ++i) {
			for(unsigned j = 0; j < N; ++j) {
				check(i, j);
			}
		}
		cout << "Case #" << ++cs << ": ";
		if(ans != inf) {
			cout << ans;
		}
		else {
			cout << "NOT POSSIBLE";
		}
		cout << endl;
		std::cerr<<cs<<endl;
	}
}
