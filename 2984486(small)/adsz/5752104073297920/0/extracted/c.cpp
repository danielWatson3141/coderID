#include <cstdio>
#include <cstdlib>
#include <string>
#include <sstream>
#include <set>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>

using namespace std;

const int N = 1000;
double chance[N][N];
	

int main()
{
	int iters = 1000000;
	for(int i=0;i<iters;i++)
	{
		int a[N];
		for(int j=0;j<N;j++) a[j] = j;
		
		for(int j=0;j<N;j++)
			swap(a[j], a[random()%N]);
			
		for(int j=0;j<N;j++)
		{
			chance[j][ a[j] ] += 1./iters;
		}
	}
	
		
	int t;
	scanf("%d", &t);
	
	vector<pair<double, int>> ratings;
	for(int cn=1;cn<=t;cn++)
	{
		scanf("%*d");
		
		double ch = 1.0;
		for(int i=0;i<N;i++)
		{
			int x;
			scanf("%d", &x);
			ch *= pow(chance[i][x]*N, 0.1);
			//dst += fabs(i - avgpos[x]);
			//dst += fabs(x - avgval[i]);
		}
		ratings.push_back(make_pair(ch, cn));
		printf("%f ", ch);
	}
	sort(ratings.begin(), ratings.end());
	
	set<int> bad;
	for(int i=t/2;i<t;i++)
	{
		bad.insert(ratings[i].second);
	}
	
	for(int cn=1;cn<=t;cn++)
	{		
		printf("Case #%d: %s", cn, bad.count(cn)==1 ? "BAD" : "GOOD");
		printf("\n");
	}
}
