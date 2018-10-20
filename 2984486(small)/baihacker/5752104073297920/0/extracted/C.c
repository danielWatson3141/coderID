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

const int N = 1000;
const int S = 1000000;

int flag[N][N];
int sm[N];
int main()
{
	srand(time(NULL));
	int data[N];
	
	for (int i = 0; i < S; ++i)
	{
		if (i % 10000 == 0) cerr << i << endl;
		
		rep(i, 0, N) data[i] = i;
		rep(i, 0, N)
		{
			#if 0
			int pos = rand() % (N - i);
			swap(data[i], data[i+pos]);
			#else
			int pos = rand() % N;
			swap(data[i], data[pos]);
			#endif
		}
		for (int i = 0; i < N; ++i)
		{
			++flag[i][data[i]];
		}
	}
	
	rep(i, 0, N)
	rep(j, 0, N) sm[i] += flag[i][j];

	int CASE = Rint();
	for (int id = 1; id <= CASE; ++id)
	{
		Rint();
		for (int i = 0; i < N; ++i)
		data[i] = Rint();
		double prob = 0;
		double compare = 0;
		rep(i, 0, N)
		prob += log(1. * flag[i][data[i]] / sm[i]),
		compare += log(0.001);
		
		if (prob > compare)
		printf("Case #%d: BAD\n", id);
		else
		printf("Case #%d: GOOD\n", id);
	}
	return 0;
}
