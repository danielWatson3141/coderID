#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
int main(int argc, char const *argv[])
{
	int T;
	scanf("%d", &T);
	for(int caseNum = 1; caseNum <= T; caseNum++)
	{
		int N, L, ans = 100;
		scanf("%d%d", &N, &L);
		char outlet[150][50], device[150][50];
		for(int i = 0; i < N; i++)
			scanf("%s", outlet[i]);
		for(int i = 0; i < N; i++)
			scanf("%s", device[i]);
		for(int i = 0; i < N; i++)
		{
			vector<int> dif;
			dif.clear();
			for(int j = 0; j < L; j++)
				if(outlet[0][j] != device[i][j])
					dif.push_back(j);
			int k;
			for(k = 1; k < N; k++)
			{
				char tmp[100];
				strcpy(tmp, outlet[k]);
				for(int index : dif)
					tmp[index] = 97 - tmp[index];
				int kk;
				for(kk = 0; kk < N; kk++)
					if(strcmp(tmp, device[kk]) == 0)
						break;
				if(kk == N)
					break;
			}
			if(k == N)
				ans = dif.size() < ans ? dif.size() : ans;
		}
		printf("Case #%d: ", caseNum);
		if(ans <= L)
			printf("%d\n", ans);
		else
			puts("NOT POSSIBLE");
	}
	return 0;
}