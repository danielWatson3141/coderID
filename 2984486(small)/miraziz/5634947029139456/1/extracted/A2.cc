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
	string filename = "A-large";
	ifstream fin(filename + ".in");
	FILE *fout = fopen((filename + ".out").c_str(), "w");

	fin >> T;
	for(int t = 1; t <= T; t++)
	{
		string outlets[MAXN];
		string devices[MAXN];

		fin >> N >> L;
		for(int j = 0; j < N; j++)
		{
			fin >> outlets[j];	
		}
		sort(outlets, outlets + N);

		for(int j = 0; j < N; j++)
		{
			fin >> devices[j];
		}
		sort(devices, devices + N);

		string ot = outlets[0];
		int mStep = L;
		for(int i = 0; i < N; i++)
		{
			string dev2[MAXN];
			for(int k = 0; k < N; k++)
			{
				dev2[k] = devices[k];
			}

			int c = 0;
			for(int j = 0; j < L; j++)
			{
				if(ot[j] != devices[i][j])
				{
					for(int k = 0; k < N; k++)
					{
						dev2[k][j] = dev2[k][j] == '1' ? '0' : '1';
					}
					c++;
				}
			}
			sort(dev2, dev2 + N);

			bool work = true;
			for(int k = 0; k < N; k++)
			{
				if(dev2[k] != outlets[k])
				{
					work = false;
					break;
				}
			}
			if(work)
			{
				mStep = min(mStep, c);
			}
		}
		if(mStep == L)
		{
			fprintf(fout, "Case #%d: %s\n", t, "NOT POSSIBLE");
		}
		else
		{	
			fprintf(fout, "Case #%d: %d\n", t, mStep);
		}
	}

	fin.close();
	fclose(fout);
 	return 0;
}