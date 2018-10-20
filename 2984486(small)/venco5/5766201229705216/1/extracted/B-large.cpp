#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <functional>
#include <cctype>
#include <sstream>
#include <cstring>
#include <iostream>
#include <iomanip>
//#include <gmp.h>
#ifdef HOME_RUN
# include <debug.hpp>
# include <dump.hpp>
# include <cassert>
#else
# define TR(x) do{}while(0)
# ifdef assert
#  indef assert
# endif
# define assert(x) do{}while(0)
#endif
using namespace std;

#define ALL(C) (C).begin(), (C).end()
#define forIter(I,C) for(typeof((C).end()) I=(C).begin(); I!=(C).end(); ++I)
#define forNF(I,S,C) for(int I=(S); I<int(C); ++I)
#define forN(I,C) forNF(I,0,C)
#define forEach(I,C) forN(I,(C).size())
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef long long i64;
typedef unsigned long long u64;
typedef unsigned u32;

inline istream& skip_endl(istream& in)
{
    string s;
    getline(in, s);
    forIter( i, s ) assert(isspace(*i));
    return in;
}

inline string get_str()
{
    string ret;
    getline(cin, ret);
    return ret;
}

map<string, int> str_index;
int get_index(const string& s)
{
    return str_index.insert(make_pair(s, str_index.size())).first->second;
}
int get_str_index()
{
    return get_index(get_str());
}

/////////////////////////////////////////////////////////////////////////////

const int INF = 999999999;

const int MAX_N = 1024;
int N;
VI ee[MAX_N];
int cc[MAX_N][MAX_N];

int go(int k, int p)
{
    int& ret = cc[k][p];
    if ( ret != INF ) return ret;
    int c0 = 0, c1 = 0;
    forIter ( j, ee[k] ) {
	int i = *j;
	if ( i == p ) continue;
	int c = go(i, k);
	if ( c > c0 ) {
	    c1 = c0;
	    c0 = c;
	}
	else if ( c > c1 ) {
	    c1 = c;
	}
    }
    if ( c1 ) {
	ret = 1+c0+c1;
    }
    else {
	ret = 1;
    }
    return ret;
}

int num_cases = 1, part_cases = 0;
int main(int argc, const char** argv)
{
    cin >> num_cases >> skip_endl;
    if ( argc == 2 ) {
        part_cases = atoi(argv[1]);
    }
    forN ( nc, num_cases ) {
        // parse input
        cin >> N >> skip_endl;
	forN ( i, N ) ee[i].clear();
	forN ( k, N-1 ) {
	    int i, j;
	    cin >> i >> j >> skip_endl;
	    --i; --j;
	    ee[i].push_back(j);
	    ee[j].push_back(i);
	}
	forN ( i, N ) sort(ALL(ee[i]));
	
        // error check
        if ( !cin ) {
            cout << "Error parsing input" << endl;
            return 1;
        }
        // main code

	int result = INF;
	
	forN ( i, N+1 ) forN ( j, N+1 ) cc[i][j] = INF;
	forN ( s, N ) {
	    int c = N-go(s, N);
	    if ( c < result ) result = c;
	}

	/*
	forN ( xx, 1<<N ) {
	    int c = __builtin_popcount(xx);
	    if ( c >= result ) continue;
	    forN ( s, N ) {
		if ( xx&(1<<s) ) continue;
		int nn = 1<<s;
		int cc = xx|nn;
		while ( nn ) {
		    int i = __builtin_ctz(nn);
		    nn ^= 1<<i;
		    int tt = ee[i]&~cc;
		    int nc = __builtin_popcount(tt);
		    if ( nc != 0 && nc != 2 ) {
			break;
		    }
		    nn |= tt;
		    cc |= tt;
		}
		if ( cc == (1<<N)-1 ) {
		    result = c;
		    break;
		}
	    }
	}
	*/

        // output
        cout << "Case #"<<nc+1<<": ";
        cout << result;
        cout << endl;
    }
}
