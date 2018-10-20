#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
	ifstream cin;
	cin.open("in.in");
	ofstream cout;
	cout.open("out.out");
	int t;
	cin>>t;
	for (int i =1; i <=t; i++)
	{
		int n,l;
		cin>>n>>l;
		vector<string> sw(n);
		vector<string> d(n);
		for (int j = 0; j < n; j++) cin>>sw[j];
		for (int j = 0; j < n; j++) cin>>d[j];
		sort(d.begin(), d.end());
		int mn = 1000000;
		for (int k = 0; k < n; k++)
		{
			int ch = 0;
			vector<bool> tk(l, false);
			for (int z = 0; z<l; z++)
			{
				if (sw[k][z] != d[0][z])
				{
					ch++;
					tk[z] = true;
				}
			}
			vector<string> sw2 = sw;
			for (int a = 0; a < n; a++)
			{
				for (int z = 0; z<l; z++)
				{
					if (sw2[a][z] == '0' && tk[z]) sw2[a][z] = '1';
					else if (sw2[a][z] == '1' && tk[z]) sw2[a][z] = '0';
				}
			}
			sort(sw2.begin(), sw2.end());
			bool ok = true;
			//cout<<ch<<endl;
			for (int a = 0; a < n; a++)
			{
				if (d[a] != sw2[a]) ok =false;
			}
			if (ok)
				mn = min(mn, ch);
		}
		if (mn == 1000000)
		{
			cout<<"Case #"<<i<<": NOT POSSIBLE"<<endl;
		}
		else
			cout<<"Case #"<<i<<": "<<mn<<endl;
	}
}