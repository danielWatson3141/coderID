#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#define REP(i,s,n) for(int i=s;i<n;i++)
using namespace std;
ifstream fin("A-small-attempt0 (1).in");
ofstream fout("out.txt");
unsigned long long outlet[160];
unsigned long long output[160];
int N, L;
int countNum;
int minCount;
unsigned long long toNum(const string &str)
{
	unsigned long long res=0;
	for (int i = 0; i < str.size(); ++i)
	{
		res <<= 1;
		res += str[i] - (int)'0';
	}
	return res;
}
void flip(int index)
{
	for (int i = 0; i < N; ++i)
	{
		outlet[i] ^= (1ull << index);
	}
}
bool isEqual(int len)
{
	vector<unsigned long long> ol(N);
	vector<unsigned long long> ot(N);
	for (int i = 0; i < N; ++i)
	{
		ol[i] = (outlet[i] & ((1ull << len) - 1));
		ot[i] = (output[i] & ((1ull << len) - 1));
	}
	sort(ol.begin(), ol.end());
	sort(ot.begin(), ot.end());
	for (int i = 0; i < N; ++i)
	{
		if (ol[i] != ot[i]) return false;
	}
	return true;
}
bool dfs(int step)
{
	if (step == L)
	{
		if (countNum < minCount)minCount = countNum;
		return true;
	}
	if (countNum>minCount) return true;
	int res = false;
	if (isEqual(step + 1))
	{
		res = dfs(step + 1);
	}
	flip(step);
	countNum++;
	if (isEqual(step + 1))
	{
		res = res || dfs(step + 1);
	}
	countNum--;
	flip(step);
	return res;
}
int main()
{
	//cout << toNum("01010") << endl;
	int T;
	fin >> T;
	string str;
	REP(caseNumber, 1, T + 1)
	{
		fin >> N >> L;
		REP(i, 0, N)
		{
			fin >> str;
			outlet[i] = toNum(str);
		}
		REP(i, 0, N)
		{
			fin >> str;
			output[i] = toNum(str);
		}
		minCount = 100000;
		countNum = 0;
		if(dfs(0))
			fout << "Case #" << caseNumber << ": "<<minCount<<"\n";
		else
		{
			fout << "Case #" << caseNumber << ": "<<"NOT POSSIBLE"<<"\n";
		}
	}
	fin.close();
	fout.close();
	return 0;
}