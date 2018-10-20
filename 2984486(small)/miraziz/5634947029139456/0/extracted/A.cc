#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_set>
#include <map>
#include <fstream>

#define MAXN 151
#define MAXL 41

using namespace std;

int T, N, L;
int main()
{
	string filename = "A-small-attempt0";
	ifstream fin(filename + ".in");
	FILE *fout = fopen((filename + ".out").c_str(), "w");

	fin >> T;
	for(int t = 1; t <= T; t++)
	{
		string outlets[MAXN];
		int rOut[MAXL] = {0};
		string devices[MAXN];

		fin >> N >> L;
		for(int j = 0; j < N; j++)
		{
			fin >> outlets[j];
			for(int k = 0; k < L; k++)
			{
				rOut[k] |= (((outlets[j][k] == '1') ? 1 : 0) << j);
			}			
		}
		for(int j = 0; j < N; j++)
		{
			fin >> devices[j];
		}
		sort(devices, devices + N);

		int mStep = MAXL + 1;
		int m = 1 << L;
		for(int i = 0; i < m; i++)
		{
			int rOut2[MAXL];
			for(int k = 0; k < L; k++)
			{
				if(i & (1 << k))
				{
					rOut2[k] = ~rOut[k] & ((1 << N) - 1);
				}
				else
				{
					rOut2[k] = rOut[k];
				}
			}
			// for(int j = 0; j < L; j++)
			// {
			// 	int v = rOut[j];
			// 	for(int k = 0; k < N; k++)
			// 	{
			// 		if(v & (1 << k))
			// 		{
			// 			printf("1");
			// 		}
			// 		else
			// 		{
			// 			printf("0");
			// 		}
			// 	}
			// 	printf(" ");
			// }
			// printf("\n");
			// for(int j = 0; j < L; j++)
			// {
			// 	int v = rOut2[j];
			// 	for(int k = 0; k < N; k++)
			// 	{
			// 		if(v & (1 << k))
			// 		{
			// 			printf("1");
			// 		}
			// 		else
			// 		{
			// 			printf("0");
			// 		}
			// 	}
			// 	printf(" ");
			// }
			// printf("\n");

			string dev[MAXN];
			for(int k = 0; k < N; k++)
			{
				for(int j = 0; j < L; j++)
				{
					dev[k] += ((rOut2[j] >> k) & 1) ? '1' : '0';
				}
			}
			sort(dev, dev + N);

			// for(int j = 0; j < N; j++)
			// {
			// 	printf("%s ", devices[j].c_str());
			// }
			// printf("\n");
			// for(int j = 0; j < N; j++)
			// {
			// 	printf("%s ", dev[j].c_str());
			// }
			// printf("\n");
			// printf("--------------------------------\n");

			bool work = true;
			for(int k = 0; k < N; k++)
			{
				if(dev[k].compare(devices[k]) != 0)
				{
					work = false;
					break;
				}
			}
			if(work)
			{
				mStep = min(mStep, __builtin_popcount(i));
			}
		}

		if(mStep == MAXL + 1)
		{
			fprintf(fout, "Case #%d: %s\n", t, "NOT POSSIBLE");
		}
		else
		{	
			fprintf(fout, "Case #%d: %d\n", t, mStep);
		}
		// printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
	}

	fin.close();
	fclose(fout);
 	return 0;
}