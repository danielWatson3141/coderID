#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <ctime>
using namespace std;
const int N = 1000;
vector <int> good(N), bad(N);
vector <int> given(N);

int get_random(int low) {
	return (rand() % (N - low)) + low;
}
void gen_good() {
	for(int i = 0; i < N; ++i) {
		good[i] = i;
	}
	for(int i = 0; i < N; ++i) {
		int k = get_random(i);
		swap(good[i], good[k]);
	}
}

void gen_bad() {
	for(int i = 0; i < N; ++i) {
		bad[i] = i;
	}
	for(int i = 0; i < N; ++i) {
		int k = get_random(0);
		swap(bad[i], bad[k]);
	}
}
int solve() {
	int good_score=0, bad_score=0;
	for(int i = 0; i < 1000; ++i) {
		gen_good();
		gen_bad();
		if(good==given) ++good_score;
		if(bad==given) ++bad_score;
	}
	if(good_score >= bad_score) {
		return 0;
	} else {
		return 1;
	}
}

int main() {
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	srand(time(NULL));
	int T;
	cin >> T;
	for(int t = 0; t < T; ++t) {
		cerr << "testcase " << t << endl;
		int n;
		cin >> n;
		for(int i = 0; i < n; ++i) {
			cin >> given[i];
		}
		int res = solve();
		cout << "Case #" << t + 1 << ": " << (res == 0 ? "GOOD" : "BAD") << endl;
	}
}