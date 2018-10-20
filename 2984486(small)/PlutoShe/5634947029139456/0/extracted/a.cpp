#include <cstdio>
#include <iostream>
#include <string.h>
#include <cstring>
#include <algorithm>
using namespace std;
int n, m, testnum, c;
std::string s1[200],s2[200],s3[200];
bool change[200];

int main() {
	freopen("A-small-attempt1.in.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &testnum);
	for (int test = 1; test <= testnum; test++) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
			std::cin >> s1[i];
		for (int i = 1; i <= n; i++) {
			std::cin >> s2[i];
			s3[i] = s1[i];
		}
		sort(s2 + 1, s2 + 1 + n);
		int ans = m + 1;
		for (int i = 1; i <= n; i++) {
			int cost = 0;
			for (int j = 0; j < m; j++) {
				if (s2[1][j] != s1[i][j]) { change[j] = true; cost++; } else { change[j] = false;}
			}

			//	s3[i] = s1[i]
			for (int j = 1; j <= n; j++) {
				s3[j] = "";
				for (int k = 0; k < m; k++)
					if (!change[k]) {
						s3[j] = s3[j] + s1[j][k];
						///printf("ww%cww", s1[j][k]);
					}
					else {
						if (s1[j][k] == '1')
							s3[j] = s3[j] + '0';
						else s3[j] = s3[j] + '1';
					}
			}
			sort(s3 + 1, s3 + 1 + n);
			int aval = true;
			/*for (int j = 1; j <= n; j++)
				printf("%s\n", s3[j].c_str());
			printf("%d\n\n",cost);*/
			for (int j = 1; j <= n; j++)
				if (s3[j]!=s2[j]) { aval = false; break;}
			//printf("%d")
			if (aval) {
				if (cost < ans) ans = cost;
			}
		}
		if (ans == m + 1) 
			printf("Case #%d: NOT POSSIBLE\n",test);
		else
			printf("Case #%d: %d\n", test, ans);
	}
	return 0;
}