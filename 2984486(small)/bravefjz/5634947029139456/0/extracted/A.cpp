#include <fstream>
#include <set>
#include <string>

using namespace std;

int T,N,L;

char devices[150][40];
char outlets[150][40];
char line[150*40];
char middle[150][40];

int y;

bool equal(int n)
{
	multiset<string> tmp;
	for (int i = 0; i < N; i++)
	{
		string dev(outlets[i],n+1);
		tmp.insert(dev);
	}
	for (int i = 0; i < N; i++)
	{
		string mid(middle[i],n+1);
		tmp.erase(mid);
	}
	if(tmp.empty())
		return true;
	else
		return false;
}

int check(int n, int flip)
{
	if(n == L)
		return 0;
	int result = -1;
	if(n >= 0)
	{
		for(int i = 0; i < N; i++)
			middle[i][n] = flip == 0 ? devices[i][n] : '0'+'1'- devices[i][n];
		if(!equal(n))
			return -1;
	}
	int result1 = check(n+1,0);
	int result2 = check(n+1,1);
	if (result1 != -1)
		result = result1;
	if (result2 != -1 && (result == -1 || result2+1 <= result))
		result = result2+1;
	return result;
}

void main()
{
	ifstream fin;
	ofstream fout;
	fin.open("in.txt");
	fout.open("out.txt");
	fin >> T;
	for(int i = 0; i < T; i++)
	{
		fin >> N >> L;
		fin.getline(line,150*40);
		fin.getline(line,150*40);
		for (int j = 0; j < N; j++)
			for(int k = 0; k < L; k++)
				outlets[j][k] = line[j*(L+1)+k];
		fin.getline(line,150*40);
		for (int j = 0; j < N; j++)
			for(int k = 0; k < L; k++)
				devices[j][k] = line[j*(L+1)+k];
		y = check(-1,0);
		fout << "Case #" << i+1 << ": ";
		if(y == -1)
			fout << "NOT POSSIBLE" << endl;
		else
			fout << y << endl;
	}

	fin.close();
	fout.close();
}