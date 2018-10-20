
#include <iostream>
#include <cstdio>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

#define fr( i , c , n ) for( int i = (c) ; i < (n) ;i++ )
#define clr( a , c ) memset( a , c , sizeof a )
#define P pair<int , int>
#define L  long long

#define maxn 1005

vector<int> graph[maxn];
bool visited[maxn];
int n;

P dfs( int v )// subtree size , nr to delete
{
	visited[v] = true;
	vector<P> children;
	P ans;
	for( vector<int>::iterator it = graph[v].begin() ; it != graph[v].end() ; it++ )
		if( !visited[*it] )
			children.push_back( dfs( *it ) );

	if( children.size() > 2 )
	{
		sort( children.begin() , children.end() );
		int d = children[children.size()-1].second + children[children.size()-2].second;
		int sum = children[children.size()-1].first + children[children.size()-2].first;
		for( int i = 0 ; i < children.size()-2 ; i++ )
		{
			d += children[i].first;
			sum += children[i].first;
		}
		ans = P( sum + 1 , d );
	}
	else if( children.size() == 2 )
	{
		int d = children[0].second + children[1].second;
		ans = P( children[0].first + children[1].first + 1 , d );
	}
	else if( children.size() == 1 )
	{
		ans = P ( 1 + children[0].first , children[0].first );
	}
	else
		ans = P( 1 , 0 );
	return ans;

}
int main()
{

	int T; scanf("%d" , &T );
	fr( t , 1 , T+1 )
	{
		fr( i , 0 , maxn )graph[i].clear();
		scanf("%d" , &n );

		fr( i , 0 , n-1 )
		{
			int a , b; scanf("%d%d" , &a , &b );a--;b--;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		int ans = n;
		fr( i , 0 , n )//root
		{
			clr( visited , false );
			ans = min( ans , dfs( i ).second );
		}
		
		printf("Case #%d: %d\n" , t , ans );
		
	}
	return 0;
}