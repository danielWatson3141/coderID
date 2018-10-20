#include <iostream>
#include <fstream>
#define REP(i,s,n) for(int i=s;i<n;i++)
using namespace std;
ifstream fin("C-small-attempt0 (1).in");
ofstream fout("out.txt");
int N;
int main()
{
	int T;
	fin >> T;
	double allS,nowS;
	int num[1001];
	REP(caseNumber, 1, T + 1)
	{
		fin >> N;
		allS = N*(N - 1) / 2;
		allS = allS * 0.51;
		REP(i, 0, N) fin >> num[i];
		nowS = 0;
		for (int i = 0; i < N; ++i)
		{
			for (int j = i + 1; j < N; ++j)
			{
				if (num[i] < num[j]) nowS++;
			}
		}
		if (nowS>allS)
			fout << "Case #" << caseNumber << ": "<<"BAD" << "\n";
		else
			fout << "Case #" << caseNumber << ": "<<"GOOD" << "\n";
	}
	fin.close();
	fout.close();
	return 0;
}