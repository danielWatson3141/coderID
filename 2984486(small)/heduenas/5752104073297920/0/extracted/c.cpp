#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<stack>
#include<list>
#include<queue>
#define print(Z,a,b) for (int __z = a; __z < b; __z ++) cout << Z[__z] << " ";
#define scan(Z,a,b) for (int __z = a; __z < b; __z ++) cin >> Z[__z];
#define bit(_z) (1ll << _z)
using namespace std;

int t;
int n;
int P[1000];
int D[1000][1000];

int randint(int a, int b) {
	return (rand() % (b-a+1)) + a;
}

int main () {
	srand(time(NULL));
	
	n = 1000;
	
		int it = 0;
		int mag_const = 100000;
		while (it < mag_const) {
			it ++;
			for (int i = 0; i < n; i ++)
				P[i] = i;
	
			for (int i = 0; i < n; i ++)
				swap(P[i], P[randint(0, n-1)]);
			
			for (int i = 0; i < n; i ++)
				D[P[i]][i] ++;
		}

	cin >> t;
	int caze = 0;
	
	while (t --) {
		caze ++;
		
		
		cin >> n;
		
		double p1 = 1.0, p2 = 1.0;
		for (int i = 0, dig; i < n; i ++) {
			cin >> dig;
			p1 *= (double)(D[dig][i]) / (double)(mag_const);
			p2 *= 1.0 / (double)(i + 1.0);
		}
		
		cout << "Case #" << caze << ": ";
		
		if (p1 > p2)
			cout << "BAD" << endl;
		else
			cout << "GOOD" << endl;
		
	}
	
	return 0;
}  	
