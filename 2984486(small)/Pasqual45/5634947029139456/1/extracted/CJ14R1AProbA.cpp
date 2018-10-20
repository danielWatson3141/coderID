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

namespace
{
	int bits(ll l)
	{
		int ret(0);
		while (l)
		{
			ret += l & 1;
			l /= 2;
		}

		return ret;
	}

	ll getBinary(const string& s)
	{
		ll ret(0);
		for (int i = 0; i < s.size(); ++i)
		{
			ret *= 2;
			ret += s[i] - '0';
		}

		return ret;
	}
}

//int main14R1A_A()
int main()
{
	ifstream fin("A-large.in");
	ofstream fout("A-large.out");
	//ifstream fin("test.in");
	//ofstream fout("test.out");

	ll a[151], b[151];
	string s;
	string fail = "NOT POSSIBLE";

	unsigned int numberOfCases;
	fin >> numberOfCases;

	for (unsigned int zz = 1; zz <= numberOfCases; ++zz)
	{
		int N, L;
		fin >> N >> L;
		for (int i = 0; i < N; ++i)
		{
			fin >> s;
			a[i] = getBinary(s);
		}

		for (int i = 0; i < N; ++i)
		{
			fin >> s;
			b[i] = getBinary(s);
		}

		map<ll, int> s, t;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				ll next = a[i] ^ b[j];
				++s[next];
				++t[next];
			}
		}

		int result = 999;
		for (auto& c : s)
		{
			if (c.second == N && t[c.first] == N)
				result = min(result, bits(c.first));
		}

		if (result < 999)
		{
			fout << "Case #" << zz << ": " << result << endl;
		}
		else
		{
			fout << "Case #" << zz << ": " << fail << endl;
		}
	}

	return 0;
}
