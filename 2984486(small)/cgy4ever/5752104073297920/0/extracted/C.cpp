#include <algorithm>
#include <iostream>
#include <iomanip>
#include <complex>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
using namespace std;
//#pragma comment(linker,"/STACK:102400000,102400000")

int n;
int lis[1001];
double f()
{
	double ret = 0;
	for(int i = 0; i < 1000; i++)
		ret += lis[i] * pow(1.0*i, 0.2);
	return ret;
}
double middle = 1661214.806472274;

int solve()
{
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> lis[i];
	if(f() < middle)
		cout << "GOOD" << endl;
	else
		cout << "BAD" << endl;
	
	return 0;
}

int MAIN()
{
	int TestCase;
	cin >> TestCase;
	for(int caseID = 1; caseID <= TestCase; caseID ++)
	{
		cout << "Case #" << caseID << ": ";
		solve();
	}
	return 0;
}

int main()
{
	#ifdef LOCAL_TEST
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif
	ios :: sync_with_stdio(false);
	cout << fixed << setprecision(16);
	return MAIN();
}
