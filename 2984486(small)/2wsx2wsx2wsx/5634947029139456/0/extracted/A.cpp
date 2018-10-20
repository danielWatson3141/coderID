#include <iostream>
#include <fstream>
#include <unordered_set>
#include <string>
#include <vector>
using namespace std;


long long str2Num(string s)
{
	long long ret = 0;
	for(int i=0; i<s.length(); ++i)
	{
		ret = ret * 2 + ((long long )s[i] - '0');
	}
	return ret;
}

int getOne(long long x)
{
	int cnt = 0;
	while (x > 0)
	{
		if (x%2 == 1)
			++cnt;
		x = x / 2;
	}
	return cnt;
}

int main()
{
	int T;
	string NP = "NOT POSSIBLE";
	ifstream fin("A-small-attempt0.in");
	ofstream fout("A.out");
	fin >> T;
	int N, L;
	int MAXA = 1000;
	for(int it = 1; it <= T; ++it)
	{
		fin >> N >> L;
		unordered_set<long long> hashSet;
		vector<long long> canSet;
		hashSet.clear();
		canSet.clear();
		string str;
		int ans = MAXA;
		
		for(int i=0; i<N; ++i)
		{
			fin >> str;	
			canSet.push_back(str2Num(str)); 
		}
		for(int i=0; i<N; ++i)
		{
			fin >> str;
			hashSet.insert(str2Num(str));
		}
		
		for(auto iter = hashSet.begin(); iter != hashSet.end(); ++iter)
		{
			long long mul = (*iter) ^ canSet[0];
			if (getOne(mul) > ans)
				continue;
			bool canCharge = true;
			for(int i=1; i<N; ++i)
			{
				long long tmp = mul ^ canSet[i];
				if (hashSet.find(tmp) == hashSet.end() )
				{
					canCharge = false;
					break;	
				}
			}
			if (canCharge)
				ans = getOne(mul);
		}
		
		if (ans != MAXA)
			fout << "Case #" << it << ": " << ans << endl;
		else
			fout << "Case #" << it << ": " << NP << endl;
	}
	
	fin.close();
	fout.close();
	
	return 0;
}
