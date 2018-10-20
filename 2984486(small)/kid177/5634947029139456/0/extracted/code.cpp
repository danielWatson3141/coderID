#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>

using namespace std;

#define WRITE

void output()
{
	static int cc = 1;
	printf("Case #%d: ", cc++);
}
int n,l;
int one_up[50];
int zero_up[50];
int one_down[50];
int zero_down[50];
string str_up[200];
string str_down[200];
string res[50];
bool hash[200][200];
map<string, bool>hh[50];
int main() 
{
	#ifdef WRITE
	freopen("A--small-attempt3.in","r",stdin);
	freopen("result","w",stdout);
	#endif
	int _;
	cin>>_;
	while(_--)
	{
		cin>>n>>l;
		memset(one_up, 0, sizeof(one_up));
		memset(zero_up, 0, sizeof(zero_up));
		memset(one_down, 0, sizeof(one_down));
		memset(zero_down, 0, sizeof(zero_down));

		for(int i = 0; i < 50; i ++)
		hh[i].clear();
		for (int i = 0; i < n; i ++)
			for(int j = 0; j < n; j ++)
				hash[i][j] = true;
		for (int i = 0; i < n;i ++)
		{
			cin>>str_up[i];
		}
		for (int i = 0; i < n;i ++)
		{
			cin>>str_down[i];
		}
		for(int i = 0; i < n; i ++)
		{
			
			for(int j = 0; j < n; j ++)
			{
				string temp = "";
				for(int k = 0;k < l;k ++)
				{
					if(str_up[i][k] == str_down[j][k])temp += "0";
					else temp += "1";
				}
				//cout<<temp<<endl;
				hh[i][temp] = true;
				if (i == 0)
				res[j] = temp; 
			}
		}
		int mini = 10000;
		for(int i = 0; i < n; i ++)
		{
			int cnt = 0;
			for (int ll = 0; ll < res[i].size(); ll++)
				if(res[i][ll] == '1')
					cnt ++;
			int j;
			for(j = 1; j < n; j ++)
			{
				if(hh[j].find(res[i]) == hh[j].end())break;
			}
			if(j == n)mini = min(mini, cnt);
		}		
		output();
		if(mini == 10000)puts("NOT POSSIBLE");
		else cout<<mini<<endl;
	}
}