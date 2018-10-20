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

typedef pair<int, pair<int,int>  >  ChildInfo;

char vis[1024];
ChildInfo dfs(int cur , vector< vector<int> >& g )
{
	vis[cur] = 1;


	vector< ChildInfo > child;
	for(int i = 0 ; i < g[cur].size(); ++i)
	{
		if( !vis[g[cur][i]] )
		{
			child.push_back( dfs( g[cur][i] , g ) );
		}
	}

	if( child.empty() )
		return make_pair( 0 , make_pair(0,1) );

	if( child.size() == 1 )
	{
		if( child[0].first == 0 )
			return make_pair( 1 , make_pair( child[0].second.first , child[0].second.second+1 ) ); // a--b
		else
			return make_pair( 0 , make_pair( child[0].second.first+child[0].second.second , 1 )  ); //no use
	}

	sort( child.begin() , child.end() );

	int del = 0;
	int s = 1;
	char good = 0;
	for(int i = child.size() ; i--; )
	{
		if(good < 2 )
		{
			++good;
			if( child[i].first == 1 )
			{
				del += child[i].second.first + child[i].second.second-1  ;
				++s;
			}
			else
			{
				del += child[i].second.first  ;
				s += child[i].second.second  ;
			}
		}
		else
		{
			del += child[i].second.first + child[i].second.second  ;
		}
	}


	return make_pair(good, make_pair(del, s )  );
}


int main()
{	
	
	scanf("%d" , &cases);	
	while( cases-- )
	{
		printf("Case #%d: " , Case++ );
		
		int n;
		cin >> n;

		vector< vector<int> > g(n);

		for(int i = 0 ; i < n-1; ++i)
		{
			int s , t;
			cin >> s >> t;
			--s; --t;
			g[s].push_back(t);
			g[t].push_back(s);
		}

		int ans = INT_MAX;
		for(int i = 0 ; i < n; ++i)
		{
			memset( vis, 0 , sizeof(vis) );
			auto a  = dfs(i,g);

			int t =  a.second.first;
			if( a.first == 1)
				t = n-1;
			ans = min(ans, t);
		}
		
		printf("%d\n" , ans);
		

	}

	

	return 0;
}

