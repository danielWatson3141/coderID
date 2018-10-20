#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>
#include <memory.h>
#include <algorithm>

using namespace std;

const char inFileName[] = "C-small.in";
const char outFileName[] = "C-small.out";
const char dataFileName[] = "data.txt";

const int MaxN = 1010;

int T;
int p[MaxN], n;
int goodMatrix[MaxN][MaxN];
int badMatrix[MaxN][MaxN];
int a[MaxN];

int randomNumber(int a, int b) 
{
	return ((rand() % (b - a + 1)) + a);
}

void GoodPermutation(int n, int a[])
{
	for (int k = 0; k < n; k++)
		a[k] = k;
	for (int k = 0; k < n; k++)
	{
		int p = randomNumber(k, n - 1);
		int tmp = a[k]; a[k] = a[p]; a[p] = tmp;
	}
}

void BadPermutation(int n, int a[])
{
	for (int k = 0; k < n; k++)
		a[k] = k;
	for (int k = 0; k < n; k++)
	{
		int p = randomNumber(0, n - 1);
		int tmp = a[k]; a[k] = a[p]; a[p] = tmp;
	}
}

int main() {
	
	FILE* inFile = fopen(inFileName, "r");
	FILE* outFile = fopen(outFileName, "w");
	FILE* dataFile = fopen(dataFileName, "r");

	srand(2014);
	/*n = 1000;
	for (int i = 1; i <= 1000000; i++)
	{
		if (i % 10000 == 0)
			printf("%d\n", i / 10000);
		GoodPermutation(n, a);
		for (int i = 0; i < n; i++)
			goodMatrix[i][ a[i] ]++;
		BadPermutation(n, a);
		for (int i = 0; i < n; i++)
			badMatrix[i][ a[i] ]++;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			fprintf(outFile, "%d ", goodMatrix[i][j]);
		fprintf(outFile, "\n");
	}
	fprintf(outFile, "\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			fprintf(outFile, "%d ", badMatrix[i][j]);
		fprintf(outFile, "\n");
	}*/

	n = 1000;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			fscanf(dataFile, "%d", &goodMatrix[i][j]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			fscanf(dataFile, "%d", &badMatrix[i][j]);

	fscanf(inFile, "%d", &T);
	for (int t = 0; t < T; t++) 
	{
		fscanf(inFile, "%d", &n);
		for (int i = 0; i < n; i++)
		{
			fscanf(inFile, "%d", &p[i]);
		}

		//long long g = 0LL, b = 0LL;
		double g = 0.0, b = 0.0;
		for (int i = 0; i < n; i++)
		{
			g = g + log((double)goodMatrix[i][ p[i] ]);
			b = b + log((double)badMatrix[i][ p[i] ]);
		}

		int x = rand() % 100;
		if (g > b || (g == b && x < 50))
			fprintf(outFile, "Case #%d: GOOD\n", t + 1);
		else
			fprintf(outFile, "Case #%d: BAD\n", t + 1);
	}	
	
	fclose(inFile);
	fclose(outFile);
	fclose(dataFile);
	return 0;
}
