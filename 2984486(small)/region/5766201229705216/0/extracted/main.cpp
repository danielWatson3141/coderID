#include<iostream>
#include<fstream>
#include<algorithm>
#include<string>
#include<utility>
#include<vector>

using namespace std;

int T, N;

int rsolve(bool** m, int* cnt, bool* c, int n, int p, int* min)
{
	vector<int> r;
	c[n] = false;
	for (int i = 0; i < N; i++)
	{
		if (i != p && c[i] && m[n][i])
		{
			r.push_back(rsolve(m, cnt, c, i, n, min));
		}
	}
	
	while (r.size() > 2 || r.size() == 1)
	{
		(*min) += *min_element(r.begin(), r.end());
		r.erase(min_element(r.begin(), r.end()));
	}
	int res = 0;
	for (int i = 0; i < r.size(); i++)
	{
		res += r[i];
	}
	return res + 1;
}

int main(void)
{
	ifstream fin("in.txt");
	ofstream fout("out.txt");

	fin >> T;

	for (int i = 0; i < T; i++)
	{
		cout << "Case #" << i + 1 << "...";

		fin >> N;

		bool** mat = new bool*[N];
		for (int j = 0; j < N; j++)
		{
			mat[j] = new bool[N];
			for (int k = 0; k < N; k++)
			{
				mat[j][k] = false;
			}
		}
		
		for (int j = 0; j < N-1; j++)
		{
			int x, y;
			fin >> x >> y;
			x--; y--;
			mat[x][y] = true;
			mat[y][x] = true;
		}

		int min = -1;

		//try each root node
		int* con = new int[N];
		for (int j = 0; j < N; j++)
		{
			int c = 0;
			for (int k = 0; k < N; k++)
			if (mat[j][k])
				c++;
			con[j] = c;
		}

		for (int j = 0; j < N; j++)
		{
			bool* c = new bool[N];
			for (int k = 0; k < N; k++)
			{
				c[k] = true;
			}
			int m = 0;
			int t = rsolve(mat, con, c, j, -1, &m);
			if (min == -1 || m < min)
				min = m;
		}

		fout << "Case #" << i + 1 << ": " << min << '\n';

		cout << " Done!\n";
	}

	fin.close();
	fout.close();

	return 0;
}