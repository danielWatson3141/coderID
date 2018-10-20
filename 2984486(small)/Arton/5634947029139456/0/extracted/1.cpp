#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

// template<class T> inline int countbit(T n){return (n==0)?0:(1+countbit(n&(n-1)));}


typedef long long int64;

vector<int64> src;
vector<int64> dest;

int countbit( int64 n )
{
    int r = 0;
    while ( n != 0 )
    {
        if ( n % 2 == 1 )
            r++;
        n = n / 2 ;
    }
    return r;
}

void ans()
{
    int min_xor_count = 1000;
    sort( src.begin(), src.end() );

    for ( int i = 0; i < src.size(); ++i )
    {
        vector<int64> y = dest;
        int64 xor_pattern = src[0]^y[i];
        int xor_count = countbit( xor_pattern );
        //cout << "test " << xor_count << " " << xor_pattern << endl;;
        // printf( "test %d %lld %lld %lld\n", xor_count, xor_pattern, src[0], y[i] );

        for ( int j = 0; j < y.size(); ++j )
        {
            y[j] = y[j] ^ xor_pattern;
        }
        sort( y.begin(), y.end() );

        bool is_same = true;
        for ( int i = 0; i < y.size(); ++i )
            if ( src[i] != y[i] )
                is_same = false;

        if ( is_same && ( xor_count < min_xor_count ) )
        {
            min_xor_count = xor_count;
        }
    }


    if ( min_xor_count == 1000 )
        cout << "NOT POSSIBLE" << endl;
    else
        cout << min_xor_count << endl;
}

int64 eat_bin()
{
    string b;
    cin >> b;
    int64 n = 0;
    for ( int i = 0; i < b.size(); ++i )
    {
        if ( b[i] == '1' )
        {
            n = n * 2 + 1;
        }
        else
            n = n * 2;
    }
    return n;
}

int main()
{
    int case_num;
    cin >> case_num;
    for ( int i = 0; i < case_num; ++i )
    {
        int node_count, bit_count;
        cin >> node_count >> bit_count;
        src.clear(); dest.clear();
        for ( int node_idx = 0; node_idx < node_count; ++node_idx )
        {
            int64 t = eat_bin();
            src.push_back( t );
        }
        for ( int node_idx = 0; node_idx < node_count; ++node_idx )
        {
            int64 t = eat_bin();
            dest.push_back( t );
        }

        printf( "Case #%d: ", i + 1);
        ans();
    }
    return 0;
}

