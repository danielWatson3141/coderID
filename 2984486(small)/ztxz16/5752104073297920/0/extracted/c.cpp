#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <ctime>
#define Max(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((b) & FASTBUFFER | (a) & ~FASTBUFFER))
#define Min(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((a) & FASTBUFFER | (b) & ~FASTBUFFER))
#define Swap(a, b) (a ^= b, b ^= a, a ^= b)
#define OO 2147483647
#define priority_queue PQ

using namespace std;

int FASTBUFFER;

int n = 1000, i, j, test, tt, ret;
int a[100005][1005], b[1005];

void gen(int i, int n);

int main()
{
	freopen("C-small-attempt3.in", "r", stdin); freopen("ans.txt", "w", stdout);
	srand(time(NULL));
	for (i = 1; i <= 100000; i++)
		gen(i, n);
	scanf("%d", &test);
	while (test--)
	{
		printf("Case #%d: ", ++tt);
		scanf("%d", &n);
		for (i = 1; i <= n; i++)
			scanf("%d", &b[i]);
		int s = 0;
		for (i = 1; i <= 100000; i++)
		{
			for (j = 0; j < n; j++)
				if (b[j] == a[i][j])
					s++;
		}
		
		if (s >= 100800)
		{
			if (test & 1)
				ret++;
			printf("BAD\n");
		}
		
		else
		{
			if (!(test & 1))
				ret++;
			printf("GOOD\n");
		}
	}
	
	//printf("%d\n", ret);
	return 0;
}

void gen(int x, int n)
{
	for (int i = 0; i < n; i++)
		a[x][i] = i;
	for (int i = 0; i < n; i++)
	{
		int p = rand() % n;
		swap(a[x][p], a[x][i]);
	}
}
