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
#include <string>
#include <complex>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <climits>
#include <ctime>

#include<unordered_map>
#include<unordered_set>
using namespace std;

int cases , Case = 1;
////////////


vector<int> good(int n )
{
	vector<int> a(n);
	for(int i = 0 ; i < n; ++i)
		a[i] = i;

	for(int i = 0 ; i < n; ++i)
	{
		int aa = rand()%(n-i)+i;
		swap( a[i] , a[aa]);
	}
	return a;
}

vector<int> bad(int n )
{
	vector<int> a(n);
	for(int i = 0 ; i < n; ++i)
		a[i] = i;

	for(int i = 0 ; i < n; ++i)
	{
		int aa = rand()%n;
		swap( a[i] , a[aa]);
	}
	return a;
}

int main()
{	
	srand(time(0));
	scanf("%d" , &cases);	
	while( cases-- )
	{
		printf("Case #%d: " , Case++ );
		
		int n;
		cin >> n;
		vector<int> in(n);
		for(int i = 0 ; i < n; ++i)
			cin >> in[i];

		int guess = 0 , guessb=0;
		int AA = 1000;

		for(int a = 0 ; a < AA; ++a)
		{
			auto gg = good(n);
			auto bb = bad(n);
			int c = 0 , b = 0;
			for(int i = 0 ; i < n; ++i)
			{
				if( in[i] == gg[i] )
					++c;
				if( in[i] == bb[i] )
					++b;
			}

			/*if( c == n )
			{
				guess = AA;
				break;
			}
			else*/ if( c > n/2 )
			{
				++guess;
			}
			if( b > n/2 )
			{
				++guessb;
			}
		}




		if( rand()&1 )
			puts("GOOD");
		else
			puts("BAD");
	}

	

	return 0;
}