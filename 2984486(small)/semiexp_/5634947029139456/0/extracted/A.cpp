#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;
typedef long long i64;

int N, L;
i64 outlet[160], plug[160];

i64 input()
{
	char in[50];
	scanf("%s", in);
	i64 ret = 0;
	for(int i=0;in[i];i++) {
		ret *= 2;
		ret += in[i] - '0';
	}
	return ret;
}

bool test(i64 flip)
{
	vector<int> os;
	for(int i = 0; i < N; i++) os.push_back(outlet[i] ^ flip);

	sort(os.begin(), os.end());

	for(int i = 0; i < os.size(); i++) if(os[i] != plug[i]) return false;

	return true;
}

int main()
{
	int T;
	scanf("%d", &T);

	for(int t = 0; t++ < T; ) {
		scanf("%d%d", &N, &L);

		for(int i = 0; i < N; i++) outlet[i] = input();
		for(int i = 0; i < N; i++) plug[i] = input();

		int ret = 1000;

		sort(plug, plug + N);

		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				i64 flip = outlet[i] ^ plug[j];

				if(test(flip)){
					int tmp = 0;
					for(int k = 0; k < L; k++) if((flip >> k) & 1) ++tmp;

					ret = min(ret, tmp);
				}

			}
		}

		if(ret == 1000) printf("Case #%d: NOT POSSIBLE\n", t);
		else printf("Case #%d: %d\n", t, ret);
	}

	return 0;
}
