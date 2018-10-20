#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <stdint.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;

#define forl(i,a,b) for(int i = a; i < b; ++i)

int main()
{
	int numcases = 0;
	cin >> numcases;
	forl(casei, 0, numcases) {
		int num;
		int cnt = 0;
		cin >> num;
		forl(i, 0, 1000) {
			cin >> num;
			if (num == i) cnt++;
		}
		if (cnt > 0 && cnt <= 4) {
			cout << "Case #" << (casei+1) << ": GOOD" << endl;
		} else {
			cout << "Case #" << (casei+1) << ": BAD" << endl;
		}
	}
	return 0;
}
