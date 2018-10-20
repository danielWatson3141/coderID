#define MAXN 150
#define MAXL 40

#include <cstdio>
#include <algorithm>
#include <cstring>

int n, l;
long long flow[MAXN];
long long target[MAXN];
int changeRequired[MAXN];
int p[MAXN];

void readArray(long long *array) {
	char c;
	for (int i = 0; i < n; i++) {
		long long curr = 0;
		int read = 0;
		while (read < l) {
			scanf("%c", &c);
			if (c == '0') {
				curr *= 2;
				read++;
			} else if (c == '1') {
				curr = curr * 2 + 1;
				read++;
			}
		}

		array[i] = curr;
		scanf("%c", &c);
	}
}

void change(int k) {
	long long mask = (1 << k);
	for (int i = 0; i < n; i++) {
		flow[i] ^= mask;
	}
}

int changeCount(long long from, long long to) {
	long long mask = from ^ to;
	int count = 0;
	while (mask > 0) {
		count += (mask & 1);
		mask >>= 1;
	}
	return count;
}

void swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

void qsort(int i, int j) {
	int l = i, r = j, mid = changeRequired[(i + j) / 2];
	do {
		while (changeRequired[i] < mid) i++;
		while (changeRequired[j] > mid) j--;
		if (i <= j) {
			swap(changeRequired + i, changeRequired + j);
			swap(p + i, p + j);
			i++;
			j--;
		}
	} while (i < j);

	if (i < r) qsort(i, r);
	if (l < j) qsort(l, j);
}

bool isValid(int k) {
	long long mask = 1;
	for (int i = 0; i < l; i++) {
		mask = (1 << i);
		if ((flow[k] & mask) != (target[0] & mask)) {
			change(i);
		}
	}

	long long temp[MAXN];
	for (int i = 0; i < n; i++) temp[i] = flow[i];
	std::sort(temp, temp + n);

	for (int i = 0; i < n; i++) {
		if (temp[i] != target[i]) {
			return false;
		}
	}

	return true;
}

int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);
	for (int q = 1; q <= t; q++) {		
		scanf("%d %d", &n, &l);
		readArray(flow);
		readArray(target);
		
		std::sort(target, target + n);

		for (int i = 0; i < n; i++) {
			changeRequired[i] = changeCount(flow[i], target[0]);
			p[i] = i;
		}
		
		qsort(0, n - 1);
		
		bool success = false;
		for (int i = 0; i < n; i++) {
			if (isValid(p[i])) {
				printf("Case #%d: %d\n", q, changeRequired[i]);
				success = true;
				break;
			}
		}

		if (success == false) {
			printf("Case #%d: NOT POSSIBLE\n", q);
		}
	} 

	return 0;
}