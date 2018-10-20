#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <bitset>
#include <numeric>
#include <ctime>
#include <cassert>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;
typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define N 1010

double S0 = 0, S1 = 0; 
int a[N], n; 

void shuf(int n) {
	for (int i = 0; i < n; i ++) 
		a[i] = i; 
	for (int i = 0; i < n; i ++) {
		int j = rand()%n; 
		swap(a[i], a[j]); 
	}
	for (int i = 0; i < n; i ++) 
		if (a[i] == i) S0 += 1; else 
		if (a[i] == i+1) S1 += 1; 
}

double dis(double x, double y) {
	return x*x + y*y; 
}

int main() {
	/*
	int n = 1000; 
	int M = 1000000; 
	for (int i = 0; i < M; i ++) shuf(n); 
	S0 /= M; S1 /= M; 
	printf ("%.9lf %.9lf\n", S0, S1); 
	printf ("%.9lf %.9lf\n", (double)1, (double)(n-1)/n); 
	return 0; 
	*/
	double S0b = 0.894362; 
	double S1b = 1.262892; 
	double S0g = 1; 
	double S1g = 0.999; 
	int _; cin >> _; 
	for (int __ = 1; __ <= _; __ ++) {
		cin >> n; 
		for (int i = 0; i < n; i ++) 
			cin >> a[i]; 
		double S0 = 0, S1 = 0; 
		for (int i = 0; i < n; i ++)
			if (a[i] == i) S0 += 1; else
			if (a[i] == i+1) S1 += 1; 
		bool F = dis(S0b-S0, S1b-S1) < dis(S0g-S0, S1g-S1); 
		printf ("Case #%d: ", __); 
		if (F) puts ("BAD"); else puts ("GOOD"); 
	}
	return 0; 
}