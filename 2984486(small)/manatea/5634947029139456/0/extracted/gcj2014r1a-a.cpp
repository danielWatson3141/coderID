#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cstdio>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int N, L;
const int MAX_N = 200;
ll in[MAX_N];
ll out[MAX_N];
ll intmp[MAX_N];
// int inbits[40];
// int outbits[40];

int bitCount(int i) {
	i = i - ((i >> 1) & 0x55555555);
	i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
	i = (i + (i >> 4)) & 0x0f0f0f0f;
	i = i + (i >> 8);
	i = i + (i >> 16);
	return i & 0x3f;
}

void solve()
{
	memset(in, 0, sizeof(in));
	memset(out, 0, sizeof(out));
	char tmp[64];
	char nch[2] = {};
	scanf("%d %d", &N, &L);
	for (int i = 0; i < N; ++i) {
		scanf("%s", tmp);
		ll num = 0;
		for (int j = 0; j < L; ++j) {
			nch[0] = tmp[L - 1 - j];
			num = num | ((ll)atoi(nch) << j);
		}
		in[i] = num;
	}
	for (int i = 0; i < N; ++i) {
		scanf("%s", tmp);
		ll num = 0;
		for (int j = 0; j < L; ++j) {
			nch[0] = tmp[L - 1 - j];
			num = num | ((ll)atoi(nch) << j);
		}
		out[i] = num;
	}

	int mask = (1 << L) - 1;
	sort(out, out + N);
	int res = INT_MAX;
	for (int flip = 0; flip <= mask; ++flip) {
		for (int i = 0; i < N; ++i) {
			intmp[i] = in[i] ^ flip;
		}
		sort(intmp, intmp + N);
		if (flip == 0) {
			for (int i = 0; i < N; ++i) {
				//cout << intmp[i] <<" " << out[i] << endl;
			}
		}

		if (memcmp(intmp, out, sizeof(ll) * N) == 0) {
			res = min(res, bitCount(flip));
		}
	}

	if (res == INT_MAX) {
		printf("NOT POSSIBLE");
	} else {
		printf("%d", res);
	}
    return;
}

int main()
{
    int nCases = 0;
    scanf("%d", &nCases);
    for (int i = 1; i <= nCases; ++i) {
        cout << "Case #" << i << ": ";
        solve();
        cout << endl;
    }
}
