#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long toBinary(string &s, int length) {
	long r = 0;
	for (int i=0; i<length; i++) {
		if (s[i]=='1') r = (r<<1) | 1;
		else r = r<<1;
	}
	return r;
}

int inPlaceIntersect(long *a, long *b, int lengthA, int lengthB) {
	int i=0, j=0, k=0;
	while (i<lengthA && j<lengthB) {
		if (a[i] < b[j]) i++;
		else if (a[i] > b[j]) j++;
		else {
			a[k] = a[i];
			k++;
			i++;
			j++;
		}
	}
	return k;	//new length
}

int hamming(long a) {
	int c=0;
	for (int i=0; i<64; i++) if ((a>>i)&1) c++;
	return c;
}




int main(void) {
	int t, testCases;
	cin >> testCases;
	
	int i, j;
	int N, L;
	string s;
	long a[256], b[256];
	long permute[256][256];
	int intersectLength, minCost, cost;
	
	for (t=1; t<=testCases; t++) {
		printf("Case #%d: ", t);
		cin >> N >> L;
		for (i=0; i<N; i++) {
			cin >> s;
			a[i] = toBinary(s, L);
		//	printf("a[%d] is %lx\n", i, a[i]);
		}
		for (i=0; i<N; i++) {
			cin >> s;
			b[i] = toBinary(s, L);
		//	printf("b[%d] is %lx\n", i, b[i]);
		}
		for (i=0; i<N; i++) for (j=0; j<N; j++) {
			permute[i][j] = a[i] ^ b[j];
		}
		for (i=0; i<N; i++) sort(&(permute[i][0]), &(permute[i][N]));
		/*
		for (i=0; i<N; i++) {
			for (j=0; j<N; j++) {
				printf("permute[%d][%d] %lx\n", i, j, permute[i][j]);
			}
			printf("\n");
		}
	//	*/
		
		intersectLength = N;
		for (i=1; i<N; i++) {
			intersectLength = inPlaceIntersect(&(permute[i][0]), &(permute[i-1][0]), N, intersectLength);
		//	for (j=0; j<intersectLength; j++) printf("%lx ", permute[i][j]);
		//	printf("\n");
		}
		
	//	printf("intersectLength %d\n", intersectLength);
	//	for (i=0; i<intersectLength; i++) printf("%lx\n", permute[N-1][i]);
		
		if (intersectLength==0) printf("NOT POSSIBLE");
		else {
			minCost = hamming(permute[N-1][0]);
			for (j=1; j<intersectLength; j++) {
				cost = hamming(permute[N-1][j]);
				if (cost < minCost) minCost = cost;
			}
			printf("%d", minCost);
		}
		
		printf("\n");
	}
	
	
	return 0;
}