#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <complex>
#include <cstdio>
#include <vector>
#include <cctype>
#include <string>
#include <ctime>
#include <cmath>
#include <set>
#include <map>

typedef long double LD;
typedef long long LL;

using namespace std;

#define sz(A) (int)(A).size()
#define mp make_pair
#define pb push_back

const int N = 1000;
int a[N];
vector<int> res[2];

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			int elem;
			cin >> elem;
			if (elem > j)
				cnt++;
		}
		if (cnt >= 515)
			printf("Case #%d: BAD\n", i + 1);
		else
			printf("Case #%d: GOOD\n", i + 1);		
	}

	return 0;
}
