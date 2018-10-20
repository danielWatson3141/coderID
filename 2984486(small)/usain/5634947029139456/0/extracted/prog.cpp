#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>

using namespace std;

#define MAXINT	1000

char a[150][40], b[150][40];

int check(int n, int l) {
	int u[150];
	for (int i = 0; i < n; i++)
		u[i] = 0;
	
	for (int i = 0; i < n; i++) {
		int found = 0;
		for (int j = 0; j < n; j++) {
			if (u[j])
				continue;
			int k;
			for (k = 0; k < l; k++)
				if (a[i][k] != b[j][k])
					break;
			
			if (k == l) {
				u[j] = 1;
				found = 1;
				break;
			}
		}
		
		if (!found)
			return 0;
	}
	
	return 1;
}

int change(int n, int p) {
	int m = 0, r = 0;
	for (int i = 0; i < n; i++) {
		if (a[i][p] == '0')
			m++;
		if (b[i][p] == '0')
			r++;
	}
	
	if (m == r) {
		if (m + r == n)
			return 2;
		return 0;
	}
	
	if (m == n - r)
		return 1;
	
	return -1;
}

void make(int n, int p) {
	for (int i = 0; i < n; i++) {
		if (a[i][p] == '0')
			a[i][p] = '1';
		else
			a[i][p] = '0';
	}
}

int doit(int p, int m, int n, int* u, int l) {
	if (p == l) {
		if (check(n, l))
			return m;
		return MAXINT;
	}
	
	int r1, r2;
	if (u[p] == 1) {
		make(n, p);
		r1 = doit(p+1, m+1, n, u, l);
		make(n, p);
		return r1;
	}
	
	if (u[p] == 0)
		return doit(p+1, m, n, u, l);
	
	if (u[p] == 2) {
		r1 = doit(p+1, m, n, u, l);
		make(n, p);
		r2 = doit(p+1, m+1, n, u, l);
		make(n, p);
		if (r1 < r2)
			return r1;
		return r2;
	}
	
	return MAXINT;
}

int solve(int n, int l) {
	int u[40];
	for (int i = 0; i < l; i++) {
		u[i] = change(n, i);
		if (u[i] < 0)
			return -1;
	}
	
	int r = doit(0, 0, n, u, l);
	
	if (r == MAXINT)
		return -1;
	
	return r;
}

int main() {
  ifstream in("A-small-attempt0.in");
  ofstream out("A-small-attempt0.out");
  int tests;
  in >> tests;
  for (int i = 1; i <= tests; i++) {
	  int n, l;
	  in >> n >> l;
	  for (int j = 0; j < n; j++)
		  for (int k = 0; k < l; k++)
			  in >> a[j][k];

	  for (int j = 0; j < n; j++)
		  for (int k = 0; k < l; k++)
			  in >> b[j][k];
	  
	  out << "Case #" << i << ": ";
	  
	  int r = solve(n, l);
	  if (r >= 0)
		  out << r << endl;
	  else
		  out << "NOT POSSIBLE" << endl;
  }
  
  in.close();
  out.close();
  
  return 0;
}