#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <cstdarg>

#define clr(a) memset(a, 0, sizeof(a))
#define fill(a, b) memset(a b, sizeof(a))

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int,int> pii;

#define DBG2 1

void dbg(const char * fmt, ...)
{
#ifdef DBG1
#if DBG2
	FILE* file = stderr;
	va_list args;
	va_start(args, fmt);
	vfprintf(file, fmt, args);
	va_end(args);

	fflush(file);
#endif
#endif
}

vector < vector <double> > calcProb(const int n)
{
	vector < vector <double> > prob(n, vector < double > (n, 0));
	for (int i = 0; i < n; ++i)
		prob[i][i] = 1.0;
	for (int i = 0; i < n; ++i)
	{
		vector <double> temp = prob[i];
		double p = 1.0 / n;
		for (int j = 0; j < n; ++j)
		{
			if (j == i) continue;
			for (int k = 0; k < n; ++k)
				prob[i][k] += prob[j][k];
		}
		for (int k = 0; k < n; ++k)
			prob[i][k] *= p;
		for (int j = 0; j < n; ++j)
		{
			if (j == i) continue;
			for (int k = 0; k < n; ++k)
				prob[j][k] = prob[j][k] * (1 - p) + temp[k] * p;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			printf("%.5lf ", prob[i][j]);
		printf("\n");
	}
	return prob;
}

vector < vector < double> > readProb(int n)
{
	FILE * file = fopen(".prob", "r");
	vector < vector < double> > prob(n, vector< double > (n));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			fscanf(file, "%lf", &prob[i][j]);
	fclose(file);

	return prob;
}

int main()
{
#ifdef DBG1
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
	freopen(".err", "w", stderr);
#endif

	vector < vector <double > > prob = readProb(1000);

	int tt;
	scanf("%d", &tt);
	for (int ii = 1; ii <= tt; ++ii)
	{
		printf("Case #%d: ", ii);
		int n;
		scanf("%d", &n);
		vector <int> perm(n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &perm[i]);
		double P = 1.0;
		for (int i = 0; i < n; ++i)
			P *= n * prob[i][perm[i]];
		if (P > 1.0)
			printf("BAD\n");
		else
			printf("GOOD\n");
	}

	return 0;
}
