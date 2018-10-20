/*
 * Author    : ben
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <functional>
#include <numeric>
#include <cctype>
using namespace std;
typedef long long LL;
const int MAXN = 155;
const int MAX_LEN = 55;
LL origin[MAXN], des[MAXN], temp_seq[MAXN];
int seq_num, seq_len;

LL convert(const char *st) {
	LL ret = 0;
	int len = strlen(st);
	for (int i = 0; i < len; i++) {
		ret <<= 1;
		if (st[i] == '1') {
			ret += 1;
		}
	}
	return ret;
}

void input() {
	char temp[MAXN];
	scanf("%d%d", &seq_num, &seq_len);
	for (int i = 0; i < seq_num; i++) {
		scanf("%s", temp);
		origin[i] = convert(temp);
	}
	for (int i = 0; i < seq_num; i++) {
		scanf("%s", temp);
		des[i] = convert(temp);
	}
}

int count_bit(long long a) {
	int ret = 0;
	while (a) {
		if (a & 1) {
			ret++;
		}
		a >>= 1;
	}
	return ret;
}

int work() {
	int ret = seq_len + 1;
	for (int i = 0; i < seq_num; i++) {
		long long key = des[0] ^ origin[i];
		for (int j = 0; j < seq_num; j++) {
			temp_seq[j] = origin[j] ^ key;
		}
		sort(temp_seq, temp_seq + seq_num);
		if (equal(temp_seq, temp_seq + seq_num, des)) {
			ret = min(ret, count_bit(key));
		}
	}
	if (ret == seq_len + 1) {
		return -1;
	}
	return ret;
}

int main() {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		printf("Case #%d: ", t);
		input();
		sort(des, des + seq_num);
		int ans = work();
		if (ans == -1) {
			printf("NOT POSSIBLE\n");
		} else {
			printf("%d\n", ans);
		}
	}
	return 0;
}

