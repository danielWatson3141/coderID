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

int run( int root, int parent, const vector<vector<int> >& tree, int& count )
{
	//cerr << root << " ";
	int ans = 0;
	int childsCount = tree[root].size();
	if( parent != -1 ) {
		childsCount --;
	}
	count = 1;
	if( childsCount == 0 )
	{
		return 0;
	}
	if( childsCount == 2 )
	{
		for( int i = 0; i < tree[root].size(); i++ )
		{
			int c = tree[root][i];
			if( c == parent )
			{
				continue;
			}
			int subCount;
			ans += run( c, root, tree, subCount );
			count += subCount;
		}
	} else
	{
		int sum = 0;
		int max1 = 0;
		int max2 = 0;
		for( int i = 0; i < tree[root].size(); i++ )
		{
			int c = tree[root][i];
			if( c == parent )
			{
				continue;
			}
			int subCount;
			int remove = run( c, root, tree, subCount );
			count += subCount;
			int addRemove = subCount - remove;
			if( addRemove >= max1 )
			{
				max2 = max1;
				max1 = addRemove;
			} else if( addRemove >= max2 )
			{
				max2 = addRemove;
			}
			sum += subCount;
		}
		if( childsCount == 1 )
		{
			ans = sum;
		} else 
		{
			ans = sum - max1 - max2;
		}
	}
	return ans;
}

int main()
{
	freopen( "input.txt", "r", stdin );
	freopen( "output.txt", "w", stdout );
	int t;
	cin >> t;
	for( int tt = 1; tt <= t; tt++ )
	{
		int n;
		cin >> n;
		vector<vector<int> > tree(n);
		for( int i = 0; i < n - 1; i++ )
		{
			int a, b;
			cin >> a >> b;
			a--; b--;
			tree[a].push_back( b );
			tree[b].push_back( a );
		}
		int ans = n - 1;
		for( int root = 0; root < n; root++ )
		{
			int count;
			int testAns=  run(root, -1, tree, count);
			ans = min( ans, testAns ) ;
			//cerr << endl << "Test root: " << root << " == " << testAns << " " << count << endl;
		}
		
		cout << "Case #" << tt << ": ";
		cout << ans;
		cout << endl;
//		break;
	}
	return 0;
}

