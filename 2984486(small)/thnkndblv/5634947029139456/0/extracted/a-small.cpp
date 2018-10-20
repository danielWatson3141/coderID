using namespace std;

#include "stdio.h"
#include "vector"
#include "algorithm"

char buff[ 1003 ];
vector <int> flow;
vector <int> req;

bool test(int n, int mask)
{
	vector< int > x;

	for (int i = 0; i < n; i++)
	{
		x.push_back( flow[ i ] ^ mask );
	}

	sort( x.begin(), x.end() );
	return x == req;
}

int bitCount(int n)
{
	int ret = 0;

	while (n > 0)
	{
		if ( n & 1 ) ret++;
		n >>= 1;
	}

	return ret;
}

int main()
{
	int ntc;

	scanf("%d", &ntc);

	for (int tc = 1; tc <= ntc; tc++)
	{
		int n, l;
		scanf("%d %d", &n, &l);

		flow.assign(n, 0);
		for (int i = 0; i < n; i++)
		{
			scanf("%s", buff);
			for (int j = 0; j < l; j++)
			{
				flow[ i ] <<= 1;
				if ( buff[ j ] == '1' ) flow[ i ] |= 1;
			}
		}

		req.assign(n, 0);
		for (int i = 0; i < n; i++)
		{
			scanf("%s", buff);
			for (int j = 0; j < l; j++)
			{
				req[ i ] <<= 1;
				if ( buff[ j ] == '1' ) req[ i ] |= 1;
			}
		}
		sort( req.begin(), req.end() );

		int ans = 1000000000;

		int N = 1 << l;
		for (int i = 0; i < N; i++) if ( test( n, i ) )
		{
			ans = min( ans, bitCount( i ) );
		} 

		if (ans == 1000000000) printf("Case #%d: NOT POSSIBLE\n", tc);
		else printf("Case #%d: %d\n", tc, ans);
	} 

	return 0;
}
