#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <sstream>

using namespace std;

char out[150][64];
char dev[150][64];
int ans;

bool valid (int p, int n)
{
	map<string,int> m;
	for (int i = 0; i < n; i += 1)
	{
		string s = out[i];
		m[s.substr(0,p+1)]++;
		
		
		s = dev[i];
		m[s.substr(0,p+1)]--;	
	}
	
	map<string,int>::iterator it;
	for (it = m.begin(); it != m.end(); ++it)
	{
		//printf("%d %s = %d\n",p,it->first.c_str(),it->second);
		if (it->second != 0) return false;
	}
	
	return true;
}

void solve(int p, int c, int n, int l)
{
	if (p == l)
	{
		//printf("S %d\n",c);
		ans = min(ans,c);
	}
	else
	{
		for (int i = 0; i < 2; i += 1)
		{
			for (int j = 0; j < n; j += 1)
			{
				int v = (out[j][p] - '0' + i) % 2;
				out[j][p] = '0'+v;
			}
			
			if (valid(p,n))
			{
				//printf("V %d = %d\n",p+1,i);
				solve(p+1,c+i,n,l);
			}
			else
			{
			}
			
			for (int j = 0; j < n; j += 1)
			{
				int v = (out[j][p] - '0' - i + 2) % 2;
				out[j][p] = '0'+v;
			}
		}
	}
}

int main (int argc, char const* argv[])
{
	int T;
	scanf("%d",&T);
	
	for (int t = 1; t <= T; t += 1)
	{
		int n,l;
		scanf("%d %d",&n,&l);

		for (int i = 0; i < n; i += 1)
		{
			scanf("%s",out[i]);
		}
		
		for (int i = 0; i < n; i += 1)
		{
			scanf("%s",dev[i]);
		}
		
		ans = 0x3f3f3f3f;
		solve(0,0,n,l);
		
		printf("Case #%d: ",t);
		if (ans != 0x3f3f3f3f)
			printf("%d\n",ans);
		else
			printf("NOT POSSIBLE\n");
	}
	return 0;
}
