#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
#define N 1000
#define STOP 50000
#define AVLEN 20
typedef long long ll;
typedef long double ld;

ll invc = 0;
int bit[1234], ar[1234], cnt[1234][1234];
ld avr[1234][1234];
int qry(int at) {
	int res = 0;
	while (at) {
		res += bit[at];
		at -= (at & -at);
	}
	return res;
}
void upd(int at) {
	while (at <= N) {
		bit[at]++;
		at += (at & -at);
	}
}
int main() {
	for (int t = 0; t < STOP; t++) {
		ll inv = 0;
		for (int i = 0; i < N; i++) ar[i] = i;
		for (int i = 0; i <= N; i++) bit[i] = 0;
		for (int i = 0; i < N; i++) {
			int swpos = random()%N;
			swap(ar[i], ar[swpos]);
		}
		//if (!t) for (int i = 0; i < N; i++) printf("%d ", ar[i]);
		for (int i = 0; i < N; i++) {
			//inv += qry(ar[i]+1);
			//upd(ar[i]+1);
			cnt[ar[i]][i]++;
		}
		//invc += inv;
		//printf("%d\n", inv);
		//if (!(t%100)) printf("%d %Lf\n", t, ((ld)invc)/((ld)t));
	}
	for (int i = 0; i < N; i++) for (int j = 1; j < N; j++) cnt[i][j] += cnt[i][j-1];
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) avr[i][j] = ((ld)(cnt[i][min(N-1, j+AVLEN)] - cnt[i][max(0, j-AVLEN)]))/((ld)(min(N-1, j+AVLEN)-max(0, j-AVLEN)+1));
	FILE *out = fopen("dump.txt", "w");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) fprintf(out, "%Lf ", avr[i][j]);
		putc('\n', out);
	}

	return 0;
}