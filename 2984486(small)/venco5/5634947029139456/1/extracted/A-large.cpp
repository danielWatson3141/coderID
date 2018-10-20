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
#include <cstring>
#include <sstream>
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

const int INF = 999999999;
const int MAX_N = 256;
const int MAX_L = 64;
int N, L;
string ff[MAX_N];
string rr[MAX_N];

int num_cases = 1, part_cases = 0;
int main(int argc, const char** argv)
{
    cin >> num_cases >> skip_endl;
    if ( argc == 2 ) {
        part_cases = atoi(argv[1]);
    }
    forN ( nc, num_cases ) {
	cin >> N >> L >> skip_endl;
	forN ( i, N ) {
	    cin >> ff[i];
	}
	cin >> skip_endl;
	forN ( i, N ) {
	    cin >> rr[i];
	}
	cin >> skip_endl;

        // error check
        if ( !cin ) {
            cout << "Error parsing input" << endl;
            return 1;
        }
        // main code

	sort(rr, rr+N);

	int result = INF;

	string tt[MAX_N];
	forN ( r, N ) {
	    int c = 0;
	    forN ( j, L ) {
		if ( ff[0][j] != rr[r][j] ) {
		    ++c;
		}
	    }
	    if ( c >= result ) continue;
	    forN ( i, N ) {
		tt[i] = ff[i];
		forN ( j, L ) {
		    if ( ff[0][j] != rr[r][j] ) {
			tt[i][j] ^= 1;
		    }
		}
	    }
	    sort(tt, tt+N);
	    bool ok = 1;
	    forN ( i, N ) {
		if ( tt[i] != rr[i] ) {
		    ok = 0;
		    break;
		}
	    }
	    if ( ok && c < result )
		result = c;
	    
	}

	/*
	forN ( bb, 1<<L ) {
	    int c = 0;
	    forN ( j, L ) {
		if ( bb&(1<<j) ) {
		    ++c;
		}
	    }
	    if ( c >= result ) continue;
	    forN ( i, N ) {
		tt[i] = ff[i];
		forN ( j, L ) {
		    if ( bb&(1<<j) ) {
			tt[i][j] ^= 1;
		    }
		}
	    }
	    sort(tt, tt+N);
	    bool ok = 1;
	    forN ( i, N ) {
		if ( tt[i] != rr[i] ) {
		    ok = 0;
		    break;
		}
	    }
	    if ( ok && c < result )
		result = c;
	}
	*/
	
        // output
        cout << "Case #"<<nc+1<<": ";
	if ( result == INF )
	    cout << "NOT POSSIBLE";
	else
	    cout << result;
        cout << endl;
    }
}
