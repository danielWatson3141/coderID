#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
#define T 120
#define N 1000
#define STOP 50000
#define AVLEN 20
typedef long long ll;
typedef long double ld;

ll invc = 0;
int bit[1234], ar[1234], cnt[1234][1234];
int main() {
	freopen("c.in", "w", stdout);
	printf("120\n");
	for (int t = 0; t < T; t++) {
		printf("1000\n");
		ll inv = 0;
		for (int i = 0; i < N; i++) ar[i] = i;
		for (int i = 0; i < N; i++) {
			int swpos = random()%N;
			swap(ar[i], ar[swpos]);
		}
		//if (!t) for (int i = 0; i < N; i++) printf("%d ", ar[i]);
		for (int i = 0; i < N; i++) printf("%d%c", ar[i], i==N-1 ? '\n' : ' ');
		//invc += inv;
		//printf("%d\n", inv);
		//if (!(t%100)) printf("%d %Lf\n", t, ((ld)invc)/((ld)t));
	}
	//for (int i = 0; i < N; i++) for (int j = 1; j < N; j++) cnt[i][j] += cnt[i][j-1];
	//for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) avr[i][j] = ((ld)(cnt[i][min(N-1, j+AVLEN)] - cnt[i][max(0, j-AVLEN)]))/((ld)(min(N-1, j+AVLEN)-max(0, j-AVLEN)+1));
	//FILE *out = fopen("dump.txt", "w");

	return 0;
}