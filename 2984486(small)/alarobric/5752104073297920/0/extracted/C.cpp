//Google Codejam
//2014 Round 1A
//Alan Richards - alarobric

//Problem C
#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <stack>
#include <array>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <limits.h>
using namespace std;

#define FOR(i, n) for(ull i=0; i<n; i++)
#define FOREACH(c, iter) for(auto iter=c.begin(); iter!=c.end(); iter++)

#ifdef DEBUG
#define Debug(x) std::cerr << x << endl
#else
#define Debug(x)
#endif

typedef unsigned long long ull;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;

template <class T>
string ContainerPrint(T a)
{
	stringstream ss;
	FOREACH(a, iter)
		ss << *iter << " ";
	return ss.str();
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

string Solve(int i_case)
{
	int N;
	std::cin >> N;
	
	int x;
	int abnormal = 0;
	int semiabnormal = 0;
	FOR(i, N)
	{
		cin >> x;
		if (x - 1 == i)	//ie if 1 is in 0 spot or 2 is in 1 spot, etc.
			abnormal++;
		if (i < N * log(2) && x == i)
			semiabnormal++;
		else if (i >= N * log(2) && x == 0)
			semiabnormal++;
	}
	
	Debug(abnormal << " " << semiabnormal);

	if (semiabnormal > abnormal)
		return "GOOD";
	if (abnormal > semiabnormal)
		return "BAD";
	if (abnormal > 2)
		return "BAD";
	return "GOOD";
}

int main()
{
	std::cerr << "GCJ 2014 Round 1A-C" << std::endl;
	int numCases;
	std::cin >> numCases;
	for (int i=1; i<=numCases; i++)
	{
		std::cout << "Case #" << i << ": " << Solve(i) << std::endl;
	}
	return 0;
}