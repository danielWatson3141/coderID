/* 2014.4.26 Celicath  */

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>

int k[1005][1005];
int line[1005];

void prep()
{
	for (int i = 0; i < 1000; i++)
	for (int j = 0; j < 1000; j++)
		k[i][j] = 0;

	for (int i = 0; i < 100000; i++)
	{
		for (int i = 0; i < 1000; i++)
			line[i] = i;

		for (int j = 0; j < 1000; j++)
		{
			int r = rand() % 1000;
			int tmp = line[r];
			line[r] = line[j];
			line[j] = tmp;
		}
		for (int j = 0; j < 1000; j++)
		{
			k[j][line[j]]++;
		}
	}
}

int main()
{
	prep();

	FILE* fin = fopen("input.txt", "r");
	FILE* fout = fopen("output.txt", "w");

	int T;

	fscanf(fin, "%d", &T);

	for (int c_n = 1; c_n <= T; c_n++)
	{
		int N;

		fscanf(fin, "%d", &N);

		int p = 0;
		for (int i = 0; i < N; i++)
		{
			int n;
			fscanf(fin, "%d", &n);

			p += k[i][n];
		}

		if (p > 100000)
			fprintf(fout, "Case #%d: BAD\n", c_n, 0);
		else
			fprintf(fout, "Case #%d: GOOD\n", c_n, 0);
	}

	return -0;
}
