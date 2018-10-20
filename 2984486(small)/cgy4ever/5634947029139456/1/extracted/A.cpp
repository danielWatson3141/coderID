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
//#include <ctime>
#include <map>
using namespace std;

int n, L;

string XOR(string a, string b)
{
	string ret;
	for(int i = 0; i < a.length(); i++)
		if(a[i] == b[i])
			ret += "0";
		else
			ret += "1";
	return ret;
}

int cnt1(string a)
{
	int ret = 0;
	for(int i = 0; i < a.length(); i++)
		ret += (a[i] == '1');
	return ret;
}

string A[301], B[301];

void solve()
{
	cin >> n >> L;
	for(int i = 1; i <= n; i++)
		cin >> A[i];
	for(int i = 1; i <= n; i++)
		cin >> B[i];
	int ans = L + 1;
	for(int c = 1; c <= n; c++)
	{
		string diff = XOR(A[1], B[c]);
		//cout << A[1] << " " << B[c] << " : " << diff << " " << cnt1(diff) << endl;
		//cout << "diff = " << diff << endl;
		map <string, int> occur;
		bool bad = false;
		for(int i = 1; i <= n; i++)
		{
			occur[XOR(A[i],diff)] = true;
		}
		for(int i = 1; i <= n; i++)
		{
			if(occur.count(B[i]) == false)
				bad = true;
		}
		if(!bad) ans = min(ans, cnt1(diff));
	}


	if(ans == L+1)
		cout << "NOT POSSIBLE" << endl;
	else
		cout << ans << endl;
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
	//srand((unsigned)time(NULL));
	#ifdef LOCAL_TEST
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif
	ios :: sync_with_stdio(false);
	cout << fixed << setprecision(16);
	return MAIN();
}
