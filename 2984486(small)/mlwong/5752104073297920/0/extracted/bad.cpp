#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int cnt[1002][1002] = {};

int a[1002];

double s(int j, int t) {
	j /= 10;
	t /= 10;
	return 10000.0/cnt[j][t];
}

int main() {
	int n = 100;
	srand(time(NULL));
	int T = 1000000;
	while (T--) {
		for (int k=0; k<n; k++) a[k] = k;
		for (int k=0; k<n; k++) {
			int p = rand()%n;
			swap(a[k], a[p]);
		}
		for (int k=0; k<n; k++) {
			//cout << a[k] << " ";
			cnt[k][a[k]] ++;
		}
		//cout << endl;
		
	}
	/*
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cout << cnt[i][j] << " ";
		}
		cout << endl;
	}
	*/
	
	int x, y, t;
	scanf("%d", &x);
	for (int i=1; i<=x; i++) {
		scanf("%d", &y);
		double score=0;
		for (int j=0; j<x; j++) {
			scanf("%d", &t);
			score += s(j,t);
		}
		printf("Case #%d: ", i);
		if (score < 123) printf("BAD\n");
		else printf("GOOD\n");
	}
	return 0;

}
