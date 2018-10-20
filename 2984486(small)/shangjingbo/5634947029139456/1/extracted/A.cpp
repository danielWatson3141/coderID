#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 200;

long long src[maxn], tar[maxn], temp[maxn];

void load(long long &x)
{
	char s[100];
	scanf("%s", s);
	x = 0;
	for (int i = 0; s[i]; ++ i) {
		x = x * 2 + s[i] - '0';
	}
}

int solve()
{
	int n, L;
	scanf("%d%d", &n, &L);
	for (int i = 0; i < n; ++ i) {
		load(src[i]);
	}
	for (int i = 0; i < n; ++ i) {
		load(tar[i]);
	}
	
	sort(tar, tar + n);
	
	int answer = -1;
	for (int i = 0; i < n; ++ i) {
		for (int j = 0; j < n; ++ j) {
			long long flip = src[i] ^ tar[j];
			
			for (int k = 0; k < n; ++ k) {
				temp[k] = src[k] ^ flip;
			}
			sort(temp, temp + n);
			bool same = true;
			for (int k = 0; k < n; ++ k) {
				if (temp[k] != tar[k]) {
					same = false;
					break;
				}
			}
			if (same) {
				int n = __builtin_popcountll(flip);
				if (answer == -1 || answer > n) {
					answer = n;
				}
			}
		}
	}
	return answer;
}

int main()
{
	int tests, test = 1;
	for (scanf("%d", &tests); test <= tests; ++ test) {
		int answer = solve();
		if (answer == -1) {
			printf("Case #%d: NOT POSSIBLE\n", test);
		} else {
			printf("Case #%d: %d\n", test, answer);
		}
	}
	return 0;
}
