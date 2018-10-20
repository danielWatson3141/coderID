#include<fstream>
#include<iostream>
#include<sstream>
#include<iomanip>
#include<string>
#include<vector>
#include<list>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#include<functional>
#include<numeric>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define mp make_pair

//int main14R1A_C()
int main()
{
	ifstream fin("C-small-attempt0.in");
	ofstream fout("C-small-attempt0.out");
	//ifstream fin("test.in");
	//ofstream fout("test.out");

	unsigned int numberOfCases;
	fin >> numberOfCases;

	int N;
	int v[1000];

	vector<pii> w;
	for (unsigned int zz = 0; zz < numberOfCases; ++zz)
	{
		fin >> N;
		for (int i = 0; i < N; ++i)
			fin >> v[i];

		int score = 0;
		for (int i = 0; i < N; ++i)
		{
			int val = v[i];
			if (i < val)
			{
				score += 2 * i + 1 - val;
			}
		}

		w.push_back({ score, zz });
	}

	sort(w.begin(), w.end());
	vector<string> result(numberOfCases, "GOOD");
	for (int i = 0; i * 2 < numberOfCases; ++i)
		result[w[i].second] = "BAD";

	for (int i = 0; i<result.size(); ++i)
	{
		fout << "Case #" << (i+1) << ": " << result[i] << endl;
	}
	
	return 0;
}
