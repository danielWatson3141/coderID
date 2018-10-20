#include <iostream>
#include <fstream>
#include <string.h>

#define INF 1000000

using namespace std;

ofstream fout("file.out");

int t,n,l,f[19],ans = INF;

string v[19],v1[19];

void func (int x,int y)
{
	if (x == l)
	{
		string v2[19];
		bool vis[19],o1 = 0;
		
		fill(vis,vis+18,0);
		
		for (int i = 0; i < n; i++)
		{
			string s;
			for (int h = 0; h < l; h++)
			{
				if (f[h] == 1)
				{
					if (v[i][h] == '1')
				 		s+='0';
				 	else
				 		s+='1';
				}
				else
					s+=v[i][h];
			}
			
			bool o = 0;
			for (int h = 0; h < n; h++)
				if (v1[h] == s && vis[h] == 0) {vis[h] = 1,o = 1;break;}
				
			if (o == 0) {o1=1;break;}
		}
		
		if (o1 == 0)
			ans = min(ans,y);
			
		return;
	}
	
	for (int i = 0; i <= 1; i++)
	{
		if (i == 1) f[x] = 1,func (x+1,y+1);
		else f[x] = 0,func (x+1,y);
	}
}

int main()
{
	cin >> t;
	
	for (int i = 0; i < t; i++)
	{
		cin >> n >> l;
		
		for (int h = 0; h < n; h++)
			cin >> v[h];
			
		for (int h = 0; h < n; h++)
			cin >> v1[h];
			
		func (0,0);
		
		fout << "Case #" << i+1 << ": ";
		
		if (ans == INF) fout << "NOT POSSIBLE\n";
		else fout << ans << "\n";
		
		ans = INF;
	}
}
