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
map < pair < size_t, size_t >, size_t > cache;

size_t subsize( const size_t r, const size_t u, const vector < vector < size_t > > & adj )
{
    if ( ! cache.count( make_pair < size_t, size_t > (r, u) ) )
    {
        size_t val = 1;

        for ( vector < size_t >::const_iterator i = adj[ u ].begin( ); i != adj[ u ].end( ); ++ i )
            if ( *i != r )
            {
                // val = max( val, 1 + subsize( u, *i, adj ) );

                for ( vector < size_t >::const_iterator j = i + 1; j != adj[ u ].end( ); ++ j )
                    if ( *j != r )
                        val = max( val,  1 + subsize( u, *i, adj ) + subsize( u, *j, adj ));
            }

        cache[ make_pair < size_t, size_t > (r, u) ] = val;
    }

    return cache[ make_pair < size_t, size_t > (r, u) ];
}

size_t solve_case( const vector < vector < size_t > > & adj )
{
    const size_t n = adj.size( );
    size_t val = 1;

    cache.clear( );

    for ( size_t r = 0; r < n; ++ r ) // root node r
        for ( vector < size_t >::const_iterator i = adj[ r ].begin( ); i != adj[ r ].end( ); ++ i )
        {
            // val = max( val, 1 + subsize( r, *i, adj ));

            for ( vector < size_t >::const_iterator j = i + 1; j != adj[ r ].end( ); ++ j )
                val = max( val,  1 + subsize( r, *i, adj ) + subsize( r, *j, adj ));
        }

    return n - val;
}


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
        vector < vector < size_t > > adj( n );
        for ( size_t j = 0; j + 1 < n; ++ j )
        {
            size_t u, v;
            fin >> u >> v;
            -- u; -- v;
            adj[ u ].push_back( v );
            adj[ v ].push_back( u );
        }

        fout << "Case #" << k + 1 << ": " << solve_case( adj ) << '\n';
    }

    fin.close();
    fout.close();
}
