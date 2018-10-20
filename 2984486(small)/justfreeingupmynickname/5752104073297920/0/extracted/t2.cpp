#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
#define N 1000
typedef long long ll;
typedef long double ld;

ll invc = 0;
int bit[1234], ar[1234];

int main() {
	freopen("c.in", "w", stdout);
	printf("120\n");
	for (int t = 0; t < 120; t++) {
		puts("1000");
		ll inv = 0;
		for (int i = 0; i < N; i++) ar[i] = i;
		for (int i = 0; i <= N; i++) bit[i] = 0;
		for (int i = 0; i < N; i++) {
			int swpos = (random()%(N-i))+i;
			swap(ar[i], ar[swpos]);
		}
		for (int i = 0; i < N; i++) printf("%d%c", ar[i], i==N-1 ? '\n' : ' ');
	}

	return 0;
}