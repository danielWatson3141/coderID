#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <set>
#include <map>
#include <vector>

using namespace std;

const int maxN = 1000 + 10;
int A[maxN];

int main() {
	int T;
	cin >> T;
	for (int tt=1; tt<=T; ++tt) {
		int N;
		cin >> N;
		bool flag = false;
		for (int i=0; i<N; ++i) {
			cin >> A[i];
			if (A[i] == i)
				flag = true;
		}
		if (flag)
			cout << "Case #" << tt << ": BAD" << endl;
		else
			cout << "Case #" << tt << ": GOOD" << endl;

	}
	return 0;
}
