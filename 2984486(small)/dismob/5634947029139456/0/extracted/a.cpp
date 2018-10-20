
#include <iostream>

#include <vector>
#include <string>


using namespace std;


int n, l;
vector<string> ol;
vector<string> dev;


int main( int, const char*[] )
{

	int test_num;
	cin >> test_num;

	for( int test=0; test<test_num; ++test )
	{

		cin >> n >> l;
		ol = dev = vector<string>( n );
		for( int i=0; i<n; ++i ) cin >> ol[i];
		for( int i=0; i<n; ++i ) cin >> dev[i];

		int res =-1;
		for( int i=0; i<(1<<l); ++i )
		{
			bool possible =true;
			int dc =0;
			vector<int> d( n, 0 );
			for( int j=0; j<n; ++j )
			{
				bool found =false;
				for( int k=0; k<n; ++k )
				{
					if ( d[k] ) continue;
					bool ok =true;
					for( int a=0; a<l; ++a )
					{
						const auto kOL = ( ol[j][a]-'0' ) ^( ( i & (1<<a) ) ? 1 : 0 );
						const auto kDev = dev[k][a]-'0';
						if ( kOL != kDev )
						{
							ok =false;
							break;
						}
					}
					if ( ok )
					{
						d[k] =1;
						found =true;
						break;
					}
				}
				if ( !found )
				{
					possible =false;
					break;
				}
			}

			if ( possible )
			{
				int count =0;
				for( int j=0; j<l; ++j ) if ( i&(1<<j) ) ++count;
				if ( res==-1 || res>count ) res =count;
			}
		}

		cout << "Case #" << (test+1) << ": ";
		if ( res < 0 )
		{
			cout << "NOT POSSIBLE";
		}
		else
		{
			cout << res;
		}
		cout << endl;
	}

	return 0;
}

