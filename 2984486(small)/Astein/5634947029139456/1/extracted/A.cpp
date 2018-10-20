#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);
	char s[50];

	for (int cn = 1; cn <= T; ++cn)
	{
		int N, L;
		scanf("%d%d", &N, &L);
		
		vector<string> va, vb;

		for (int i = 0; i < N; ++i) {
			scanf("%s", s);
			va.push_back(s);
		}
		for (int i = 0; i < N; ++i) {
			scanf("%s", s);
			vb.push_back(s);
		}

		int ret = L + 1;
		vector<string> vc(N);
		sort(va.begin(), va.end());
		sort(vb.begin(), vb.end());

		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
			{
				// match va[i] = vb[j]
				int cnt = 0;
				for (int k = 0; k < L; ++k)
					if (va[i][k] != vb[j][k]) cnt++;
				if (ret <= cnt) continue;

				for (int k = 0; k < N; ++k)
				{
					vc[k] = "";
					for (int l = 0; l < L; ++l)
					{
						if (va[i][l] == vb[j][l])
						{
							vc[k] += vb[k][l];
						}
						else
						{
							vc[k] += '0' + '1' - vb[k][l];
						}
					}
				}
				sort(vc.begin(), vc.end());
				if (va == vc)
				{
					ret = cnt;
				}
			}
		printf("Case #%d: ", cn);
		if (ret > L) printf("NOT POSSIBLE\n"); else printf("%d\n", ret);
	}
} 