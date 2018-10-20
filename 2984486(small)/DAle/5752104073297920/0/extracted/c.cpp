#include <fstream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <utility>
#include <cmath>
#include <functional>
#include <stack>
#include <set>
#include <iostream>

using namespace std;

int a[1005];
vector<pair<double,int> > res; 

vector<int> genGood(int n)
{
	vector<int> a(n);
	for (int k = 0; k < n; ++k)
		a[k] = k;
	for (int k = 0; k < n; ++k)
	{
		int p = k + rand() % (n-k);
		swap(a[k], a[p]);
	}
	return a;
}

vector<int> genBad(int n)
{
	vector<int> a(n);
	for (int k = 0; k < n; ++k)
		a[k] = k;
	for (int k = 0; k < n; ++k)
	{
		int p = rand() % n;
		swap(a[k], a[p]);
	}
	return a;
}

int main()
{
/*
	ofstream ofs("c.in");
	ofs << "120\n";
	for (int i = 0; i < 120; ++i)
	{
		vector<int> a;
		if (i % 2 == 0)
			a = genGood(1000);
		else 
			a = genBad(1000);
		ofs << 1000 << endl;
		for (int j= 0; j < 1000; ++j)
			ofs << a[j] << ' ';
		ofs << endl;
	}
	return 0;
*/

	ifstream ifs("c.in");
	ofstream ofs("c.out");
	int t;
	ifs >> t;
	for (int test = 0; test < t; ++test)
	{
		int n;
		ifs >> n;
		for (int i = 0; i < n; ++i)
			ifs >> a[i];

		vector<int> c(5);
		for (int i = 0; i < n; ++i)
			c[i*5/n] += a[i]-i;
		double d = 0;
		double dx = 0;
		for (int i = 0; i < 5; ++i)
		{
			double x = c[i];
			d += x*x;
			dx += x;
		}
		res.push_back(make_pair(d / n - (dx/n)*(dx/n), test));
//		res.push_back(make_pair(d1 - d2, test));
	}
	sort(res.begin(), res.end());
	reverse(res.begin(), res.end());
	vector<string> out(t, "BAD");
	for (int i = 0; i < t/2; ++i)
		out[res[i].second] = "GOOD";


	int res = 0;
	for (int test = 0; test < t; ++test) 
	{
		if (test % 2 == 0 && out[test] == "GOOD" || test % 2 == 1 && out[test] != "GOOD") ++res;
		ofs << "Case #" << test+1 << ": " << out[test] << endl;
	}
	cout << res;
	return 0;

}
