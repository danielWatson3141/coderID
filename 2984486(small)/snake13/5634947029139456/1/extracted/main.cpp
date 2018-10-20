#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <fstream>
#include <math.h>
#include <map>
#include <string>
#include <ctime>
#define LL long long int
#define double long double
using namespace std;

void solve (int T)
{
	int i,j,k,n,l,MIN;
	cin>>n>>l;
	string s;
	vector <string> v,dev;
	for (i=0; i<n; i++)
	{
		cin>>s;
		v.push_back(s);
	}
	for (i=0; i<n; i++)
	{
		cin>>s;
		dev.push_back(s);
	}

	vector <string> possible, help;
	vector <int> count;
	for (i=0; i<n; i++)
	{
		s = "";
		int a = 0;
		for (j=0; j<l; j++)
			if (v[0][j] == dev[i][j])
				s += '0';
			else
			{
				s += '1';
				a++;
			}
		possible.push_back(s);
		count.push_back(a);
	}
	MIN = 10000;
	sort(dev.begin(), dev.end());
	for (i=0; i<n; i++)
	{
		help = v;
		for (j=0; j<n; j++)
		{
			for (k=0; k<l; k++)
				if (help[j][k] == possible[i][k])
					help[j][k] = '0';
				else
					help[j][k] = '1';
		}
		sort(help.begin(), help.end());
		if (help==dev && count[i] < MIN) MIN = count[i];
	}

	cout << "Case #" <<T<<": ";
	if (MIN == 10000) cout<<"NOT POSSIBLE" << endl;
	else cout<<MIN<<endl;
}

int main()
{
	freopen("A-large.in", "r", stdin); freopen("output.txt", "w", stdout);
	int i, t;
	cin>>t;
	for (i=1; i<=t; i++)
		solve(i);
	return 0;
}