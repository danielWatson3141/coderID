#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<string>
using namespace std;

int main()
{
	//freopen("in.txt", "r", stdin);
	freopen("A-small-attempt0.in", "r", stdin);
	//freopen("A-small-attempt1.in", "r", stdin);
	//freopen("A-small-attempt2.in", "r", stdin);
	//freopen("A-large.in", "r", stdin);
	freopen("A.out", "w", stdout);

	int T;
	int N, L;
	char outlet[200][50], flow[200][50], str[200][50];
	scanf("%d", &T);
	for(int Case = 1; Case <= T; Case++)
	{
		scanf("%d%d", &N, &L);
		for(int i = 0; i < N; i++)
		{
			scanf("%s", &outlet[i]);
		}
		for(int i = 0; i < N; i++)
		{
			scanf("%s", &flow[i]);
		}
		int ans = 1000000;
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++) strcpy(str[j], outlet[j]);
			int t = 0;
			for(int j = 0; j < L; j++)
			{
				if(outlet[0][j] != flow[i][j])
				{
					t++;
					for(int k = 1; k < N; k++)
					{
						if(str[k][j] == '0') str[k][j] = '1';
						else str[k][j] = '0';
					}
				}
			}
			int ct = 0;
			for(int j = 1; j < N; j++)
			{
				for(int k = 0; k < N; k++)
				{
					if(k == i) continue;
					if(strcmp(str[j], flow[k]) == 0) ct++;
				}
			}
			if(ct == N - 1 && t < ans)
			{
				ans = t;
			}
		}
		printf("Case #%d: ", Case);
		if(ans != 1000000) printf("%d\n", ans);
		else printf("NOT POSSIBLE\n");
	}
	return 0;
}
