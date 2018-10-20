#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int main()
{
	FILE * fIn;
	fopen_s(&fIn, "C-small-attempt0.in", "rt");
	FILE* fOut;
	fopen_s(&fOut, "C-small-attempt0.out", "wt");
	
	int T=0;
	int caseNum = 1;
	fscanf(fIn, "%d", &T);

	while(T--)
	{
		int N;
		int list[1000];
		fscanf(fIn, "%d", &N);
		for (int i = 0; i < N; i++)
		{
			fscanf(fIn, "%d", &list[i]);
		}
		int chk = 0;
		for (int i = 0; i < N-1; i++)
		{
			if (list[i+1] > list[i])
			{
				chk++;
			}
		}
		if (chk > N*3/4)
			fprintf(fOut, "Case #%d: BAD\n", caseNum);
		else
			fprintf(fOut, "Case #%d: GOOD\n", caseNum);
	}

	fclose(fIn);
	fclose(fOut);
}