#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
int t, k;
int n, l;
int i, j;
int ans;
unsigned long long result, tt;
unsigned long long a[150], b[150], c[150];
int cnta[40], cntb[40];
char tmp[50];

string PROG = "A-Large";
FILE *fin, *fout;

bool check()
{
	int i;
	for (i = 0; i < l; i++)
	{
		if ((cnta[i] != cntb[i]) && (cnta[i] + cntb[i] != n))
			return false;
	}
	return true;
}
bool doublecheck()
{
	int i, j, p;
	bool flag;
	ans = 999999;
	for (p = 0; p < n; p++)
	{
		result = a[0] ^ b[p];
		for (i = 0; i < n; i++)
			c[i] = result ^ a[i];
		for (i = 0; i < n - 1; i++)
			for (j = i + 1; j < n; j++)
			{
				if (c[i] > c[j])
				{
					tt = c[i]; c[i] = c[j]; c[j] = tt;
				}
			}
		flag = 1;
		for (i = 0; i < n; i++)
			if (c[i] != b[i])
			{
				flag = 0;
				break;
			}
		if (flag == 1)
		{
			i = 0;
			while (result > 0)
			{
				i += result & 1;
				result = result >> 1;
			}
			if (i < ans)
				ans = i;
		}
	}
	
	if (ans < 999999)
		return true;
	return false;
}
int main()
{
	fin = fopen((PROG + ".in").c_str(), "r");
	fout = fopen((PROG + ".out").c_str(), "w");
	
	fscanf(fin, "%d", &t);
	for (k = 1; k <= t; k++)
	{
		fscanf(fin, "%d %d", &n, &l);
		for (i = 0; i < l; i++)
			cnta[i] = cntb[i] = 0;
		for (i = 0; i < n; i++)
		{
			fscanf(fin, "%s ", tmp);
			a[i] = 0;
			for (j = 0; j < l; j++)
			{
				a[i] = (a[i] << 1) + tmp[j] - '0';
				cnta[j] += tmp[j] - '0';
			}
		}
		for (i = 0; i < n; i++)
		{
			fscanf(fin, "%s ", tmp);
			b[i] = 0;
			for (j = 0; j < l; j++)
			{
				b[i] = (b[i] << 1) + tmp[j] - '0';
				cntb[j] += tmp[j] - '0';
			}
		}
		
		fprintf(fout, "Case #%d: ", k);
		if (check())
		{
			for (i = 0; i < n - 1; i++)
				for (j = i + 1; j < n; j++)
				{
					if (b[i] > b[j])
					{
						tt = b[i]; b[i] = b[j]; b[j] = tt;
					}
				}
			
			if (doublecheck())
				fprintf(fout, "%d\n", ans);
			else
			{
				fprintf(fout, "NOT POSSIBLE\n");
			}
		}
		else
		{
			fprintf(fout, "NOT POSSIBLE\n");
		}
	}
	return 0;
}