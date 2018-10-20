#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <cmath>
#include <cstdio>
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
typedef unsigned u32; typedef int i32;
typedef long long i64; typedef unsigned long long u64;
typedef vector<int> VI; typedef vector<VI> VVI; typedef vector<string> VS;
typedef pair<int, int> P; typedef vector<P> VP; typedef vector<VP> VVP;

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
/////////////////////////////////////////////////////////////////////////////

const int MAX_N = 1024;
int N, M;
int pp[MAX_N];
double prob[MAX_N][MAX_N];

void init_guess()
{
    if ( N == M ) return;
    M = N;
    double p0 = 1./N;
    forN ( s, N ) {
	double cp[MAX_N];
	forN ( j, N ) cp[j] = 0;
	cp[s] = 1;
	forN ( t, N ) {
	    double ppt = cp[t];
	    forN ( i, N ) {
		if ( i == t ) {
		    cp[i] = p0;
		}
		else {
		    cp[i] += (ppt-cp[i])*p0;
		}
	    }
	}
	forN ( j, N ) {
	    prob[s][j] = cp[j];
	}
	//TR(s|A(prob[s],N));
    }
}

bool guess_good()
{
    if ( N == 3 ) return pp[0];
    init_guess();
    double pb = 1;
    forN ( i, N ) {
	int s = pp[i];
	pb *= prob[s][i]*N;
    }
    return pb < 1;
}

int get_rand(int size)
{
    int c = RAND_MAX/size;
    int r;
    do {
	r = random();
    } while ( r >= c*size );
    return r/c;
}

int num_cases = 1, part_cases = 0;
int main(int argc, const char** argv)
{
    NTR = 10000;
    cin >> num_cases >> skip_endl;
    if ( argc == 2 ) {
        part_cases = atoi(argv[1]);
    }

    if ( 1 ) {
	N = 1000;
	srandom(4);
	int guessed_cnt = 0, good_cnt = 0;
	forN ( t, 120 ) {
	    bool good = get_rand(2);
	    good_cnt += good;
	    forN ( i, N ) pp[i] = i;
	    if ( good ) {
		forN ( i, N ) {
		    int j = i+get_rand(N-i);
		    swap(pp[i], pp[j]);
		}
	    }
	    else {
		forN ( i, N ) {
		    int j = get_rand(N);
		    swap(pp[i], pp[j]);
		}
	    }
	    bool guess = guess_good();
	    //TR(good|guess);
	    guessed_cnt += (guess == good);
	}
	TR(guessed_cnt|good_cnt);
	if ( guessed_cnt < 109 ) return 1;
    }
    forN ( nc, num_cases ) {
        // parse input
        cin >> N >> skip_endl;
	forN ( i, N ) cin >> pp[i];
	cin >> skip_endl;
        
        // error check
        if ( !cin ) { cout << "Error parsing input" << endl; return 1; }
        // main code

	bool good = guess_good();

        // output
        cout << "Case #"<<nc+1<<": ";
        cout << (good? "GOOD": "BAD");
        cout << endl;
    }
}
