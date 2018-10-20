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

		int N = -1, L = -1;
		fin >> N >> L;

		string* o = new string[N];
		string* d = new string[N];

		for (int j = 0; j < N; j++)
		{
			fin >> o[j];
		}
		for (int j = 0; j < N; j++)
		{
			fin >> d[j];
		}

		vector<string> pos;
		vector<int> counts;

		for (int j = 0; j < N; j++)
		{
			string p = "";
			int count = 0;
			for (int l = 0; l < L; l++)
			{
				if (d[0][l] == o[j][l])
					p += '0';
				else
				{
					p += '1';
					count++;
				}
			}
			pos.push_back(p);
			counts.push_back(count);
		}

		for (int j = 1; j < N; j++)
		{
			for (int k = pos.size()-1; k >= 0; k--)
			{
				string p = "";
				for (int l = 0; l < L; l++)
				{
					if (pos[k][l] == '0')
					{
						p += d[j][l];
					}
					else
					{
						p += (d[j][l] == '0') ? '1' : '0';
					}
				}

				bool test = true;
				for (int l = 0; l < N; l++)
				{
					if (strcmp(p.c_str(), o[l].c_str()) == 0)
					{
						test = false;
						break;
					}
				}
				if (test)
				{
					pos.erase(pos.begin() + k);
					counts.erase(counts.begin() + k);
				}
			}
			if (pos.size() <= 0)
				break;
		}

		if (pos.size() <= 0)
			fout << "Case #" << i + 1 << ": NOT POSSIBLE\n";
		else
			fout << "Case #" << i + 1 << ": " << *min_element(counts.begin(), counts.end()) <<'\n';

	}




	return 0;
}