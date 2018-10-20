//Seikang

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <stdlib.h>
#include <assert.h>

#include <vector>
#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>

#include <cmath>
#include <complex>
#include <algorithm>

#include <ctime>
#define gtime clock()

using namespace std;

#define SZ(cont) (int)(cont.size())
#define ALL(cont) (cont).begin(), (cont).end()
#define DEBUG(x) cerr << ">" << #x << ":" << x << endl

typedef long long int64;
typedef pair<int64, int64> ii;
typedef vector<int64> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<string> vs;

const int64 oo32 = 1ll << 30, oo64 = 1ll << 60;
const double pi = acos(-1.0), eps = 1e-9;
inline bool equal(const double &a, const double &b){return abs(a - b) < eps;}


int main()
{
	//freopen ("a.in", "rt", stdin);
	//freopen ("a.out", "wt", stdout);
	int C;
	cin >> C;
	for (int i = 0; i < C; ++i)
	{
		cout << "Case #" << (i + 1) << ": ";
		int N, L;
		cin >> N >> L;
		vs outlets = vs(N);
		vs devices = vs(N);
		for (int j = 0; j < N; ++j)
		{
			cin >> outlets[j];
		}
		std::map<string, int> dic;
		for (int j = 0; j < N; ++j)
		{
			cin >> devices[j];
			dic[devices[j]]++;
		}

		int64 ans = oo32;
		for (int j = 0; j < N; ++j)
		{
			//matching device 0 with outlet j
			int64 m = 0;
			string s = "";
			for (int k = 0; k < L; ++k)
			{
				if(devices[0][k] != outlets[j][k])
				{
					m++;
					s += "1";
				}
				else
				{
					s += "0";
				}
			}

			//evaluate new conf
			std::map<string, int> dic_tmp;
			for (int k = 0; k < N; ++k)
			{
				string tmp = ""; 
				for (int l = 0; l < L; ++l)
				{
					if(s[l] == '1')
						tmp += (outlets[k][l] == '0' ? "1" : "0");
					else
						tmp += (outlets[k][l] == '0' ? "0" : "1");
				}
				dic_tmp[tmp]++;
			}

			bool valid = true;
			for (map<string, int>::iterator it = dic.begin(); it != dic.end(); it++)
			{
				if(it->second != dic_tmp[it->first])
				{
					valid = false;
					break;
				}
			}

			if(valid)
			{
				ans = min(ans, m);
			}
		}

		if(ans != oo32)
		{
			cout << ans << endl;
		}
		else
		{
			cout << "NOT POSSIBLE" << endl;
		}
	}
	return 0;
}
