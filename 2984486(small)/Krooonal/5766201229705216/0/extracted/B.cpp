#include <cstdio>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <set>
#include <map>
#include <list>
#include <string>
#include <cstring>

using namespace std;

#define DEBUG 0
#define all(C) (C).begin() , (C).end()
#define tr(C , it) for(typeof((C).begin()) it = (C).begin() ; it != (C).end() ; it++)
#define present(C , key) ((C).find(key) != (C).end())
#define cpresent(C , key) (find(all(C) , key) != (C).end())
#define sz(a) int((a).size())
#define pb push_back
#define MOD 1000000007


typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int , int> PI;

int graph[16][16];
int N;
set<int> removed;
int visited[16];

int degr(int r)
{
	int i , ret = 0;
	for(i=0 ; i<N ; i++)
	{
		if(removed.count(i) != 0)
			continue;
			
		if(graph[r][i] == 1)
			ret++;
	}
	return ret;
}

bool checkfb(int r)
{
	int i;
	int deg = degr(r);
	
	if(deg != 1 && deg != 3)
		return false;
		
	bool flag = true;
	visited[r] = 1;
	for(i=0 ; i<N ; i++)
	{
		if(removed.count(i) != 0)
			continue;
			
		if(graph[r][i] && visited[ i ] == 0)
			flag = flag & checkfb(i);
	}
	return flag;
}

int main()
{
	int __A;
	scanf("%d" , &__A);
	
	int i , j;
	int u , v , flag , k , ans , deg;
	for(int _i = 1 ; _i <= __A ; _i++)
	{
		printf("Case #%d: " , _i);
		scanf("%d" , &N);

			
		ans = N-1;
		memset(graph , 0 , sizeof(graph));
		for(i=0 ; i<N ; i++)
		{
			scanf("%d %d" , &u , &v);
			u--;
			v--;
			graph[u][v] = 1;
			graph[v][u] = 1;
		}
		
		//brute force
		removed.clear();
		for(i=0 ; i<(1 << N) ; i++)
		{
			removed.clear();
			//printf("removing ");
			for(j=0 ; j<N ; j++)
			{
				if(i & (1 << j))
				{
					removed.insert(j);
					//printf("%d " , j);
				}
			}
			//printf("\n");
			
			flag = false;
			for(j=0 ; j<N ; j++)
			{
				if(removed.count(j) != 0)
					continue;
				
				if(degr(j) != 2)
					continue;
				memset(visited , 0 , sizeof(visited));
				flag = true;
				visited[j] = 1;
				for(k=0 ; k<N ; k++)
				{
					if(removed.count(k) != 0)
						continue;
			
					if(graph[j][k] && visited[ k ] == 0)
						flag = flag & checkfb(k);
					
				}
				if(flag)
				{
					flag = true;
					for(k = 0 ; k < N ; k++)
					{
						if( !visited[k] && removed.count(k) == 0)
						{
							flag = false;
						}
					}
					if(flag)
						break;
				}
			}
			
			if(flag)
			{
				ans = min(ans , (int)removed.size());
			}
		}
		printf("%d\n" , ans);
		
	}
	return 0;
}
