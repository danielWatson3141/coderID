#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <climits>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
typedef long long ll;
using namespace std;

int n = 0;
int arr[1000];

int main()
{
	int t = 0;		
	int i = 0, j = 0;

	FILE* in = freopen("D:/Lab/Contests/Contests/file/C-small-attempt4.in", "r", stdin);
	FILE* out = freopen("D:/Lab/Contests/Contests/file/C-small-attempt4.out", "w", stdout);

	fscanf(in, "%d", &t);

	for(i = 0; i < t; i++)
	{
		fscanf(in, "%d", &n);
		
		for(j = 0; j < n; ++j)
		{
			fscanf(in, "%d", &arr[j]);
		}
		fprintf(out, "Case #%d: %s\n", (i + 1), "BAD");
	}

	fclose(out);
	fclose(in);

	return 0;
}