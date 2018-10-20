#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <bitset>
#include <string>
#include <numeric>
#include <functional>
#include <iterator>
#include <typeinfo>
#include <utility>
#include <memory>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstddef>
#include <complex>
#include <ctime>
#include <cassert>
using namespace std;

typedef long long int64;
const int inf = 2000000000;
static inline int Rint()
{
	struct X{ int dig[256]; X(){
	for(int i = '0'; i <= '9'; ++i) dig[i] = 1; dig['-'] = 1;
	}};
	static 	X fuck;int s = 1, v = 0, c;
	for (;!fuck.dig[c = getchar()];);
	if (c == '-') s = 0; else if (fuck.dig[c]) v = c ^ 48;
	for (;fuck.dig[c = getchar()]; v = v * 10 + (c ^ 48));
	return s ? v : -v;
}
typedef vector<int> vi;
typedef vi::iterator ivi;
typedef map<int, int> mii;
typedef mii::iterator imii;
typedef set<int> si;
typedef si::iterator isi;

#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define rep(i, s, e) for (int i = (s); i < (e); ++i)
#define foreach(itr, c) for(__typeof((c).begin()) itr = (c).begin(); itr != (c).end(); ++itr)
template<typename T> static inline void cmax(T& a, const T& b){if(b>a)a=b;}
template<typename T> static inline void cmin(T& a, const T& b){if(b<a)a=b;}

string data[200];
string dest[200];
int main()
{
	int T = Rint();
	for (int id = 1; id <= T; ++id)
	{
		int n = Rint(), l = Rint();
		rep(i, 0, n)
		 cin >> data[i];
		rep(i, 0, n)
		 cin >> dest[i];
		sort(dest, dest+n);
		int best = 20000;
		rep(x, 0, n)
		{
			int flag[64] = {0};
			rep(i, 0, l)
			if (data[0][i] != dest[x][i])
			flag[i] = 1;
			
			vector<string> temp;
			rep(i, 0, n)
			{
				string t = data[i];
				rep(j, 0, l)
				if (flag[j]) t[j] = t[j] == '1' ? '0' : '1';
				temp.push_back(t);
			}
			sort(all(temp));
			int ok = 1;
			rep(i, 0, n)
			if (temp[i] != dest[i]) {ok = 0; break;}
			if (ok) {int tans = accumulate(flag, flag+l, 0); cmin(best, tans);}
		}
		printf("Case #%d: ", id);
		if (best > l) puts("NOT POSSIBLE");
		else printf("%d\n", best);
	}
	return 0;
}
