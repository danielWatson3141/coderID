#include <fstream>
#include <string>
using namespace std;
int main(void)
{
	ofstream fout ("a.out");
	ifstream fin ("a.in");
	int NTotalCase, NCurrentCase;
	string current;
	int bitA[40], bitB[40];
	int N, L, i, j, ans;

	fin >> NTotalCase;
	for (NCurrentCase = 1; NCurrentCase <= NTotalCase; NCurrentCase++)
	{
		ans = 0;
		fin >> N >> L;
		for (i = 0; i < L; i++)
			bitA[i] = 0;
		for (i = 0; i < L; i++)
			bitB[i] = 0;
		for (i = 0; i < N; i++)
		{
			fin >> current;
			for (j = 0; j < L; j++)
			{
				if (current.at(j) == '1')
					bitA[j]++;
			}
		}
		for (i = 0; i < N; i++)
		{
			fin >> current;
			for (j = 0; j < L; j++)
			{
				if (current.at(j) == '1')
					bitB[j]++;
			}
		}
		for (i = 0; i < L; i++)
		{
			if (bitA[i] == bitB[i])
				continue;
			else if (bitA[i] + bitB[i] == N)
				ans++;
			else
			{
				fout << "Case #" << NCurrentCase << ": NOT POSSIBLE" << endl;
				break;
			}
		}
		if (i == L)
			fout << "Case #" << NCurrentCase << ": " << ans << endl;
	}
	return 0;
}
