#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MN 155
#define ML 55
#define LL long long

LL origin[MN];
LL des[MN];
LL temp_seq[MN];
int sm, sl;

LL Con(char *st) {
	LL ret = 0;
	int len = (int)strlen(st);
	for (int i = 0; i < len; i++) {
		ret <<= 1;
		if (st[i] == '1') {
			ret += 1;
		}
	}
	return ret;
}

void Input() {
	char temp[MN];
	scanf("%d%d", &sm, &sl);
	for (int i = 0; i < sm; i++) {
		scanf("%s", temp);
		origin[i] = Con(temp);
	}
	for (int i = 0; i < sm; i++) {
		scanf("%s", temp);
		des[i] = Con(temp);
	}
}

int CB(LL a) {
	int ret = 0;
	while (a) {
		if (a & 1)
			ret++;
		a >>= 1;
	}
	return ret;
}

int work() {
	int ret = sl + 1;
	for (int i = 0; i < sm; i++) {
		LL key = des[0] ^ origin[i];
		for (int j = 0; j < sm; j++) {
			temp_seq[j] = origin[j] ^ key;
		}
		sort(temp_seq, temp_seq + sm);
		if (equal(temp_seq, temp_seq + sm, des)) {
			ret = min(ret, CB(key));
		}
	}
	if (ret == sl + 1)
		return -1;
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("testin.txt", "r", stdin);
	freopen("testout.txt", "w", stdout);
#endif
	int T,cas=1;
	scanf("%d", &T);
	while(T--){
		printf("Case #%d: ", cas++);
		Input();
		sort(des, des + sm);
		int ans = work();
		if (ans == -1)
			printf("NOT POSSIBLE\n");
		else
			printf("%d\n", ans);
	}
	return 0;
}
