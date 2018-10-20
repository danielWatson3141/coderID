#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <fstream>
#include <memory>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <windows.h>

using namespace std;
#pragma warning(disable: 4996)

#define OUTPUTLOG2(X,Y)\
{\
	char msg[1024];\
	sprintf( msg, X, Y );\
	OutputDebugString(msg);\
}
#define OUTPUTLOG OutputDebugString

bool Check( vector<__int64>& lhs, vector<__int64>& rhs )
{
	sort( rhs.begin(), rhs.end() );
	sort( lhs.begin(), lhs.end() );
	for( int i = 0; i < lhs.size(); i++ ){
		if( lhs[i] != rhs[i] )
			return false;
	}
	return true;
}

int CntBit( vector<__int64>& r, int bit )
{
	int num = 0;
	for( int i = 0; i < r.size(); i++ )
		if( (r[i] & (1<<bit)) != 0 )
			num++;

	return num;
}

void RevBit( vector<__int64>& r, int bit )
{
	for( int i = 0; i < r.size(); i++ ){
		r[i] = r[i] ^ (1<<bit);
	}
}

int N, L;

int RecCheck( vector<__int64>& device, vector<__int64>& outlet, int i, vector<int>& type, int ans )
{
	if( i >= L ){
		if( Check( device, outlet ) ){
			return ans;
		}
		return INT_MAX;
	}
	if( Check( device, outlet ) ){
		return ans;
	}

	for( int j = i; j < L; j++ ){
		if( type[i] == 2 ){
			int r1 = RecCheck( device, outlet, i+1, type, ans );

			vector<__int64> outletrev(outlet);
			RevBit( outletrev, i );
			int r2 = RecCheck( device, outletrev, i+1, type, ans+1 );
			ans = min( r1, r2 );
		}
		break;
	}

	return ans;
}


void main(int argc, char*argv[]) // usage: main.exe in.txt out.txt
{
	int i,j,k,l,m,n;

	ifstream fin(argv[1]);
	if( fin == NULL ){
		OUTPUTLOG2("cannot open in-file : %s\n", argv[1]);
		return;
	}
	FILE* fout = fopen(argv[2],"w");
	if( fin == NULL ){
		OUTPUTLOG2("cannot open out-file : %s\n", argv[2]);
		return;
	}

/////////////////////////////
	char line[1024];
	int CASE;
	fin >> CASE;
	for( int test_case = 1; test_case <= CASE; test_case++ ){
	/////////////////////////////
		//fin.getline(line,1024);
		fin >> N;
		fin >> L;
		vector<__int64> device(N);
		vector<__int64> outlet(N);

		for( int i = 0; i < N; i++ ){
			string s;
			fin >> s;
			__int64 t = 0;
			for( int j = 0; j < L; j++ ){
				if( s[j] == '1' )
					t += (__int64)1 << j;
			}
			device[i] = t;
		}
		for( int i = 0; i < N; i++ ){
			string s;
			fin >> s;
			__int64 t = 0;
			for( int j = 0; j < L; j++ ){
				if( s[j] == '1' )
					t += (__int64)1 << j;
			}
			outlet[i] = t;
		}

		int ans = 0;

		vector<int> type(L,0);
		for( int i = 0; i < L; i++ ){
			int devb = CntBit( device, i );
			int outb = CntBit( outlet, i );
			if( devb == outb )
				if( devb&1 == 0 && devb == N/2 ){
					type[i] = 2;
				}else
					type[i] = 0;
			else if( devb == N-outb )
				type[i] = 1;
			else{
				ans = INT_MAX;
				goto end;
			}
		}

		for( int i = 0; i < L; i++ ){
			if( type[i] == 1 ){
				RevBit( outlet, i );
				ans++;
			}
		}

		if( Check( device, outlet ) ){
			goto end;
		}
		
		for( int i = 0; i < L; i++ ){
			if( type[i] == 2 ){
				int r1 = RecCheck( device, outlet, i+1, type, ans );

				vector<__int64> outletrev(outlet);
				RevBit( outletrev, i );
				int r2 = RecCheck( device, outletrev, i+1, type, ans+1 );
				ans = min(r1, r2);
			}
			break;
		}
	

	/////////////////////////////
end:
		if( ans == INT_MAX )
			fprintf(fout,"Case #%d: NOT POSSIBLE\n", test_case);
		else
			fprintf(fout,"Case #%d: %d\n", test_case, ans);
		if( fin.eof() ){
			if( test_case != CASE ){
				OUTPUTLOG( "in-file error:eof" );
			}
			break;
		}
	}

	OUTPUTLOG( "program end" );
}