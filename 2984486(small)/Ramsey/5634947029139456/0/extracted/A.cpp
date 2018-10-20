#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>
#include <memory.h>
#include <algorithm>

using namespace std;

const char inFileName[] = "A-small.in";
const char outFileName[] = "A-small.out";

const int MaxN = 200;
const int MaxL = 11;

int T;
int n, l, sol;
char d[MaxL], f[MaxN][MaxL]; 
int a[MaxN];
bool mark[1 << MaxL];

int val(char s[])
{
	int len = strlen(s);
	int ret = 0;
	for (int i = 0; i < len; i++)
		ret = 2 * ret + (s[i] == '1' ? 1 : 0);
	return ret;
}

int main() {
	
	FILE* inFile = fopen(inFileName, "r");
	FILE* outFile = fopen(outFileName, "w");

	fscanf(inFile, "%d", &T);
	for (int t = 0; t < T; t++) 
	{
		fscanf(inFile, "%d%d", &n, &l);
		for (int i = 1; i <= n; i++)
			fscanf(inFile, "%s", f[i]);
		for (int i = 1; i <= n; i++)
		{
			fscanf(inFile, "%s", d);
			a[i] = val(d);
		}

		int sol = l + 1;
		for (int mask = 0; mask < (1 << l); mask++)
		{
			for (int i = 0; i < (1 << MaxL); i++)
				mark[i] = false;

			int num = 0;
			for (int j = 0; j < l; j++)
			{
				if ((mask & (1 << j)) != 0) num++;
			}

			for (int i = 1; i <= n; i++)
			{
				for (int j = 0; j < l; j++)
				{
					if ((mask & (1 << j)) != 0)
						d[j] = (f[i][j] == '1' ? '0' : '1');
					else
						d[j] = (f[i][j] == '1' ? '1' : '0');
				}
				d[l] = '\0';
				mark[val(d)] = true;
			}

			bool ok = true;
			for (int i = 1; i <= n; i++)
				ok = ok && mark[ a[i] ];

			if (ok && num < sol) sol = num;
		}

		if (sol != l + 1)
			fprintf(outFile, "Case #%d: %d\n", t + 1, sol);
		else
			fprintf(outFile, "Case #%d: NOT POSSIBLE\n", t + 1);
	}	
	
	fclose(inFile);
	fclose(outFile);
	return 0;
}
