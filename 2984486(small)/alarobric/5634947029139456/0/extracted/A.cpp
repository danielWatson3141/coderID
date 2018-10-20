//Google Codejam
//2014 Round 1A
//Alan Richards - alarobric

//Problem A
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
#include <bitset>
#include <cmath>
#include <algorithm>
#include <limits.h>
using namespace std;

#define FOR(i, n) for(ull i=0; i<n; ++i)
#define FOREACH(c, iter) for(auto iter=c.begin(); iter!=c.end(); ++iter)

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

#define maxL 10

string toString(const int i)
{
	ostringstream ss;
	ss << i;
	return ss.str();
}

string Solve(int i_case)
{
	int N, L;
	std::cin >> N >> L;
	std::vector<ull> outlet;
	std::vector<ull> device;
	outlet.resize(N); device.resize(N);
	std:string z;
	FOR(i, N)
	{
		std::cin >> z;
		outlet[i] = std::bitset<maxL>(z).to_ullong();
	}
	FOR(i, N)
	{
		std::cin >> z;
		device[i] = std::bitset<maxL>(z).to_ullong();
	}

	Debug(ContainerPrint(outlet));
	Debug(ContainerPrint(device));

	std::sort(device.begin(), device.end());

	//no point to flip a switch more than once
	
	//brute force try each possible combination of flips aka every L-bit number
	size_t minFlips = INT_MAX;
	FOR(i, pow(2,L))
	{
		//flip all switches given by i
		auto tempOutlet = outlet;
		FOREACH(tempOutlet, iter)
		{
			*iter = *iter ^ i;
		}
		Debug("xor'ed with " << i << " - " << ContainerPrint(tempOutlet));

		//sort and compare with device
		std::sort(tempOutlet.begin(), tempOutlet.end());
		if (tempOutlet == device)
		{
			std::bitset<maxL> temp(i);
			minFlips = min(minFlips, temp.count());
		}
	}

	if (minFlips != INT_MAX)
		return toString(minFlips);
	
	return "NOT POSSIBLE";
}

/*std::fstream in("in.txt"), 
    out("out.txt"); 

std::copy( 
    std::istreambuf_iterator< char>( in.rdbuf() ), 
    std::istreambuf_iterator< char>(), 
    std::ostreambuf_iterator< char>( out.rdbuf() ) 
); */

int main()
{
	std::cerr << "GCJ 2014 Round 1A-A" << std::endl;
	int numCases;
	std::cin >> numCases;
	for (int i=1; i<=numCases; i++)
	{
		std::cout << "Case #" << i << ": " << Solve(i) << std::endl;
	}
	return 0;
}