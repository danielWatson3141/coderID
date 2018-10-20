/* 2014.4.26 Celicath  */

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>

std::multimap<int, int> edge;
int found[1005];
int delc[1005];
int goc[1005];

int del(int loc)
{
	if (delc[loc])
		return delc[loc];

	auto ran = edge.equal_range(loc);

	found[loc] = 1;
	int result = 1;
	for (auto a = ran.first; a != ran.second; a++)
		if (found[a->second] == 0)
			result += del(a->second);

	delc[loc] = result;
	return result;
}

int go(int loc, bool root)
{
	if (goc[loc] != -1)
		return goc[loc];

	found[loc] = 2;

	int c = edge.count(loc);
	if (!root) c--;
	auto ran = edge.equal_range(loc);
	int result = 0;
	if (c == 0)
		result = 0;
	else if(c == 1)
	{
		for (auto a = ran.first; a != ran.second; a++)
			if (found[a->second] != 2)
				result = delc[a->second];
	}
	else if (c == 2)
	{
		for (auto a = ran.first; a != ran.second; a++)
			if (found[a->second] != 2)
				result += go(a->second, false);
	}
	else
	{
		for (auto a = ran.first; a != ran.second; a++)
			if (found[a->second] != 2)
				result += delc[a->second];

		int max1 = -100000007, max2 = -100000008;
		for (auto a = ran.first; a != ran.second; a++)
		{
			if (delc[a->second] < delc[loc])
			{
				int k = delc[a->second] - go(a->second, false);
				if (k > max1)
				{
					max2 = max1;
					max1 = k;
				}
				else if (k > max2)
					max2 = k;
			}
		}
		result -= max1 + max2;
	}
	goc[loc] = result;
	return result;
}

int main()
{
	FILE* fin = fopen("input.txt", "r");
	FILE* fout = fopen("output.txt", "w");

	int T;

	fscanf(fin, "%d", &T);

	for (int c_n = 1; c_n <= T; c_n++)
	{
		int N;

		fscanf(fin, "%d", &N);

		edge.clear();
		for (int i = 0; i < N - 1; i++)
		{
			int x, y;
			fscanf(fin, "%d%d", &x, &y);
			edge.insert(std::pair<int, int>(x,y));
			edge.insert(std::pair<int, int>(y,x));
		}
		int min = 2147483647;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				found[j] = delc[j] = 0;
				goc[j] = -1;
			}
			// i ´Â rootÀÌ´Ù.
			del(i);

			int result = go(i, true);
			if (min > result) min = result;
		}

		fprintf(fout, "Case #%d: %d\n", c_n, min);
		printf("Case #%d: %d\n", c_n, min);
	}

	return -0;
}
