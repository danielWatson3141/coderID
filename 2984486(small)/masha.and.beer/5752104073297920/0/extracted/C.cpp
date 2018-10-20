// A.cpp : Defines the entry point for the console application.
//

#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

#define MAXN 1010

int a[MAXN];
int p[100][100];
int n;

double p1[MAXN];
double p2[MAXN];
double pm[MAXN][MAXN];
double n1;
double n11;

void bad2(int q) {
	for(int i=0; i<n; ++i) {
		//for(int j=0; j<n; ++j) p1[i][j] = 0.0;
		p1[i] = 0.0;		
	}
	p1[q] = 1.0;

	for(int k=0; k<n; ++k) {		
		for(int i=0; i<n; ++i) p2[i] = n11 * p1[i] + n1 * p1[k];
		p2[k] = n1; // * (1.0 - p1[k]);	

		for(int i=0; i<n; ++i) {
			p1[i] = p2[i];
			//printf("%.3f ", p1[i]);
		}
		//printf("\n");
	}
	//printf("\n");
	for(int i=0; i<n; ++i) pm[q][i] = p1[i];
}

void bad() {
	for(int i=0; i<n; ++i) a[i] = i;
	for(int i=0; i<n; ++i) {
		int x =  rand() % n;
		swap(a[i], a[x]);
	}

	for(int i=0; i<n; ++i) {
		//printf("%i ", a[i]);
		p[ a[i] ][i]++;
	}
	//printf("\n");
}

void good() {
	for(int i=0; i<n; ++i) a[i] = i;
	for(int i=0; i<n; ++i) {
		int x =  rand() % (n-i);
		swap(a[i], a[i + x]);
	}

	for(int i=0; i<n; ++i) {
		//printf("%i ", a[i]);
		p[ a[i] ][i]++;
	}
	//printf("\n");
}

void init() {
	n1 = 1.0 / n;
	n11 = 1.0 - n1;
	for(int i=0; i<n; ++i) bad2(i);
	//printf("%f\n", pm[1][1]);
}


int main(){
	int tc;
	n = 5;
	//tc = 10000;
	//for(int i=0; i<tc; ++i) bad();

	/*
	for(int i=0; i<n; ++i) {
		for(int j=0; j<n; ++j) printf("%3f ", p[i][j]*1.0/tc);
		printf("\n");
	}
	*/

	//init();
	//bad2(0);

	//return 0;
	freopen("C-small-attempt2.in", "r", stdin);	
	freopen("C-small-attempt2.out", "w", stdout);
	scanf("%i", &tc);
	int lan = 0;
	for(int tt=1; tt<=tc; ++tt) {
		scanf("%i", &n);
		if (n != lan) {
		init();
		lan = n;
		}
		double sum = 0.0;
		for(int i=0; i<n; ++i) {
			scanf("%i", &a[i]);
			//printf("%f\n", pm[ a[i] ][i]);
			sum += pm[a[i]][i];
		}
		//printf("%f\n", sum);
		
		printf("Case #%i: ", tt);
		if (sum > 1.0) printf("BAD\n"); else printf("GOOD\n");
		
	}

	return 0;
}

