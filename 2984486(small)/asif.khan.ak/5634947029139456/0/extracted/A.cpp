#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<string>
#include<queue>
#include<set>
#include<map>
#include<cmath>
using namespace std;

#define MAX 12
int test_case;
int N, L;
string s;

int outLet[ MAX ], device[ MAX ];

int getIntValue(string in) {
	int ret = 0;
	int cur = 1;
	int l = in.size();
	for(int i = l - 1; i >= 0; i --) {
		if(in[ i ] == '1') ret += (cur);
		cur *= 2;
	}

	return ret;
}

int getPositiveBits(int n) {
	int ans = 0;
	while(n > 0 ) {
		if(n % 2 == 1) ans ++;
		n /= 2;
	}

	return ans;
}

int isOkay(int mask) {
	int i, j, k;
	int tempOut[ MAX ], tempDevice[ MAX ];
	for(i = 0; i < N; i ++)  {
		tempOut[ i ] = outLet[ i ];
		tempDevice[ i ] = device[ i ];
	}

	for(i = 0; i < L; i ++) {
		if(mask & (1 << i)) {
			for(j = 0; j < N; j ++) tempOut[ j ] ^= ( 1 << i);
		}
	}

	sort(tempOut, tempOut + N);
	sort(tempDevice, tempDevice + N);

	bool isok = true;
	for(i = 0; i < N; i ++) {
		if(tempOut[ i ] != tempDevice[ i ]) {
			isok = false;
			break;
		}
	}

	return isok;

}


int main() {
	freopen("A-small-attempt1.in", "r", stdin);
	freopen("outputA.txt", "w", stdout);
	scanf("%d", &test_case);
	for(int caseId = 1; caseId <= test_case; caseId ++) {
		scanf("%d %d", &N, &L);
		for(int i = 0; i < N; i ++) {
			cin >> s;
			int value = getIntValue(s);
			outLet[ i ] = value;
		}

		for(int j = 0; j < N; j ++) {
			cin >> s;
			int val = getIntValue(s);
			device[ j ] = val;
		}


		int ans = -1;
		for(int k = 0; k < ( 1 << L ); k ++) {
			if(isOkay(k)) {
				int temp = getPositiveBits(k);
				if(temp < ans || ans == -1) ans = temp;
			}
		}

		if(ans == -1) {
			printf("Case #%d: NOT POSSIBLE\n", caseId);
		} else {
			printf("Case #%d: %d\n", caseId, ans);
		}
	}
	return 0;
}