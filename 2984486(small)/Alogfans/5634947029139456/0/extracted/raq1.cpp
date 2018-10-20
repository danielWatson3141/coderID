#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;

const ull MaxN = 10000;
const ull Inf = 10000000;

ull n, m;
string src[200];
char tmp[200][60] = {0};
vector<string> tmp2;
string dst[200];
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	ull total_test_case;
	cin >> total_test_case;
	for (ull current_case_index = 1; current_case_index <= total_test_case; current_case_index++)
	{
		cin >> n >> m;
		for (ull i = 0; i < n; i++)
			cin >> src[i];
		for (ull i = 0; i < n; i++)
			cin >> dst[i];

		sort(dst, dst + n);
		ull ok = 0;
		ull covbit = 0;
		ull p = 1;
		for (ull i = 0; i < (p << m) && !ok; i++)
		{
			for (ull j = 0; j < n; j++)
				strcpy(tmp[j], src[j].c_str());
			covbit = 0;
			for (ull judgebit = 0; judgebit < m; judgebit++)
			{
				if (i & (p << judgebit))
				{
					covbit++;
					for (ull j = 0; j < n; j++)
						tmp[j][judgebit] = ((src[j][judgebit] == '0') ? '1' : '0');
				}
			}

			tmp2.clear();
			for (ull k = 0; k < n; k++)
			{
				string t(tmp[k]);
				tmp2.push_back(t);
			}
			sort(tmp2.begin(), tmp2.end());

			ull allsame = 1;
			for (ull i = 0; i < n; i++)
			{
				if (strcmp(dst[i].c_str(), tmp2[i].c_str()) != 0)
					allsame = 0;
			}
			if (allsame)
				ok = 1;
		}
		if (ok)
			cout << "Case #" << current_case_index << ": " << covbit << endl;
		else
			cout << "Case #" << current_case_index << ": " << "NOT POSSIBLE" << endl;
	}
	return 0;
}
