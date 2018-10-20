#include<iostream>
#include<fstream>
#include<algorithm>
#include<string>
#include<utility>
#include<vector>

using namespace std;

int main(void)
{
	ifstream fin("in.txt");
	ofstream fout("out.txt");




	int T = -1;
	fin >> T;

	for (int i = 0; i < T; i++)
	{
		int N;
		fin >> N;

		int c = 0;
		vector<int> t, r;
		for (int j = 0; j < N; j++)
		{
			int temp;
			fin >> temp;
			t.push_back(temp);
			r.push_back(temp);
		}
		sort(t.begin(), t.end());

		for (int j = 0; j < N; j++)
		{
			if (r[j] == t[j])
				c++;
		}

		if (c > 1)
			fout << "Case #" << i + 1 << ": BAD\n";
		else
			fout << "Case #" << i + 1 << ": GOOD\n";
	}

	return 0;
}