#include <bits/stdc++.h>
using namespace std;
int N, L, TC, ans;
long long power[200], phone[200];
char str[200];
bitset<200> flip, done;
void brute (int K) {
	if (K == -1) {
		int num = 0;
		for (int i = 0; i < L; ++i) {
			num += flip[i];
		}
		ans = min(num, ans);
		return;
	}
	if (done[K]) {
		if (flip[K]) {
			for (int i = 0; i < N; ++i) power[i] ^= (1ll<<K);
			sort(power, power+N);
		}
		bool pass = 1;
		//printf("Level %d (%d):\n", K, (int) flip[K]);
		for (int i = 0; i < N && pass; ++i) {
			//printf("%lld vs %lld\n", (power[i]&(1ll<<K)), (phone[i]&(1ll<<K)));
			if ((power[i]&(1ll<<K)) != (phone[i]&(1ll<<K))) pass = 0;
		}
		if (pass) brute(K-1);
		if (flip[K]) {
			for (int i = 0; i < N; ++i) power[i] ^= (1ll<<K);
			sort(power, power+N);
		}
	}
	else {
		done[K] = 1;
		flip[K] = 0;
		brute(K);
		flip[K] = 1;
		brute(K);
		done[K] = 0;
	}
}
int main () {
	freopen("charging.in", "r", stdin);
	freopen("charging.out", "w", stdout);
	scanf("%d", &TC);
	for (int T = 1; T <= TC; ++T) {
		scanf("%d%d", &N, &L);
		for (int i = 0; i < N; ++i) {
			scanf("%s", str);
			power[i] = 0;
			for (int j = 0; j < L; ++j) {
				if (str[j] == '1') power[i] += 1ll<<(L-j-1);
			}
		}
		for (int i = 0; i < N; ++i) {
			scanf("%s", str);
			phone[i] = 0;
			for (int j = 0; j < L; ++j) {
				if (str[j] == '1') phone[i] += 1ll<<(L-j-1);
			}
		}
		sort(power, power+N);
		sort(phone, phone+N);
		flip.reset();
		done.reset();
		done.flip();
		bool dead = 0;
		for (int k = 0; k < L && !dead; ++k) {
			int a = 0;
			for (int i = 0; i < N; ++i) {
				if (power[i]&(1ll<<k)) ++a;
				else --a;
			}
			int b = 0;
			for (int i = 0; i < N; ++i) {
				if (phone[i]&(1ll<<k)) ++b;
				else --b;
			}
			if (a == 0 && b == 0) done[k] = 0;
			if (a == b) continue;
			if (a != -b) dead = 1;
			else flip[k] = 1;
		}
		if (dead) {
			printf("Case #%d: NOT POSSIBLE\n", T);
			continue;
		}
		ans = 1000000;
		brute(L-1);
		if (ans == 1000000) printf("Case #%d: NOT POSSIBLE\n", T);
		else printf("Case #%d: %d\n", T, ans);
	}
}
