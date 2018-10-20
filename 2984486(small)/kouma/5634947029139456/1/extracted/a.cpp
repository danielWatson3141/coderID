
#include <iostream>
#include <string>
#include <vector>
#include <set>

#include <stdio.h>
#include <stdlib.h>

char CASE[] = "CASE #";
char FAIL[] = "NOT POSSIBLE";

std::vector<int> read_line()
{
    int index = 0;
    int prev  = 0;

    std::string line;
    std::vector<int> values;
    std::getline( std::cin, line );

    while( std::string::npos != index )
    {
        int size = 0;
        index = line.find( " ", prev );
        if( std::string::npos != index ) {
            size = index - prev;
        }
        else {
            size = index;
        }
        std::string tmp_string = line.substr( prev, size );
        values.push_back( atoi( tmp_string.c_str() ) );
        if( std::string::npos == index )
        {
            break;
        }
        prev = index+1;
    }

    return values;
}

long long read_bdigit( std::string &num_str )
{
    long long num = 0;
    long long val = 1;
    for( int i = 0; i < num_str.size(); i++ ) {
        num += val * ( ( num_str[i] == '1' ) ? 1 : 0 );
        val *= 2;
    }
    return num;
}

std::vector<long long> read_bin_line()
{
    int index = 0;
    int prev  = 0;

    std::string line;
    std::vector<long long> values;
    std::getline( std::cin, line );

    while( std::string::npos != index )
    {
        int size = 0;
        index = line.find( " ", prev );
        if( std::string::npos != index ) {
            size = index - prev;
        }
        else {
            size = index;
        }
        std::string tmp_string = line.substr( prev, size );
        values.push_back( read_bdigit( tmp_string ) );
        if( std::string::npos == index )
        {
            break;
        }
        prev = index+1;
    }

    return values;
}

bool check( const long long &diff, int diff_idx, const std::vector<long long> &dev, const std::vector<long long> &outlet )
{
    bool ok = true;
    std::set<int> check_list;
    check_list.insert( diff_idx );
    for( int i = 1; i< dev.size(); i++ ) {
        bool is_find = false;
        for( int j = 0; j < outlet.size(); j++ ) {
            if( check_list.end() == check_list.find( j ) ) {
                if( diff == ( dev[i] ^ outlet[j] ) ) {
                    check_list.insert( j );
                    is_find = true;
                    break;
                }
            }
        }
        if( !is_find ){
            ok = false;
            break;
        }
    }
    return ok;
}

int main()
{
    std::vector<int> tmp;
    int case_num = 0;

    tmp = read_line();
    case_num = tmp[0];

    for( int i = 0; i < case_num; i++ )//SET Any
    {
        std::vector<int> env = read_line();

        std::vector<long long> outlet = read_bin_line();
        std::vector<long long> dev    = read_bin_line();
        bool is_find = false;
        int  num = 0;

        for( std::vector<long long>::iterator it = dev.begin(); it != dev.end(); ++it ) {
            for( int j = 0; j < outlet.size(); j++ ) {    
                long long diff = *it ^ outlet[j];

                int tmp_num = 0;
                if( 0 != diff ) {
                    for( int k = 0; k < env[1]; k++ ) {
                        if( diff & ( 1 << k ) ) {
                            tmp_num++;
                        }
                    }
                }
                
                if( ( check( diff, j, dev, outlet ) ) &&
                    ( ( num > tmp_num ) || ( num == 0 ) ) ) {
                    num = tmp_num;
                    is_find = true;
                    if( 0 == tmp_num ) {
                        break;
                    }
                }
            }
            break;
        }

        if( is_find ) {
            printf( "%s%d: %d\n", CASE, i+1, num );
        }
        else {
            printf( "%s%d: %s\n", CASE, i+1, FAIL );
        }
    }
}

