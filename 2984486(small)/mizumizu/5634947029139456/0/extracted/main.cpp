/*
 * main.cpp
 */
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <climits>
#include <cfloat>
#include <cstring>
#include <ctime>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
 
using namespace std;

typedef unsigned int   UI;
typedef unsigned long  UL;
typedef long long      LL;
typedef vector<int>    VI;
typedef vector<long>   VL;
typedef vector<string> VS;

#define FOR(i,s,e) for(UL i=UL(s); i<UL(e); i++)
#define FORV(it,c) for(__typeof__((c).begin()) it=(c).begin(); (it)!=(c).end(); (it)++)
#define CONTAINS(x,c) (find((c).begin(),(c).end(),(x))!=(c).end())
#define ALL(c) (c).begin(),(c).end()
#define ZC(x) memset((x),0,sizeof((x)))
#define P(x) cout << (x) << endl

#include "ChargingChaos.h"


int main( int argc, char* argv[] ) {
	if (argc != 2) return 1;
	
	ifstream ifs(argv[1]);
	string line;
	
	int case_num = 0;
	if (getline(ifs, line)) { 
		istringstream si(line);
		si >> case_num;
	}
	
	for (int i = 1; i <= case_num; i++) {
		ChargingChaos m;
		Case c = m.readCase(ifs);
		/*
		P(c.N);P(c.L);
		FORV(s,c.outlet){cout<<*s << " ";};
		cout << endl;
		FORV(s,c.device){cout<<*s << " ";};
		cout << endl;
		*/
		int res = m.solve(c);
		if (res == -1) 
			cout << "Case #" << i << ": NOT POSSIBLE" << endl;
		else 
			cout << "Case #" << i << ": " << res << endl;
	}
}
