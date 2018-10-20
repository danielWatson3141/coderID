#include <fstream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <utility>
#include <cmath>
#include <functional>
#include <stack>
#include <set>

using namespace std;

int main()
{
	ifstream ifs("a.in");
	ofstream ofs("a.out");
	int t;
	ifs >> t;
	for (int test = 0; test < t; ++test)
	{
		int n, l;
		ifs >> n >> l;
		vector<string> a(n);
		vector<string> b(n);
		for (int i = 0; i < n; ++i)
		{
			ifs >> a[i];
		}
		for (int i = 0; i < n; ++i)
		{
			ifs >> b[i];
		}

		int best = l+1;
		set<string> sa;
		for (int i = 0; i < n; ++i)
			sa.insert(a[i]);

		for (int i = 0; i < n; ++i)
		{
			vector<int> pos;
			for (int j = 0; j < l; ++j)
			{
				if (a[0][j] != b[i][j])
				{
					pos.push_back(j);
				}
			}
			if (pos.size() < best)
			{
				set<string> sb;
				for (int j = 0; j < n; ++j)
				{
					string s = b[j];
					for (int k = 0; k < pos.size(); ++k)
						if (s[pos[k]] == '0')
							s[pos[k]] = '1';
						else 
							s[pos[k]] = '0';
					sb.insert(s);
				}
				if (sa == sb)
					best = pos.size();
			}
		}

		ofs << "Case #" << test+1 << ": ";
		if (best == l+1) 
		{
			ofs << "NOT POSSIBLE" << endl;
		} 
		else 
		{
			ofs << best << endl;
		}
	}
	return 0;
}
