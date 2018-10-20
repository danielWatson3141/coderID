#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <map>
#include <algorithm>
#include <ctime>
#include <cmath>
using namespace std;

#define FOR(i,a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); ++ i)

//#define LOCAL

const int maxT = 120;
const int maxn = 1000;

int a[maxT][maxn], answer[maxT], truth[maxT];

void generate(int a[][maxn], int truth[], int tests, int n)
{
	for (int test = 0; test < tests; ++ test) {
		for (int i = 0; i < n; ++ i) {
			a[test][i] = i;
		}
		int type = rand() & 1;
		for (int i = 0; i < n; ++ i) {
			int j;
			if (type == 0) {
				j = rand() % n;
			} else {
				j = rand() % (n - i) + i;
			}
			swap(a[test][i], a[test][j]);
		}
		truth[test] = type;
	}
}

int main()
{
	srand(time(0));
	
	int tests, test = 1;
	int n = maxn;
#ifdef LOCAL
	tests = 120;
	generate(a, truth, tests, n);
#else
	for (scanf("%d", &tests); test <= tests; ++ test) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++ i) {
			scanf("%d", &a[test - 1][i]);
		}
	}
#endif

	//generate(records, type, maxInstance, n);
	vector< pair<double, int> > order;
	for (int i = 0; i < tests; ++ i) {
		int sum = 0;
		for (int j = 0; j < n; ++ j) {
			sum += (a[i][j] - j) > 10;
		}
		//order.push_back(make_pair(sum, i));
		answer[i] = sum > 501;
	}
	/*sort(order.begin(), order.end());
	for (int i = 0; i < tests; ++ i) {
fprintf(stderr, "%lf %d\n", order[i].first, truth[order[i].second]);
		answer[order[i].second] = i + i < tests;
	}*/
#ifdef LOCAL
	int same = 0;
	for (int i = 0; i < tests; ++ i) {
		same += answer[i] == truth[i];
	}
	same = max(same, tests - same);
	printf("correct = %d\n", same);
#else
	for (int i = 0; i < tests; ++ i) {
		printf("Case #%d: ", i + 1);
		if (answer[i] == 0) {
			puts("GOOD");
		} else {
			puts("BAD");
		}
	}
#endif
	
	return 0;
}
