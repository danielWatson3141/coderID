// CookieClicker.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>

using namespace std;

bool isSame(int  N, int L, vector<string>& init, vector<string>& devReqs)
{
	bool allSame = true;
	std::sort(init.begin(), init.end());
	std::sort(devReqs.begin(), devReqs.end());

	for (int i = 0; i < N; ++i)
	{
		if (init[i] != devReqs[i])
		{
			allSame = false;
			break;
		}
	}
	return allSame;
}

bool ApplyFlipsWorks(vector<int>& flips, vector<string> init, vector<string>& devReqs, int L, int N)
{
	for (int i = 0; i < flips.size(); ++i)
	{
		for (int j = 0; j < init.size(); ++j)
		{
		
			if (init[j][flips[i]] == '0')
			{
				init[j][flips[i]] = '1';
			}
			else
			{
				init[j][flips[i]] = '0';
			}
		}
	}

	return isSame(N, L, init, devReqs);
}

string Solve(int  N, int L, vector<string>& init, vector<string>& devReqs)
{
	string ret = "NOT POSSIBLE";

	if (isSame(N, L, init, devReqs))
	{
		return std::to_string(0);
	}
	
	vector<int> flipsNeeded;
	int minFlips = L+1;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			string d = devReqs[i];
			string s = init[j];
			if (s != d)
			{
				flipsNeeded.clear();
				for (int k = 0; k < L; ++k)
				{
					if (s[k] != d[k])
					{
						flipsNeeded.push_back(k);
					}
				}

				if (ApplyFlipsWorks(flipsNeeded, init, devReqs, L, N))
				{
					if (minFlips > flipsNeeded.size())
					{
						minFlips = flipsNeeded.size();
					}
				}
			}

		}
	}

	if (minFlips < L + 1)
	{
		ret = std::to_string(minFlips);
	}

	// std::to_string(i + 1)
	return ret;
}

int _tmain(int argc, _TCHAR* argv [])
{
	ifstream ifs;
	ofstream ofs;
	ifs.open("c:\\GCJ_Inputs\\2014_1A_1\\input.in", ifstream::in);
	ofs.open("c:\\GCJ_Inputs\\2014_1A_1\\output.out", ifstream::out);

	if (!ifs)
	{
		cout << "Error reading input" << endl;
		return 0;
	}

	if (!ofs)
	{
		cout << "Error opening output" << endl;
		return 0;
	}

	cout << "STARTING" << endl;

	unsigned int numTests = 0;
	ifs >> numTests;

	for (unsigned int i = 0; i < numTests; ++i)
	{
		cout << "..";

		int N, L = 0;
		ifs >> N;
		ifs >> L;

		vector<string> init;
		vector<string> devReqs;
		string s;
		for (int i = 0; i < N; ++i)
		{
			ifs >> s;
			init.push_back(s);
		}
		for (int i = 0; i < N; ++i)
		{
			ifs >> s;
			devReqs.push_back(s);
		}
		std::sort(init.begin(), init.end());
		std::sort(devReqs.begin(), devReqs.end());

		string ret = Solve(N, L, init, devReqs);
		ofs << "Case #" + std::to_string(i + 1) + ": ";
		ofs << ret << endl;
	}

	cout << endl;
	cout << "COMPLETE" << endl;

	ofs.close();
	ifs.close();

	return 0;
}

