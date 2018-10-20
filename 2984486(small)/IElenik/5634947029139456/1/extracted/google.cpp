#define _cRT_SEcURE_NO_DEPREcATE
//#define long long long long

#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <assert.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <map>
#include <list>
#include <set>
#include <deque>
#include <math.h>

using namespace std;

FILE * in, * out;

#define fo(a,b,c) for(int a = ( b ); a < ( c ); ++ a )
#define fr(a,b) fo( a, 0, ( b ) )
#define fi(a) fr( i, ( a ) )
#define fj(a) fr( j, ( a ) )
#define fk(a) fr( k, ( a ) )
#define mp make_pair
#define pb push_back
#define all(v) (v).begin( ), (v).end( )
#define _(a,b) memset( a, b, sizeof( a ) )

int ri() { int a; fscanf(in, "%d", &a ); return a; }
double rf() 
{ 
	double a; 
	fscanf(in, "%lf", &a ); 
	return a; 
}

char * sbuf = 0; 
string rstr() 
{
	//fscanf(in, "%lf", sbuf); 
	if(sbuf == 0)
		sbuf = new char [(1<<20)+1];

	char c;
	char * b = sbuf;
	while(c = fgetc(in))
	{
		if(c == '\r' || c == '\n' || c == -1) 
		{
			if(b - sbuf > 0)
				break;
			continue;
		}
		*b++=c;
	}
	*b = 0;
	return sbuf; 
}
long long rll() { long long a; fscanf(in, "%lld", &a ); return a; }

long long readbi(int l)
{
	long long res = 0;
	int count = 0;
	int c;
	while( (c = fgetc(in)) && l != 0)
	{
		if(c == '1' || c == '0') 
		{
			res *= 2;
			if(c == '1') res |= 1;
			l--;
		}
	}
	return res;
}

int main(int argc, char * argv[])
{
	in	= fopen("A-large (1).in","rt");
	out	= fopen("out.txt","wt");
	int numcases = ri();


	for(int ca = 1; ca<=numcases; ca++)
	{
		int n = ri();
		int l = ri();

		vector<long long> src(n);
		vector<long long> dst(n);
		vector<long long> tmp(n);
		for(int i = 0; i<n; i++)
			src[i] = readbi(l);
		for(int i = 0; i<n; i++)
			dst[i] = readbi(l);
		
		sort(src.begin(),src.end());
		sort(dst.begin(),dst.end());

		int n_bits = l+1;
		for(int i = 0; i<n; i++)
		{
			long long mask = dst[i]^src[0];
			for(int i = 0; i<n; i++)
				tmp[i] = (src[i]^mask);
			sort(tmp.begin(),tmp.end());
			bool bfound = false;
			for(int i = 0; i<n; i++)
				if(tmp[i] != dst[i]) bfound = true;
			if(!bfound) 
			{ 
				long long cb = 1;
				int count = 0;
				for(int i = 0; i<l; i++)
				{
					if(mask&cb) count ++;
					cb *= 2;
				}

				if(n_bits >= count) n_bits = count;
			}

		}


		if(n_bits <= l)
			fprintf(out,"Case #%d: %d\n", ca, n_bits);
		else
			fprintf(out,"Case #%d: NOT POSSIBLE\n", ca);
	}
	return 0;
}

