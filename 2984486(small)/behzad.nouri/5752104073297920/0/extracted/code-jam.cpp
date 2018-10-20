#include <cstdlib>

#include <limits>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <map>
#include <list>
#include <set>

#include <iostream>
#include <fstream>
#include <iterator>


#ifdef BUG
    #include "header.hpp"
#else
    #define DEBUG(var)
#endif

using namespace std;

/* ------------------------------ */
int main ( const int argc, char * argv [ ])
{
    // const size_t INF = numeric_limits< size_t >::max( ) / 8;

    fstream fin, fout;
    fin.open( "input.txt", fstream::in );
    fout.open( "output.txt", fstream::out );

    size_t t;
    fin >> t;

    for ( size_t k = 0; k < t; ++ k )
    {
        size_t n;
        fin >> n;

        vector < size_t > a( n );
        for ( vector < size_t >::iterator j = a.begin( ); j != a.end( ); ++ j )
            fin >> *j;

        const size_t i = find( a.begin(), a.end( ), n - 1 ) - a.begin( );
        fout << "Case #" << k + 1 << ": " << ( n < 2 * i  ? "BAD" : "GOOD" ) << '\n';

        // const size_t left  = accumulate( a.begin( ), a.begin( ) + ( n - 1 ) / 2, 0 );
        // const size_t right = accumulate( a.rbegin( ) + 1, a.rbegin( ) + 1 + ( n - 1 ) / 2, 0);

        // DEBUG( left );
        // DEBUG( right );

        // const bool flag = static_cast< double > ( rand( ) ) / RAND_MAX < 0.5;

        // fout << "Case #" << k + 1 << ": " << ( left < right && flag ? "BAD" : "GOOD" ) << '\n';
    }

    fin.close();
    fout.close();
}
