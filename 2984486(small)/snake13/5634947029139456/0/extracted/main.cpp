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
	int i,j,k,n,l;
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
	int kol = 1;
	for (i=0; i<l; i++) kol*=2;
	sort(dev.begin(), dev.end());

	vector <string> help;
	int a, MIN = 10000;
	for (i=0; i<kol; i++)
	{
		int N = i;
		help = v;
		a = 0;
		for (j=0; j<l; j++)
		{
			for (k=0; k<n; k++)
			{
				help[k][j] = (((int) v[k][j] -'0' + N%2)%2) + '0';
			}
			a += N%2;
			N/=2;
		}
		sort(help.begin(), help.end());
		if (help == dev && a < MIN)
		{
			MIN = a;
		}
		//cout<<i<<" " << a << endl;
		//for (j=0; j<n; j++) cout<<dev[j]<<" "; cout<<endl;
		//for (j=0; j<n; j++) cout<<help[j]<<" "; cout<<endl;
	}
	cout << "Case #" <<T<<": ";
	if (MIN == 10000) cout<<"NOT POSSIBLE" << endl;
	else cout<<MIN<<endl;
}

int main()
{
	freopen("A-small-attempt2.in", "r", stdin); freopen("output.txt", "w", stdout);
	int i, t;
	cin>>t;
	for (i=1; i<=t; i++)
		solve(i);
	return 0;
}