/*************************************************************************
    > File Name: a.cpp
    > Author: lax
    > Mail: xingkungao@gmail.com
    > Created Time: Sat 26 Apr 2014 09:04:22 AM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAXN = 150;
const int MAXL = 40;
int t;
int n;
int l;
//char A[MAXN][MAXL], B[MAXN][MAXL];
long long int A[MAXN], B[MAXN];
long long int C[MAXN]; 

int compare(const void* a, const void* b) {
	return *(long long*)a - *(long long*)b;
}

int main() {
	int ans;
	int flag;
	char str[41];
	char *endp = NULL;
	int kase = 0;
	scanf("%d", &t);
	while (kase++ < t) {
		ans = (1 << 30);
		scanf("%d", &n);
		scanf("%d", &l);
		for (int i = 0; i < n; i++)  {
			scanf("%s", str);
			A[i] = strtoull(str, &endp, 2);
		}

		for (int i = 0; i < n; i++)  {
			scanf("%s", str);
			B[i] = strtoul(str, &endp, 2);
		}
		qsort(B, n, sizeof(long long  int), compare);

		for (long long i = 0; i < ((1 << l)); i++) {
			memcpy(C, A, sizeof(long long) * n);
			for (int j = 0; j < n; j++)
				C[j] = C[j] ^ i;
			qsort(C, n, sizeof(long long  int), compare);
			int k;
			for (k = 0; k < n; k++) {
				if (C[k] != B[k])
					break;
			}
			int cnt;
			if (k == n) {
				cnt = 0;				
				long long h = i;
				while (h > 0) {
					cnt++;
					h = h &( h -1); 
				}
				ans = ans > cnt	? cnt : ans;
			}

		}
		if (ans == (1 << 30)) {
			printf("Case #%d: NOT POSSIBLE\n", kase);
		}else
			printf("Case #%d: %d\n", kase, ans);
	}
	return 0;
}


			


			






