/*
 * 1010.cpp
 *
 *  Created on: 2014-4-23
 *      Author: lenovo
 */
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
string s1[200], s2[200], s3[200];
int N, L;
int ans, t;
void ismatch() {
	sort(s3, s3 + N);
	bool r = true;
	int i;
	for (i = 0; i < N; i++) {
		if (s3[i] != s2[i]) {
			r = false;
			break;
		}
	}
	if (r) {
		if (t < ans)
			ans = t;
	}
}
void f(int k) {
	int i;
	for (i = 0; i < N; i++) {
		if (s3[i][k] == '0')
			s3[i][k] = '1';
		else
			s3[i][k] = '0';
	}
}
int main() {
	int T, Case = 0;
	scanf("%d", &T);
	int i, j;
	while (T--) {
		Case++;
		scanf("%d %d", &N, &L);
		for (i = 0; i < N; i++)
			cin >> s1[i];
		for (i = 0; i < N; i++)
			cin >> s2[i];
		ans = L + 1;
		sort(s2, s2 + N);
		for (i = 0; i < (1 << L); i++) {
			for (j = 0; j < N; j++)
				s3[j] = s1[j];
			t = 0;
			for (j = 0; j < L; j++) {
				if (i & (1 << j)) {
					t++;
					f(j);
				}
			}
			ismatch();
		}
		printf("Case #%d: ", Case);
		if (ans < L + 1)
			printf("%d\n", ans);
		else
			printf("NOT POSSIBLE\n");
	}
	return 0;
}
