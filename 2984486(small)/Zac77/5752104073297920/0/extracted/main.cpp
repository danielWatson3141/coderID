#define N 1000

#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
int good[N][N];
int bad[N][N];
int main(void)
{
	ofstream fout ("c.out");
	ifstream fin ("C-small-attempt0.in");
	ifstream goodIn ("good.table");
	ifstream badIn ("bad.table");
	int NTotalCase, NCurrentCase;
	int input;
	int i, j;
	double ansGood, ansBad;
	for (i = 0 ; i < N; i++)
		for (j = 0 ; j < N; j++)
		{
			goodIn >> input;
			good[i][j] = input;
			badIn >> input;
			bad[i][j] = input;
		}
	fin >> NTotalCase;
	for (NCurrentCase = 1; NCurrentCase <= NTotalCase; NCurrentCase++)
	{
		fin >> input;
		ansGood = 1;
		ansBad = 1;
		for (i = 0 ; i < N; i++)
		{
			fin >> input;
			ansGood *= (double)good[i][input]/1000;
			ansBad *= (double)bad[i][input]/1000;
		}
		if (ansGood > ansBad)
			fout << "Case #" << NCurrentCase << ": GOOD" << endl;
		else
			fout << "Case #" << NCurrentCase << ": BAD" << endl;
	}
	return 0;
}
