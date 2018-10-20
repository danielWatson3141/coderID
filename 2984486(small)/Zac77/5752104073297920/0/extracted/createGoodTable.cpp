#define N 1000
#define runTimes 1000000

#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
int count[N][N];
int main(void)
{
	ofstream fout ("good.table");
	srand (time(NULL));
	int a[1000];
	int i, k, temp, times;
	for (i = 0 ; i < N; i++)
		for (k = 0 ; k < N; k++)
			count[i][k] = 0;
	for (times = 0; times < runTimes; times++)
	{
		for (i = 0 ; i < N; i++)
			a[i] = i;
		for (i = 0 ; i < N; i++)
		{
			k = rand() % (N - i) + i;
			temp = a[i];
			a[i] = a[k];
			a[k] = temp;
		}
		for (i = 0 ; i < N; i++)
			count[i][a[i]]++;
	}
	for (i = 0 ; i < N; i++)
	{
		for (k = 0 ; k < N; k++)
			fout << count[i][k] << " ";
		fout << endl;
	}
	return 0;
}
