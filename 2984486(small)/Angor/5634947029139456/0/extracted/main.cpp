#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <assert.h>

const int INF = 1e9;

using namespace std;

int main()
{
	freopen( "input.txt", "r", stdin );
	freopen( "output.txt", "w", stdout );
	int t;
	cin >> t;
	for( int tt = 1; tt <= t; tt++ )
	{
		int ans = -1;

		int n, l;
		cin >> n >> l;
		vector<long long> input;
		vector<long long> output;
		for( int i = 0; i < n; i++ )
		{
			string s;
			cin >> s;
			long long mask = 0;
			for( int i = 0; i < s.size(); i++ )
			{
				if( s[i] == '1' )
				{
					mask = mask | (1 << i);
				}
			}
			input.push_back(mask);
		}
		
		for( int i = 0; i < n; i++ )
		{
			string s;
			cin >> s;
			long long mask = 0;
			for( int i = 0; i < s.size(); i++ )
			{
				if( s[i] == '1' )
				{
					mask = mask | (1 << i);
				}
			}
			output.push_back(mask);
		}


		for( int mask = 0; mask < 1 << l; mask++ )
		{
			int count = 0;
			int maskCopy = mask;
			while( maskCopy ) 
			{
				count++;
				maskCopy = maskCopy & (maskCopy - 1);
			}

			set<int> newInput;
			for( int i = 0; i < n; i++ )
			{
				newInput.insert( input[i] ^ mask );
			}
			bool isAns = true;
			for( int i = 0; i < n; i++ )
			{
				if( newInput.find(output[i]) == newInput.end() )
				{
					isAns = false;
					break;
				}
			}
			if( isAns )
			{
				ans = ans == -1 ? count : min( ans, count );
			}
		}

		cout << "Case #" << tt << ": ";
		if( ans == -1 ) {
			cout << "NOT POSSIBLE";
		} else 
		{
			cout << ans;
		}
		cout << endl;
	}
	return 0;
}

