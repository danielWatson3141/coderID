#include <vector>
#include <array>
#include <string>
#include <iostream>
#include <array>
#include <algorithm>
#include <stdio.h>
#include <stack>
#include <float.h>
using namespace std;

//#include <boost/tokenizer.hpp>
//#include <boost/foreach.hpp>
#include <boost/lexical_cast.hpp>
//#include <boost/format.hpp>
//#include <boost/multiprecision/cpp_int.hpp>
using namespace boost;
//using namespace boost::multiprecision;

template<typename T>
static vector<T> transpose(const vector<T>& in)
{
	int iMax = in.size();
	int jMax = in[0].size();
	vector<T> out(jMax);
	for (auto &v: out) v.resize(iMax);
	for (int i = 0; i < iMax; ++i)
		for (int j = 0; j < jMax; ++j)
			out[j][i] = in[i][j];
	return out;
}


static auto solve = [](int n, int l, vector<string>& o, vector<string>& d)
{
	unsigned int res = INT_MAX;
	sort(d.begin(), d.end());
	for (int i = 0; i < (1 << l); ++i)
	{
		vector<string> temp = o;
		for (int j = 0; j < n; ++j)
		{
			for (int k = 0; k < l; ++k)
			{
				if (i & (1<<k))
				{
					if (temp[j][k] == '0')
					{
						temp[j][k] = '1';
					}
					else
					{
						temp[j][k] = '0';
					}
				}
			}
		}
		sort(temp.begin(), temp.end());
		bool isSuccess = true;
		for (int j = 0; j < n; ++j)
		{
			if (temp[j] != d[j])
			{
				isSuccess = false;
				break;
			}
		}
		if (isSuccess)
			res = min(__popcnt(i), res);
	}
	return res == INT_MAX ? "NOT POSSIBLE" : boost::lexical_cast<string>(res);
};

int main(int argv, char* argc[])
{
	int caseNum;
	cin >> caseNum;
	for (int i = 0; i < caseNum; ++i)
	{
		int n, l;
		cin >> n >> l;
		vector<string> outlet(n);
		vector<string> dev(n);
		for (auto &v : outlet)cin >> v;
		for (auto &v : dev)cin >> v;
		cout << "Case #" << i + 1 << ": " << solve(n, l, outlet, dev) << endl;

	}

	return 0;
}