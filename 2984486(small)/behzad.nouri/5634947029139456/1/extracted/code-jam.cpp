#include <cstdlib>

#include <limits>
#include <vector>
#include <algorithm>
#include <functional>
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

size_t cnt_diff( const string & a, const string & b )
{
    size_t k = 0;
    for ( string::const_iterator i = a.begin(), j = b.begin(); i != a.end(); ++i, ++j )
        if ( *i != *j )
            ++ k;

    return k;
}

string modify( const string & a, const string & b, const string & c )
{
    const size_t n = a.length( );

    string str( n, ' ' );
    for( size_t j = 0; j < n; ++ j )
        str[ j ] = a[ j ] == b[ j ] ? c[ j ] : ( c[ j ] == '1' ? '0' : '1' );

    return str;
}

int main ( const int argc, char * argv [ ])
{
    const size_t INF = numeric_limits< size_t >::max( ) / 8;

    fstream fin, fout;
    fin.open( "input.txt", fstream::in );
    fout.open( "output.txt", fstream::out );

    size_t t;
    fin >> t;

    for ( size_t k = 0; k < t; ++ k )
    {
        size_t N, L;
        fin >> N >> L;
        vector < string > xs( N ), ys( N );

        for( vector < string >::iterator j = xs.begin( ); j != xs.end(); ++ j )
            fin >> *j;

        for( vector < string >::iterator j = ys.begin( ); j != ys.end(); ++ j )
            fin >> *j;

        DEBUG( xs );
        DEBUG( ys );

        DEBUG( cnt_diff( xs.front( ), ys.front() ));

        size_t val = INF;
        for ( vector < string >::const_iterator j = xs.begin( ); j != xs.end( ); ++ j )
            if ( cnt_diff( ys.front( ), * j ) < val )
            {
                DEBUG( cnt_diff( ys.front(), *j) );
                set < string > pool;
                for ( vector < string >::const_iterator i = xs.begin( ); i != xs.end(); ++ i )
                {
                    const string str = modify( ys.front( ), *j, *i );
                    if ( pool.count( str ) )
                        break;
                    else
                        pool.insert( str );
                }


                bool flag = true;
                for ( vector < string >::const_iterator i = ys.begin( ); i != ys.end( ); ++ i )
                    if ( ! pool.count( *i ) )
                    {
                        flag = false;
                        break;
                    }

                if ( flag )
                    val = cnt_diff( ys.front( ), *j );
            }

        fout << "Case #" << k + 1 << ": ";
        if ( val < INF )
            fout << val << '\n';
        else
            fout << "NOT POSSIBLE" << '\n';

    }

    fin.close();
    fout.close();
}
