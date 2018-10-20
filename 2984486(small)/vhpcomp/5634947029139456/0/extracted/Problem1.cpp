#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <iostream>
#include <cstdlib>


using namespace std;

int NoOf1(int v)
{
	int count = 0;
	while (v > 0)
	{
		if ((v & 0x1) == 1)
			count++;
		v = v >> 1;
	}
	return count;
}

bool canMatch(vector<string> f, vector<string> n, int p, int L)
{
	for (int i = 0; i < f.size(); i++)
	{
		for (int j = 0; j < L; j++)
		{
			if ((p & (0x1 << j)) != 0)
			{
				if (f[i][j] == '0')
					f[i][j] = '1';
				else if (f[i][j] == '1')
					f[i][j] = '0';
			}
		}
	}
	sort(f.begin(), f.end());
	sort(n.begin(), n.end());
	for (int i = 0; i < f.size(); i++)
	{
		if (f[i] != n[i])
			return false;
	}
	return true;
}

int main()
{
	int T;

	//ifstream fin("C:\\weilin\\Competition\\GCJ20141A\\GCJ20141A\\input.txt");
	ifstream fin("C:\\weilin\\Competition\\GCJ20141A\\GCJ20141A\\A-small-attempt0.in");
	ofstream fout("output.txt");

	fin >> T;

	long long total = 0;


	for (int i = 0; i < T; i++)
	{
		int N, L;

		fin >> N >> L;
		vector<string> flow;
		vector<string> need;

		for (int j = 0; j < N; j++)
		{
			string f;
			fin >> f;
			flow.push_back(f);
		}

		for (int j = 0; j < N; j++)
		{
			string f;
			fin >> f;
			need.push_back(f);
		}

		int res = 999999;
		for (int j = 0; j < (1 << L); j++)
		{
			if (canMatch(flow, need, j, L))
			{
				int temp = NoOf1(j);
				if (temp < res)
					res = temp;
			}
		}


		if (res == 999999)
		{
			fout << "Case #" << i + 1 << ": " << "NOT POSSIBLE" << endl;
		} else 
			fout << "Case #" << i + 1 << ": " << res << endl;

	}
	return 0;
}