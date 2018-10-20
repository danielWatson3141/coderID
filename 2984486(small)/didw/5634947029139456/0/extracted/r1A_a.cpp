#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int leastChange;
int devices[10];

void FlipOutlet(int outlet[], int posBit, int size)
{
	for (int i = 0; i < size; i++)
	{
		int bit = outlet[i]%(int)pow(10.0, posBit+1)/(int)pow(10.0, posBit);
		if ( bit == 1)
			outlet[i] -= (int)pow(10.0, posBit);
		else
			outlet[i] += (int)pow(10.0, posBit);
	}
}

int comp (const void * elem1, const void * elem2) 
{
    int f = *((int*)elem1);
    int s = *((int*)elem2);
    if (f > s) return  1;
    if (f < s) return -1;
    return 0;
}

int isMatch(int outlet[], int size, int length)
{
	int outlet_[10];
	memcpy(outlet_, outlet, 10*sizeof(int));
	qsort (outlet_, size, sizeof(*outlet), comp);
	for (int i = 0; i < size; i++)
	{
		if (outlet_[i] != devices[i])
			return 0;
	}
	return 1;
}

void ChangeOutlet(int outlet[], int posBit, int size, int changed, int L)
{
	if(isMatch(outlet, size, L))
	{
		if(leastChange > changed)
		{
			leastChange = changed;
		}
	}
	if (posBit < L)
	{
		ChangeOutlet(outlet, posBit+1, size, changed, L);
		FlipOutlet(outlet, posBit, size);
		ChangeOutlet(outlet, posBit+1, size, changed+1, L);
		FlipOutlet(outlet, posBit, size);
	}
}


int main()
{
	FILE * fIn;
	fopen_s(&fIn, "A-small-attempt0.in", "rt");
	FILE* fOut;
	fopen_s(&fOut, "A-small-attempt0.out", "wt");
	
	int T=0;
	int caseNum = 1;
	fscanf(fIn, "%d", &T);

	while(T--)
	{
		leastChange = 100;
		int outlet[10];
		int N, L;
		fscanf(fIn, "%d %d", &N, &L);
		for(int i = 0; i < N; i++)
		{
			fscanf(fIn, "%d", &outlet[i]);
		}
		for(int i = 0; i < N; i++)
		{
			fscanf(fIn, "%d", &devices[i]);
		}
		qsort (devices, N, sizeof(*devices), comp);
		// change outlet
		ChangeOutlet(outlet, 0, N, 0, L);

		// check outlet & devices

		if(leastChange==100)
			fprintf(fOut, "Case #%d: NOT POSSIBLE\n", caseNum);
		else
			fprintf(fOut, "Case #%d: %d\n", caseNum, leastChange);
		caseNum++;
	}
}