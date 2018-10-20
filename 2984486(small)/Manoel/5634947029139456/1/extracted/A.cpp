#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> outlets, devices;

string transform(string a, string p)
{
	string t = "";
	
	for(int i=0; i<p.size(); i++)
	{
		if(p[i] == '0')
			t += a[i];
		else
		{
			if(a[i] == '0')
				t += "1";
			else
				t += "0";
		}
	}
	
	return t;
}

bool test(string p)
{
	vector<string> v;
	
	for(int i=0; i<outlets.size(); i++)
		v.push_back(transform(outlets[i], p));
	
	sort(v.begin(), v.end());
	
	bool fit = true;
	
	for(int i=0; i<v.size(); i++)
		if(v[i] != devices[i])
			fit = false;
	
	return fit;
}

int main()
{
	//freopen("A-large.in", "r", stdin);
	//freopen("A-large.out", "w", stdout);
	
	int nt, t=1;
	scanf(" %d", &nt);
	
	while(nt--)
	{
		int n, l;
		scanf(" %d %d", &n, &l);
		
		outlets.clear();
		devices.clear();
		
		for(int i=0; i<n; i++)
		{
			char str[50];
			scanf(" %s", str);
			
			outlets.push_back(string(str));
		}
		
		for(int i=0; i<n; i++)
		{
			char str[50];
			scanf(" %s", str);
			
			devices.push_back(string(str));
		}
		
		sort(devices.begin(), devices.end());
		
		int ans = -1;
		
		for(int i=0; i<outlets.size(); i++)
		{
			string p = "";
			int cost = 0;
			
			for(int j=0; j<l; j++)
			{
				if(outlets[i][j] == devices[0][j])
				{
					p += "0";
				}
				else
				{
					p += "1";
					cost += 1;
				}
			}
			
			if(test(p))
				ans = ans < 0 ? cost : min(ans, cost);
		}
		
		printf("Case #%d: ", t++);
		if(ans < 0)
			printf("NOT POSSIBLE\n");
		else
			printf("%d\n", ans);
	}
	
	//fclose(stdin);
	//fclose(stdout);
	
	return 0;
}
